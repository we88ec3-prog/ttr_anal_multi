
void FUN_007349b0(void)

{
  undefined4 *unaff_ESI;
  
  _memset(unaff_ESI + 0x46,0,0x800);
  unaff_ESI[4] = 0x800;
  unaff_ESI[5] = 0x400;
  unaff_ESI[2] = 0x20;
  unaff_ESI[3] = 0x40;
  *unaff_ESI = 0x40;
  unaff_ESI[1] = 0x10;
  FUN_00734a00();
  return;
}

