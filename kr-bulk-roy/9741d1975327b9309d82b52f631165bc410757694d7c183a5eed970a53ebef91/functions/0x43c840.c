
/* WARNING: Removing unreachable block (ram,0x0043c8c2) */

void FUN_0043c840(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009474c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005aa040(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_0043c9e0();
  FUN_005a9f40(in_ECX + 0x164);
  FUN_0040b670(in_ECX);
  ExceptionList = local_10;
  return;
}

