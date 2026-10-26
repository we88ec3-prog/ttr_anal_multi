
undefined4 FUN_0054afa0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  
  iVar1 = FUN_005498c0(param_1);
  uVar3 = 0;
  uVar2 = *(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2;
  if (uVar2 != 0) {
    piVar4 = *(int **)(in_ECX + 4);
    do {
      if (*piVar4 == iVar1) {
        return 1;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < uVar2);
  }
  return 0;
}

