
undefined4 * FUN_004fcc70(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d65b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[1] = in_ECX[1];
  param_1[2] = in_ECX[2];
  param_1[3] = in_ECX[3];
  param_1[9] = 7;
  param_1[8] = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  FUN_004026e0(in_ECX + 4,0,0xffffffff);
  local_8 = 0;
  FUN_004fcd00(param_1 + 0xb,in_ECX + 0xb);
  ExceptionList = local_10;
  return param_1;
}

