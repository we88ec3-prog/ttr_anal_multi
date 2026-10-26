
void FUN_00401b40(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x3d);
  while (cVar1 == '\0') {
    FUN_00401b40(param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[10]) {
      FUN_0089120c(param_1[5]);
    }
    param_1[10] = 7;
    param_1[9] = 0;
    *(undefined2 *)(param_1 + 5) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x3d);
  }
  return;
}

