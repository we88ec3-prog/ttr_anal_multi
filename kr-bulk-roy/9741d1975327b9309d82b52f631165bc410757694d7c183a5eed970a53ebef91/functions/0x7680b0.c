
uint FUN_007680b0(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if (*(int *)(in_ECX + 0x130) != 0) {
    piVar1 = *(int **)(in_ECX + 0x110);
    iVar5 = *(int *)(in_ECX + 0x114) - (int)piVar1 >> 2;
    iVar7 = 0;
    iVar8 = 0;
    iVar6 = 0;
    if (1 < iVar5) {
      iVar4 = (iVar5 - 2U >> 1) + 1;
      iVar6 = iVar4 * 2;
      piVar2 = piVar1;
      do {
        iVar7 = iVar7 + *(int *)(*piVar2 + 0x10);
        iVar8 = iVar8 + *(int *)(piVar2[1] + 0x10);
        piVar2 = piVar2 + 2;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    iVar4 = 0;
    if (iVar6 < iVar5) {
      iVar4 = *(int *)(piVar1[iVar6] + 0x10);
    }
    uVar3 = *(int *)(in_ECX + 0x130) - (iVar4 + iVar7 + iVar8);
    if (*(uint *)(param_1 + 0x10) < uVar3) {
      uVar3 = *(uint *)(param_1 + 0x10);
    }
    return uVar3;
  }
  return *(uint *)(param_1 + 0x10);
}

