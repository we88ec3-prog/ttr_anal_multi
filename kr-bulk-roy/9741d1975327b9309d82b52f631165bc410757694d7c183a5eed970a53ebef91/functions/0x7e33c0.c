
void FUN_007e33c0(void)

{
  char *_FullPath;
  int iVar1;
  char *unaff_EDI;
  char local_18 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _FullPath = unaff_EDI;
  if (0xf < *(uint *)(unaff_EDI + 0x14)) {
    _FullPath = *(char **)unaff_EDI;
  }
  __splitpath(_FullPath,(char *)0x0,(char *)0x0,(char *)0x0,local_18);
  iVar1 = __stricmp(local_18,".gb3");
  if ((iVar1 == 0) || (iVar1 = __stricmp(local_18,".3do"), iVar1 == 0)) {
    FUN_007e3790(unaff_EDI);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar1 = __stricmp(local_18,".ptc");
  if (iVar1 == 0) {
    if (0xf < *(uint *)(unaff_EDI + 0x14)) {
      FUN_007e3790(unaff_EDI);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    FUN_007e3790(unaff_EDI);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar1 = __stricmp(local_18,".mo3");
  if (iVar1 != 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (0xf < *(uint *)(unaff_EDI + 0x14)) {
    FUN_007e3660(unaff_EDI,*(undefined4 *)unaff_EDI);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_007e3660(unaff_EDI,unaff_EDI);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

