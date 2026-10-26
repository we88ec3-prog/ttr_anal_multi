
void FUN_00609da0(void)

{
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = *unaff_EDI;
  unaff_ESI[1] = unaff_EDI[1];
  unaff_ESI[2] = unaff_EDI[2];
  unaff_ESI[3] = unaff_EDI[3];
  unaff_ESI[4] = unaff_EDI[4];
  unaff_ESI[5] = unaff_EDI[5];
  unaff_ESI[0xb] = 7;
  unaff_ESI[10] = 0;
  *(undefined2 *)(unaff_ESI + 6) = 0;
  FUN_004026e0(unaff_EDI + 6,0,0xffffffff);
  unaff_ESI[0xd] = unaff_EDI[0xd];
  unaff_ESI[0xe] = unaff_EDI[0xe];
  unaff_ESI[0x10] = unaff_EDI[0x10];
  unaff_ESI[0x11] = unaff_EDI[0x11];
  unaff_ESI[0x12] = unaff_EDI[0x12];
  unaff_ESI[0x13] = unaff_EDI[0x13];
  unaff_ESI[0x14] = unaff_EDI[0x14];
  return;
}

