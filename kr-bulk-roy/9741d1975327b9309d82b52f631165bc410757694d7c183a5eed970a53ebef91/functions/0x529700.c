
void FUN_00529700(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x4d);
  while (cVar1 == '\0') {
    FUN_00529700(param_1[2]);
    piVar2 = (int *)*param_1;
    if (7 < (uint)param_1[0x11]) {
      FUN_0089120c(param_1[0xc]);
    }
    param_1[0x11] = 7;
    param_1[0x10] = 0;
    *(undefined2 *)(param_1 + 0xc) = 0;
    if (7 < (uint)param_1[10]) {
      FUN_0089120c(param_1[5]);
    }
    param_1[10] = 7;
    param_1[9] = 0;
    *(undefined2 *)(param_1 + 5) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x4d);
  }
  return;
}

