
void FUN_007799a0(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c76e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  in_ECX[1] = DAT_00fba828;
  in_ECX[2] = 0;
  local_8 = 0;
  *in_ECX = FoxUI::FXUIBackground3X::vftable;
  _eh_vector_constructor_iterator_
            (in_ECX + 3,0x40,3,(_func_void_void_ptr *)&LAB_007766a0,FUN_00776700);
  local_8 = CONCAT31(local_8._1_3_,1);
  _eh_vector_constructor_iterator_
            (in_ECX + 0x33,0x10,3,(_func_void_void_ptr *)&LAB_00755c40,FUN_005f5d10);
  in_ECX[0x3f] = 10;
  in_ECX[0x41] = 10;
  in_ECX[0x40] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x44] = 0;
  *(undefined1 *)(in_ECX + 0x43) = 0;
  ExceptionList = local_10;
  return;
}

