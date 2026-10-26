
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00803ff0(void)

{
  uint uVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009052d3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  _eh_vector_constructor_iterator_(&DAT_00fc10d0,0x18,0xc,FUN_004d7f50,FUN_004d7fc0);
  local_8 = 0;
  lpCriticalSection = (LPCRITICAL_SECTION)FUN_00891268(0x18,uVar1);
  if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
    lpCriticalSection = (LPCRITICAL_SECTION)0x0;
  }
  else {
    InitializeCriticalSectionAndSpinCount(lpCriticalSection,4000);
  }
  DAT_00fc11f4 = lpCriticalSection;
  DAT_00fc11f0 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,(LPCSTR)0x0);
  _DAT_00fc11f8 = 0;
  _DAT_00fc11fc = 0;
  ExceptionList = local_10;
  return &DAT_00fc10d0;
}

