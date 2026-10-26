
void FUN_006f08f0(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = CLogBackend_Type2::vftable;
  FUN_006f0600();
  if (0xf < (uint)unaff_ESI[0x22]) {
    FUN_0089120c(unaff_ESI[0x1d]);
  }
  unaff_ESI[0x22] = 0xf;
  unaff_ESI[0x21] = 0;
  *(undefined1 *)(unaff_ESI + 0x1d) = 0;
  piVar1 = (int *)unaff_ESI[0x16];
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(undefined4 *)(unaff_ESI[0x16] + 4) = unaff_ESI[0x16];
  unaff_ESI[0x17] = 0;
  if (piVar2 != (int *)unaff_ESI[0x16]) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)unaff_ESI[0x16]);
  }
  FUN_0089120c(unaff_ESI[0x16]);
  piVar1 = (int *)unaff_ESI[0x13];
  piVar2 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(undefined4 *)(unaff_ESI[0x13] + 4) = unaff_ESI[0x13];
  unaff_ESI[0x14] = 0;
  if (piVar2 != (int *)unaff_ESI[0x13]) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != (int *)unaff_ESI[0x13]);
  }
  FUN_0089120c(unaff_ESI[0x13]);
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 0xd));
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 7));
  DeleteCriticalSection((LPCRITICAL_SECTION)(unaff_ESI + 1));
  *unaff_ESI = CLogBackend::vftable;
  return;
}

