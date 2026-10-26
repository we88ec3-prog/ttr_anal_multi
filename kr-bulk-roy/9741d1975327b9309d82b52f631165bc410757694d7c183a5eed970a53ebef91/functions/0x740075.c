
undefined4 FUN_00740075(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBP;
  int unaff_ESI;
  undefined1 *unaff_EDI;
  
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
          *unaff_EDI = (char)iVar1;
          iVar1 = *(int *)(unaff_ESI + 0xc);
          iVar2 = iVar2 + 1;
          unaff_EDI = unaff_EDI + 1;
        } while (iVar2 < iVar1);
        unaff_EDI = *(undefined1 **)(unaff_EBP + -4);
      }
      unaff_EDI = unaff_EDI + *(int *)(unaff_ESI + 0x10);
      iVar2 = *(int *)(unaff_EBP + -0xc) + 1;
      *(undefined1 **)(unaff_EBP + -4) = unaff_EDI;
      *(int *)(unaff_EBP + -0xc) = iVar2;
    } while (iVar2 < *(int *)(unaff_ESI + 8));
  }
  FUN_0073ff40(*(undefined4 *)(unaff_EBP + -8),unaff_ESI);
  **(int **)(unaff_EBP + 0xc) = unaff_ESI;
  return 0;
}

