
/* WARNING: Removing unreachable block (ram,0x0059608d) */

void FUN_00596010(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009474c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_00597bc0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0xb4);
  FUN_0040b670(in_ECX);
  ExceptionList = local_10;
  return;
}

