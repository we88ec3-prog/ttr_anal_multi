
undefined4 * FUN_0067dd40(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919e46;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  *param_1 = FUI::CShopStoneEnchantWnd::vftable;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0xffffffff;
  param_1[0x47] = 0xffffffff;
  param_1[0x48] = 0xffffffff;
  param_1[0x49] = 0xffffffff;
  param_1[0x4a] = 0;
  param_1[0x4b] = 0;
  param_1[0x51] = 7;
  param_1[0x50] = 0;
  *(undefined2 *)(param_1 + 0x4c) = 0;
  param_1[0x53] = 0xffffffff;
  param_1[0x54] = 0xffffffff;
  param_1[0x56] = 0;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  param_1[0x59] = 0;
  param_1[0x5a] = 0xffffffff;
  local_8 = 1;
  _eh_vector_constructor_iterator_(param_1 + 0x5c,0x58,3,FUN_0067dd00,FUN_0067dea0);
  param_1[0x9e] = 0;
  param_1[0x9f] = 0;
  ExceptionList = local_10;
  return param_1;
}

