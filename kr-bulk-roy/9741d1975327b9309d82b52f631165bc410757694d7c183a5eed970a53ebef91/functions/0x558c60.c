
void FUN_00558c60(int param_1,UINT param_2,WPARAM param_3,LPARAM param_4)

{
  HDC hdc;
  HWND unaff_EDI;
  HGDIOBJ local_70;
  HDC local_6c;
  undefined1 local_68 [4];
  int local_64;
  int local_60;
  tagPAINTSTRUCT local_50;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_70;
  if (param_2 == 0xf) {
    local_6c = BeginPaint(unaff_EDI,&local_50);
    hdc = CreateCompatibleDC(local_6c);
    local_70 = SelectObject(hdc,*(HGDIOBJ *)(param_1 + 0x10));
    GetObjectW(*(HANDLE *)(param_1 + 0x10),0x18,local_68);
    BitBlt(local_6c,0,0,local_64,local_60,hdc,0,0,0xcc0020);
    SelectObject(hdc,local_70);
    DeleteDC(hdc);
    EndPaint(unaff_EDI,&local_50);
  }
  else if (param_2 == 0x10) {
    __security_check_cookie(local_c ^ (uint)&local_70);
    return;
  }
  DefWindowProcW(unaff_EDI,param_2,param_3,param_4);
  __security_check_cookie(local_c ^ (uint)&local_70);
  return;
}

