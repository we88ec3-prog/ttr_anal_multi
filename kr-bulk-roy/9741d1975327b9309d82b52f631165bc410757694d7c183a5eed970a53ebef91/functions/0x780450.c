
void FUN_00780450(void)

{
  undefined4 *unaff_ESI;
  
  unaff_ESI[0xc] = 7;
  _memset(unaff_ESI,0,0x34);
  unaff_ESI[8] = 0x3f800000;
  unaff_ESI[4] = 0x3f800000;
  *unaff_ESI = 0x3f800000;
  return;
}

