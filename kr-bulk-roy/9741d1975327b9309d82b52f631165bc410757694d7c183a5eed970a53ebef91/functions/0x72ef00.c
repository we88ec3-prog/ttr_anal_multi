
undefined4 * FUN_0072ef00(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009195e3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0xf;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *param_1 = TiXmlDocument::vftable;
  param_1[0x18] = 0xf;
  param_1[0x17] = 0;
  *(undefined1 *)(param_1 + 0x13) = 0;
  local_8 = 1;
  param_1[0x1c] = 0xffffffff;
  param_1[0x1b] = 0xffffffff;
  param_1[0x1a] = 4;
  *(undefined1 *)(param_1 + 0x1d) = 0;
  FUN_00403040(param_2,0,0xffffffff);
  *(undefined1 *)(param_1 + 0x11) = 0;
  param_1[0x12] = 0;
  FUN_00402a70(&DAT_00bf2375,0);
  param_1[0x1c] = 0;
  param_1[0x1b] = 0;
  ExceptionList = local_10;
  return param_1;
}

