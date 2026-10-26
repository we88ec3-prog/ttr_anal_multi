
void FUN_00807790(void)

{
  LPCRITICAL_SECTION lpCriticalSection;
  undefined4 *unaff_EDI;
  
  lpCriticalSection = (LPCRITICAL_SECTION)*unaff_EDI;
  if (lpCriticalSection != (LPCRITICAL_SECTION)0x0) {
    DeleteCriticalSection(lpCriticalSection);
    FUN_0089120c(lpCriticalSection);
    *unaff_EDI = 0;
  }
  return;
}

