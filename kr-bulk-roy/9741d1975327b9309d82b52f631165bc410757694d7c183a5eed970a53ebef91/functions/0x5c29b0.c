
/* WARNING: Removing unreachable block (ram,0x005c2a3d) */

void FUN_005c29b0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009474c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005b52c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_005adc60();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x2f8));
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x2f8) + 0xd0))();
  ExceptionList = local_10;
  return;
}

