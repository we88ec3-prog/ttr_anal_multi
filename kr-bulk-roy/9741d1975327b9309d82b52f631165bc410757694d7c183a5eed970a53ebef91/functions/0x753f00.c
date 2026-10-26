
undefined4 * FUN_00753f00(undefined4 *param_1,undefined4 param_2)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911d53;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[1] = 0xffffffff;
  param_1[2] = 0xffffffff;
  param_1[3] = 0;
  param_1[4] = 0xf4242;
  param_1[5] = in_ECX;
  *param_1 = FoxUI::FXUIEventI1S1::vftable;
  param_1[0xb] = 7;
  param_1[10] = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  local_8 = 1;
  FUN_004026e0(param_2,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

