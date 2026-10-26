
void FUN_007dcee0(void)

{
  char cVar1;
  int iVar2;
  int *unaff_ESI;
  char *unaff_EDI;
  
  DAT_00fba844 = DAT_00fba844 + 1;
  *unaff_ESI = DAT_00fba844;
  unaff_ESI[0x11] = 0;
  unaff_ESI[0x13] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x17] = 1;
  unaff_ESI[0x18] = 0;
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(unaff_ESI + 0x19),4000);
  unaff_ESI[0x1f] = 0;
  unaff_ESI[0x20] = 0;
  unaff_ESI[0x21] = 0;
  iVar2 = 4 - (int)unaff_EDI;
  do {
    cVar1 = *unaff_EDI;
    unaff_EDI[(int)unaff_ESI + iVar2] = cVar1;
    unaff_EDI = unaff_EDI + 1;
  } while (cVar1 != '\0');
  return;
}

