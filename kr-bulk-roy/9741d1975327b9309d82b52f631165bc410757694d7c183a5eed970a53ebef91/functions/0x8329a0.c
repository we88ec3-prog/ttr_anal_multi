
void FUN_008329a0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x39);
  while (cVar1 == '\0') {
    FUN_008329a0(param_1[2]);
    piVar2 = (int *)*param_1;
    if (param_1[9] != 0) {
      FUN_0089120c(param_1[9]);
    }
    param_1[9] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x39);
  }
  return;
}

