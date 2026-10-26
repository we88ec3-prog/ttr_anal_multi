
void FUN_006aac80(void)

{
  WCHAR WVar1;
  WCHAR *pWVar2;
  int in_ECX;
  WCHAR local_210;
  undefined1 local_20e [518];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  FUN_00755e50();
  FUN_006ab780();
  FUN_00615fc0(200);
  FUN_00615fc0(300);
  FUN_006ab870();
  *(undefined1 *)(*(int *)(in_ECX + 0xf4) + 0xca) = 1;
  local_210 = L'\0';
  _memset(local_20e,0,0x206);
  SHGetSpecialFolderPathW((HWND)0x0,&local_210,5,1);
  pWVar2 = &local_210;
  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x144) = 0x104;
  do {
    WVar1 = *pWVar2;
    pWVar2 = pWVar2 + 1;
  } while (WVar1 != L'\0');
  FUN_00402160(&local_210,(int)pWVar2 - (int)local_20e >> 1);
  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x100) + 0xd0) + 0xd8) = 0x1a;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

