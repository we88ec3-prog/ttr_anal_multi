
int FUN_00837000(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909238;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  uVar1 = FUN_007b2620();
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)uVar1 = uVar1;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x38) = 1;
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x39) = 1;
  local_8 = 1;
  FUN_008370b0(param_2);
  ExceptionList = local_10;
  return param_1;
}

