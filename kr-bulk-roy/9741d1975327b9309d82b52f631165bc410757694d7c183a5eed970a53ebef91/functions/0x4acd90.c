
undefined4 FUN_004acd90(undefined4 param_1,code *param_2)

{
  double *pdVar1;
  int iVar2;
  double local_28;
  double local_20;
  undefined4 local_18;
  undefined8 local_14;
  undefined4 local_c;
  int iStack_8;
  
  local_18 = DAT_00fe1804;
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004acde0:
    local_14 = (double)CONCAT44((int)ROUND(*pdVar1),SUB84(*pdVar1,0));
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_20 = (double)CONCAT44(local_20._4_4_,3);
        local_28 = local_14;
        pdVar1 = &local_28;
        goto LAB_004acde0;
      }
    }
    local_14 = (double)((ulonglong)local_14 & 0xffffffff);
  }
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) != 3) {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_28 = (double)CONCAT44(iStack_8,local_c);
        local_20 = (double)CONCAT44(local_20._4_4_,3);
        pdVar1 = &local_28;
        goto LAB_004ace2b;
      }
    }
    (*param_2)(0,local_14._4_4_);
    return 0;
  }
LAB_004ace2b:
  local_20 = *pdVar1;
  iStack_8 = (int)ROUND(local_20);
  (*param_2)(iStack_8,local_14._4_4_);
  return 0;
}

