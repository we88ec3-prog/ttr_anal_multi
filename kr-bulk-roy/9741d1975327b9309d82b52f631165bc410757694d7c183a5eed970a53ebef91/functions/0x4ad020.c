
void FUN_004ad020(void)

{
  undefined2 *in_EAX;
  undefined2 *in_ECX;
  undefined2 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  unaff_ESI[2] = *in_EAX;
  unaff_ESI[3] = in_EAX[1];
  *(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(in_EAX + 2);
  *(undefined4 *)(unaff_ESI + 6) = *(undefined4 *)(in_EAX + 4);
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(in_EAX + 6);
  *(undefined4 *)(unaff_ESI + 10) = *(undefined4 *)(in_EAX + 8);
  *(undefined4 *)(unaff_ESI + 0x16) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined1 *)(unaff_ESI + 0xc) = 0;
  FUN_00403040(in_EAX + 10,0,0xffffffff);
  return;
}

