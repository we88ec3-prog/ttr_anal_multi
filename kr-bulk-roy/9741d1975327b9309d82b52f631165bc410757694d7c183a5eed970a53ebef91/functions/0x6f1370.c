
void FUN_006f1370(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[8] = 1;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  _memset(unaff_ESI + 0x18,0,0x100);
  _memset(unaff_ESI + 0x98,0,0x100);
  unaff_ESI[0xd8] = 0;
  unaff_ESI[0xd9] = 0;
  unaff_ESI[0xdc] = 0;
  unaff_ESI[0xdd] = 0;
  _memset(unaff_ESI + 0xde,0,0x80);
  _memset(unaff_ESI + 0x11e,0,0x80);
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  _memset(unaff_ESI + 0xc,0,0x30);
  _memset(unaff_ESI + 0x13e,0,0x80);
  unaff_ESI[0x15e] = 0;
  return;
}

