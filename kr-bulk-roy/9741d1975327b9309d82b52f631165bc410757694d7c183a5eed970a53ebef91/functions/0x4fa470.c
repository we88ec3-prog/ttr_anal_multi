
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fa470(void)

{
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0091309b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 3;
  if (DAT_00fe1a6c != 0) {
    FUN_004fb7d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fe1a6c = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1a70);
  if (7 < DAT_00fe1a64) {
    FUN_0089120c(DAT_00fe1a50);
  }
  DAT_00fe1a64 = 7;
  _DAT_00fe1a60 = 0;
  DAT_00fe1a50 = DAT_00fe1a50 & 0xffff0000;
  local_8 = local_8 & 0xffffff00;
  _eh_vector_destructor_iterator_(&DAT_00fe1910,0x20,10,FUN_004fa440);
  local_8 = 4;
  FUN_004fad20(*DAT_00fe1904,DAT_00fe1904);
  FUN_0089120c(DAT_00fe1904);
  ExceptionList = local_10;
  return;
}

