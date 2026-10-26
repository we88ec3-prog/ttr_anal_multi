
undefined4 FUN_0056b210(int *param_1)

{
  float fVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  double local_24;
  double local_1c;
  code *local_14;
  undefined4 local_10;
  undefined8 local_c;
  
  local_14 = DAT_00fe27f0;
  pdVar3 = (double *)(*(int *)(*param_1 + 8) + -0x10);
  local_10 = DAT_00fe2778;
  iVar4 = *(int *)(*(int *)(*param_1 + 8) + -8);
  if (iVar4 == 3) {
LAB_0056b267:
    local_c = *pdVar3;
  }
  else {
    if (iVar4 == 4) {
      iVar4 = FUN_006f7760();
      if (iVar4 != 0) {
        local_1c = (double)CONCAT44(local_1c._4_4_,3);
        local_24 = local_c;
        pdVar3 = &local_24;
        goto LAB_0056b267;
      }
    }
    local_c = 0.0;
  }
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b2a6:
    local_1c = *pdVar3;
    iVar4 = (int)ROUND(local_1c);
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_1c;
      if (iVar4 != 0) {
        local_1c = (double)CONCAT44(local_1c._4_4_,3);
        local_24 = dVar2;
        pdVar3 = &local_24;
        goto LAB_0056b2a6;
      }
    }
    iVar4 = 0;
  }
  fVar1 = (float)local_c;
  local_c = (double)CONCAT44(fVar1,(undefined4)local_c);
  (*local_14)(iVar4,fVar1);
  return 0;
}

