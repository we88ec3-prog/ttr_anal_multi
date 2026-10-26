
void FUN_00401e80(void)

{
  undefined4 *in_EAX;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = *in_EAX;
  unaff_ESI[1] = *unaff_EDI;
  unaff_ESI[7] = 7;
  unaff_ESI[6] = 0;
  *(undefined2 *)(unaff_ESI + 2) = 0;
  FUN_004026e0(unaff_EDI + 1,0,0xffffffff);
  *(undefined1 *)(unaff_ESI + 9) = *(undefined1 *)(unaff_EDI + 8);
  *(undefined1 *)((int)unaff_ESI + 0x25) = *(undefined1 *)((int)unaff_EDI + 0x21);
  *(undefined4 *)((int)unaff_ESI + 0x26) = *(undefined4 *)((int)unaff_EDI + 0x22);
  *(undefined4 *)((int)unaff_ESI + 0x2a) = *(undefined4 *)((int)unaff_EDI + 0x26);
  *(undefined2 *)((int)unaff_ESI + 0x2e) = *(undefined2 *)((int)unaff_EDI + 0x2a);
  return;
}

