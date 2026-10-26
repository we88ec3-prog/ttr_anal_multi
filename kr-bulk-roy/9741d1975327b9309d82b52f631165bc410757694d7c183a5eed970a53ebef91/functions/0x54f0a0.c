
undefined4 FUN_0054f0a0(int *param_1)

{
  double dVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  double local_2c;
  double local_24;
  double local_1c;
  double local_14;
  code *local_c;
  undefined4 local_8;
  
  local_c = DAT_00fe1e30;
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x10);
  local_8 = DAT_00fe1e28;
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -8);
  if (iVar3 == 3) {
LAB_0054f0fb:
    local_14 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      dVar1 = local_24;
      if (iVar3 != 0) {
        local_24 = (double)CONCAT44(local_24._4_4_,3);
        local_2c = dVar1;
        pdVar2 = &local_2c;
        goto LAB_0054f0fb;
      }
    }
    local_14 = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x18);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x20);
  if (iVar3 == 3) {
LAB_0054f13a:
    local_1c = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      dVar1 = local_24;
      if (iVar3 != 0) {
        local_24 = (double)CONCAT44(local_24._4_4_,3);
        local_2c = dVar1;
        pdVar2 = &local_2c;
        goto LAB_0054f13a;
      }
    }
    local_1c = 0.0;
  }
  iVar3 = *(int *)(*(int *)(*param_1 + 8) + -0x28);
  pdVar2 = (double *)(*(int *)(*param_1 + 8) + -0x30);
  if (iVar3 == 3) {
LAB_0054f175:
    local_24 = *pdVar2;
  }
  else {
    if (iVar3 == 4) {
      iVar3 = FUN_006f7760();
      dVar1 = local_24;
      if (iVar3 != 0) {
        local_24 = (double)CONCAT44(local_24._4_4_,3);
        local_2c = dVar1;
        pdVar2 = &local_2c;
        goto LAB_0054f175;
      }
    }
    local_24 = 0.0;
  }
  iVar3 = *param_1;
  iVar4 = *(int *)(iVar3 + 8);
  if (*(int *)(iVar4 + -0x38) != 4) {
    iVar4 = FUN_006fb5d0();
    if (iVar4 == 0) {
      iVar3 = 0;
      goto LAB_0054f1c1;
    }
    if (*(uint *)(*(int *)(iVar3 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar3 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar4 = *(int *)(iVar3 + 8);
  }
  iVar3 = *(int *)(iVar4 + -0x40) + 0x10;
LAB_0054f1c1:
  (*local_c)(iVar3,(float)local_24,(float)local_1c,(float)local_14);
  return 0;
}

