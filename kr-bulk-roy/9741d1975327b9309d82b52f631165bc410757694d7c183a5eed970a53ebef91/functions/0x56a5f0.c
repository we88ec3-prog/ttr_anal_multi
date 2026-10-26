
undefined4 FUN_0056a5f0(int *param_1,code *param_2)

{
  float fVar1;
  double *pdVar2;
  int iVar3;
  double local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  double local_18;
  double local_10;
  undefined4 local_8;
  
  local_8 = DAT_00fe2778;
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -8);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x10);
  if (iVar3 == 3) {
LAB_0056a642:
    local_10 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_18;
        pdVar2 = &local_28;
        goto LAB_0056a642;
      }
    }
    local_10 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x18);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x20);
  if (iVar3 == 3) {
LAB_0056a685:
    local_18 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_18;
        pdVar2 = &local_28;
        goto LAB_0056a685;
      }
    }
    local_18 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x28);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x30);
  if (iVar3 == 3) {
LAB_0056a6c0:
    fVar1 = (float)*pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_28 = (double)CONCAT44(uStack_1c,local_20);
        local_20 = 3;
        pdVar2 = &local_28;
        goto LAB_0056a6c0;
      }
    }
    fVar1 = 0.0;
  }
  (*param_2)(fVar1,(float)local_18,(float)local_10);
  return 0;
}

