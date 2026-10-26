
void FUN_008392d0(void)

{
  undefined4 *unaff_ESI;
  
  unaff_ESI[0xd] = 7;
  _memset(unaff_ESI + 1,0,0x34);
  unaff_ESI[9] = 0x3f800000;
  unaff_ESI[5] = 0x3f800000;
  unaff_ESI[1] = 0x3f800000;
  *unaff_ESI = 0;
  *(undefined8 *)(unaff_ESI + 0x10) = 0;
  unaff_ESI[0xf] = 0;
  unaff_ESI[0x12] = 0;
  unaff_ESI[0x14] = 0;
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  unaff_ESI[0x18] = 0;
  unaff_ESI[0x19] = 0;
  unaff_ESI[0x1a] = 0;
  unaff_ESI[0x1c] = 0;
  unaff_ESI[0x1b] = 0;
  unaff_ESI[0xe] = 0;
  unaff_ESI[0x13] = 4;
  return;
}

