
void FUN_004ca730(void)

{
  undefined4 *unaff_ESI;
  
  unaff_ESI[0x2d] = 0x3f800000;
  *unaff_ESI = CBasicObject::vftable;
  unaff_ESI[0x22] = 0;
  unaff_ESI[0x23] = 0;
  unaff_ESI[0x24] = 0x7f;
  unaff_ESI[0x26] = 0;
  unaff_ESI[0x27] = 0;
  unaff_ESI[0x2b] = 0;
  unaff_ESI[0x2e] = 0;
  *(undefined1 *)(unaff_ESI + 0x2f) = 0;
  unaff_ESI[0x30] = 0;
  unaff_ESI[0x31] = 0;
  unaff_ESI[0x32] = 0;
  unaff_ESI[0x33] = 0;
  unaff_ESI[0x34] = 100;
  unaff_ESI[0x35] = 0;
  unaff_ESI[0x36] = 0;
  unaff_ESI[0x37] = 0;
  *(undefined2 *)(unaff_ESI + 1) = 0;
  _memset((void *)((int)unaff_ESI + 6),0,0x80);
  unaff_ESI[0x28] = 0;
  unaff_ESI[0x29] = 0;
  unaff_ESI[0x2a] = 0;
  unaff_ESI[0x38] = 0;
  *(undefined1 *)(unaff_ESI + 0x39) = 0;
  return;
}

