
undefined4 FUN_0056b2e0(int *param_1)

{
  code *pcVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  double local_3c;
  undefined8 local_34;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  pcVar1 = DAT_00fe281c;
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b33d:
    local_34 = *pdVar3;
    local_1c = (int)ROUND(local_34);
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_34;
      if (iVar4 != 0) {
        local_34 = (double)CONCAT44(local_34._4_4_,3);
        local_3c = dVar2;
        pdVar3 = &local_3c;
        goto LAB_0056b33d;
      }
    }
    local_1c = 0;
  }
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b390:
    local_34 = *pdVar3;
    local_20 = (int)ROUND(local_34);
    local_8 = local_20;
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_34;
      if (iVar4 != 0) {
        local_34 = (double)CONCAT44(local_34._4_4_,3);
        local_3c = dVar2;
        pdVar3 = &local_3c;
        goto LAB_0056b390;
      }
    }
    local_20 = 0;
  }
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b3e3:
    local_34 = *pdVar3;
    local_24 = (int)ROUND(local_34);
    local_c = local_24;
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_34;
      if (iVar4 != 0) {
        local_34 = (double)CONCAT44(local_34._4_4_,3);
        local_3c = dVar2;
        pdVar3 = &local_3c;
        goto LAB_0056b3e3;
      }
    }
    local_24 = 0;
  }
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b436:
    local_34 = *pdVar3;
    local_28 = (int)ROUND(local_34);
    local_10 = local_28;
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_34;
      if (iVar4 != 0) {
        local_34 = (double)CONCAT44(local_34._4_4_,3);
        local_3c = dVar2;
        pdVar3 = &local_3c;
        goto LAB_0056b436;
      }
    }
    local_28 = 0;
  }
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b489:
    local_34 = *pdVar3;
    local_2c = (int)ROUND(local_34);
    local_14 = local_2c;
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_34;
      if (iVar4 != 0) {
        local_34 = (double)CONCAT44(local_34._4_4_,3);
        local_3c = dVar2;
        pdVar3 = &local_3c;
        goto LAB_0056b489;
      }
    }
    local_2c = 0;
  }
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b4d8:
    local_18 = (int)ROUND(*pdVar3);
    local_34 = (double)CONCAT44(local_18,SUB84(*pdVar3,0));
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_34;
      if (iVar4 != 0) {
        local_34 = (double)CONCAT44(local_34._4_4_,3);
        local_3c = dVar2;
        pdVar3 = &local_3c;
        goto LAB_0056b4d8;
      }
    }
    local_34 = (double)((ulonglong)local_34 & 0xffffffff);
  }
  iVar4 = *param_1;
  iVar5 = *(int *)(iVar4 + 8);
  if (*(int *)(iVar5 + -0x68) != 4) {
    iVar5 = FUN_006fb5d0();
    if (iVar5 == 0) {
      iVar4 = 0;
      goto LAB_0056b566;
    }
    if (*(uint *)(*(int *)(iVar4 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar4 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar5 = *(int *)(iVar4 + 8);
  }
  iVar4 = *(int *)(iVar5 + -0x70) + 0x10;
LAB_0056b566:
  (*pcVar1)(iVar4,local_34._4_4_,local_2c,local_28,local_24,local_20,local_1c);
  return 0;
}

