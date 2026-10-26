
int FUN_008bc850(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    return 0x23;
  }
  if (((*(uint *)(param_1 + 0x10) <= param_2) || (param_2 + param_3 < param_2)) ||
     (*(uint *)(param_1 + 0x10) < param_2 + param_3)) {
    return 0x10;
  }
  if (param_3 == 0) {
    return 0;
  }
  pcVar1 = *(code **)(*(int *)(*(int *)(param_1 + 0x60) + 0xc) + 0x54);
  if ((pcVar1 != (code *)0x0) && (((param_4 & 3) != 0 || ((param_4 & 0xf0000) == 0x10000)))) {
    iVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5);
    if (iVar2 == 0) {
      iVar2 = FUN_008ba1b0(param_1,param_3,param_4);
      return iVar2;
    }
    if ((char)iVar2 != '\a') {
      return iVar2;
    }
  }
  iVar2 = 0;
  if ((param_4 & 0x20000000) != 0) {
    return 7;
  }
  uVar3 = 0;
  if (param_3 != 0) {
    while (iVar2 = FUN_008bb2e0(param_1,uVar3 + param_2,param_4 | 0x100), iVar2 == 0) {
      if ((param_4 & 0x10) == 0) {
        iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x40);
      }
      else {
        iVar2 = *(int *)(*(int *)(param_1 + 0x54) + 0x44);
      }
      *(int *)(param_5 + uVar3 * 4) = iVar2 << 10;
      uVar3 = uVar3 + 1;
      if (param_3 <= uVar3) {
        return 0;
      }
    }
  }
  return iVar2;
}

