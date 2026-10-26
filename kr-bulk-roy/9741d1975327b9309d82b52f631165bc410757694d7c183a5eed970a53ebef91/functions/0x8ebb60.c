
void FUN_008ebb60(void)

{
  undefined4 uVar1;
  int *unaff_EDI;
  
  uVar1 = *(undefined4 *)(*unaff_EDI + 100);
  if ((char)unaff_EDI[0x49] != '\0') {
    unaff_EDI[0x4a] = 0;
    *(undefined1 *)(unaff_EDI + 0x49) = 0;
  }
  FUN_008b9f80(uVar1,unaff_EDI[0x3d]);
  unaff_EDI[0x3d] = 0;
  unaff_EDI[0x3c] = 0;
  FUN_008b9f80(uVar1,unaff_EDI[0x3f]);
  unaff_EDI[0x3f] = 0;
  *(undefined2 *)(unaff_EDI + 0x3e) = 0;
  FUN_008eb6e0();
  FUN_008b9f80(uVar1,unaff_EDI[0x1f]);
  unaff_EDI[0x1f] = 0;
  FUN_008b9f80(uVar1,unaff_EDI[0x22]);
  unaff_EDI[0x22] = 0;
  unaff_EDI[0x1d] = 0;
  unaff_EDI[0x1e] = 0;
  unaff_EDI[0x20] = 0;
  unaff_EDI[0x21] = 0;
  unaff_EDI[0x23] = 0;
  unaff_EDI[0x24] = 0;
  *(undefined2 *)(unaff_EDI + 0x4b) = 0;
  return;
}

