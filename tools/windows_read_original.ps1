[CmdletBinding()]
param(
    [ValidateRange(0, 2147483647)] [int] $ProcessId = 0,
    [string] $OutputPath = "original-cache-snapshot.json",
    [string] $Label = "snapshot",
    [ValidateRange(1, 100)] [int] $RepeatCount = 1,
    [ValidateRange(0, 5000)] [int] $IntervalMilliseconds = 100,
    [ValidateRange(1, 4096)] [int] $ReaderSafetyMaxVessels = 2048,
    [switch] $RequireNotAdvancing,
    [switch] $IncludeAmounts,
    [UInt32] $KnownControlWordGlobalVa = 0
)

Set-StrictMode -Version Latest
$ErrorActionPreference = "Stop"
$expectedOriginalSha256 = "7744d5c7c76d51418e00c67cda112c14a495c93b0386ee5a52f05e165702b71c"
$originalPreferredBase = [UInt64] 0x00400000

# These are the only process APIs used: image/module queries, OpenProcess with
# VM_READ plus QUERY_LIMITED_INFORMATION, ReadProcessMemory, and CloseHandle.
# No write, allocation, thread, debugger, injection, input, or suspension API exists here.
if (-not ("ChemLabOriginalReadOnlyProbe" -as [type])) {
    Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;

public static class ChemLabOriginalReadOnlyProbe {
    [DllImport("kernel32.dll", SetLastError=true)]
    private static extern IntPtr OpenProcess(uint access, bool inherit, uint processId);
    [DllImport("kernel32.dll", SetLastError=true)]
    private static extern bool ReadProcessMemory(IntPtr process, IntPtr address,
        [Out] byte[] buffer, UIntPtr size, out UIntPtr read);
    [DllImport("kernel32.dll", SetLastError=true)]
    private static extern bool CloseHandle(IntPtr handle);
    [DllImport("kernel32.dll", CharSet=CharSet.Unicode, SetLastError=true)]
    private static extern bool QueryFullProcessImageNameW(IntPtr process, uint flags,
        StringBuilder name, ref uint size);
    [DllImport("kernel32.dll", SetLastError=true)]
    private static extern IntPtr CreateToolhelp32Snapshot(uint flags, uint processId);
    [DllImport("kernel32.dll", CharSet=CharSet.Unicode, SetLastError=true)]
    private static extern bool Module32FirstW(IntPtr snapshot, ref ModuleEntry module);
    [DllImport("kernel32.dll", CharSet=CharSet.Unicode, SetLastError=true)]
    private static extern bool Module32NextW(IntPtr snapshot, ref ModuleEntry module);

    [StructLayout(LayoutKind.Sequential, CharSet=CharSet.Unicode)]
    public struct ModuleEntry {
        public uint dwSize, th32ModuleID, th32ProcessID, GlblcntUsage, ProccntUsage;
        public IntPtr modBaseAddr;
        public uint modBaseSize;
        public IntPtr hModule;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst=256)] public string szModule;
        [MarshalAs(UnmanagedType.ByValTStr, SizeConst=260)] public string szExePath;
    }

    public static IntPtr Open(uint processId) {
        IntPtr handle = OpenProcess(0x0010 | 0x1000, false, processId);
        if (handle == IntPtr.Zero)
            throw new Win32Exception(Marshal.GetLastWin32Error(), "Read-only OpenProcess failed; no elevation attempted");
        return handle;
    }

    public static void Close(IntPtr handle) {
        if (handle != IntPtr.Zero) CloseHandle(handle);
    }

    public static string ImagePath(IntPtr handle) {
        StringBuilder name = new StringBuilder(32768);
        uint size = (uint) name.Capacity;
        if (!QueryFullProcessImageNameW(handle, 0, name, ref size))
            throw new Win32Exception(Marshal.GetLastWin32Error(), "Cannot query target image path");
        return name.ToString();
    }

    public static ModuleEntry[] Modules(uint processId) {
        // SNAPMODULE | SNAPMODULE32 enables 32-bit module enumeration from a 64-bit host.
        IntPtr snapshot = CreateToolhelp32Snapshot(0x00000008 | 0x00000010, processId);
        if (snapshot == new IntPtr(-1))
            throw new Win32Exception(Marshal.GetLastWin32Error(), "Read-only module enumeration failed");
        try {
            List<ModuleEntry> result = new List<ModuleEntry>();
            ModuleEntry entry = new ModuleEntry();
            entry.dwSize = (uint) Marshal.SizeOf(typeof(ModuleEntry));
            if (!Module32FirstW(snapshot, ref entry))
                throw new Win32Exception(Marshal.GetLastWin32Error(), "No target modules available");
            do {
                result.Add(entry);
                entry.dwSize = (uint) Marshal.SizeOf(typeof(ModuleEntry));
            } while (Module32NextW(snapshot, ref entry));
            return result.ToArray();
        } finally { CloseHandle(snapshot); }
    }

    public static byte[] Read(IntPtr handle, ulong address, int length) {
        if (length < 0 || length > 1048576) throw new ArgumentOutOfRangeException("length");
        byte[] bytes = new byte[length];
        if (length == 0) return bytes;
        UIntPtr read;
        if (!ReadProcessMemory(handle, new IntPtr(unchecked((long) address)), bytes,
                new UIntPtr((uint) length), out read) || read.ToUInt64() != (ulong) length)
            throw new Win32Exception(Marshal.GetLastWin32Error(),
                String.Format("Exact read failed at 0x{0:X}, requested {1} bytes", address, length));
        return bytes;
    }

    public static byte[] CStringBytes(IntPtr handle, ulong address, int maximum) {
        if (address == 0) return new byte[0];
        List<byte> result = new List<byte>();
        while (result.Count < maximum) {
            ulong current = address + (ulong) result.Count;
            int pageRemaining = 4096 - (int) (current & 4095);
            int size = Math.Min(32, Math.Min(pageRemaining, maximum - result.Count));
            byte[] part = Read(handle, current, size);
            foreach (byte value in part) {
                if (value == 0) return result.ToArray();
                result.Add(value);
            }
        }
        throw new InvalidOperationException("CString terminator was not found within the reader safety limit");
    }
}
'@
}

# GB18030 decodes original GBK/ANSI chemical names without discarding their raw bytes.
try {
    $providerType = "System.Text.CodePagesEncodingProvider" -as [type]
    if ($null -ne $providerType) {
        [System.Text.Encoding]::RegisterProvider([System.Text.CodePagesEncodingProvider]::Instance)
    }
} catch { }
$originalTextEncoding = [System.Text.Encoding]::GetEncoding(54936)

function Get-HexBytes([byte[]] $Bytes) {
    return [BitConverter]::ToString($Bytes).Replace("-", "").ToLowerInvariant()
}

function Get-HexAddress([UInt64] $Address) { return ("0x{0:x8}" -f $Address) }

function Read-UInt32([UInt64] $Address) {
    return [BitConverter]::ToUInt32([ChemLabOriginalReadOnlyProbe]::Read($originalHandle, $Address, 4), 0)
}

function Read-Int32([UInt64] $Address) {
    return [BitConverter]::ToInt32([ChemLabOriginalReadOnlyProbe]::Read($originalHandle, $Address, 4), 0)
}

function Get-RuntimeAddress([UInt64] $PreferredVa) {
    return $runtimeModuleBase + ($PreferredVa - $originalPreferredBase)
}

function Read-OriginalString([UInt32] $Pointer) {
    try {
        [byte[]] $bytes = [ChemLabOriginalReadOnlyProbe]::CStringBytes($originalHandle, [UInt64] $Pointer, 512)
        return [ordered] @{ status = "read"; pointer = (Get-HexAddress $Pointer); raw_hex = (Get-HexBytes $bytes); encoding = "GB18030 (original GBK-compatible bytes)"; text = $originalTextEncoding.GetString($bytes) }
    } catch {
        return [ordered] @{ status = "unreadable"; pointer = (Get-HexAddress $Pointer); error = $_.Exception.Message }
    }
}

function Convert-DoubleBytes([byte[]] $Bytes, [int] $Offset = 0) {
    [byte[]] $exactBytes = $Bytes[$Offset..($Offset + 7)]
    $number = [BitConverter]::ToDouble($exactBytes, 0)
    $classification = "finite"
    if ([Double]::IsNaN($number)) { $classification = "nan" }
    elseif ([Double]::IsPositiveInfinity($number)) { $classification = "positive_infinity" }
    elseif ([Double]::IsNegativeInfinity($number)) { $classification = "negative_infinity" }
    return [ordered] @{ ieee754_le_hex = (Get-HexBytes $exactBytes); classification = $classification; value_text = $number.ToString("R", [Globalization.CultureInfo]::InvariantCulture) }
}

function Read-DoubleArray([UInt64] $Address, [int] $ActiveCount, [object[]] $Species) {
    [byte[]] $bytes = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, $Address, 800)
    $slots = @()
    for ($slotIndex = 0; $slotIndex -lt 100; $slotIndex++) {
        $value = Convert-DoubleBytes $bytes ($slotIndex * 8)
        $value["slot"] = $slotIndex
        $value["in_active_count"] = ($slotIndex -lt $ActiveCount)
        if ($slotIndex -lt $ActiveCount) { $value["species"] = $Species[$slotIndex] }
        else { $value["species"] = $null }
        $slots += $value
    }
    return [ordered] @{ address = (Get-HexAddress $Address); count = 100; raw_hex = (Get-HexBytes $bytes); slots = $slots }
}

function Read-RunState {
    $runGlobal = Read-Int32 (Get-RuntimeAddress 0x0057a6f8)
    $mainFormPointer = Read-UInt32 (Get-RuntimeAddress 0x005799c4)
    $pauseValue = $null
    $pauseError = $null
    if ($mainFormPointer -ne 0) {
        try { $pauseValue = Read-Int32 ([UInt64] $mainFormPointer + 0x5bc) }
        catch { $pauseError = $_.Exception.Message }
    }
    $advancing = $null
    if ($runGlobal -ne 1) { $advancing = $false }
    elseif ($null -ne $pauseValue) { $advancing = ($pauseValue -eq 0) }
    [byte[]] $elapsedBytes = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, (Get-RuntimeAddress 0x005636cc), 8)
    return [ordered] @{ running_global_0057a6f8 = $runGlobal; main_form_pointer_005799c4 = (Get-HexAddress $mainFormPointer); pause_field_0x5bc = $pauseValue; pause_read_error = $pauseError; simulation_advancing = $advancing; elapsed_005636cc = (Convert-DoubleBytes $elapsedBytes) }
}

function Read-Snapshot([int] $Sequence) {
    $startedUtc = [DateTime]::UtcNow.ToString("o")
    $beforeRun = Read-RunState
    if ($RequireNotAdvancing -and $beforeRun.simulation_advancing -ne $false) {
        throw "The target is advancing or pause state is unknown. The reader will not pause it."
    }
    $countAddress = Get-RuntimeAddress 0x0058779c
    $pointerArrayAddress = Get-RuntimeAddress 0x00585850
    $beforeCount = Read-Int32 $countAddress
    if ($beforeCount -lt 0 -or $beforeCount -gt $ReaderSafetyMaxVessels) {
        throw "Apparatus count $beforeCount exceeds the reader safety bound (not an original simulation limit)."
    }
    [byte[]] $beforePointers = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, $pointerArrayAddress, ($beforeCount * 4))
    $vessels = @()
    for ($vesselIndex = 0; $vesselIndex -lt $beforeCount; $vesselIndex++) {
        $pointer = [BitConverter]::ToUInt32($beforePointers, $vesselIndex * 4)
        $record = [ordered] @{ native_index = $vesselIndex; pointer = (Get-HexAddress $pointer); status = "read" }
        if ($pointer -eq 0) { $record["status"] = "null_pointer"; $vessels += $record; continue }
        try {
            $record["label"] = Read-OriginalString (Read-UInt32 ([UInt64] $pointer + 4))
            $record["type_id"] = Read-Int32 ([UInt64] $pointer + 8)
            $record["native_type_parameter"] = Read-Int32 ([UInt64] $pointer + 12)
            $speciesCount = Read-Int32 ([UInt64] $pointer + 0x104)
            if ($speciesCount -lt 0 -or $speciesCount -gt 100) { throw "Invalid native species count $speciesCount at +0x104." }
            $record["species_count_0x104"] = $speciesCount
            [byte[]] $speciesPointers = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, ([UInt64] $pointer + 0x108), ($speciesCount * 4))
            $species = @()
            for ($speciesIndex = 0; $speciesIndex -lt $speciesCount; $speciesIndex++) {
                $species += (Read-OriginalString ([BitConverter]::ToUInt32($speciesPointers, $speciesIndex * 4)))
            }
            $record["species"] = $species
            $record["arrays"] = [ordered] @{
                volume_0x5b8 = (Read-DoubleArray ([UInt64] $pointer + 0x5b8) $speciesCount $species)
                solid_0x3cd8 = (Read-DoubleArray ([UInt64] $pointer + 0x3cd8) $speciesCount $species)
                solid_0x3ff8 = (Read-DoubleArray ([UInt64] $pointer + 0x3ff8) $speciesCount $species)
            }
            if ($IncludeAmounts) {
                $record.arrays["moles_0x8d8"] = Read-DoubleArray ([UInt64] $pointer + 0x8d8) $speciesCount $species
                $record.arrays["mass_0x298"] = Read-DoubleArray ([UInt64] $pointer + 0x298) $speciesCount $species
            }
            $scalars = [ordered] @{}
            foreach ($offset in @(0x4318, 0x3cc8, 0x4338, 0x3cc0)) {
                $scalars[("0x{0:x}" -f $offset)] = Convert-DoubleBytes ([ChemLabOriginalReadOnlyProbe]::Read($originalHandle, ([UInt64] $pointer + [UInt64] $offset), 8))
            }
            $record["scalars"] = $scalars
            $afterSpeciesCount = Read-Int32 ([UInt64] $pointer + 0x104)
            [byte[]] $afterSpeciesPointers = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, ([UInt64] $pointer + 0x108), ($speciesCount * 4))
            $record["species_identity_stable_during_read"] = ($afterSpeciesCount -eq $speciesCount -and (Get-HexBytes $speciesPointers) -eq (Get-HexBytes $afterSpeciesPointers))
        } catch { $record["status"] = "incomplete"; $record["error"] = $_.Exception.Message }
        $vessels += $record
    }
    $afterCount = Read-Int32 $countAddress
    [byte[]] $afterPointers = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, $pointerArrayAddress, ($beforeCount * 4))
    $afterRun = Read-RunState
    if ($RequireNotAdvancing -and $afterRun.simulation_advancing -ne $false) {
        throw "The target began advancing or its pause state became unknown during the read. No paused-state output was saved."
    }
    return [ordered] @{
        sequence = $Sequence; label = $Label; read_started_utc = $startedUtc; read_finished_utc = [DateTime]::UtcNow.ToString("o")
        apparatus_count_before = $beforeCount; apparatus_count_after = $afterCount
        apparatus_identity_stable_during_read = ($beforeCount -eq $afterCount -and (Get-HexBytes $beforePointers) -eq (Get-HexBytes $afterPointers))
        run_state_before = $beforeRun; run_state_after = $afterRun
        read_is_atomic = $false; vessels = $vessels
    }
}

$originalHandle = [IntPtr]::Zero
try {
    if ($ProcessId -eq 0) {
        $matchingProcessIds = @()
        foreach ($candidateProcess in @(Get-Process -Name "_main", "main", "仿真化学实验室" -ErrorAction SilentlyContinue)) {
            $candidateHandle = [IntPtr]::Zero
            try {
                $candidateHandle = [ChemLabOriginalReadOnlyProbe]::Open([UInt32] $candidateProcess.Id)
                $candidatePath = [ChemLabOriginalReadOnlyProbe]::ImagePath($candidateHandle)
                if ((Get-FileHash -LiteralPath $candidatePath -Algorithm SHA256).Hash.ToLowerInvariant() -eq $expectedOriginalSha256) { $matchingProcessIds += $candidateProcess.Id }
            } catch { }
            finally { [ChemLabOriginalReadOnlyProbe]::Close($candidateHandle) }
        }
        if ($matchingProcessIds.Count -ne 1) { throw "Found $($matchingProcessIds.Count) matching original processes. Supply -ProcessId explicitly; no process was changed." }
        $ProcessId = $matchingProcessIds[0]
    }
    $originalHandle = [ChemLabOriginalReadOnlyProbe]::Open([UInt32] $ProcessId)
    $originalImagePath = [ChemLabOriginalReadOnlyProbe]::ImagePath($originalHandle)
    $actualSha256 = (Get-FileHash -LiteralPath $originalImagePath -Algorithm SHA256).Hash.ToLowerInvariant()
    if ($actualSha256 -ne $expectedOriginalSha256) { throw "Refusing memory reads: target image SHA-256 does not match the recovered original main.exe." }
    # Windows ARM's combined SNAPMODULE/SNAPMODULE32 enumeration can report the
    # same x86 module twice. Collapse only identical path/base/size identities;
    # conflicting mappings still fail the exactly-one-module guard below.
    $moduleDetails = @([ChemLabOriginalReadOnlyProbe]::Modules([UInt32] $ProcessId) | Where-Object { $_.szExePath -ieq $originalImagePath } | Sort-Object modBaseAddr,modBaseSize,szExePath -Unique)
    if ($moduleDetails.Count -ne 1) { throw "Could not identify exactly one original executable module by its image path." }
    $runtimeModuleBase = [UInt64] $moduleDetails[0].modBaseAddr.ToInt64()
    [byte[]] $dosHeader = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, $runtimeModuleBase, 64)
    if ($dosHeader[0] -ne 0x4d -or $dosHeader[1] -ne 0x5a) { throw "Target module lacks the original PE DOS header." }
    $peOffset = [BitConverter]::ToUInt32($dosHeader, 0x3c)
    if ($peOffset -gt 1048576) { throw "Unreasonable PE header offset; reader safety check failed." }
    [byte[]] $peHeader = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, ($runtimeModuleBase + $peOffset), 64)
    if ([BitConverter]::ToUInt32($peHeader, 0) -ne 0x00004550 -or [BitConverter]::ToUInt16($peHeader, 4) -ne 0x014c -or [BitConverter]::ToUInt16($peHeader, 24) -ne 0x010b) { throw "Target is not the expected original x86 PE32 module." }
    if ([BitConverter]::ToUInt32($peHeader, 52) -ne $originalPreferredBase) { throw "Original PE preferred image base does not match address evidence." }
    $snapshots = @()
    for ($captureIndex = 0; $captureIndex -lt $RepeatCount; $captureIndex++) {
        $snapshots += Read-Snapshot $captureIndex
        if ($captureIndex + 1 -lt $RepeatCount -and $IntervalMilliseconds -gt 0) { Start-Sleep -Milliseconds $IntervalMilliseconds }
    }
    $controlWord = [ordered] @{ status = "not_captured"; explanation = "ReadProcessMemory cannot obtain the live x87 hardware control word. No thread-context, suspension, or debugger APIs are used." }
    if ($KnownControlWordGlobalVa -ne 0) {
        $cwAddress = Get-RuntimeAddress $KnownControlWordGlobalVa
        [byte[]] $cwBytes = [ChemLabOriginalReadOnlyProbe]::Read($originalHandle, $cwAddress, 2)
        $controlWord = [ordered] @{ status = "caller_specified_memory_global_read"; preferred_va = (Get-HexAddress $KnownControlWordGlobalVa); runtime_address = (Get-HexAddress $cwAddress); raw_hex = (Get-HexBytes $cwBytes); value_hex = ("0x{0:x4}" -f [BitConverter]::ToUInt16($cwBytes, 0)); explanation = "This is the specified memory global, not an observed hardware register. The caller must provide original-code evidence for the address." }
    }
    $output = [ordered] @{
        format = "ChemLab-original-read-only-memory-profile"; version = 1
        provenance = [ordered] @{ process_id = $ProcessId; image_path = $originalImagePath; image_sha256 = $actualSha256; expected_sha256 = $expectedOriginalSha256; runtime_module_base = (Get-HexAddress $runtimeModuleBase); preferred_image_base = (Get-HexAddress $originalPreferredBase); module_size = $moduleDetails[0].modBaseSize; process_pointer_bits = 32; host_pointer_bits = ([IntPtr]::Size * 8); process_access = "PROCESS_VM_READ | PROCESS_QUERY_LIMITED_INFORMATION"; procedure = "ReadProcessMemory only; no writes, inputs, thread APIs, debugger attachment, or process suspension" }
        scope = [ordered] @{ global_vessel_count_va = "0x0058779c"; global_vessel_pointer_array_va = "0x00585850"; array_offsets = @("0x5b8", "0x3cd8", "0x3ff8"); scalar_offsets = @("0x4318", "0x3cc8", "0x4338", "0x3cc0"); array_slots = 100; include_amounts = [bool] $IncludeAmounts; reader_safety_max_vessels = $ReaderSafetyMaxVessels }
        x87_control_word = $controlWord
        limitations = @("Snapshots are sequential reads and are not atomic. Identity checks detect some concurrent changes but do not prove no race or torn double read.", "All 100 numeric slots are captured, including inactive slots. Their bytes are observations of this allocation, not universal constructor defaults.", "Raw little-endian IEEE-754 hex is authoritative. Decimal value_text is display only and may include NaN/Infinity.", "The reader does not claim that a stored control-word global equals a thread's current hardware control word.")
        snapshots = $snapshots
    }
    $resolvedOutputPath = $ExecutionContext.SessionState.Path.GetUnresolvedProviderPathFromPSPath($OutputPath)
    $outputDirectory = [IO.Path]::GetDirectoryName($resolvedOutputPath)
    if (-not [IO.Directory]::Exists($outputDirectory)) { [IO.Directory]::CreateDirectory($outputDirectory) | Out-Null }
    $json = $output | ConvertTo-Json -Depth 15
    [IO.File]::WriteAllText($resolvedOutputPath, $json, (New-Object System.Text.UTF8Encoding($false)))
    Write-Output ("Saved {0} read-only snapshot(s) from original process {1}: {2}" -f $snapshots.Count, $ProcessId, $resolvedOutputPath)
} finally { [ChemLabOriginalReadOnlyProbe]::Close($originalHandle) }
