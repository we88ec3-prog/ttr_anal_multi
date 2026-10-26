
void FUN_007e40e0(void)

{
  undefined4 *in_EAX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_EAX;
  unaff_ESI[1] = in_EAX[1];
  unaff_ESI[2] = in_EAX[2];
  unaff_ESI[3] = in_EAX[3];
  unaff_ESI[4] = in_EAX[4];
  unaff_ESI[5] = in_EAX[5];
  unaff_ESI[6] = in_EAX[6];
  unaff_ESI[7] = in_EAX[7];
  unaff_ESI[8] = in_EAX[8];
  unaff_ESI[9] = in_EAX[9];
  unaff_ESI[0xf] = 0xf;
  unaff_ESI[0xe] = 0;
  *(undefined1 *)(unaff_ESI + 10) = 0;
  FUN_00403040(in_EAX + 10,0,0xffffffff);
  return;
}

