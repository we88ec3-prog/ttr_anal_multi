
/* WARNING: Removing unreachable block (ram,0x0063aba8) */

void FUN_0063aa80(void)

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
  FUN_0063b060(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0xfc);
  FUN_0063b140();
  FUN_005a9f40(in_ECX + 0x100);
  FUN_0063b220();
  FUN_005a9f40(in_ECX + 0x104);
  FUN_0040b670(in_ECX);
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,0,*(undefined4 *)(in_ECX + 0xfc));
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,1,*(undefined4 *)(in_ECX + 0x100));
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,2,*(undefined4 *)(in_ECX + 0x104));
  }
  FUN_00749920(*(undefined4 *)(in_ECX + 0xf8));
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  FUN_0040b5b0(0);
  ExceptionList = local_10;
  return;
}

