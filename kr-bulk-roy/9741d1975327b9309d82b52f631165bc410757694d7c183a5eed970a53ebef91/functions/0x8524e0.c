
undefined4 * FUN_008524e0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091137b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  param_1[1] = *in_ECX;
  FUN_0062d9b0(in_ECX + 1);
  local_8 = 0;
  FUN_006dddf0(param_1 + 6,in_ECX + 5);
  ExceptionList = local_10;
  return param_1;
}

