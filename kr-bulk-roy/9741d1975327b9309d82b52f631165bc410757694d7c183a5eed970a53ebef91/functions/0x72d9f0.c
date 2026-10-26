
undefined4 * FUN_0072d9f0(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00911f2e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  *param_1 = TiXmlAttribute::vftable;
  param_1[10] = 0xf;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[0x11] = 0xf;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  local_8 = 2;
  FUN_00403040(param_2,0,0xffffffff);
  FUN_00403040(param_3,0,0xffffffff);
  param_1[4] = 0;
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  ExceptionList = local_10;
  return param_1;
}

