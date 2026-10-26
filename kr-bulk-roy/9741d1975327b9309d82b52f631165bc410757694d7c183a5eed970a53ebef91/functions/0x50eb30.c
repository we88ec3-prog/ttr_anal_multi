
void FUN_0050eb30(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x49);
  while (cVar1 == '\0') {
    FUN_0050eb30(param_1[2]);
    piVar2 = (int *)*param_1;
    FUN_007b6d70();
    FUN_0089120c(param_1[0xc]);
    param_1[0xc] = 0;
    if (7 < (uint)param_1[9]) {
      FUN_0089120c(param_1[4]);
    }
    param_1[9] = 7;
    param_1[8] = 0;
    *(undefined2 *)(param_1 + 4) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x49);
  }
  return;
}

