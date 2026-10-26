
undefined4 FUN_004a2850(undefined4 param_1,code *param_2)

{
  double *pdVar1;
  int iVar2;
  double local_30;
  double local_28;
  undefined4 local_20;
  undefined8 local_1c;
  int local_14;
  undefined4 local_10;
  int iStack_c;
  int local_8;
  
  local_20 = DAT_00fe1778;
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004a28a4:
    local_1c = *pdVar1;
    local_14 = (int)ROUND(local_1c);
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_28 = (double)CONCAT44(local_28._4_4_,3);
        local_30 = local_1c;
        pdVar1 = &local_30;
        goto LAB_004a28a4;
      }
    }
    local_14 = 0;
  }
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004a28f7:
    local_8 = (int)ROUND(*pdVar1);
    local_1c = (double)CONCAT44(local_8,SUB84(*pdVar1,0));
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_28 = (double)CONCAT44(local_28._4_4_,3);
        local_30 = local_1c;
        pdVar1 = &local_30;
        goto LAB_004a28f7;
      }
    }
    local_1c = (double)((ulonglong)local_1c & 0xffffffff);
  }
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004a2942:
    local_28 = *pdVar1;
    iVar2 = (int)ROUND(local_28);
    iStack_c = iVar2;
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_30 = (double)CONCAT44(iStack_c,local_10);
        local_28 = (double)CONCAT44(local_28._4_4_,3);
        pdVar1 = &local_30;
        goto LAB_004a2942;
      }
    }
    iVar2 = 0;
  }
  (*param_2)(iVar2,local_1c._4_4_,local_14);
  return 0;
}

