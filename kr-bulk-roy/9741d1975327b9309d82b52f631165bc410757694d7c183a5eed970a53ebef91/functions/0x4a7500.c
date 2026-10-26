
/* WARNING: Removing unreachable block (ram,0x004a7578) */

void FUN_004a7500(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009211e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004a75a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(param_1);
  FUN_0040b670(0);
  ExceptionList = local_10;
  return;
}

