
undefined4 * FUN_005064d0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d583;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *in_ECX;
  param_1[1] = in_ECX[1];
  param_1[2] = in_ECX[2];
  param_1[3] = in_ECX[3];
  FUN_007e8a90(param_1 + 4,in_ECX + 4);
  local_8 = 0;
  param_1[8] = in_ECX[8];
  param_1[9] = in_ECX[9];
  param_1[10] = in_ECX[10];
  param_1[0xb] = in_ECX[0xb];
  param_1[0xc] = in_ECX[0xc];
  param_1[0xd] = in_ECX[0xd];
  param_1[0xe] = in_ECX[0xe];
  param_1[0xf] = in_ECX[0xf];
  param_1[0x10] = in_ECX[0x10];
  param_1[0x11] = in_ECX[0x11];
  param_1[0x12] = in_ECX[0x12];
  param_1[0x17] = 0;
  param_1[0x18] = 7;
  *(undefined2 *)(param_1 + 0x13) = 0;
  FUN_004026e0(in_ECX + 0x13,0,0xffffffff);
  local_8._0_1_ = 1;
  FUN_005ca290(param_1 + 0x1a,in_ECX + 0x1a);
  local_8 = CONCAT31(local_8._1_3_,2);
  param_1[0x1e] = in_ECX[0x1e];
  param_1[0x1f] = in_ECX[0x1f];
  param_1[0x20] = in_ECX[0x20];
  param_1[0x21] = in_ECX[0x21];
  param_1[0x22] = in_ECX[0x22];
  param_1[0x23] = in_ECX[0x23];
  param_1[0x24] = in_ECX[0x24];
  FUN_00506610(param_1 + 0x25,in_ECX + 0x25);
  ExceptionList = local_10;
  return param_1;
}

