
void FUN_0050ec70(int *param_1)

{
  char cVar1;
  int *piVar2;
  
  cVar1 = *(char *)((int)param_1 + 0x69);
  while (cVar1 == '\0') {
    FUN_0050ec70(param_1[2]);
    piVar2 = (int *)*param_1;
    if (param_1[0x16] != 0) {
      FUN_0089120c(param_1[0x16]);
    }
    param_1[0x16] = 0;
    param_1[0x17] = 0;
    param_1[0x18] = 0;
    if (7 < (uint)param_1[0x14]) {
      FUN_0089120c(param_1[0xf]);
    }
    param_1[0x14] = 7;
    param_1[0x13] = 0;
    *(undefined2 *)(param_1 + 0xf) = 0;
    if (7 < (uint)param_1[0xb]) {
      FUN_0089120c(param_1[6]);
    }
    param_1[0xb] = 7;
    param_1[10] = 0;
    *(undefined2 *)(param_1 + 6) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x69);
  }
  return;
}

