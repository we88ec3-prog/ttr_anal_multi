
void FUN_006f8a40(void)

{
  int *piVar1;
  int unaff_EDI;
  undefined1 local_44 [60];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar1 = *(int **)(*(int *)(unaff_EDI + 0x14) + 4);
  if ((piVar1[2] == 6) && (*(char *)(*piVar1 + 6) == '\0')) {
    FUN_006f7d80();
    FUN_006f7c50(local_44);
    FUN_006f7c30();
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

