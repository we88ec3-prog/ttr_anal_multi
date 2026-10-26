
void FUN_00742140(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x2819);
  while (cVar1 == '\0') {
    FUN_00742140(param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x2819);
  }
  return;
}

