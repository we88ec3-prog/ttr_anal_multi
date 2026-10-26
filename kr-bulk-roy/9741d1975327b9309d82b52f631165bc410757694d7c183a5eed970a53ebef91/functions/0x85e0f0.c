
void FUN_0085e0f0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)param_1 + 0x45);
  while (cVar1 == '\0') {
    FUN_0085e0f0(param_1[2]);
    piVar2 = (int *)param_1[4];
    piVar3 = (int *)*param_1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      param_1[4] = 0;
    }
    FUN_0089120c(param_1);
    param_1 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x45);
  }
  return;
}

