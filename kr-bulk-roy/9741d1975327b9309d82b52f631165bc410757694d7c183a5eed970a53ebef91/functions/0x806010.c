
void FUN_00806010(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 0xffffffff;
  unaff_ESI[0x282a] = 1;
  FUN_008063e0(unaff_ESI);
  unaff_ESI[0x2830] = 0;
  unaff_ESI[0x2831] = 0;
  unaff_ESI[0x2832] = 0;
  unaff_ESI[0x2833] = 0;
  unaff_ESI[0x2834] = 0;
  unaff_ESI[0x282d] = 1;
  return;
}

