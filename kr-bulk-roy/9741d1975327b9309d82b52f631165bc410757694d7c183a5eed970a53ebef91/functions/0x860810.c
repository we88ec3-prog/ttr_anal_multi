
void FUN_00860810(int param_1,int *param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int *piVar5;
  
  if (param_3 == param_4) {
    *param_2 = param_3;
    return;
  }
  piVar4 = (int *)FUN_0077f9d0(*(undefined4 *)(param_1 + 4),param_1);
  piVar2 = *(int **)(param_1 + 4);
  for (piVar5 = piVar4; piVar5 != piVar2; piVar5 = piVar5 + 1) {
    puVar3 = (undefined4 *)*piVar5;
    if (puVar3 != (undefined4 *)0x0) {
      piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*puVar3)(1);
      }
    }
  }
  *(int **)(param_1 + 4) = piVar4;
  *param_2 = param_3;
  return;
}

