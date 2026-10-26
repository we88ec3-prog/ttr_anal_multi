
void FUN_007b8030(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)param_1[2];
  if (piVar3 != (int *)param_1[2]) {
    do {
      iVar1 = piVar3[9];
      FUN_007dd1f0();
      *(undefined4 *)(iVar1 + 0x44) = 0;
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)param_1[2]);
  }
  iVar1 = *param_1;
  piVar3 = *(int **)(iVar1 + 4);
  piVar2 = (int *)*piVar3;
  if (piVar2 != piVar3) {
    do {
      (**(code **)(*(int *)piVar2[9] + 8))();
      piVar2 = (int *)*piVar2;
    } while (piVar2 != (int *)*(int *)(iVar1 + 4));
  }
  param_1[0xc] = 0;
  return;
}

