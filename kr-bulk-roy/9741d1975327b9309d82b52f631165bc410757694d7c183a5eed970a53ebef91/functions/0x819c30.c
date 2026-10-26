
int FUN_00819c30(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00907338;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  uVar1 = FUN_00820120();
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x18) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x19) = 1;
  local_8 = 1;
  FUN_00819ce0(param_2);
  ExceptionList = local_10;
  return param_1;
}

