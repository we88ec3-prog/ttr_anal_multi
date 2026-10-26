
void FUN_004d3d00(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090d8ad;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0xd] = 100;
  in_ECX[0xe] = 100;
  in_ECX[0xf] = 100;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  *in_ECX = CCharStatus::vftable;
  in_ECX[0x17] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  *(undefined1 *)(in_ECX + 0x36) = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  *(undefined2 *)(in_ECX + 0x3a) = 0;
  in_ECX[0x3b] = 0;
  *(undefined2 *)(in_ECX + 0x3d) = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x43] = 0;
  local_8 = 1;
  uStack_7 = 0;
  _eh_vector_constructor_iterator_
            (in_ECX + 0x44,0x1c,7,(_func_void_void_ptr *)&LAB_0041d760,FUN_00418290);
  local_8 = 2;
  FUN_00825dd0(in_ECX + 0x75);
  _local_8 = CONCAT31(uStack_7,3);
  FUN_0081a780(in_ECX + 0x7d);
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  ExceptionList = local_10;
  return;
}

