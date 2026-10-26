
void FUN_00bcdef0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a08367;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0055bb50(&DAT_00fcde48);
  local_8 = 0xffffffff;
  _eh_vector_destructor_iterator_(&DAT_00fcde48,0x4c,0x104,FUN_0055b800);
  ExceptionList = local_10;
  return;
}

