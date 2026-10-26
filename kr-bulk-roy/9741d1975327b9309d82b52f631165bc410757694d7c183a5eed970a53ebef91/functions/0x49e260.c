
void FUN_0049e260(void)

{
  undefined4 *in_EAX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_EAX;
  unaff_ESI[1] = in_EAX[1];
  unaff_ESI[7] = 7;
  unaff_ESI[6] = 0;
  *(undefined2 *)(unaff_ESI + 2) = 0;
  FUN_004026e0(in_EAX + 2,0,0xffffffff);
  return;
}

