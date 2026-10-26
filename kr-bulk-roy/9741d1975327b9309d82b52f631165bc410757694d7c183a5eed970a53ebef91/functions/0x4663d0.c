
void FUN_004663d0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x4d);
  while (cVar1 == '\0') {
    FUN_004663d0(param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[0xc]) {
      FUN_0089120c(param_1[7]);
    }
    param_1[0xc] = 7;
    param_1[0xb] = 0;
    *(undefined2 *)(param_1 + 7) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x4d);
  }
  return;
}

