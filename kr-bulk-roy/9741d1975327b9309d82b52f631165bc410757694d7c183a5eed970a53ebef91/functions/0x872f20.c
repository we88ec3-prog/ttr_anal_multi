
void FUN_00872f20(int param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  FUN_0077f9d0(*(undefined4 *)(param_1 + 4),param_3);
  piVar2 = *(int **)(param_1 + 4);
  for (piVar4 = piVar2 + -1; piVar4 != piVar2; piVar4 = piVar4 + 1) {
    puVar3 = (undefined4 *)*piVar4;
    if (puVar3 != (undefined4 *)0x0) {
      piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*puVar3)(1);
      }
    }
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -4;
  *param_2 = param_3;
  return;
}

