
int * FUN_00850540(int *param_1,int *param_2)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (param_1 != param_2) {
    iVar3 = param_2[1] - *param_2 >> 0x1f;
    iVar5 = (param_2[1] - *param_2) / 0x24 + iVar3;
    uVar4 = iVar5 - iVar3;
    if (iVar5 == iVar3) {
      if (*param_1 != param_1[1]) {
        iVar3 = FUN_008539a0(param_2);
        param_1[1] = iVar3;
        return param_1;
      }
    }
    else {
      uVar1 = (param_1[1] - *param_1) / 0x24;
      if (uVar4 <= uVar1) {
        FUN_008539a0(param_2);
        param_1[1] = *param_1 + ((param_2[1] - *param_2) / 0x24) * 0x24;
        return param_1;
      }
      if (uVar4 <= (uint)((param_1[2] - *param_1) / 0x24)) {
        iVar3 = *param_2;
        FUN_008539a0(param_2);
        iVar3 = FUN_00853e00(iVar3 + uVar1 * 0x24,param_2);
        param_1[1] = iVar3;
        return param_1;
      }
      if (*param_1 != 0) {
        FUN_0089120c(*param_1);
      }
      cVar2 = FUN_00850b70();
      if (cVar2 != '\0') {
        iVar3 = FUN_00853e00(*param_2,param_2);
        param_1[1] = iVar3;
      }
    }
  }
  return param_1;
}

