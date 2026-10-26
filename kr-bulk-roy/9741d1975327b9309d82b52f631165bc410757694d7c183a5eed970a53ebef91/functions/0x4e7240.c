
/* WARNING: Removing unreachable block (ram,0x004e7266) */

void FUN_004e7240(void)

{
  uint uVar1;
  undefined4 in_ECX;
  int iVar2;
  int *unaff_ESI;
  
  uVar1 = unaff_ESI[1] - *unaff_ESI >> 3;
  if (uVar1 < 0x15) {
    if (uVar1 < 0x14) {
      FUN_004e72d0();
      FUN_004e7400(in_ECX);
      unaff_ESI[1] = unaff_ESI[1] + (0x14 - (unaff_ESI[1] - *unaff_ESI >> 3)) * 8;
    }
  }
  else {
    iVar2 = *unaff_ESI + 0xa0;
    if (iVar2 != unaff_ESI[1]) {
      unaff_ESI[1] = iVar2;
      return;
    }
  }
  return;
}

