
void FUN_008f1840(void)

{
  uint *unaff_ESI;
  uint uVar1;
  
  uVar1 = 0;
  if (unaff_ESI != (uint *)0x0) {
    FUN_008b9f80();
    unaff_ESI[1] = 0;
    FUN_008b9f80();
    unaff_ESI[2] = 0;
    if (unaff_ESI[5] != 0) {
      if (*unaff_ESI != 0) {
        do {
          FUN_008b9f80();
          *(undefined4 *)(unaff_ESI[5] + 4 + uVar1 * 8) = 0;
          uVar1 = uVar1 + 1;
        } while (uVar1 < *unaff_ESI);
      }
      FUN_008b9f80();
      unaff_ESI[5] = 0;
    }
    FUN_008b9f80();
    unaff_ESI[7] = 0;
    FUN_008b9f80();
    unaff_ESI[9] = 0;
    FUN_008b9f80();
  }
  return;
}

