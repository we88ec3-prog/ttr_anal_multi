
void FUN_004014b0(void)

{
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = *unaff_EDI;
  unaff_ESI[6] = 7;
  unaff_ESI[5] = 0;
  *(undefined2 *)(unaff_ESI + 1) = 0;
  FUN_004026e0(unaff_EDI + 1,0,0xffffffff);
  *(undefined1 *)(unaff_ESI + 8) = *(undefined1 *)(unaff_EDI + 8);
  *(undefined1 *)((int)unaff_ESI + 0x21) = *(undefined1 *)((int)unaff_EDI + 0x21);
  *(undefined4 *)((int)unaff_ESI + 0x22) = *(undefined4 *)((int)unaff_EDI + 0x22);
  *(undefined4 *)((int)unaff_ESI + 0x26) = *(undefined4 *)((int)unaff_EDI + 0x26);
  *(undefined2 *)((int)unaff_ESI + 0x2a) = *(undefined2 *)((int)unaff_EDI + 0x2a);
  return;
}

