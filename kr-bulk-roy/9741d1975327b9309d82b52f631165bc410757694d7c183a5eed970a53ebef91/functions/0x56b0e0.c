
undefined4 FUN_0056b0e0(int *param_1)

{
  float fVar1;
  double *pdVar2;
  int iVar3;
  double local_34;
  double local_2c;
  code *local_24;
  undefined4 local_20;
  undefined8 local_1c;
  undefined8 local_14;
  undefined4 local_c;
  int iStack_8;
  
  local_24 = DAT_00fe27e4;
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x10);
  local_20 = DAT_00fe2778;
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -8);
  if (iVar3 == 3) {
LAB_0056b13b:
    local_1c = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_2c = (double)CONCAT44(local_2c._4_4_,3);
        local_34 = local_1c;
        pdVar2 = &local_34;
        goto LAB_0056b13b;
      }
    }
    local_1c = 0.0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056b182:
    local_14 = (double)CONCAT44((int)ROUND(*pdVar2),SUB84(*pdVar2,0));
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_2c = (double)CONCAT44(local_2c._4_4_,3);
        local_34 = local_14;
        pdVar2 = &local_34;
        goto LAB_0056b182;
      }
    }
    local_14 = (double)((ulonglong)local_14 & 0xffffffff);
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056b1cd:
    local_2c = *pdVar2;
    iVar3 = (int)ROUND(local_2c);
    iStack_8 = iVar3;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_34 = (double)CONCAT44(iStack_8,local_c);
        local_2c = (double)CONCAT44(local_2c._4_4_,3);
        pdVar2 = &local_34;
        goto LAB_0056b1cd;
      }
    }
    iVar3 = 0;
  }
  fVar1 = (float)local_1c;
  local_1c = (double)CONCAT44(fVar1,(undefined4)local_1c);
  (*local_24)(iVar3,local_14._4_4_,fVar1);
  return 0;
}

