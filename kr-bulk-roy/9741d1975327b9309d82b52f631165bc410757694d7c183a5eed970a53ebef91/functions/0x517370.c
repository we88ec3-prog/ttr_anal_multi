
void FUN_00517370(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  cVar1 = *(char *)((int)param_1 + 0x21);
  while (cVar1 == '\0') {
    FUN_00517370(param_1[2]);
    piVar4 = (int *)param_1[4];
    piVar2 = (int *)*param_1;
    if (piVar4 != (int *)0x0) {
      piVar3 = (int *)param_1[5];
      for (; piVar4 != piVar3; piVar4 = piVar4 + 4) {
        if (*piVar4 != 0) {
          FUN_0089120c(*piVar4);
        }
        *piVar4 = 0;
        piVar4[1] = 0;
        piVar4[2] = 0;
      }
      FUN_0089120c(param_1[4]);
    }
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x21);
  }
  return;
}

