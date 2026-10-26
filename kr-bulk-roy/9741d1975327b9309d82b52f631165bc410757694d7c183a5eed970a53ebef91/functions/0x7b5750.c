
void FUN_007b5750(void)

{
  LPCRITICAL_SECTION unaff_EDI;
  
  FUN_006df330();
  FUN_0089120c(unaff_EDI[1].DebugInfo);
  unaff_EDI[1].DebugInfo = (PRTL_CRITICAL_SECTION_DEBUG)0x0;
  DeleteCriticalSection(unaff_EDI);
  return;
}

