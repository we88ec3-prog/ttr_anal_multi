
uint FUN_008b7e80(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_2 == param_3) {
    return param_1;
  }
  iVar3 = (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
  iVar2 = (param_2 ^ (int)param_2 >> 0x1f) - ((int)param_2 >> 0x1f);
  iVar4 = (param_3 ^ (int)param_3 >> 0x1f) - ((int)param_3 >> 0x1f);
  if ((iVar3 < 0xb505) && (iVar2 < 0xb505)) {
    if (0 < iVar4) {
      uVar1 = (iVar3 * iVar2) / iVar4;
      goto LAB_008b7eff;
    }
  }
  else if (0 < iVar4) {
    FUN_008b7d00();
    uVar1 = FUN_008b7d60();
    goto LAB_008b7eff;
  }
  uVar1 = 0x7fffffff;
LAB_008b7eff:
  if ((int)(param_1 ^ param_2 ^ param_3) < 0) {
    uVar1 = -uVar1;
  }
  return uVar1;
}

