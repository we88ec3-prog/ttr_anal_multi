
void FUN_0077e550(void)

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
  unaff_ESI[0x1d] = 0x3f48f5c3;
  *unaff_ESI = gbCamera::vftable;
  unaff_ESI[0x21] = 0x280;
  unaff_ESI[0x1e] = 0x41200000;
  unaff_ESI[0x22] = 0x1e0;
  unaff_ESI[0x1f] = 0x461c4000;
  return;
}

