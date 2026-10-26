
void FUN_004db690(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x55);
  while (cVar1 == '\0') {
    FUN_004db690(param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[0x10]) {
      FUN_0089120c(param_1[0xb]);
    }
    param_1[0x10] = 7;
    param_1[0xf] = 0;
    *(undefined2 *)(param_1 + 0xb) = 0;
    if (7 < (uint)param_1[9]) {
      FUN_0089120c(param_1[4]);
    }
    param_1[9] = 7;
    param_1[8] = 0;
    *(undefined2 *)(param_1 + 4) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x55);
  }
  return;
}

