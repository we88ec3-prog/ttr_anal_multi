
void FUN_00565a90(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x31);
  while (cVar1 == '\0') {
    FUN_00565a90(param_1[2]);
    piVar2 = (int *)*param_1;
    if (0xf < (uint)param_1[10]) {
      FUN_0089120c(param_1[5]);
    }
    param_1[10] = 0xf;
    param_1[9] = 0;
    *(undefined1 *)(param_1 + 5) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x31);
  }
  return;
}

