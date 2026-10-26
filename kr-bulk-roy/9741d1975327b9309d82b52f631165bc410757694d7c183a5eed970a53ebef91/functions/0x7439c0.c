
undefined4 * FUN_007439c0(undefined4 *param_1,int *param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  char cVar4;
  int in_EAX;
  undefined4 *puVar5;
  
  puVar1 = (uint *)(param_3 + 0x10);
  if (*(int *)(in_EAX + 8) == 0) {
    FUN_00743c60(param_1,1,param_3);
    return param_1;
  }
  piVar2 = *(int **)(in_EAX + 4);
  if (param_2 == (int *)*piVar2) {
    if ((*(uint *)(param_3 + 0x14) <= (uint)param_2[5]) &&
       ((*(uint *)(param_3 + 0x14) < (uint)param_2[5] || (*puVar1 < (uint)param_2[4])))) {
      FUN_00743c60(param_1,1,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar2) {
    uVar3 = *(uint *)(piVar2[2] + 0x14);
    if ((uVar3 <= *(uint *)(param_3 + 0x14)) &&
       ((uVar3 < *(uint *)(param_3 + 0x14) || (*(uint *)(piVar2[2] + 0x10) < *puVar1)))) {
      FUN_00743c60(param_1,0,param_3);
      return param_1;
    }
  }
  else {
    if ((*(uint *)(param_3 + 0x14) <= (uint)param_2[5]) &&
       ((*(uint *)(param_3 + 0x14) < (uint)param_2[5] || (*puVar1 < (uint)param_2[4])))) {
      FUN_00743df0();
      cVar4 = FUN_00743960();
      if (cVar4 != '\0') {
        if (*(char *)(param_2[2] + 0x2819) == '\0') {
          FUN_00743c60(param_1,1,param_3);
          return param_1;
        }
        FUN_00743c60(param_1,0,param_3);
        return param_1;
      }
    }
    cVar4 = FUN_00743960();
    if ((cVar4 != '\0') &&
       ((FUN_00741b70(), param_2 == *(int **)(in_EAX + 4) || (cVar4 = FUN_00743960(), cVar4 != '\0')
        ))) {
      if (*(char *)(param_2[2] + 0x2819) == '\0') {
        FUN_00743c60(param_1,1,param_3);
        return param_1;
      }
      FUN_00743c60(param_1,0,param_3);
      return param_1;
    }
  }
  puVar5 = (undefined4 *)FUN_00743b70(in_EAX,param_3);
  *param_1 = *puVar5;
  return param_1;
}

