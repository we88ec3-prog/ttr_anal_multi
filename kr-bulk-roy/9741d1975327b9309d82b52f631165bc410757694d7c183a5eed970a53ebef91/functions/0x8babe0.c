
int FUN_008babe0(int *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint local_8;
  
  local_8 = 0;
  if (param_1[5] == 0) {
    uVar3 = param_1[2];
    if ((uVar3 < (uint)param_1[1]) && (param_2 <= param_1[1] - uVar3)) {
      param_1[8] = *param_1 + uVar3;
      param_1[9] = *param_1 + uVar3 + param_2;
      param_1[2] = uVar3 + param_2;
      return 0;
    }
  }
  else {
    iVar1 = param_1[7];
    if (param_2 <= (uint)param_1[1]) {
      iVar2 = FUN_008b9f30(iVar1,param_2,&local_8);
      uVar3 = local_8;
      *param_1 = iVar2;
      if (local_8 == 0) {
        local_8 = (*(code *)param_1[5])(param_1,param_1[2],iVar2,param_2);
        if (local_8 < param_2) {
          FUN_008b9f80(iVar1,*param_1);
          *param_1 = 0;
          uVar3 = 0x55;
        }
        param_1[8] = *param_1;
        param_1[2] = param_1[2] + local_8;
        param_1[9] = *param_1 + param_2;
      }
      return uVar3;
    }
  }
  return 0x55;
}

