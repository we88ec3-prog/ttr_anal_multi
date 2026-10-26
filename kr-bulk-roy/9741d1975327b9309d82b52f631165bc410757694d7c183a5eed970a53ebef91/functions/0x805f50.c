
void FUN_00805f50(void)

{
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 0xffffffff;
  unaff_ESI[0x282b] = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[0x1406] = unaff_ESI + 6;
  *(undefined1 *)(unaff_ESI + 0x2809) = 0;
  unaff_ESI[0x280a] = 0;
  unaff_ESI[0x2808] = unaff_ESI + 0x1408;
  unaff_ESI[0x2821] = 0;
  unaff_ESI[0x2822] = 0;
  unaff_ESI[0x2823] = 0;
  unaff_ESI[0x2824] = 0;
  unaff_ESI[0x2825] = 0;
  unaff_ESI[0x2826] = 0;
  unaff_ESI[0x2827] = 0;
  unaff_ESI[0x2828] = 0;
  unaff_ESI[0x2829] = 0;
  unaff_ESI[0x282a] = 0;
  unaff_ESI[0x2820] = 2;
  FUN_008063e0(unaff_ESI);
  unaff_ESI[0x2830] = 0;
  unaff_ESI[0x2831] = 0;
  unaff_ESI[0x2832] = 0;
  unaff_ESI[0x2833] = 0;
  unaff_ESI[0x2834] = 0;
  unaff_ESI[0x282c] = 0;
  unaff_ESI[0x282d] = 1;
  return;
}

