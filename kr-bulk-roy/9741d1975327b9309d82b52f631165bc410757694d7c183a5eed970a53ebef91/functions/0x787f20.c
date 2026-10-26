
int FUN_00787f20(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *unaff_EDI;
  
  iVar3 = unaff_EDI[1] - *unaff_EDI;
  iVar2 = iVar3 * -0x6db6db6d;
  uVar1 = iVar3 / 0x1c;
  if (param_1 < uVar1) {
    iVar2 = *unaff_EDI + param_1 * 0x1c;
    if (iVar2 != unaff_EDI[1]) {
      iVar2 = FUN_00789d70(param_1);
      unaff_EDI[1] = iVar2;
      return iVar2;
    }
  }
  else if (uVar1 < param_1) {
    FUN_00788380();
    FUN_00789ab0(param_1);
    iVar2 = (unaff_EDI[1] - *unaff_EDI) / 0x1c;
    unaff_EDI[1] = unaff_EDI[1] + (param_1 - iVar2) * 0x1c;
  }
  return iVar2;
}

