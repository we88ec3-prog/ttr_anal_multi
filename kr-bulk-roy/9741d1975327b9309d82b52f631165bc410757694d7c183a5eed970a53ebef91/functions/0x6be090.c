
undefined4 FUN_006be090(int *param_1)

{
  double dVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  double local_28;
  double local_20;
  code *local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int iStack_8;
  
  local_14 = DAT_00fe3180;
  local_18 = DAT_00fe3184;
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -8);
  if ((iVar3 == 0) || ((iVar3 == 1 && (*(int *)(*(int *)(*param_1 + 8) + -0x10) == 0)))) {
    local_10 = 0;
  }
  else {
    local_10 = 1;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_006be114:
    local_20 = *pdVar2;
    iVar3 = (int)ROUND(local_20);
    iStack_8 = iVar3;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_28 = (double)CONCAT44(iStack_8,local_c);
        local_20 = (double)CONCAT44(local_20._4_4_,3);
        pdVar2 = &local_28;
        goto LAB_006be114;
      }
    }
    iVar3 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_006be15f:
    local_20 = *pdVar2;
    iVar4 = (int)ROUND(local_20);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar1 = local_20;
      if (iVar4 != 0) {
        local_20 = (double)CONCAT44(local_20._4_4_,3);
        local_28 = dVar1;
        pdVar2 = &local_28;
        goto LAB_006be15f;
      }
    }
    iVar4 = 0;
  }
  (*local_18)(iVar4,iVar3,local_10 != 0);
  return 0;
}

