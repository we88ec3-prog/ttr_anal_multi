
void * FUN_0062e1d0(void *param_1)

{
  void *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090cce6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  _eh_vector_copy_constructor_iterator_(param_1,in_ECX,0x10,3,FUN_0062d9b0,FUN_00418290);
  FUN_0062d9b0((int)in_ECX + 0x30);
  local_8 = 0;
  *(undefined4 *)((int)param_1 + 0x54) = 7;
  *(undefined4 *)((int)param_1 + 0x50) = 0;
  *(undefined2 *)((int)param_1 + 0x40) = 0;
  FUN_004026e0((int)in_ECX + 0x40,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined4 *)((int)param_1 + 0x70) = 7;
  *(undefined4 *)((int)param_1 + 0x6c) = 0;
  *(undefined2 *)((int)param_1 + 0x5c) = 0;
  FUN_004026e0((int)in_ECX + 0x5c,0,0xffffffff);
  ExceptionList = local_10;
  return param_1;
}

