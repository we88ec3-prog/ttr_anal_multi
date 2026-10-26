
void FUN_007fae60(void)

{
  undefined4 *unaff_ESI;
  
  FUN_007f9fc0();
  unaff_ESI[0x56] = 0x3f800000;
  *unaff_ESI = IS3D::QP_EmitterSet::vftable;
  unaff_ESI[0x57] = 0x3f800000;
  unaff_ESI[0x58] = 0x3f800000;
  unaff_ESI[0x5b] = 0x3f800000;
  unaff_ESI[0x5c] = 0x3f800000;
  unaff_ESI[0x5d] = 0;
  unaff_ESI[0x5e] = 0;
  unaff_ESI[0x5f] = 0;
  unaff_ESI[0x60] = 0;
  unaff_ESI[0x61] = 0;
  unaff_ESI[0x62] = 0;
  unaff_ESI[0x5a] = 1;
  unaff_ESI[0x59] = 1;
  return;
}

