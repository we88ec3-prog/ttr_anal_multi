
void FUN_007592c0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  bool bVar5;
  int *piVar6;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  bVar5 = false;
  piVar3 = (int *)*piVar1;
  iVar4 = 0;
  while (piVar6 = piVar3, piVar6 != piVar1) {
    if ((bVar5) && (iVar2 = piVar6[3], iVar4 == iVar2)) {
      piVar3 = (int *)*piVar6;
      iVar4 = iVar2;
      if (piVar6 != *(int **)(param_1 + 0x1c)) {
        *(int *)piVar6[1] = *piVar6;
        *(int *)(*piVar6 + 4) = piVar6[1];
        FUN_0089120c(piVar6);
        *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
      }
    }
    else {
      iVar4 = piVar6[3];
      bVar5 = true;
      piVar3 = (int *)*piVar6;
    }
  }
  return;
}

