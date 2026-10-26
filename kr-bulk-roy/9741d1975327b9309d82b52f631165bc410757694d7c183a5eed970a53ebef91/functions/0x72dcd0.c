
undefined4 * FUN_0072dcd0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919668;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  param_1[0xd] = 0xf;
  param_1[0xc] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[4] = 0;
  param_1[5] = 4;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  local_8 = 0;
  *param_1 = TiXmlText::vftable;
  FUN_00402a70(&DAT_00bf2375,0);
  *(undefined1 *)(param_1 + 0x11) = 0;
  ExceptionList = local_10;
  return param_1;
}

