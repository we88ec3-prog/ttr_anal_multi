
void FUN_0073abe0(void)

{
  LPCWSTR lpWideCharStr;
  char *_Src;
  int iVar1;
  int in_ECX;
  undefined1 auStack_134 [4];
  undefined **local_130;
  int local_12c;
  char local_128 [268];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092886e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_134;
  ExceptionList = &local_14;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_c = 0;
    FUN_00736880(DAT_00d61f20 ^ (uint)&stack0xfffffec0);
    _atexit(FUN_00bce6f0);
  }
  local_c = 0xffffffff;
  if (DAT_00fcde2c != 0) {
    lpWideCharStr = (LPCWSTR)(in_ECX + 0x24);
    if (7 < *(uint *)(in_ECX + 0x38)) {
      lpWideCharStr = *(LPCWSTR *)lpWideCharStr;
    }
    if (lpWideCharStr == (LPCWSTR)0x0) {
      _Src = "";
    }
    else {
      WideCharToMultiByte(0,0,lpWideCharStr,-1,&DAT_00fdf710,0x400,(LPCSTR)0x0,(LPBOOL)0x0);
      _Src = &DAT_00fdf710;
    }
    _strcpy_s(local_128,0x104,_Src);
    local_12c = in_ECX + 8;
    local_130 = `long___cdecl_Graphics::GetImageInfoFromFile(char_const*,_D3DXIMAGE_INFO*)'::__l2::
                GetImageInfoFromFileBox::vftable;
    iVar1 = FUN_00737d40();
    if (-1 < iVar1) {
      FUN_00737f40(local_128,*(undefined4 *)(in_ECX + 0xc),0,in_ECX + 0x44);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_134);
  return;
}

