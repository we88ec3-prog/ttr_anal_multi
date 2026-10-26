
/* WARNING: Removing unreachable block (ram,0x005aad6f) */

void FUN_005aaca0(void)

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
  FUN_005aaf40();
  FUN_005a9f40(in_ECX + 0x164);
  FUN_005ab020();
  FUN_005a9f40(in_ECX + 0x168);
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x164) + 0x16c))(0);
  (**(code **)(**(int **)(in_ECX + 0x164) + 0xd0))();
  FUN_00596d70(in_ECX,*(undefined4 *)(in_ECX + 0x168),1,0,0,0,0);
  ExceptionList = local_10;
  return;
}

