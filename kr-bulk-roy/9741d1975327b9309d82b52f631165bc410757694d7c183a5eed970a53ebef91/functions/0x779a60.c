
undefined4 * FUN_00779a60(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c72e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  param_1[1] = DAT_00fba828;
  param_1[2] = param_2;
  local_8 = 0;
  *param_1 = FoxUI::FXUIBackground3X::vftable;
  _eh_vector_constructor_iterator_
            (param_1 + 3,0x40,3,(_func_void_void_ptr *)&LAB_007766a0,FUN_00776700);
  local_8 = CONCAT31(local_8._1_3_,1);
  _eh_vector_constructor_iterator_
            (param_1 + 0x33,0x10,3,(_func_void_void_ptr *)&LAB_00755c40,FUN_005f5d10);
  param_1[0x44] = 0;
  param_1[0x3f] = 10;
  param_1[0x41] = 10;
  param_1[0x40] = 0;
  param_1[0x42] = 0;
  *(undefined1 *)(param_1 + 0x43) = 0;
  ExceptionList = local_10;
  return param_1;
}

