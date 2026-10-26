
undefined4 * FUN_0060d500(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f7a8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00754880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(undefined1 *)(param_1 + 0x56) = 1;
  local_8 = 0;
  *param_1 = FUI::CSkillSlotToolTip::vftable;
  param_1[0x57] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x58) = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0;
  param_1[0x5b] = 0;
  param_1[0x5c] = 0;
  param_1[0x5d] = 0;
  param_1[0x5e] = 0;
  param_1[0x5f] = 0;
  param_1[0x60] = 0;
  param_1[0x61] = 0;
  param_1[0x62] = 0;
  param_1[99] = 0;
  param_1[100] = 0;
  param_1[0x65] = 0;
  FUN_00830e10();
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[0x79] = 7;
  param_1[0x78] = 0;
  *(undefined2 *)(param_1 + 0x74) = 0;
  *(undefined2 *)(param_1 + 0x7b) = 0;
  ExceptionList = local_10;
  return param_1;
}

