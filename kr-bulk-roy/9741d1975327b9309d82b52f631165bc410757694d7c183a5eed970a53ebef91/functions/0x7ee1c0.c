
void FUN_007ee1c0(void)

{
  undefined4 *unaff_ESI;
  uint uVar1;
  
  uVar1 = 0;
  if ((int)(unaff_ESI[4] - unaff_ESI[3]) >> 2 != 0) {
    do {
      (**(code **)(**(int **)(unaff_ESI[3] + uVar1 * 4) + 0x18))();
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)((int)(unaff_ESI[4] - unaff_ESI[3]) >> 2));
  }
  *unaff_ESI = 1;
  return;
}

