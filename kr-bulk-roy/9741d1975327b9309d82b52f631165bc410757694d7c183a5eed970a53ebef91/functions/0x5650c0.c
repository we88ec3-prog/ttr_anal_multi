
void FUN_005650c0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  
  piVar1 = (int *)FUN_00489c60();
  iVar2 = 0;
  piVar3 = piVar1;
  do {
    if (10 < *piVar3) {
      return;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 5;
  } while (iVar2 < 0x20);
  iVar2 = 0;
  piVar3 = piVar1;
  do {
    if (*piVar3 == 0) {
      piVar1 = piVar1 + iVar2 * 5;
      *piVar1 = 10;
      piVar1[1] = 0;
      if (param_1 == 0) {
        fVar4 = 40.0;
      }
      else {
        fVar4 = (float)param_1;
      }
      piVar1[2] = (int)fVar4;
      piVar1[3] = param_2;
      piVar1[4] = param_3;
      return;
    }
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 5;
  } while (iVar2 < 0x20);
  return;
}

