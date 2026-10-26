
undefined4 FUN_004acbf0(void)

{
  double *pdVar1;
  int iVar2;
  double local_34;
  double local_2c;
  code *local_24;
  undefined4 local_20;
  undefined8 local_1c;
  int local_14;
  undefined4 local_10;
  int iStack_c;
  int local_8;
  
  local_24 = DAT_00fe1814;
  local_20 = DAT_00fe1804;
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004acc4d:
    local_1c = *pdVar1;
    local_14 = (int)ROUND(local_1c);
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_2c = (double)CONCAT44(local_2c._4_4_,3);
        local_34 = local_1c;
        pdVar1 = &local_34;
        goto LAB_004acc4d;
      }
    }
    local_14 = 0;
  }
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004acca0:
    local_8 = (int)ROUND(*pdVar1);
    local_1c = (double)CONCAT44(local_8,SUB84(*pdVar1,0));
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_2c = (double)CONCAT44(local_2c._4_4_,3);
        local_34 = local_1c;
        pdVar1 = &local_34;
        goto LAB_004acca0;
      }
    }
    local_1c = (double)((ulonglong)local_1c & 0xffffffff);
  }
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004acceb:
    local_2c = *pdVar1;
    iVar2 = (int)ROUND(local_2c);
    iStack_c = iVar2;
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_34 = (double)CONCAT44(iStack_c,local_10);
        local_2c = (double)CONCAT44(local_2c._4_4_,3);
        pdVar1 = &local_34;
        goto LAB_004acceb;
      }
    }
    iVar2 = 0;
  }
  (*local_24)(iVar2,local_1c._4_4_,local_14);
  return 0;
}

