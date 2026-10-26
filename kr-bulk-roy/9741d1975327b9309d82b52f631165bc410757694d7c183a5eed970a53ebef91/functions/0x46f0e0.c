
void FUN_0046f0e0(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x51);
  while (cVar1 == '\0') {
    FUN_0046f0e0(param_1[2]);
    piVar2 = (int *)*param_1;
    if (0xf < (uint)param_1[0x11]) {
      FUN_0089120c(param_1[0xc]);
    }
    param_1[0x11] = 0xf;
    param_1[0x10] = 0;
    *(undefined1 *)(param_1 + 0xc) = 0;
    if (0xf < (uint)param_1[10]) {
      FUN_0089120c(param_1[5]);
    }
    param_1[10] = 0xf;
    param_1[9] = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x51);
  }
  return;
}

