using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Runtime.InteropServices;
using System.Text;

public static class ChemLabOriginalDibReadProbe {
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
