
undefined4 FUN_004a2460(int *param_1)

{
  float fVar1;
  double *pdVar2;
  int iVar3;
  double local_38;
  double local_30;
  double local_28;
  double local_20;
  code *local_18;
  undefined4 local_14;
  float local_10;
  undefined4 local_c;
  int iStack_8;
  
  local_18 = DAT_00fe1788;
  local_14 = DAT_00fe1778;
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_004a24bd:
    local_28 = *pdVar2;
    local_10 = (float)(int)ROUND(*pdVar2);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_30 = (double)CONCAT44(local_30._4_4_,3);
        local_38 = local_28;
        pdVar2 = &local_38;
        goto LAB_004a24bd;
      }
    }
    local_10 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x18);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x20);
  if (iVar3 == 3) {
LAB_004a250c:
    local_20 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_30 = (double)CONCAT44(local_30._4_4_,3);
        local_38 = local_28;
        pdVar2 = &local_38;
        goto LAB_004a250c;
      }
    }
    local_20 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x28);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x30);
  if (iVar3 == 3) {
LAB_004a254f:
    local_28 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_30 = (double)CONCAT44(local_30._4_4_,3);
        local_38 = local_28;
        pdVar2 = &local_38;
        goto LAB_004a254f;
      }
    }
    local_28 = 0.0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_004a258e:
    local_30 = *pdVar2;
    iVar3 = (int)ROUND(local_30);
    iStack_8 = iVar3;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_38 = (double)CONCAT44(iStack_8,local_c);
        local_30 = (double)CONCAT44(local_30._4_4_,3);
        pdVar2 = &local_38;
        goto LAB_004a258e;
      }
    }
    iVar3 = 0;
  }
  fVar1 = local_10;
  local_10 = (float)local_28;
  (*local_18)(iVar3,local_10,(float)local_20,fVar1);
  return 0;
}

