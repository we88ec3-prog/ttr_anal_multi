
void FUN_0051b5c0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x45);
  while (cVar1 == '\0') {
    FUN_0051b5c0(param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[0xf]) {
      FUN_0089120c(param_1[10]);
    }
    param_1[0xf] = 7;
    param_1[0xe] = 0;
    *(undefined2 *)(param_1 + 10) = 0;
    if (7 < (uint)param_1[8]) {
      FUN_0089120c(param_1[3]);
    }
    param_1[8] = 7;
    param_1[7] = 0;
    *(undefined2 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x45);
  }
  return;
}

