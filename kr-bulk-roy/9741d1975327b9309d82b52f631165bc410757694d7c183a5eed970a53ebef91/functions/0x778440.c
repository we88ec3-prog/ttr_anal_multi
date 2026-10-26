
undefined4 * FUN_00778440(undefined4 *param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c7ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  param_1[1] = DAT_00fba828;
  param_1[2] = param_2;
  local_8 = 0;
  *param_1 = FoxUI::FXUIBackground9::vftable;
  _eh_vector_constructor_iterator_
            (param_1 + 3,0x40,9,(_func_void_void_ptr *)&LAB_007766a0,FUN_00776700);
  local_8 = CONCAT31(local_8._1_3_,1);
  _eh_vector_constructor_iterator_
            (param_1 + 0x93,0x10,9,(_func_void_void_ptr *)&LAB_00755c40,FUN_005f5d10);
  param_1[0xbc] = 0;
  param_1[0xb7] = 10;
  param_1[0xb9] = 10;
  param_1[0xb8] = 10;
  param_1[0xba] = 10;
  *(undefined1 *)(param_1 + 0xbb) = 0;
  ExceptionList = local_10;
  return param_1;
}

