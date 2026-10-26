
undefined4 FUN_004acaa0(int *param_1)

{
  code *pcVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  double local_14;
  undefined8 local_c;
  
  pcVar1 = DAT_00fe180c;
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_004acaf5:
    local_c._4_4_ = (int)ROUND(*pdVar3);
    local_c._0_4_ = SUB84(*pdVar3,0);
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_c;
      if (iVar4 != 0) {
        local_c = (double)CONCAT44(local_c._4_4_,3);
        local_14 = dVar2;
        pdVar3 = &local_14;
        goto LAB_004acaf5;
      }
    }
    local_c._4_4_ = 0;
  }
  iVar4 = *param_1;
  iVar5 = *(int *)(iVar4 + 8);
  if (*(int *)(iVar5 + -0x18) != 4) {
    iVar5 = FUN_006fb5d0();
    if (iVar5 == 0) {
      (*pcVar1)(0,local_c._4_4_);
      return 0;
    }
    if (*(uint *)(*(int *)(iVar4 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar4 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar5 = *(int *)(iVar4 + 8);
  }
  (*pcVar1)(*(int *)(iVar5 + -0x20) + 0x10,local_c._4_4_);
  return 0;
}

