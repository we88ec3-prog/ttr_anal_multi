
undefined4 * FUN_004cfd10(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009132f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ca730(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  *param_1 = CDropItem::vftable;
  param_1[0x3c] = 0;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  *(undefined1 *)(param_1 + 0x41) = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0x3f800000;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x48] = 0xff6600;
  param_1[0x4e] = 7;
  param_1[0x4d] = 0;
  *(undefined2 *)(param_1 + 0x49) = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  ExceptionList = local_10;
  return param_1;
}

