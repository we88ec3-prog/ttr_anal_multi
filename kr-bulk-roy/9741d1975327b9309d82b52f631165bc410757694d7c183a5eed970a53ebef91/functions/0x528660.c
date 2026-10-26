
undefined4 * FUN_00528660(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091e05e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[6] = 7;
  param_1[5] = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  FUN_004026e0(in_ECX + 1,0,0xffffffff);
  local_8 = 0;
  param_1[8] = in_ECX[8];
  param_1[9] = in_ECX[9];
  param_1[0xf] = 7;
  param_1[0xe] = 0;
  *(undefined2 *)(param_1 + 10) = 0;
  FUN_004026e0(in_ECX + 10,0,0xffffffff);
  local_8._0_1_ = 1;
  FUN_00527300(param_1 + 0x11,in_ECX + 0x11);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00527570(param_1 + 0x14,in_ECX + 0x14);
  ExceptionList = local_10;
  return param_1;
}

