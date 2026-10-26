
void FUN_0080cd50(void)

{
  LPCRITICAL_SECTION unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009051b8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  EnterCriticalSection(unaff_EDI);
  local_8 = 0;
  FUN_0080cdb0(&stack0x00000004);
  LeaveCriticalSection(unaff_EDI);
  ExceptionList = local_10;
  return;
}

