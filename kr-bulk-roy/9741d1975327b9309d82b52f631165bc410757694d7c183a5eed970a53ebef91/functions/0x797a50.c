
undefined4 * FUN_00797a50(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009152bb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  FUN_007cd2b0(uVar1);
  local_8 = 0;
  FUN_007cd2b0();
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2f] = 0x3faaaaab;
  param_1[0x34] = 0;
  param_1[0x2c] = 1;
  param_1[0x36] = 0;
  param_1[0x32] = 1;
  param_1[0x30] = 0;
  param_1[0x35] = param_1[9];
  param_1[0x31] = 0;
  param_1[0x33] = 0;
  param_1[0x2d] = 0x400;
  param_1[0x2e] = 0x300;
  ExceptionList = local_10;
  return param_1;
}

