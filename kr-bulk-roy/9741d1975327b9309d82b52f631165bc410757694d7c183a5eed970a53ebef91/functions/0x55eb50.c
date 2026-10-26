
undefined4 FUN_0055eb50(void)

{
  double *pdVar1;
  int iVar2;
  double local_2c;
  double local_24;
  code *local_1c;
  undefined4 local_18;
  undefined8 local_14;
  undefined4 local_c;
  int iStack_8;
  
  local_1c = DAT_00fe1f34;
  local_18 = DAT_00fe1f30;
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_0055eba9:
    local_14 = (double)CONCAT44((int)ROUND(*pdVar1),SUB84(*pdVar1,0));
  }
  else {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_24 = (double)CONCAT44(local_24._4_4_,3);
        local_2c = local_14;
        pdVar1 = &local_2c;
        goto LAB_0055eba9;
      }
    }
    local_14 = (double)((ulonglong)local_14 & 0xffffffff);
  }
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) != 3) {
    if (*(int *)(pdVar1 + 1) == 4) {
      iVar2 = FUN_006f7760();
      if (iVar2 != 0) {
        local_2c = (double)CONCAT44(iStack_8,local_c);
        local_24 = (double)CONCAT44(local_24._4_4_,3);
        pdVar1 = &local_2c;
        goto LAB_0055ebf4;
      }
    }
    (*local_1c)(0,local_14._4_4_);
    return 0;
  }
LAB_0055ebf4:
  local_24 = *pdVar1;
  iStack_8 = (int)ROUND(local_24);
  (*local_1c)(iStack_8,local_14._4_4_);
  return 0;
}

