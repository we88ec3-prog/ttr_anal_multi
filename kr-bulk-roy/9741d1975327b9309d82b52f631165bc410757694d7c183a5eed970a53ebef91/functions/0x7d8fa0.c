
undefined4 * FUN_007d8fa0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091175b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  FUN_00403040(in_ECX + 1,0,0xffffffff);
  local_8 = 0;
  param_1[0xd] = 0xf;
  param_1[0xc] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  FUN_00403040(in_ECX + 8,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

