
undefined4 FUN_0056ac30(int *param_1)

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
  undefined8 local_20;
  int local_18;
  int local_14;
  undefined4 local_10;
  int iStack_c;
  int local_8;
  
  local_28 = DAT_00fe27dc;
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x10);
  local_24 = DAT_00fe2778;
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -8);
  if (iVar3 == 3) {
LAB_0056ac8b:
    local_20 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056ac8b;
      }
    }
    local_20 = 0.0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056acd2:
    local_38 = *pdVar2;
    local_14 = (int)ROUND(local_38);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056acd2;
      }
    }
    local_14 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056ad25:
    local_38 = *pdVar2;
    local_8 = (int)ROUND(*pdVar2);
    local_18 = local_8;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056ad25;
      }
    }
    local_18 = 0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x38);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x40);
  if (iVar3 == 3) {
LAB_0056ad74:
    local_30 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056ad74;
      }
    }
    local_30 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x48);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x50);
  if (iVar3 == 3) {
LAB_0056adb7:
    local_38 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        local_48 = local_38;
        pdVar2 = &local_48;
        goto LAB_0056adb7;
      }
    }
    local_38 = 0.0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056adfe:
    local_40 = *pdVar2;
    iVar3 = (int)ROUND(local_40);
    iStack_c = iVar3;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_48 = (double)CONCAT44(iStack_c,local_10);
        local_40 = (double)CONCAT44(local_40._4_4_,3);
        pdVar2 = &local_48;
        goto LAB_0056adfe;
      }
    }
    iVar3 = 0;
  }
  fVar1 = (float)local_20;
  local_20 = (double)CONCAT44((float)local_38,(undefined4)local_20);
  (*local_28)(iVar3,(float)local_38,(float)local_30,local_18,local_14,fVar1);
  return 0;
}

