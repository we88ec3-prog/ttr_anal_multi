
undefined4 FUN_00702600(int param_1)

{
  double *pdVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  float10 extraout_ST0;
  int local_40;
  double local_38;
  double local_30;
  double local_18;
  undefined4 local_10;
  
  iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 0xc) >> 4;
  fVar6 = (float10)FUN_006f6290(param_1,1);
  local_30 = (double)fVar6;
  local_40 = 2;
  if (1 < iVar5) {
    do {
      pdVar1 = (double *)FUN_006f50f0();
      if (*(int *)(pdVar1 + 1) == 3) {
LAB_00702680:
        local_38 = *pdVar1;
        fVar7 = (float10)local_38;
        if ((float10)0 == fVar7) goto LAB_00702697;
      }
      else {
        if ((*(int *)(pdVar1 + 1) == 4) && (iVar2 = FUN_006f7760(), iVar2 != 0)) {
          local_10 = 3;
          pdVar1 = &local_18;
          goto LAB_00702680;
        }
        local_38 = 0.0;
LAB_00702697:
        iVar2 = FUN_006f50f0();
        fVar7 = extraout_ST0;
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
            FUN_006f5da0(local_40);
          }
          fVar7 = (float10)local_38;
        }
      }
      fVar6 = (float10)local_30;
      if (fVar6 < fVar7) {
        local_30 = (double)fVar7;
        fVar6 = fVar7;
      }
      local_40 = local_40 + 1;
    } while (local_40 <= iVar5);
  }
  pdVar1 = *(double **)(param_1 + 8);
  *pdVar1 = (double)fVar6;
  *(undefined4 *)(pdVar1 + 1) = 3;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  return 1;
}

