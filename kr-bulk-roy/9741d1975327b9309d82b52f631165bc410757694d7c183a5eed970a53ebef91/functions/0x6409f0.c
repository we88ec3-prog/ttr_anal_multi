
void FUN_006409f0(void)

{
  int *piVar1;
  LPCWSTR ***lpText;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 *local_28;
  LPCWSTR **local_24 [5];
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = 100;
  local_28 = (undefined4 *)(in_ECX + 0xa8);
  do {
    piVar1 = (int *)FUN_00746940(iVar3);
    if ((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 4))(), iVar2 != 700)) {
      FUN_00404a80();
      lpText = (LPCWSTR ***)local_24[0];
      if (local_10 < 8) {
        lpText = local_24;
      }
      MessageBoxW((HWND)0x0,(LPCWSTR)lpText,L"Error",0);
      if (7 < local_10) {
        FUN_0089120c(local_24[0]);
      }
    }
    else {
      *local_28 = piVar1;
    }
    local_28 = local_28 + 1;
    iVar3 = iVar3 + 100;
  } while (iVar3 < 700);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

