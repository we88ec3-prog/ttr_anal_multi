
void FUN_0051f280(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = *(char *)((int)param_1 + 0x51);
  while (cVar1 == '\0') {
    FUN_0051f280(param_1[2]);
    piVar2 = (int *)*param_1;
    iVar4 = param_1[0x10];
    if (iVar4 != 0) {
      iVar3 = param_1[0x11];
      for (; iVar4 != iVar3; iVar4 = iVar4 + 0x14) {
        if (*(int *)(iVar4 + 4) != 0) {
          FUN_0089120c(*(int *)(iVar4 + 4));
        }
        *(undefined4 *)(iVar4 + 4) = 0;
        *(undefined4 *)(iVar4 + 8) = 0;
        *(undefined4 *)(iVar4 + 0xc) = 0;
      }
      FUN_0089120c(param_1[0x10]);
    }
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    if (param_1[0xc] != 0) {
      FUN_0089120c(param_1[0xc]);
    }
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    if (7 < (uint)param_1[10]) {
      FUN_0089120c(param_1[5]);
    }
    param_1[10] = 7;
    param_1[9] = 0;
    *(undefined2 *)(param_1 + 5) = 0;
    FUN_0089120c(param_1);
    param_1 = piVar2;
    cVar1 = *(char *)((int)piVar2 + 0x51);
  }
  return;
}

