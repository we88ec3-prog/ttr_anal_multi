
void FUN_00721390(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (param_1 != 0) {
    iVar1 = **(int **)(param_1 + 4);
    piVar3 = *(int **)(param_1 + 4);
    while (iVar1 != 0) {
      piVar2 = (int *)*piVar3;
      (*(code *)PTR_FUN_00d63d4c)(piVar3);
      piVar3 = piVar2;
      iVar1 = *piVar2;
    }
    (*(code *)PTR_FUN_00d63d4c)(param_1);
  }
  return;
}

