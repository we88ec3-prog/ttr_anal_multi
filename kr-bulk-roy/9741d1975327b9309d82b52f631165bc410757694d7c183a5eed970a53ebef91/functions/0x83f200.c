
void FUN_0083f200(int *param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  cVar1 = *(char *)((int)param_1 + 0x89);
  while (cVar1 == '\0') {
    FUN_0083f200(param_1[2]);
    piVar2 = (int *)*param_1;
    param_1[0x14] = 0;
    param_1[0x15] = 0;
    piVar3 = (int *)param_1[0x18];
    param_1[0x17] = 4;
    param_1[4] = 0;
    param_1[0x13] = 0;
    param_1[0x16] = 0;
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      param_1[0x18] = 0;
    }
    piVar3 = (int *)param_1[0x19];
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      param_1[0x19] = 0;
    }
    piVar3 = (int *)param_1[0x1a];
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      param_1[0x1a] = 0;
    }
    param_1[0x1b] = 0;
    param_1[0x1c] = 0;
    param_1[0x1d] = 0;
    param_1[0x1e] = 0;
    param_1[0x20] = 0;
    param_1[0x1f] = 0;
    param_1[0x12] = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x89);
  }
  return;
}

