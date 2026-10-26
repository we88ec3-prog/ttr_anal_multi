
/* WARNING: Removing unreachable block (ram,0x006a4c55) */

void FUN_006a4af0(void)

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
  FUN_006a5260(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0xfc);
  FUN_006a5340();
  FUN_005a9f40(in_ECX + 0x108);
  FUN_006a5420();
  FUN_005a9f40(in_ECX + 0x100);
  FUN_006a5500();
  FUN_005a9f40(in_ECX + 0x104);
  FUN_0040b670(in_ECX);
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,0,*(undefined4 *)(in_ECX + 0xfc));
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,1,*(undefined4 *)(in_ECX + 0x108));
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,2,*(undefined4 *)(in_ECX + 0x100));
  }
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,3,*(undefined4 *)(in_ECX + 0x104));
  }
  FUN_00749920(*(undefined4 *)(in_ECX + 0xf8));
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  FUN_0040b5b0(0);
  FUN_00823850();
  ExceptionList = local_10;
  return;
}

