
void FUN_00856910(void)

{
  undefined4 *_Dst;
  undefined4 *unaff_ESI;
  
  FUN_0077fd70(unaff_ESI);
  _Dst = unaff_ESI + 0x1c;
  *unaff_ESI = gbTexture::vftable;
  _memset(_Dst,0,0x44);
  unaff_ESI[0x2b] = 0x3f800000;
  unaff_ESI[0x26] = 0x3f800000;
  unaff_ESI[0x21] = 0x3f800000;
  *_Dst = 0x3f800000;
  unaff_ESI[0x2e] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x1a] = 2;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x2d] = 0;
  unaff_ESI[0x17] = 0x3f800000;
  unaff_ESI[0x18] = 0x3f800000;
  _memset(_Dst,0,0x44);
  unaff_ESI[0x2b] = 0x3f800000;
  unaff_ESI[0x26] = 0x3f800000;
  unaff_ESI[0x21] = 0x3f800000;
  *_Dst = 0x3f800000;
  return;
}

