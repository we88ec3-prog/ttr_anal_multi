
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_004fa330(void)

{
  BOOL BVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910715;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004fad80();
  local_8 = 0;
  _eh_vector_constructor_iterator_
            (&DAT_00fe1910,0x20,10,(_func_void_void_ptr *)&LAB_004fa310,FUN_004fa440);
  DAT_00fe1a64 = 7;
  _DAT_00fe1a60 = 0;
  DAT_00fe1a50._0_2_ = 0;
  DAT_00fe1a6c = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)&DAT_00fe1a70,4000);
  BVar1 = PathIsDirectoryW(L"./Rank");
  if (BVar1 == 0) {
    CreateDirectoryW(L"./Rank",(LPSECURITY_ATTRIBUTES)0x0);
  }
  ExceptionList = local_10;
  return &DAT_00fe1900;
}

