
undefined4 * FUN_0080e230(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = CSound::vftable;
  param_1[1] = 0;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_0040b0b0(param_2,0);
  DAT_00fba864 = DAT_00fba864 + 1;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[1] = param_1[1] + 1;
  ExceptionList = local_10;
  return param_1;
}

