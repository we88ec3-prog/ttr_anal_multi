
void FUN_008040a0(undefined4 param_1,int param_2)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = param_2;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EDI + 0x124));
  FUN_00804260(&param_1);
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EDI + 0x124));
  if (iVar1 == 2) {
    SetEvent(*(HANDLE *)(unaff_EDI + 0x120));
  }
  return;
}

