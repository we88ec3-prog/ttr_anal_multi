
short FUN_008d0fd0(int param_1,uint *param_2)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  short *psVar4;
  
  uVar3 = *(uint *)(param_1 + 0x10);
  sVar1 = 0;
  uVar2 = *param_2 + 1;
  if (*param_2 + 1 < uVar3) {
    uVar2 = uVar3;
  }
  uVar3 = *(int *)(param_1 + 0x14) + uVar3;
  if (uVar2 < uVar3) {
    psVar4 = (short *)(*(int *)(param_1 + 0x18) + uVar2 * 2);
    do {
      sVar1 = *psVar4;
      if (sVar1 != 0) goto LAB_008d1011;
      uVar2 = uVar2 + 1;
      psVar4 = psVar4 + 1;
    } while (uVar2 < uVar3);
  }
  uVar2 = 0;
LAB_008d1011:
  *param_2 = uVar2;
  return sVar1;
}

