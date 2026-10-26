
undefined4 FUN_00740070(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  int unaff_ESI;
  byte *unaff_EDI;
  bool in_ZF;
  
  *(byte **)(unaff_EBP + -4) = unaff_EDI;
  if (in_ZF) {
    iVar1 = *(int *)(unaff_ESI + 8);
    *(undefined4 *)(unaff_EBP + 8) = 0;
    if (0 < iVar1) {
      iVar1 = *(int *)(unaff_ESI + 0xc);
      while( true ) {
        iVar2 = 0;
        if (0 < iVar1) {
          do {
            iVar1 = *(int *)(&DAT_00c460a0 + (uint)*unaff_EDI * 4);
            if (0xff < iVar1) {
              iVar1 = 0xff;
            }
            *unaff_EDI = (byte)iVar1;
            iVar1 = *(int *)(unaff_ESI + 0xc);
            iVar2 = iVar2 + 1;
            unaff_EDI = unaff_EDI + 1;
          } while (iVar2 < iVar1);
        }
        *(int *)(unaff_EBP + -4) = *(int *)(unaff_EBP + -4) + *(int *)(unaff_ESI + 0x10);
        iVar2 = *(int *)(unaff_EBP + 8) + 1;
        *(int *)(unaff_EBP + 8) = iVar2;
        if (*(int *)(unaff_ESI + 8) <= iVar2) break;
        unaff_EDI = *(byte **)(unaff_EBP + -4);
      }
    }
  }
  else {
    iVar1 = *(int *)(unaff_ESI + 8);
    *(undefined4 *)(unaff_EBP + -0xc) = 0;
    if (0 < iVar1) {
      iVar1 = *(int *)(unaff_ESI + 0xc);
      do {
        iVar2 = 0;
        if (0 < iVar1) {
          do {
            iVar1 = FUN_0073fcb0();
            if (0xff < iVar1) {
              iVar1 = 0xff;
            }
            *unaff_EDI = (byte)iVar1;
            iVar1 = *(int *)(unaff_ESI + 0xc);
            iVar2 = iVar2 + 1;
            unaff_EDI = unaff_EDI + 1;
          } while (iVar2 < iVar1);
          unaff_EDI = *(byte **)(unaff_EBP + -4);
        }
        unaff_EDI = unaff_EDI + *(int *)(unaff_ESI + 0x10);
        iVar2 = *(int *)(unaff_EBP + -0xc) + 1;
        *(byte **)(unaff_EBP + -4) = unaff_EDI;
        *(int *)(unaff_EBP + -0xc) = iVar2;
      } while (iVar2 < *(int *)(unaff_ESI + 8));
    }
  }
  FUN_0073ff40(*(undefined4 *)(unaff_EBP + -8),unaff_ESI);
  **(int **)(unaff_EBP + 0xc) = unaff_ESI;
  return 0;
}

