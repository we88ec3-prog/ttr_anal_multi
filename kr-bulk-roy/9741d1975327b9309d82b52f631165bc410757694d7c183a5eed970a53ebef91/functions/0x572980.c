
void FUN_00572980(int param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091b1bb;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  iVar1 = *(int *)(param_1 + 4);
  FUN_00504180(*(undefined4 *)(*(int *)(iVar1 + 4) + 4));
  *(int *)(*(int *)(iVar1 + 4) + 4) = *(int *)(iVar1 + 4);
  *(undefined4 *)*(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 4);
  *(int *)(*(int *)(iVar1 + 4) + 8) = *(int *)(iVar1 + 4);
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    local_8._0_1_ = 1;
    FUN_004f7fe0(**(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 4));
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0089120c(*(undefined4 *)(iVar1 + 4),uVar2);
    FUN_0089120c(iVar1);
  }
  iVar1 = *(int *)(param_1 + 0x18);
  FUN_005741d0(*(undefined4 *)(*(int *)(iVar1 + 4) + 4));
  *(int *)(*(int *)(iVar1 + 4) + 4) = *(int *)(iVar1 + 4);
  *(undefined4 *)*(undefined4 *)(iVar1 + 4) = *(undefined4 *)(iVar1 + 4);
  *(int *)(*(int *)(iVar1 + 4) + 8) = *(int *)(iVar1 + 4);
  *(undefined4 *)(iVar1 + 8) = 0;
  iVar1 = *(int *)(param_1 + 0x18);
  if (iVar1 != 0) {
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00574490(**(undefined4 **)(iVar1 + 4),*(undefined4 **)(iVar1 + 4));
    FUN_0089120c(*(undefined4 *)(iVar1 + 4),uVar2);
    FUN_0089120c(iVar1);
  }
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00440a80();
    FUN_0089120c(*(undefined4 *)(param_1 + 8));
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  ExceptionList = local_10;
  return;
}

