
void FUN_006520e0(int *param_1)

{
  float fVar1;
  int iVar2;
  
  fVar1 = (float)param_1[0x50] + 0.033333335;
  param_1[0x50] = (int)fVar1;
  if ((int)fVar1 != param_1[0x51]) {
    if ((int)fVar1 < 10) {
      iVar2 = param_1[0x3c];
      if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
        iVar2 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
        if (iVar2 == 0xbf6b) {
          FUN_0077b200();
        }
      }
      (**(code **)(*(int *)param_1[0x3c] + 200))();
    }
    else {
      (**(code **)(*param_1 + 0xd4))();
    }
    param_1[0x51] = (int)fVar1;
  }
  param_1 = param_1 + 0x3e;
  iVar2 = 4;
  do {
    if (*(int *)(*param_1 + 0x25c) != 0) {
      FUN_005dfba0(*param_1);
    }
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

