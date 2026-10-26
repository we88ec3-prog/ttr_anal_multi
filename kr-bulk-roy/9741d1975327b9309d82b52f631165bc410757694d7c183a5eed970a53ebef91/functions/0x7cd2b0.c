
void FUN_007cd2b0(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0x3fc90fdb;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = 0x3f800000;
  unaff_ESI[9] = 0x43fa0000;
  unaff_ESI[10] = 0x3f91361e;
  unaff_ESI[0x10] = 0xf;
  unaff_ESI[0xf] = 0;
  *(undefined1 *)(unaff_ESI + 0xb) = 0;
  FUN_00402a70("Default",7);
  return;
}

