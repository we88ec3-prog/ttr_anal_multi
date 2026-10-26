
void FUN_00869e60(void)

{
  undefined4 *unaff_ESI;
  
  unaff_ESI[1] = 0;
  unaff_ESI[7] = 0xf;
  unaff_ESI[6] = 0;
  *(undefined1 *)(unaff_ESI + 2) = 0;
  *unaff_ESI = gbParticle::vftable;
  FUN_00869f50();
  FUN_0086a1b0();
  unaff_ESI[0xd0] = 0;
  unaff_ESI[0xd1] = 0;
  unaff_ESI[0xd2] = 0;
  unaff_ESI[0xd3] = 0;
  unaff_ESI[0xd0] = 0;
  unaff_ESI[0xd1] = 0;
  unaff_ESI[0xd6] = 0x3f800000;
  unaff_ESI[0xd3] = 0x3f800000;
  unaff_ESI[0xd4] = 1;
  unaff_ESI[0xd2] = 0x3f800000;
  unaff_ESI[0xd5] = 1;
  unaff_ESI[0xd8] = 1;
  unaff_ESI[0xd9] = 1;
  unaff_ESI[0xcf] = 0;
  unaff_ESI[0xd7] = 0;
  unaff_ESI[9] = 0;
  return;
}

