
void FUN_004d3610(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x21);
  while (cVar1 == '\0') {
    FUN_004d3610(param_1[2]);
    piVar2 = (int *)*param_1;
    if (param_1[4] != 0) {
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

