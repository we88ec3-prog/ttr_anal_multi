
void FUN_0073f510(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x9d);
  while (cVar1 == '\0') {
    FUN_0073f510(param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_0073e5e0();
    if (7 < (uint)param_1[8]) {
      FUN_0089120c(param_1[3]);
    }
    param_1[8] = 7;
    param_1[7] = 0;
    *(undefined2 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x9d);
  }
  return;
}

