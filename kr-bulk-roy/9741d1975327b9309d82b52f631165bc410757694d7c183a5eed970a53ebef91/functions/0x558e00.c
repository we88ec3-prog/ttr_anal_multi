
void FUN_00558e00(void)

{
  HDC hdc;
  HDC hdc_00;
  int unaff_ESI;
  undefined1 local_4c [4];
  LONG local_48;
  LONG local_44;
  POINT local_34;
  POINT local_2c;
  SIZE local_24;
  HGDIOBJ local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  GetObjectW(*(HANDLE *)(unaff_ESI + 0x10),0x18,local_4c);
  GetWindowRect(*(HWND *)(unaff_ESI + 0xc),&local_18);
  local_24.cy = local_44;
  local_24.cx = local_48;
  local_34.x = local_18.left;
  local_34.y = local_18.top;
  hdc = GetDC(*(HWND *)(unaff_ESI + 0xc));
  hdc_00 = CreateCompatibleDC(hdc);
  local_1c = SelectObject(hdc_00,*(HGDIOBJ *)(unaff_ESI + 0x10));
  local_2c.x = 0;
  local_2c.y = 0;
  UpdateLayeredWindow(*(HWND *)(unaff_ESI + 0xc),hdc,&local_34,&local_24,hdc_00,&local_2c,0,
                      (BLENDFUNCTION *)(unaff_ESI + 0x18),2);
  SelectObject(hdc_00,local_1c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

