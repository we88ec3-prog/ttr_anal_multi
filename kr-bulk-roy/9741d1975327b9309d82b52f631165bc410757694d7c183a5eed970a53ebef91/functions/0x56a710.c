
undefined4 FUN_0056a710(int *param_1)

{
  float fVar1;
  double *pdVar2;
  int iVar3;
  double local_64;
  double local_5c;
  double local_54;
  double local_4c;
  code *local_44;
  undefined4 local_40;
  undefined8 local_3c;
  float local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int iStack_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_44 = DAT_00fe27a4;
  local_40 = DAT_00fe2778;
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a76d:
    local_54 = *pdVar2;
    local_24 = (int)ROUND(local_54);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_54;
        pdVar2 = &local_64;
        goto LAB_0056a76d;
      }
    }
    local_24 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a7c0:
    local_54 = *pdVar2;
    local_28 = (int)ROUND(local_54);
    local_8 = local_28;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_54;
        pdVar2 = &local_64;
        goto LAB_0056a7c0;
      }
    }
    local_28 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a813:
    local_54 = *pdVar2;
    local_2c = (int)ROUND(local_54);
    local_c = local_2c;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_54;
        pdVar2 = &local_64;
        goto LAB_0056a813;
      }
    }
    local_2c = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a866:
    local_54 = *pdVar2;
    local_30 = (int)ROUND(local_54);
    local_10 = local_30;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_54;
        pdVar2 = &local_64;
        goto LAB_0056a866;
      }
    }
    local_30 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a8b9:
    local_54 = *pdVar2;
    local_14 = (int)ROUND(*pdVar2);
    local_34 = (float)local_14;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_54;
        pdVar2 = &local_64;
        goto LAB_0056a8b9;
      }
    }
    local_34 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x58);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x60);
  if (iVar3 == 3) {
LAB_0056a908:
    local_4c = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_54;
        pdVar2 = &local_64;
        goto LAB_0056a908;
      }
    }
    local_4c = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x68);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x70);
  if (iVar3 == 3) {
LAB_0056a94b:
    local_54 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_54;
        pdVar2 = &local_64;
        goto LAB_0056a94b;
      }
    }
    local_54 = 0.0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a992:
    local_18 = (int)ROUND(*pdVar2);
    local_3c = (double)CONCAT44(local_18,SUB84(*pdVar2,0));
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        local_64 = local_3c;
        pdVar2 = &local_64;
        goto LAB_0056a992;
      }
    }
    local_3c = (double)((ulonglong)local_3c & 0xffffffff);
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a9e5:
    local_5c = *pdVar2;
    iVar3 = (int)ROUND(local_5c);
    iStack_1c = iVar3;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_64 = (double)CONCAT44(iStack_1c,local_20);
        local_5c = (double)CONCAT44(local_5c._4_4_,3);
        pdVar2 = &local_64;
        goto LAB_0056a9e5;
      }
    }
    iVar3 = 0;
  }
  fVar1 = local_34;
  local_34 = (float)local_54;
  (*local_44)(iVar3,local_3c._4_4_,local_34,(float)local_4c,fVar1,local_30,local_2c,local_28,
              local_24);
  return 0;
}

