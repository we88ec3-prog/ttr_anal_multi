
void FUN_00860880(int *param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_1;
  if (piVar4 != (int *)0x0) {
    piVar2 = (int *)param_1[1];
    for (; piVar4 != piVar2; piVar4 = piVar4 + 1) {
      puVar3 = (undefined4 *)*piVar4;
      if (puVar3 != (undefined4 *)0x0) {
        piVar1 = puVar3 + 1;
        *piVar1 = *piVar1 + -1;
        if (*piVar1 == 0) {
          (**(code **)*puVar3)(1);
        }
      }
    }
    FUN_0089120c(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}

