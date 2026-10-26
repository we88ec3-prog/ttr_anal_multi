
undefined4 FUN_0056ae80(int *param_1)

{
  float fVar1;
  double *pdVar2;
  int iVar3;
  double local_48;
  double local_40;
  double local_38;
  double local_30;
  code *local_28;
  undefined4 local_24;
  float local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int iStack_10;
  int local_c;
  int local_8;
  
  local_28 = DAT_00fe27e0;
  local_24 = DAT_00fe2778;
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056aedd:
    local_38 = *pdVar2;
    local_18 = (int)ROUND(local_38);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056aedd;
      }
    }
    local_18 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056af30:
    local_38 = *pdVar2;
    local_1c = (int)ROUND(local_38);
    local_8 = local_1c;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056af30;
      }
    }
    local_1c = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056af83:
    local_38 = *pdVar2;
    local_c = (int)ROUND(*pdVar2);
    local_20 = (float)local_c;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056af83;
      }
    }
    local_20 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x38);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x40);
  if (iVar3 == 3) {
LAB_0056afd2:
    local_30 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056afd2;
      }
    }
    local_30 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x48);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x50);
  if (iVar3 == 3) {
LAB_0056b015:
    local_38 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056b015;
      }
    }
    local_38 = 0.0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056b05c:
    local_40 = *pdVar2;
    iVar3 = (int)ROUND(local_40);
    iStack_10 = iVar3;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_48 = (double)CONCAT44(iStack_10,local_14);
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        pdVar2 = &local_48;
        goto LAB_0056b05c;
      }
    }
    iVar3 = 0;
  }
  fVar1 = local_20;
  local_20 = (float)local_38;
  (*local_28)(iVar3,local_20,(float)local_30,fVar1,local_1c,local_18);
  return 0;
}

