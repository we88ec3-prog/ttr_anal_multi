
undefined4 * FUN_00510350(undefined4 *param_1,undefined4 *param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910488;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  param_1[6] = 7;
  param_1[5] = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  FUN_004026e0(param_2 + 1,0,0xffffffff);
  local_8 = 0;
  *(undefined1 *)(param_1 + 8) = *(undefined1 *)(param_2 + 8);
  FUN_0050e250(param_1 + 9,param_2 + 9);
  ExceptionList = local_10;
  return param_1;
}

