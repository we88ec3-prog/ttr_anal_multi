
void FUN_00861aa0(void)

{
  undefined4 *unaff_ESI;
  
  FUN_0077fd70(unaff_ESI);
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x1b] = 3;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1c] = 0;
  *unaff_ESI = gbLight::vftable;
  unaff_ESI[0x23] = 0x3f800000;
  unaff_ESI[0x24] = 0x3f800000;
  unaff_ESI[0x25] = 0x3f800000;
  return;
}

