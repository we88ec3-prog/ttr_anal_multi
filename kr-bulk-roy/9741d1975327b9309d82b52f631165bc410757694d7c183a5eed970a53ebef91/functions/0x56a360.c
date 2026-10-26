
undefined4 FUN_0056a360(int *param_1,code *param_2)

{
  double dVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  double local_14;
  undefined8 local_c;
  
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0056a3ac:
    local_c._4_4_ = (int)ROUND(*pdVar2);
    local_c._0_4_ = SUB84(*pdVar2,0);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      dVar1 = local_c;
      if (iVar3 != 0) {
        local_c = (double)CONCAT44(local_c._4_4_,3);
        local_14 = dVar1;
        pdVar2 = &local_14;
        goto LAB_0056a3ac;
      }
    }
    local_c._4_4_ = 0;
  }
  iVar3 = *param_1;
  iVar4 = *(int *)(iVar3 + 8);
  if (*(int *)(iVar4 + -0x18) != 4) {
    iVar4 = FUN_006fb5d0();
    if (iVar4 == 0) {
      (*param_2)(0,local_c._4_4_);
      return 0;
    }
    if (*(uint *)(*(int *)(iVar3 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar3 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar4 = *(int *)(iVar3 + 8);
  }
  (*param_2)(*(int *)(iVar4 + -0x20) + 0x10,local_c._4_4_);
  return 0;
}

