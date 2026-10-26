
void FUN_0073b7f0(void)

{
  HDC hdc;
  HBITMAP h;
  HGDIOBJ ho;
  int unaff_ESI;
  BITMAPINFO local_34;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  hdc = CreateCompatibleDC((HDC)0x0);
  *(HDC *)(unaff_ESI + 0xc) = hdc;
  _memset(&local_34,0,0x2c);
  local_34.bmiHeader.biSize = 0x28;
  local_34.bmiHeader.biWidth = 0x800;
  local_34.bmiHeader.biHeight = -0x300;
  local_34.bmiHeader.biPlanes = 1;
  local_34.bmiHeader.biBitCount = 0x20;
  local_34.bmiHeader.biCompression = 0;
  local_34.bmiHeader.biXPelsPerMeter = 0;
  local_34.bmiHeader.biYPelsPerMeter = 0;
  local_34.bmiHeader.biClrUsed = 0;
  local_34.bmiHeader.biClrImportant = 0;
  h = CreateDIBSection(hdc,&local_34,0,(void **)(unaff_ESI + 0x14),(HANDLE)0x0,0);
  *(HBITMAP *)(unaff_ESI + 0x10) = h;
  ho = SelectObject(*(HDC *)(unaff_ESI + 0xc),h);
  if (ho != (HGDIOBJ)0x0) {
    DeleteObject(ho);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

