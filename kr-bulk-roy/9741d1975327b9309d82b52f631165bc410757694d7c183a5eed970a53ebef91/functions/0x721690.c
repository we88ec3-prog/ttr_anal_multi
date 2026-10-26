
void FUN_00721690(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  if (iVar1 != 0) {
    iVar2 = **(int **)(iVar1 + 4);
    piVar4 = *(int **)(iVar1 + 4);
    while (iVar2 != 0) {
      piVar3 = (int *)*piVar4;
      (*(code *)PTR_FUN_00d63d4c)(piVar4);
      piVar4 = piVar3;
      iVar2 = *piVar3;
    }
    (*(code *)PTR_FUN_00d63d4c)(iVar1);
  }
  return;
}

