
void FUN_006f10e0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = CLogBackend_Type1::vftable;
  EnterCriticalSection((LPCRITICAL_SECTION)unaff_ESI[0x4e]);
  if ((FILE *)unaff_ESI[0x49] != (FILE *)0x0) {
    _fclose((FILE *)unaff_ESI[0x49]);
  }
  unaff_ESI[0x49] = 0;
  LeaveCriticalSection((LPCRITICAL_SECTION)unaff_ESI[0x4e]);
  if (0xf < (uint)unaff_ESI[6]) {
    FUN_0089120c(unaff_ESI[1]);
  }
  unaff_ESI[6] = 0xf;
  unaff_ESI[5] = 0;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  *unaff_ESI = CLogBackend::vftable;
  return;
}

