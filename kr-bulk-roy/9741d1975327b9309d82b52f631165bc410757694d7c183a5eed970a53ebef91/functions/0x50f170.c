
undefined4 * FUN_0050f170(int param_1,undefined4 *param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  
  piVar1 = *(int **)(param_1 + 4);
  if (*(int *)(param_1 + 8) == 0) {
    FUN_0050f810(param_2,1,param_4);
    return param_2;
  }
  if (param_3 == (int *)*piVar1) {
    if ((*(int *)(param_4 + 0xc) < param_3[3]) ||
       ((*(int *)(param_4 + 0xc) <= param_3[3] && (*(int *)(param_4 + 0x10) < param_3[4])))) {
      FUN_0050f810(param_2,1,param_4);
      return param_2;
    }
  }
  else if (param_3 == piVar1) {
    iVar2 = *(int *)(piVar1[2] + 0xc);
    if ((iVar2 < *(int *)(param_4 + 0xc)) ||
       ((iVar2 <= *(int *)(param_4 + 0xc) && (*(int *)(piVar1[2] + 0x10) < *(int *)(param_4 + 0x10))
        ))) {
      FUN_0050f810(param_2,0,param_4);
      return param_2;
    }
  }
  else {
    if ((*(int *)(param_4 + 0xc) < param_3[3]) ||
       ((*(int *)(param_4 + 0xc) <= param_3[3] && (*(int *)(param_4 + 0x10) < param_3[4])))) {
      FUN_0050fc50();
      cVar3 = FUN_0050df20();
      if (cVar3 != '\0') {
        if (*(char *)(param_3[2] + 0x69) == '\0') {
          FUN_0050f810(param_2,1,param_4);
          return param_2;
        }
        FUN_0050f810(param_2,0,param_4);
        return param_2;
      }
    }
    cVar3 = FUN_0050df20();
    if ((cVar3 != '\0') &&
       ((FUN_0050ef20(), param_3 == *(int **)(param_1 + 4) ||
        (cVar3 = FUN_0050df20(), cVar3 != '\0')))) {
      if (*(char *)(param_3[2] + 0x69) == '\0') {
        FUN_0050f810(param_2,1,param_4);
        return param_2;
      }
      FUN_0050f810(param_2,0,param_4);
      return param_2;
    }
  }
  puVar4 = (undefined4 *)FUN_0050f720(param_1,param_4);
  *param_2 = *puVar4;
  return param_2;
}

