
uint FUN_00408780(uint param_1,uint param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar5 = 0;
  uVar6 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;
  uVar4 = param_1;
  if (uVar6 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
    do {
      if (iVar1 != 0) {
        for (piVar2 = *(int **)(iVar1 + 0xa8); piVar2 != *(int **)(iVar1 + 0xac);
            piVar2 = piVar2 + 1) {
          iVar3 = *piVar2;
          if (*(uint *)(iVar3 + 0x20) == uVar5) goto LAB_004087d4;
        }
      }
      iVar3 = 0;
LAB_004087d4:
      uVar4 = *(uint *)(iVar3 + 0x20);
      if (uVar4 == param_2) {
        return (uint)(*(int *)(*(int *)(*(int *)(param_1 + 0xf0) + uVar5 * 4) + 0x25c) != 0);
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < uVar6);
  }
  return uVar4 & 0xffffff00;
}

