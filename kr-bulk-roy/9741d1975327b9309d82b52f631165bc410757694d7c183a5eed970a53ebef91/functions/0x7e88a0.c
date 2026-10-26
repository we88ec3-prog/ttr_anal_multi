
void FUN_007e88a0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x59);
  while (cVar1 == '\0') {
    FUN_007e88a0(param_1[2]);
    piVar2 = (int *)*param_1;
    if (param_1[0x12] != 0) {
      FUN_0089120c(param_1[0x12]);
    }
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0x14] = 0;
    if (0xf < (uint)param_1[0x10]) {
      FUN_0089120c(param_1[0xb]);
    }
    param_1[0x10] = 0xf;
    param_1[0xf] = 0;
    *(undefined1 *)(param_1 + 0xb) = 0;
    if (0xf < (uint)param_1[8]) {
      FUN_0089120c(param_1[3]);
    }
    param_1[8] = 0xf;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x59);
  }
  return;
}

