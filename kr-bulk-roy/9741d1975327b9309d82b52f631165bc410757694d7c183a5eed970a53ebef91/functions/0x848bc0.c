
int * FUN_00848bc0(int *param_1,int *param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 != param_2) {
    iVar3 = *param_2;
    uVar4 = param_2[1] - iVar3 >> 3;
    if (uVar4 == 0) {
      FUN_00848ca0();
      return param_1;
    }
    iVar1 = *param_1;
    uVar5 = param_1[1] - iVar1 >> 3;
    if (uVar4 <= uVar5) {
      FUN_00848e60();
      param_1[1] = *param_1 + (param_2[1] - *param_2 >> 3) * 8;
      return param_1;
    }
    if (uVar4 <= (uint)(param_1[2] - iVar1 >> 3)) {
      FUN_00848e60();
      iVar3 = FUN_00848d40(iVar3 + uVar5 * 8,param_2);
      param_1[1] = iVar3;
      return param_1;
    }
    if (iVar1 != 0) {
      FUN_0089120c(iVar1);
    }
    cVar2 = FUN_004bb3e0();
    if (cVar2 != '\0') {
      iVar3 = FUN_00848d40(*param_2,param_2);
      param_1[1] = iVar3;
    }
  }
  return param_1;
}

