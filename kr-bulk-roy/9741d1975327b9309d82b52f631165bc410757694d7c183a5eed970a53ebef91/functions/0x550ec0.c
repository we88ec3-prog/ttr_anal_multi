
void FUN_00550ec0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *local_8;
  
  local_8 = *(int **)(param_1 + 4);
  piVar2 = (int *)*local_8;
  if (piVar2 != local_8) {
    do {
      iVar1 = piVar2[2];
      FUN_00550780();
      if (*(int *)(iVar1 + 0x74) == 0) {
        piVar3 = (int *)*piVar2;
      }
      else {
        if (*(int *)(iVar1 + 0x24) != 0) {
          FUN_007be5f0();
        }
        FUN_007be5f0();
        if (*(int **)(iVar1 + 0x28) != (int *)0x0) {
          (**(code **)(**(int **)(iVar1 + 0x28) + 0x10))();
          if (*(int **)(iVar1 + 0x28) != (int *)0x0) {
            (**(code **)(**(int **)(iVar1 + 0x28) + 8))();
            *(undefined4 *)(iVar1 + 0x28) = 0;
          }
        }
        FUN_0089120c(iVar1);
        piVar3 = (int *)*piVar2;
        if (piVar2 != *(int **)(param_1 + 4)) {
          *(int **)piVar2[1] = piVar3;
          *(int *)(*piVar2 + 4) = piVar2[1];
          FUN_0089120c(piVar2);
          *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
        }
        local_8 = *(int **)(param_1 + 4);
      }
      piVar2 = piVar3;
    } while (piVar3 != local_8);
  }
  return;
}

