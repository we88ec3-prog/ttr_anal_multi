
void FUN_00471680(void)

{
  int *piVar1;
  LPCWSTR ***lpText;
  int iVar2;
  int in_ECX;
  int *unaff_EDI;
  undefined4 local_2c;
  int local_28;
  LPCWSTR **local_24 [5];
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_2c = 0;
  FUN_0082ef00(&local_2c);
  if (((local_28 == *(int *)(in_ECX + 0x50)) ||
      (piVar1 = *(int **)(local_28 + 0x10), piVar1 == (int *)0x0)) ||
     (iVar2 = (**(code **)(*piVar1 + 4))(), iVar2 != 0x4b2)) {
    FUN_00404a80();
    lpText = (LPCWSTR ***)local_24[0];
    if (local_10 < 8) {
      lpText = local_24;
    }
    MessageBoxW((HWND)0x0,(LPCWSTR)lpText,L"Error",0);
    if (7 < local_10) {
      FUN_0089120c(local_24[0]);
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  else {
    *unaff_EDI = (int)piVar1;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

