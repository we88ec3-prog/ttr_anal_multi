
undefined1 * FUN_0081e440(undefined1 *param_1)

{
  undefined1 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091425b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[4] = in_ECX[4];
  *(undefined4 *)(param_1 + 0x1c) = 7;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  FUN_004026e0(in_ECX + 8,0,0xffffffff);
  local_8 = 0;
  FUN_0081e220(param_1 + 0x24,in_ECX + 0x24);
  ExceptionList = local_10;
  return param_1;
}

