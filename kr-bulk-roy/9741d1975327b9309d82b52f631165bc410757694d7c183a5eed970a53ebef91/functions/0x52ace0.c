
void FUN_0052ace0(void)

{
  undefined1 *in_EAX;
  undefined1 *in_ECX;
  undefined1 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  unaff_ESI[4] = *in_EAX;
  *(undefined4 *)(unaff_ESI + 0x1c) = 7;
  *(undefined4 *)(unaff_ESI + 0x18) = 0;
  *(undefined2 *)(unaff_ESI + 8) = 0;
  FUN_004026e0(in_EAX + 4,0,0xffffffff);
  return;
}

