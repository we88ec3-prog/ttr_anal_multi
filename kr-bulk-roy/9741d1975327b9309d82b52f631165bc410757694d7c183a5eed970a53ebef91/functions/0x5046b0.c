
void FUN_005046b0(int param_1)

{
  uint uVar1;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009173b2;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00505990(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  local_8 = 1;
  FUN_005059e0(local_14,**(undefined4 **)(param_1 + 4),*(undefined4 **)(param_1 + 4));
  FUN_0089120c(*(undefined4 *)(param_1 + 4),uVar1);
  ExceptionList = local_10;
  return;
}

