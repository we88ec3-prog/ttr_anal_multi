
void FUN_00837200(void)

{
  undefined4 *in_EAX;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = *in_EAX;
  unaff_ESI[1] = *unaff_EDI;
  unaff_ESI[2] = unaff_EDI[1];
  unaff_ESI[3] = unaff_EDI[2];
  unaff_ESI[4] = unaff_EDI[3];
  unaff_ESI[5] = unaff_EDI[4];
  FUN_008356f0(unaff_EDI + 5);
  unaff_ESI[10] = unaff_EDI[9];
  return;
}

