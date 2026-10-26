
void FUN_004c9010(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x364) != 0) {
    if (*(int *)(*(int *)(param_1 + 0x364) + 0x24) != 0) {
      FUN_007be5f0();
    }
    if (*(int *)(param_1 + 0x364) != 0) {
      FUN_004c7db0();
      *(undefined4 *)(param_1 + 0x364) = 0;
    }
  }
  piVar2 = (int *)(param_1 + 0x164);
  param_1 = 0x80;
  do {
    if (*piVar2 != 0) {
      if (*(int *)(*piVar2 + 0x24) != 0) {
        FUN_007be5f0();
      }
      iVar1 = *piVar2;
      if (iVar1 != 0) {
        FUN_007be5f0();
        if (*(int **)(iVar1 + 0x28) != (int *)0x0) {
          (**(code **)(**(int **)(iVar1 + 0x28) + 0x10))();
          if (*(int **)(iVar1 + 0x28) != (int *)0x0) {
            (**(code **)(**(int **)(iVar1 + 0x28) + 8))();
            *(undefined4 *)(iVar1 + 0x28) = 0;
          }
        }
        FUN_0089120c(iVar1);
        *piVar2 = 0;
      }
    }
    piVar2 = piVar2 + 1;
    param_1 = param_1 + -1;
  } while (param_1 != 0);
  return;
}

