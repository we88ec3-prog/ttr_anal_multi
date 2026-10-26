
void FUN_00850690(uint param_1)

{
  uint uVar1;
  int iVar2;
  int *unaff_EDI;
  
  uVar1 = (unaff_EDI[1] - *unaff_EDI) / 0x24;
  if (param_1 < uVar1) {
    if (*unaff_EDI + param_1 * 0x24 != unaff_EDI[1]) {
      iVar2 = FUN_008539a0(param_1);
      unaff_EDI[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < param_1) {
    FUN_00850bb0(param_1 - uVar1);
    FUN_00853a00(unaff_EDI[1],param_1);
    unaff_EDI[1] = unaff_EDI[1] + (param_1 - (unaff_EDI[1] - *unaff_EDI) / 0x24) * 0x24;
  }
  return;
}

