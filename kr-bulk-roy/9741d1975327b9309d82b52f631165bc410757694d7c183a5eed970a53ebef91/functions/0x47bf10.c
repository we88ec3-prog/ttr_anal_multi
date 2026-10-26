
void FUN_0047bf10(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x41);
  while (cVar1 == '\0') {
    FUN_0047bf10(param_1[2]);
    piVar2 = (int *)*param_1;
    if (0xf < (uint)param_1[0xe]) {
      FUN_0089120c(param_1[9]);
    }
    param_1[0xe] = 0xf;
    param_1[0xd] = 0;
    *(undefined1 *)(param_1 + 9) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x41);
  }
  return;
}

