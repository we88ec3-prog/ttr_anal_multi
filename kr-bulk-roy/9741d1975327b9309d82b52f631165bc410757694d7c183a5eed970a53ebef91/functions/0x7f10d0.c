
void FUN_007f10d0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = IS3D::CItemBaseNodeParticle::vftable;
  if (0xf < (uint)unaff_ESI[0x1c]) {
    FUN_0089120c(unaff_ESI[0x17]);
  }
  unaff_ESI[0x1c] = 0xf;
  unaff_ESI[0x1b] = 0;
  *(undefined1 *)(unaff_ESI + 0x17) = 0;
  if (0xf < (uint)unaff_ESI[0x15]) {
    FUN_0089120c(unaff_ESI[0x10]);
  }
  unaff_ESI[0x15] = 0xf;
  unaff_ESI[0x14] = 0;
  *(undefined1 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = IS3D::CItemBaseNode::vftable;
  if (unaff_ESI[10] != 0) {
    FUN_00440a80();
    FUN_0089120c(unaff_ESI[10]);
  }
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  return;
}

