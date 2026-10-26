
void FUN_007e94c0(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[0xd] != 0) {
    FUN_0089120c(unaff_ESI[0xd]);
  }
  unaff_ESI[0xd] = 0;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0xf] = 0;
  if (unaff_ESI[9] != 0) {
    FUN_0089120c(unaff_ESI[9]);
  }
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  if (unaff_ESI[5] != 0) {
    FUN_0089120c(unaff_ESI[5]);
  }
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  *unaff_ESI = IS3D::CSteppable::vftable;
  return;
}

