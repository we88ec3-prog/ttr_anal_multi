
float10 FUN_006f6290(undefined4 param_1,undefined4 param_2)

{
  double *pdVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  float10 extraout_ST0;
  double local_1c;
  undefined4 local_14;
  double local_c;
  
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) != 3) {
    if ((*(int *)(pdVar1 + 1) != 4) || (iVar2 = FUN_006f7760(), iVar2 == 0)) {
      local_c = 0.0;
      goto LAB_006f62ea;
    }
    local_14 = 3;
    local_1c = local_c;
    pdVar1 = &local_1c;
  }
  local_c = *pdVar1;
  if ((float10)0 != (float10)local_c) {
    return (float10)local_c;
  }
LAB_006f62ea:
  iVar2 = FUN_006f50f0();
  if (*(int *)(iVar2 + 8) != 3) {
    if ((*(int *)(iVar2 + 8) != 4) || (iVar2 = FUN_006f7760(), iVar2 == 0)) {
      puVar3 = (undefined4 *)FUN_006f50f0();
      if ((puVar3 == &DAT_00c0bfc8) || (puVar3[2] == -1)) {
        pcVar4 = "no value";
      }
      else {
        pcVar4 = (&PTR_DAT_00c0be1c)[puVar3[2]];
      }
      FUN_006f5580(param_1,"%s expected, got %s","number",pcVar4);
      FUN_006f5da0(param_2);
    }
    return (float10)local_c;
  }
  return extraout_ST0;
}

