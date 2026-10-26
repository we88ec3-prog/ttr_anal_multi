
undefined4 * FUN_0077b520(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a538;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  param_1[1] = DAT_00fba828;
  local_8 = 0;
  *param_1 = FoxUI::FXUISoundPath::vftable;
  param_1[2] = 0;
  _eh_vector_constructor_iterator_
            (param_1 + 3,0x1c,6,(_func_void_void_ptr *)&LAB_00402140,FUN_004fa440);
  param_1[0x32] = 7;
  param_1[0x31] = 0;
  *(undefined2 *)(param_1 + 0x2d) = 0;
  param_1[0x39] = 7;
  param_1[0x38] = 0;
  *(undefined2 *)(param_1 + 0x34) = 0;
  ExceptionList = local_10;
  return param_1;
}

