
undefined4 * FUN_007c10e0(undefined4 *param_1,int *param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  int in_EAX;
  undefined4 *puVar5;
  
  puVar1 = (uint *)(param_3 + 0x10);
  if (*(int *)(in_EAX + 8) == 0) {
    FUN_007c1950(param_1,1,param_3);
    return param_1;
  }
  piVar2 = *(int **)(in_EAX + 4);
  if (param_2 == (int *)*piVar2) {
    if ((*(int *)(param_3 + 0x14) <= param_2[5]) &&
       ((*(int *)(param_3 + 0x14) < param_2[5] || (*puVar1 < (uint)param_2[4])))) {
      FUN_007c1950(param_1,1,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar2) {
    iVar3 = *(int *)(piVar2[2] + 0x14);
    if ((iVar3 <= *(int *)(param_3 + 0x14)) &&
       ((iVar3 < *(int *)(param_3 + 0x14) || (*(uint *)(piVar2[2] + 0x10) < *puVar1)))) {
      FUN_007c1950(param_1,0,param_3);
      return param_1;
    }
  }
  else {
    if ((*(int *)(param_3 + 0x14) <= param_2[5]) &&
       ((*(int *)(param_3 + 0x14) < param_2[5] || (*puVar1 < (uint)param_2[4])))) {
      FUN_00827b40();
      cVar4 = FUN_004dd480();
      if (cVar4 != '\0') {
        if (*(char *)(param_2[2] + 0x29) == '\0') {
          FUN_007c1950(param_1,1,param_3);
          return param_1;
        }
        FUN_007c1950(param_1,0,param_3);
        return param_1;
      }
    }
    cVar4 = FUN_004dd480();
    if ((cVar4 != '\0') &&
       ((FUN_0080f830(), param_2 == *(int **)(in_EAX + 4) || (cVar4 = FUN_004dd480(), cVar4 != '\0')
        ))) {
      if (*(char *)(param_2[2] + 0x29) == '\0') {
        FUN_007c1950(param_1,1,param_3);
        return param_1;
      }
      FUN_007c1950(param_1,0,param_3);
      return param_1;
    }
  }
  puVar5 = (undefined4 *)FUN_007c1850(in_EAX);
  *param_1 = *puVar5;
  return param_1;
}

