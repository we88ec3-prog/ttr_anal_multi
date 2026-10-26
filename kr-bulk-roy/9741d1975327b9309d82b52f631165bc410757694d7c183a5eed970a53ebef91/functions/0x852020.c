
void FUN_00852020(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x11);
  while (cVar1 == '\0') {
    FUN_00852020(param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x11);
  }
  return;
}

