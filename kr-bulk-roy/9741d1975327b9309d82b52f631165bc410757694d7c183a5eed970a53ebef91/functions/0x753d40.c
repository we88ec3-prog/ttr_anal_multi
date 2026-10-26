
undefined4 * FUN_00753d40(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911d83;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  param_1[4] = 0xf4418;
  *param_1 = FoxUI::FXUIEventS1::vftable;
  param_1[10] = 7;
  param_1[9] = 0;
  *(undefined2 *)(param_1 + 5) = 0;
  local_8 = 1;
  FUN_004026e0(param_2,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

