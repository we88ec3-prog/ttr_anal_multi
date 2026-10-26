
void FUN_007b7fd0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = *param_1;
  piVar2 = *(int **)(iVar1 + 4);
  piVar3 = (int *)*piVar2;
  if (piVar3 != piVar2) {
    do {
      (**(code **)(*(int *)piVar3[9] + 4))();
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*(int *)(iVar1 + 4));
  }
  piVar2 = *(int **)param_1[2];
  if (piVar2 == (int *)param_1[2]) {
    param_1[0xc] = 1;
    return;
  }
  do {
    *(undefined4 *)(piVar2[9] + 0x44) = 1;
    piVar2 = (int *)*piVar2;
  } while (piVar2 != (int *)param_1[2]);
  param_1[0xc] = 1;
  return;
}

