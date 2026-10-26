
void FUN_007a2500(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  cVar1 = *(char *)((int)param_1 + 0x19);
  while (cVar1 == '\0') {
    FUN_007a2500(param_1[2]);
    piVar2 = (int *)param_1[5];
    piVar3 = (int *)*param_1;
    if (piVar2 != (int *)0x0) {
      LOCK();
      iVar4 = piVar2[1] + -1;
      piVar2[1] = iVar4;
      UNLOCK();
      if (iVar4 == 0) {
        (**(code **)*piVar2)();
        LOCK();
        iVar4 = piVar2[2] + -1;
        piVar2[2] = iVar4;
        UNLOCK();
        if (iVar4 == 0) {
          (**(code **)(*piVar2 + 4))();
        }
      }
    }
    FUN_0089120c(param_1);
    param_1 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x19);
  }
  return;
}

