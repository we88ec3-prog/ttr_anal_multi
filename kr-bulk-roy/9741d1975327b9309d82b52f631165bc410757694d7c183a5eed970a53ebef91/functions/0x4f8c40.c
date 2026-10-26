
void FUN_004f8c40(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x45);
  while (cVar1 == '\0') {
    FUN_004f8c40(param_1[2]);
    piVar2 = (int *)*param_1;
    if (0xf < (uint)param_1[0xf]) {
      FUN_0089120c(param_1[10]);
    }
    param_1[0xf] = 0xf;
    param_1[0xe] = 0;
    *(undefined1 *)(param_1 + 10) = 0;
    if (0xf < (uint)param_1[8]) {
      FUN_0089120c(param_1[3]);
    }
    param_1[8] = 0xf;
    param_1[7] = 0;
    *(undefined1 *)(param_1 + 3) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x45);
  }
  return;
}

