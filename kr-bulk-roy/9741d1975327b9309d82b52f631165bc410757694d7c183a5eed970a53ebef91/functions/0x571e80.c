
void FUN_00571e80(void)

{
  undefined4 *in_EAX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_EAX;
  unaff_ESI[1] = in_EAX[1];
  FUN_004026e0(in_EAX + 2,0,0xffffffff);
  unaff_ESI[9] = in_EAX[9];
  FUN_00571f70(in_EAX + 10);
  return;
}

