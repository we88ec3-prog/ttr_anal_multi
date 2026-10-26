
void FUN_00776790(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  
  iVar2 = *(int *)(param_1 + 4);
  if (*(int *)(unaff_ESI + 4) != iVar2) {
    if (((iVar2 != 0) && (piVar3 = *(int **)(iVar2 + 8), piVar3 != (int *)0x0)) &&
       (piVar3[0x27] = piVar3[0x27] + 1, piVar3[0x27] == 1)) {
      (**(code **)(*piVar3 + 0x24))();
    }
    if ((*(int *)(unaff_ESI + 4) != 0) &&
       (piVar3 = *(int **)(*(int *)(unaff_ESI + 4) + 8), piVar3 != (int *)0x0)) {
      piVar1 = piVar3 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar3 + 0x28))();
      }
    }
    *(int *)(unaff_ESI + 4) = iVar2;
  }
  FUN_004026e0(param_1 + 8,0,0xffffffff);
  FUN_004026e0(param_1 + 0x24,0,0xffffffff);
  return;
}

