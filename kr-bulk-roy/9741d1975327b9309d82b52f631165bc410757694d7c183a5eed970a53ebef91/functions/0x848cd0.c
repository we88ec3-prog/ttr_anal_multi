
void FUN_00848cd0(void)

{
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[0x15] != 0) {
    FUN_0089120c(unaff_ESI[0x15]);
  }
  unaff_ESI[0x15] = 0;
  unaff_ESI[0x16] = 0;
  unaff_ESI[0x17] = 0;
  if (0xf < (uint)unaff_ESI[5]) {
    FUN_0089120c(*unaff_ESI);
  }
  unaff_ESI[4] = 0;
  unaff_ESI[5] = 0xf;
  *(undefined1 *)unaff_ESI = 0;
  return;
}

