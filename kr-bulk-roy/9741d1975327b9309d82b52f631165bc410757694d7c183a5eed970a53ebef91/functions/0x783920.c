
void FUN_00783920(int *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int *piVar4;
  
  cVar2 = *(char *)((int)param_1 + 0x15);
  while (cVar2 == '\0') {
    FUN_00783920(param_1[2]);
    puVar3 = (undefined4 *)param_1[4];
    piVar4 = (int *)*param_1;
    if (puVar3 != (undefined4 *)0x0) {
      piVar1 = puVar3 + 1;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)*puVar3)(1);
      }
    }
    FUN_0089120c(param_1);
    param_1 = piVar4;
    cVar2 = *(char *)((int)piVar4 + 0x15);
  }
  return;
}

