
/* WARNING: Removing unreachable block (ram,0x008792e9) */
/* WARNING: Removing unreachable block (ram,0x008792f0) */

void FUN_008792b0(void)

{
  int iVar1;
  uint uVar2;
  uint in_EAX;
  undefined4 in_ECX;
  int *unaff_ESI;
  
  uVar2 = (unaff_ESI[1] - *unaff_ESI) / 0xc;
  if (in_EAX < uVar2) {
    iVar1 = *unaff_ESI + in_EAX * 0xc;
    if (iVar1 != unaff_ESI[1]) {
      unaff_ESI[1] = iVar1;
      return;
    }
  }
  else if (uVar2 < in_EAX) {
    FUN_008507f0(in_EAX - uVar2);
    FUN_00879380(in_ECX);
    unaff_ESI[1] = unaff_ESI[1] + (in_EAX - (unaff_ESI[1] - *unaff_ESI) / 0xc) * 0xc;
  }
  return;
}

