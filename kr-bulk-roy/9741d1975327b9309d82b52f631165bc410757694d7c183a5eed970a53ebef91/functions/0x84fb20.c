
uint FUN_0084fb20(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  piVar2 = (int *)*in_ECX;
  uVar4 = in_ECX[1] - (int)piVar2 >> 2;
  iVar6 = param_2;
  while (uVar5 = 0, piVar3 = piVar2, uVar4 != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x48) + iVar6 * 0x18);
    while (*piVar3 == *(int *)((*piVar1 - (int)piVar2) + (int)piVar3)) {
      uVar5 = uVar5 + 1;
      piVar3 = piVar3 + 1;
      if (uVar4 <= uVar5) goto LAB_0084fb6f;
    }
    iVar6 = piVar1[4];
    if (iVar6 == param_2) {
      return (uint)piVar1 & 0xffffff00;
    }
  }
LAB_0084fb6f:
  *param_3 = iVar6;
  return CONCAT31((int3)((uint)piVar3 >> 8),1);
}

