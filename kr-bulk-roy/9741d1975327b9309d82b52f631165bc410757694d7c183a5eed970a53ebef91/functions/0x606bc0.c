
undefined4 * FUN_00606bc0(undefined4 *param_1)

{
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920f24;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  local_8 = 0;
  *param_1 = FUI::CItemMakingRecipeDlg::vftable;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x50] = 7;
  param_1[0x4f] = 0;
  *(undefined2 *)(param_1 + 0x4b) = 0;
  FUN_00402160(&DAT_00bed1fc,0);
  *(undefined1 *)(param_1 + 0x52) = 0;
  param_1[0x53] = 0;
  param_1[0x54] = 0;
  param_1[0x55] = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_004d7fe0(param_1 + 0x53,local_14,0,0);
  ExceptionList = local_10;
  return param_1;
}

