
void FUN_008076f0(undefined4 *param_1)

{
  int unaff_EDI;
  
  *param_1 = 0;
  param_1[1] = 0;
  EnterCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EDI + 0x58));
  FUN_00804260(&param_1);
  *(int *)(unaff_EDI + 0x54) = *(int *)(unaff_EDI + 0x54) + -1;
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(unaff_EDI + 0x58));
  return;
}

