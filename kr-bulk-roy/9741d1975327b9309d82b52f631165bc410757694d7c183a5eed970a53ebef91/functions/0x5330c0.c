
undefined2 * FUN_005330c0(undefined2 *param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00912d88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_004026e0(in_ECX,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0xe) = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(in_ECX + 0x24);
  *(undefined4 *)(param_1 + 0x1e) = 7;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  param_1[0x14] = 0;
  FUN_004026e0(in_ECX + 0x28,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

