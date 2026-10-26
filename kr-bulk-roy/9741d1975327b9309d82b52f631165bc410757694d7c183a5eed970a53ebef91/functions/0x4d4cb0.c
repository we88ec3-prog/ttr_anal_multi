
void FUN_004d4cb0(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[0x1a] != 0) {
    FUN_0049bf30();
    FUN_0089120c(unaff_ESI[0x1a]);
  }
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0x1c] = 0;
  *unaff_ESI = FlyingObject::CFadeObject::vftable;
  if (0xf < (uint)unaff_ESI[0x17]) {
    FUN_0089120c(unaff_ESI[0x12]);
  }
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0xf;
  *(undefined1 *)(unaff_ESI + 0x12) = 0;
  *unaff_ESI = FlyingObject::CDefFlyingObject::vftable;
  return;
}

