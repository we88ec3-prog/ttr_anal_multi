
undefined1 * FUN_00529b90(undefined1 *param_1)

{
  undefined1 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d11b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[1] = in_ECX[1];
  *(undefined4 *)(param_1 + 0x18) = 7;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  FUN_004026e0(in_ECX + 4,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x34) = 7;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined2 *)(param_1 + 0x20) = 0;
  FUN_004026e0(in_ECX + 0x20,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

