
/* WARNING: Removing unreachable block (ram,0x006658c4) */

void FUN_00665800(void)

{
  int iVar1;
  int in_ECX;
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
  FUN_00665ca0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0x108);
  FUN_0040b670(in_ECX);
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf4) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,0,*(undefined4 *)(in_ECX + 0x108));
  }
  FUN_00749920(*(undefined4 *)(in_ECX + 0xf4));
  (**(code **)(**(int **)(in_ECX + 0xf4) + 200))();
  FUN_0040b5b0(0);
  ExceptionList = local_10;
  return;
}

