
void FUN_007361f0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x61);
  while (cVar1 == '\0') {
    FUN_007361f0(param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x61);
  }
  return;
}

