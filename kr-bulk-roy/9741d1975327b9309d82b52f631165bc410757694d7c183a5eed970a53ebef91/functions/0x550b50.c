
void FUN_00550b50(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    if (iVar3 != 0) {
      FUN_007be5f0();
      if (*(int **)(iVar3 + 0x28) != (int *)0x0) {
        (**(code **)(**(int **)(iVar3 + 0x28) + 0x10))();
        if (*(int **)(iVar3 + 0x28) != (int *)0x0) {
          (**(code **)(**(int **)(iVar3 + 0x28) + 8))();
          *(undefined4 *)(iVar3 + 0x28) = 0;
        }
      }
      FUN_0089120c(iVar3);
    }
  }
  piVar4 = *(int **)(param_1 + 4);
  piVar5 = (int *)*piVar4;
  *piVar4 = (int)piVar4;
  *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
  *(undefined4 *)(param_1 + 8) = 0;
  if (piVar5 != *(int **)(param_1 + 4)) {
    do {
      piVar4 = (int *)*piVar5;
      FUN_0089120c(piVar5);
      piVar5 = piVar4;
    } while (piVar4 != (int *)*(int *)(param_1 + 4));
  }
  FUN_005527c0(param_1 + 0x10);
  FUN_00552880(param_1 + 0x30);
  return;
}

