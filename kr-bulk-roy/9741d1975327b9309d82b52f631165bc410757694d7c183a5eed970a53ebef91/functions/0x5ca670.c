
undefined2 * FUN_005ca670(undefined2 *param_1,int param_2)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091a9c0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_00402800(in_ECX);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x16) = 0;
  param_1[0xe] = 0;
  FUN_004026e0(param_2,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_005ca360(param_1 + 0x1c,param_2 + 0x1c);
  ExceptionList = local_10;
  return param_1;
}

