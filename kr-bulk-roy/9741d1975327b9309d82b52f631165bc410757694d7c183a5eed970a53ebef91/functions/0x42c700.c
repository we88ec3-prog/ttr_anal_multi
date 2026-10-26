
void FUN_0042c700(void)

{
  int *piVar1;
  int iVar2;
  LPCWSTR **pppWVar3;
  undefined4 *unaff_EDI;
  LPCWSTR *local_24 [5];
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = (int *)FUN_00746940(4000);
  if (piVar1 == (int *)0x0) {
    FUN_00404a80();
    pppWVar3 = (LPCWSTR **)local_24[0];
    if (local_10 < 8) {
      pppWVar3 = local_24;
    }
    MessageBoxW((HWND)0x0,(LPCWSTR)pppWVar3,L"Error",0);
    if (7 < local_10) {
      FUN_0089120c(local_24[0]);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 700) {
      *unaff_EDI = piVar1;
    }
    else {
      FUN_00404a80();
      pppWVar3 = (LPCWSTR **)local_24[0];
      if (local_10 < 8) {
        pppWVar3 = local_24;
      }
      MessageBoxW((HWND)0x0,(LPCWSTR)pppWVar3,L"Error",0);
      if (7 < local_10) {
        FUN_0089120c(local_24[0]);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

