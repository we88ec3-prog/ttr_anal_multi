
void FUN_008b9440(int param_1,int *param_2)

{
  short *psVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = 0;
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    psVar1 = (short *)(param_1 + 2);
    if (*psVar1 == 0) {
      iVar7 = 0;
      param_1 = 0;
      iVar6 = 0;
    }
    else {
      piVar2 = *(int **)(param_1 + 4);
      iVar7 = *piVar2;
      iVar8 = piVar2[1];
      param_1 = iVar7;
      iVar6 = iVar8;
      piVar5 = piVar2;
      while (piVar4 = piVar5 + 2, piVar4 < piVar2 + *psVar1 * 2) {
        iVar3 = *piVar4;
        if (iVar3 < param_1) {
          param_1 = iVar3;
        }
        if (iVar7 < iVar3) {
          iVar7 = iVar3;
        }
        iVar3 = piVar5[3];
        if (iVar3 < iVar8) {
          iVar8 = iVar3;
        }
        piVar5 = piVar4;
        if (iVar6 < iVar3) {
          iVar6 = iVar3;
        }
      }
    }
    param_2[2] = iVar7;
    *param_2 = param_1;
    param_2[1] = iVar8;
    param_2[3] = iVar6;
  }
  return;
}

