
undefined1 * FUN_0081e4d0(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d6fb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *param_2;
  param_1[4] = *in_ECX;
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(param_1 + 0x20) = 7;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  FUN_004026e0(in_ECX + 8,0,0xffffffff);
  local_8 = 0;
  FUN_004fcd00(param_1 + 0x28,in_ECX + 0x24);
  ExceptionList = local_10;
  return param_1;
}

