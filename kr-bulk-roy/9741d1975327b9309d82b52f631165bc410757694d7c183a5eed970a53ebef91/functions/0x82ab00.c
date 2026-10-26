
void FUN_0082ab00(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x1d);
  while (cVar1 == '\0') {
    FUN_0082ab00(param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x1d);
  }
  return;
}

