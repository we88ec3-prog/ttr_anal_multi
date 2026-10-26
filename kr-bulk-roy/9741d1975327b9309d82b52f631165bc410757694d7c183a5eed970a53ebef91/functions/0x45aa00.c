
undefined4 FUN_0045aa00(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = 0;
  uVar5 = *(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2;
  if (uVar5 != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
    do {
      if (iVar1 != 0) {
        for (piVar2 = *(int **)(iVar1 + 0xa8); piVar2 != *(int **)(iVar1 + 0xac);
            piVar2 = piVar2 + 1) {
          iVar3 = *piVar2;
          if (*(uint *)(iVar3 + 0x20) == uVar4) goto LAB_0045aa54;
        }
      }
      iVar3 = 0;
LAB_0045aa54:
      if (*(int *)(iVar3 + 0x20) == param_2) {
        return *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xf0) + uVar4 * 4) + 0x2b0);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  return 0xffffffff;
}

