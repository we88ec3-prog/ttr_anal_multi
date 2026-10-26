
void FUN_00778380(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c7ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  in_ECX[1] = DAT_00fba828;
  in_ECX[2] = 0;
  local_8 = 0;
  *in_ECX = FoxUI::FXUIBackground9::vftable;
  _eh_vector_constructor_iterator_
            (in_ECX + 3,0x40,9,(_func_void_void_ptr *)&LAB_007766a0,FUN_00776700);
  local_8 = CONCAT31(local_8._1_3_,1);
  _eh_vector_constructor_iterator_
            (in_ECX + 0x93,0x10,9,(_func_void_void_ptr *)&LAB_00755c40,FUN_005f5d10);
  in_ECX[0xb7] = 10;
  in_ECX[0xb9] = 10;
  in_ECX[0xb8] = 10;
  in_ECX[0xba] = 10;
  in_ECX[0xbc] = 0;
  *(undefined1 *)(in_ECX + 0xbb) = 0;
  ExceptionList = local_10;
  return;
}

