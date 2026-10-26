
undefined2 * FUN_008294f0(undefined2 *param_1)

{
  undefined2 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090bfb1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  *(undefined4 *)(param_1 + 0xc) = 7;
  *(undefined4 *)(param_1 + 10) = 0;
  param_1[2] = 0;
  FUN_004026e0(in_ECX + 2,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1a) = 7;
  *(undefined4 *)(param_1 + 0x18) = 0;
  param_1[0x10] = 0;
  FUN_004026e0(in_ECX + 0x10,0,0xffffffff);
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x28) = 7;
  *(undefined4 *)(param_1 + 0x26) = 0;
  param_1[0x1e] = 0;
  FUN_004026e0(in_ECX + 0x1e,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  *(undefined4 *)(param_1 + 0x2e) = *(undefined4 *)(in_ECX + 0x2e);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(in_ECX + 0x30);
  *(undefined4 *)(param_1 + 0x32) = *(undefined4 *)(in_ECX + 0x32);
  *(undefined1 *)(param_1 + 0x34) = *(undefined1 *)(in_ECX + 0x34);
  *(undefined4 *)(param_1 + 0x36) = *(undefined4 *)(in_ECX + 0x36);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(in_ECX + 0x38);
  FUN_004fcd00(param_1 + 0x3a,in_ECX + 0x3a);
  ExceptionList = local_10;
  return param_1;
}

