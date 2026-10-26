
undefined4 * FUN_0046c600(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917a18;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007564e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 1;
  local_8 = 0;
  *param_1 = FUI::COnScreenKeyBoardDialog::vftable;
  _memset(param_1 + 0x3d,0,0xc4);
  param_1[0x6e] = 0;
  param_1[0x6f] = 0;
  param_1[0x70] = 0;
  param_1[0x71] = 0;
  param_1[0x72] = 0;
  param_1[0x73] = 0;
  param_1[0x74] = 0;
  _eh_vector_constructor_iterator_
            (param_1 + 0x76,0x10,0x31,(_func_void_void_ptr *)&LAB_00755c40,FUN_005f5d10);
  _memset(param_1 + 0x13a,0,0xc4);
  param_1[0x16b] = 0;
  ExceptionList = local_10;
  return param_1;
}

