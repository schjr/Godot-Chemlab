# Read-only original DIB pixel capture

The existing pixels can be read without calling target code. Do **not** call
TBitmap.GetScanLine004E95B0: it calls004E9130 (copy-on-write preparation),
004E9668 (handle/DIB conversion) andGdiFlush. A read-only probe must use
already-existing metadata and a nonnull bmBits pointer; a DDB is explicitly
unavailable until the original app itself creates a CPU-readable DIB.

For each original vessel, fields+FC,+F8,+F4 point to TBitmap objects.
Validate their VMT004E2AF4, then read shared=U32(bitmap+20).
Constructor004E8F0D writes this shared pointer;004E991C copies84bytes of
Win32 DIBSECTION metadata into shared+18. The layout is:

| Shared offset | Meaning |
|---|---|
|+08|primary HBITMAP handle|
|+10|palette handle|
|+14|secondary HBITMAP/DIB handle, **not a pixel pointer**|
|+18|BITMAP.bmType|
|+1C|BITMAP.bmWidth signed32|
|+20|BITMAP.bmHeight signed32|
|+24|BITMAP.bmWidthBytes signed32|
|+28|BITMAP.bmPlanes WORD|
|+2A|BITMAP.bmBitsPixel WORD|
|+2C|BITMAP.bmBits32-bit address of existing backing pixels|
|+30|BITMAPINFOHEADER.biSize|
|+34|biWidth signed32|
|+38|biHeight signed32; positive=bottom-up,negative=top-down|
|+3C|biPlanes WORD|
|+3E|biBitCount WORD|
|+40|biCompression DWORD|
|+44|biSizeImage DWORD|
|+48/+4C|biXPelsPerMeter/biYPelsPerMeter|
|+50/+54|biClrUsed/biClrImportant|
|+58/+5C/+60|DIBSECTION bitfield masks|
|+64/+68|DIBSECTION section handle/offset|

004E95C1–CA selects shared+18 as BITMAP and shared+30 as DIB header.
004E95EB–F5 reverses row index when biHeight>0.004E95F7–960A reads
biBitCount,biWidth and adds BITMAP.bmBits. Helper004E510C computes
stride=((width*bits+31)&~31)/8. Thus visual row y has address
bits+(height-1-y)*stride for positive stored height, otherwise bits+y*stride.
Rows retain native padding; color24 is B/G/R, color32 isB/G/R/reserved.
The reserved byte is not opacity and must not be silently rewritten.

004E9684–968E calls GetObject(HBITMAP,0x54,shared+18) if cached header
is missing. It fills cached header fields and004E96D0 can create a DIB
copy. The probe must not invoke this code or call GetObject on a remote
process handle as if it were a local GDI object. Shared metadata can therefore
be absent or stale; pointer/metadata consistency guards remain necessary.

Prepared tools (no target app calls or writes):

```powershell
powershell -NoProfile -File .\read_original_dib_pixels.ps1 -ProcessId 9348 -Output .\original-dib-pixels.json
```

Keep `original_dib_read_probe.cs` alongside the script. Run with existing
policy/privileges; no execution-policy or elevation change is requested.
The default expected six pointers are0D960000,0D964380,0D968700,0D96CA80,
0D970E00,0D97C000. For another explicitly identified snapshot, pass all six
`-ExpectedVessels` values. No pointer search or arbitrary process selection
is performed. Image SHA256 must match the retained original PE and PE32 x86
headers; module-relative globals are relocated from preferred base00400000.

The reader uses only the same read/query APIs as `windows_read_original.ps1`:
OpenProcess(VM_READ|QUERY_LIMITED_INFORMATION), module/image queries,
ReadProcessMemory,CloseHandle. It requires non-advancing run/pause state,
unchanged elapsed time and apparatus count/pointers before/after. Each bitmap
object/metadata and full backing store are read twice and compared. Valid
existing DIBs require40-byte header,plane1,BI_RGB,color24/32,matching BITMAP
dimensions/stride, at most1024x1024 and1MiB/image. Null bits produce an explicit
unavailable record; unsupported or changing metadata/pixels abort the capture.
Fresh output filenames preserve prior evidence. There is no injection,
targetGDIcall,GdiFlush,draw/refresh request, suspension, GUI input or network.

The JSON records both exact raw backing storage and visual-top-down storage
(including padding), SHA256s, raw bitmap/shared metadata, addresses, source
reader hashes, run-state and process provenance. It does not compare these
pixels to the standalone GDI probes or automatically verify a production
profile. In particular, repeated stable reads cannot prove the target's
pending GDI batches have drained. It is a stable per-bitmap read, not an
atomic complete-frame capture. Pause/last draw history and matched input
geometry/colors/DC state still require independent evidence.

This tool was source-reviewed on macOS; Windows execution and actual original
pixel capture remain pending. No target memory was modified while preparing it.
