using System;
using System.Runtime.InteropServices;
public sealed class OriginalGdiBitmap : IDisposable {
 [DllImport("gdi32.dll")] static extern IntPtr CreateCompatibleDC(IntPtr dc);
 [DllImport("gdi32.dll")] static extern bool DeleteDC(IntPtr dc);
 [DllImport("gdi32.dll")] static extern bool DeleteObject(IntPtr o);
 [DllImport("gdi32.dll")] static extern IntPtr SelectObject(IntPtr dc, IntPtr o);
 [DllImport("gdi32.dll")] static extern IntPtr CreateDIBSection(IntPtr dc, IntPtr info, uint usage, out IntPtr bits, IntPtr section, uint offset);
 [DllImport("gdi32.dll")] static extern IntPtr CreateSolidBrush(uint color);
 [DllImport("gdi32.dll")] static extern IntPtr CreatePen(int style, int width, uint color);
 [DllImport("gdi32.dll")] static extern bool Rectangle(IntPtr dc,int l,int t,int r,int b);
 [DllImport("gdi32.dll")] static extern bool Ellipse(IntPtr dc,int l,int t,int r,int b);
 [DllImport("gdi32.dll")] static extern bool Arc(IntPtr dc,int l,int t,int r,int b,int sx,int sy,int ex,int ey);
 [DllImport("gdi32.dll")] static extern bool BitBlt(IntPtr dst,int x,int y,int w,int h,IntPtr src,int sx,int sy,uint rop);
 [DllImport("gdi32.dll")] static extern bool StretchBlt(IntPtr dst,int x,int y,int w,int h,IntPtr src,int sx,int sy,int sw,int sh,uint rop);
 [DllImport("gdi32.dll")] static extern bool PatBlt(IntPtr dc,int x,int y,int w,int h,uint rop);
 [DllImport("gdi32.dll")] static extern uint SetBkColor(IntPtr dc,uint c);
 [DllImport("gdi32.dll")] static extern uint SetTextColor(IntPtr dc,uint c);
 [DllImport("gdi32.dll")] static extern bool GdiFlush();
 [DllImport("gdi32.dll")] static extern IntPtr GetStockObject(int index);
 [DllImport("user32.dll",CharSet=CharSet.Unicode)] static extern IntPtr LoadImage(IntPtr instance,string file,uint type,int cx,int cy,uint flags);
 [DllImport("user32.dll")] static extern IntPtr GetDC(IntPtr window);
 [DllImport("user32.dll")] static extern int ReleaseDC(IntPtr window,IntPtr dc);
 [DllImport("user32.dll")] static extern uint GetSysColor(int index);
 [DllImport("gdi32.dll")] static extern IntPtr CreateCompatibleBitmap(IntPtr dc,int width,int height);
 [DllImport("gdi32.dll")] static extern int GetDeviceCaps(IntPtr dc,int index);
 [DllImport("gdi32.dll")] static extern int SetROP2(IntPtr dc,int mode);
 [DllImport("gdi32.dll")] static extern int SetBkMode(IntPtr dc,int mode);
 [DllImport("gdi32.dll")] static extern int SetStretchBltMode(IntPtr dc,int mode);
 [DllImport("gdi32.dll")] static extern int GetStretchBltMode(IntPtr dc);
 [DllImport("gdi32.dll")] static extern int GetDIBits(IntPtr dc,IntPtr bitmap,uint start,uint count,byte[] bits,IntPtr info,uint usage);
 [DllImport("gdi32.dll")] static extern int SetDIBits(IntPtr dc,IntPtr bitmap,uint start,uint count,byte[] bits,IntPtr info,uint usage);
 IntPtr dc,bitmap,oldBitmap,bits; int width,height,bpp;
 static IntPtr ColorInfo(int w,int h,int bitCount) {
  IntPtr info=Marshal.AllocHGlobal(40);for(int i=0;i<40;i++)Marshal.WriteByte(info,i,0);
  Marshal.WriteInt32(info,0,40);Marshal.WriteInt32(info,4,w);Marshal.WriteInt32(info,8,-h);
  Marshal.WriteInt16(info,12,1);Marshal.WriteInt16(info,14,(short)bitCount);return info;
 }
 public int StretchMode {get{return GetStretchBltMode(dc);}set{if(value<1||value>4)throw new Exception("Invalid native stretch mode");SetStretchBltMode(dc,value);}}
 public static int DesktopBits {get{IntPtr screen=GetDC(IntPtr.Zero);try{return GetDeviceCaps(screen,12)*GetDeviceCaps(screen,14);}finally{ReleaseDC(IntPtr.Zero,screen);}}}

 public OriginalGdiBitmap(int w,int h,int bitCount) {
  width=w;height=h;bpp=bitCount;dc=CreateCompatibleDC(IntPtr.Zero);
  if(bitCount==0) {
   // Original empty/device TBitmap resize path004E8610 uses screen-compatible DDB.
   IntPtr screen=GetDC(IntPtr.Zero);try{bitmap=CreateCompatibleBitmap(screen,w,h);}finally{ReleaseDC(IntPtr.Zero,screen);}
  }else{
   if(bitCount!=24&&bitCount!=32)throw new Exception("Unsupported native color bitmap format");
   IntPtr info=ColorInfo(w,h,bitCount);bitmap=CreateDIBSection(dc,info,0,out bits,IntPtr.Zero,0);Marshal.FreeHGlobal(info);
  }
  if(bitmap==IntPtr.Zero) throw new Exception("CreateDIBSection failed");
  oldBitmap=SelectObject(dc,bitmap);SetBkColor(dc,0xFFFFFF);SetTextColor(dc,GetSysColor(8));SetROP2(dc,13);SetBkMode(dc,2);
  if(!PatBlt(dc,0,0,w,h,0x00FF0062)) throw new Exception("WHITENESS failed");
 }
 public void Shape(string kind,int l,int t,int r,int b,uint penColor,uint brushColor,int brushStyle,int sx,int sy,int ex,int ey) {
  IntPtr pen=CreatePen(0,1,penColor),brush=brushStyle==1?GetStockObject(5):CreateSolidBrush(brushColor);
  IntPtr op=SelectObject(dc,pen),ob=SelectObject(dc,brush);
  SetROP2(dc,13);SetBkColor(dc,brushStyle==1?(~brushColor)&0xFFFFFF:brushColor);SetBkMode(dc,brushStyle==1?1:2);
  bool ok=kind=="rectangle"?Rectangle(dc,l,t,r,b):kind=="ellipse"?Ellipse(dc,l,t,r,b):Arc(dc,l,t,r,b,sx,sy,ex,ey);
  SelectObject(dc,op);SelectObject(dc,ob);DeleteObject(pen);if(brushStyle!=1)DeleteObject(brush);
  // Original VCL 004E43C8/004E4588/004E4744 ignore GDI BOOL.
  // Empty/clipped geometry therefore keeps the actual resulting pixels.
 }
 public void Texture(string file) {
  IntPtr source=CreateCompatibleDC(IntPtr.Zero);
  // LR_LOADFROMFILE | LR_CREATEDIBSECTION: use the actual 24-bit original BMP.
  IntPtr image=LoadImage(IntPtr.Zero,file,0,0,0,0x2010);
  if(image==IntPtr.Zero)throw new Exception("LoadImage guti failed");
  IntPtr previous=SelectObject(source,image);SetBkColor(source,0xFFFFFF);SetTextColor(source,0);
  // Original TCanvas.Draw uses the complete 90x90 source, destination clipping.
  //004E917C:24bpp non-monochrome guti uses COLORONCOLOR on normal color devices.
  SetTextColor(dc,GetSysColor(8));SetStretchBltMode(dc,GetDeviceCaps(dc,12)*GetDeviceCaps(dc,14)<9?4:3);
  bool ok=StretchBlt(dc,0,0,90,90,source,0,0,90,90,0x00EE0086);
  SelectObject(source,previous);DeleteObject(image);DeleteDC(source);
  if(!ok)throw new Exception("SRCPAINT failed");
 }
 public void CopyRectWords(string sourceWords,int sourceWidth,int sourceHeight,int l,int t,int r,int b,int sl,int st,int sr,int sb,uint rop) {
  using(var source=new OriginalGdiBitmap(sourceWidth,sourceHeight,32)) {
   source.LoadWords(sourceWords);
   // Original VCL004E4420 uses StretchBlt and ignores its BOOL result.
   StretchBlt(dc,l,t,r-l,b-t,source.dc,sl,st,sr-sl,sb-st,rop);
  }
 }
 public void LoadWords(string base64) {
  byte[] raw=Convert.FromBase64String(base64);if(raw.Length!=width*height*4)throw new Exception("Initial BGRA dimensions differ");GdiFlush();
  if(bpp==32){Marshal.Copy(raw,0,bits,raw.Length);return;}
  // For24bpp/device profiles let native GDI perform its own format conversion.
  IntPtr info=ColorInfo(width,height,32);SelectObject(dc,oldBitmap);
  try{if(SetDIBits(dc,bitmap,0,(uint)height,raw,info,0)==0)throw new Exception("Native input pixel conversion failed");}
  finally{SelectObject(dc,bitmap);Marshal.FreeHGlobal(info);}
 }
 public string ConvertedWords() {
  GdiFlush();byte[] raw=new byte[width*height*4];
  if(bpp==32){Marshal.Copy(bits,raw,0,raw.Length);return Convert.ToBase64String(raw);}
  // Native004EA36C/004E8610 converts to32-bit via GDI. Return visual top-down rows.
  IntPtr info=ColorInfo(width,height,32);SelectObject(dc,oldBitmap);
  try{if(GetDIBits(dc,bitmap,0,(uint)height,raw,info,0)==0)throw new Exception("Native32-bit output conversion failed");}
  finally{SelectObject(dc,bitmap);Marshal.FreeHGlobal(info);}
  return Convert.ToBase64String(raw);
 }
 public string Coverage() {
  if(bpp!=32)throw new Exception("Expected 32-bit coverage probe");
  GdiFlush();byte[] raw=new byte[width*height*4],coverage=new byte[width*height];Marshal.Copy(bits,raw,0,raw.Length);
  for(int i=0;i<coverage.Length;i++) coverage[i]=(byte)((raw[i*4]!=255||raw[i*4+1]!=255||raw[i*4+2]!=255)?1:0);
  return Convert.ToBase64String(coverage);
 }
 public void Dispose(){if(dc!=IntPtr.Zero){SelectObject(dc,oldBitmap);DeleteObject(bitmap);DeleteDC(dc);dc=IntPtr.Zero;}}
}