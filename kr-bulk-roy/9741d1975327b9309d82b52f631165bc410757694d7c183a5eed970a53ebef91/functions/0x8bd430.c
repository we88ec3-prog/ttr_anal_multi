
void FUN_008bd430(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  char local_88;
  byte local_87;
  char acStack_86 [61];
  char local_49;
  char local_3e;
  char local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (in_ECX == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  iVar1 = FUN_008b97e0();
  if ((((((iVar1 == 0) && (iVar1 = FUN_008bab70(), iVar1 == 0)) && (local_88 == '\0')) &&
       ((local_3e == '\0' && (local_36 == '\0')))) &&
      ((local_87 != 0 && ((local_87 < 0x22 && (local_49 == '\0')))))) &&
     (acStack_86[local_87] == '\0')) {
    FUN_008bd330((CONCAT31(CONCAT21(CONCAT11(local_35,local_34),local_33),local_32) + 0x7fU &
                 0xffffff80) + 0x80,param_1);
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

