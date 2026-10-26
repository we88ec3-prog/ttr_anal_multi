
void FUN_00852180(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x35);
  while (cVar1 == '\0') {
    FUN_00852180(param_1[2]);
    piVar2 = (int *)*param_1;
    if (param_1[9] != 0) {
      FUN_0089120c(param_1[9]);
    }
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    if (param_1[5] != 0) {
      FUN_0089120c(param_1[5]);
    }
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x35);
  }
  return;
}

