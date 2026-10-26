
undefined4 * FUN_0064ee40(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009163a4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00744320(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  *(undefined1 *)(param_1 + 0x29) = 0;
  *param_1 = FUI::CMiniMapChartPanelRTT::vftable;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = FoxUI::FXUIImageSetItemRef::vftable;
  param_1[0x2d] = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  _eh_vector_constructor_iterator_
            (param_1 + 0x2e,8,4,(_func_void_void_ptr *)&LAB_007765c0,FUN_00776620);
  local_8._0_1_ = 2;
  _eh_vector_constructor_iterator_
            (param_1 + 0x36,8,4,(_func_void_void_ptr *)&LAB_007765c0,FUN_00776620);
  param_1[0x3e] = FoxUI::FXUIImageSetItemRef::vftable;
  param_1[0x3f] = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  param_1[0x43] = 0;
  param_1[0x42] = 0;
  param_1[0x41] = 0;
  param_1[0x40] = 0;
  _eh_vector_constructor_iterator_
            (param_1 + 0x44,0x10,0x23,(_func_void_void_ptr *)&LAB_00755c40,FUN_005f5d10);
  _memset(param_1 + 0xd0,0,0x8c);
  _memset(param_1 + 0xf3,0,0x8c);
  param_1[0x116] = 0;
  ExceptionList = local_10;
  return param_1;
}

