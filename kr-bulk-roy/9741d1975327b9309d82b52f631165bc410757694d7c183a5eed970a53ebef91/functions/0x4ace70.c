
undefined4 FUN_004ace70(int *param_1)

{
  code *pcVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  double local_1c;
  undefined8 local_14;
  int local_c;
  int local_8;
  
  pcVar1 = DAT_00fe184c;
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_004acecd:
    local_14 = *pdVar3;
    local_c = (int)ROUND(local_14);
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_14;
      if (iVar4 != 0) {
        local_14 = (double)CONCAT44(local_14._4_4_,3);
        local_1c = dVar2;
        pdVar3 = &local_1c;
        goto LAB_004acecd;
      }
    }
    local_c = 0;
  }
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_004acf18:
    local_8 = (int)ROUND(*pdVar3);
    local_14 = (double)CONCAT44(local_8,SUB84(*pdVar3,0));
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_14;
      if (iVar4 != 0) {
        local_14 = (double)CONCAT44(local_14._4_4_,3);
        local_1c = dVar2;
        pdVar3 = &local_1c;
        goto LAB_004acf18;
      }
    }
    local_14 = (double)((ulonglong)local_14 & 0xffffffff);
  }
  iVar4 = *param_1;
  iVar5 = *(int *)(iVar4 + 8);
  if (*(int *)(iVar5 + -0x28) != 4) {
    iVar5 = FUN_006fb5d0();
    if (iVar5 == 0) {
      iVar4 = 0;
      goto LAB_004acf73;
    }
    if (*(uint *)(*(int *)(iVar4 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar4 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar5 = *(int *)(iVar4 + 8);
  }
  iVar4 = *(int *)(iVar5 + -0x30) + 0x10;
LAB_004acf73:
  (*pcVar1)(iVar4,local_14._4_4_,local_c);
  return 0;
}

