
void FUN_0081f720(void)

{
  undefined1 *in_EAX;
  undefined1 *in_ECX;
  undefined1 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  unaff_ESI[4] = *in_EAX;
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(in_EAX + 4);
  unaff_ESI[0xc] = in_EAX[8];
  *(undefined4 *)(unaff_ESI + 0x24) = 7;
  *(undefined4 *)(unaff_ESI + 0x20) = 0;
  *(undefined2 *)(unaff_ESI + 0x10) = 0;
  FUN_004026e0(in_EAX + 0xc,0,0xffffffff);
  return;
}

