
int FUN_006f6370(undefined4 param_1,undefined4 param_2)

{
  double *pdVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  double local_18;
  undefined4 local_10;
  
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) != 3) {
    if ((*(int *)(pdVar1 + 1) != 4) || (iVar2 = FUN_006f7760(), iVar2 == 0)) goto LAB_006f63e2;
    local_10 = 3;
    pdVar1 = &local_18;
  }
  local_18 = *pdVar1;
  if ((int)ROUND(local_18) != 0) {
    return (int)ROUND(local_18);
  }
LAB_006f63e2:
  iVar2 = FUN_006f50f0();
  if ((*(int *)(iVar2 + 8) != 3) &&
     ((*(int *)(iVar2 + 8) != 4 || (iVar2 = FUN_006f7760(), iVar2 == 0)))) {
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
  return 0;
}

