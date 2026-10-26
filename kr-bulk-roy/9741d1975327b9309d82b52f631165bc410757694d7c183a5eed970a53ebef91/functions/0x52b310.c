
undefined4 * FUN_0052b310(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009101d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[6] = 7;
  param_1[5] = 0;
  *(undefined2 *)(param_1 + 1) = 0;
  FUN_004026e0(in_ECX + 1,0,0xffffffff);
  local_8 = 0;
  param_1[0xd] = 7;
  param_1[0xc] = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  FUN_004026e0(in_ECX + 8,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0052b3b0(param_1 + 0xf,in_ECX + 0xf);
  ExceptionList = local_10;
  return param_1;
}

