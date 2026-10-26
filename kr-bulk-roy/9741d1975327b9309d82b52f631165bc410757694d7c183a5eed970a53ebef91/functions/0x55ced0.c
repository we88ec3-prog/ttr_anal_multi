
undefined4 FUN_0055ced0(void)

{
  uint uVar1;
  double *pdVar2;
  int iVar3;
  undefined4 uVar4;
  int local_3c;
  int local_38;
  int local_34;
  undefined8 local_30;
  double local_28;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00938d3e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  pdVar2 = (double *)FUN_006f50f0(uVar1);
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cf46:
    local_30 = *pdVar2;
    local_34 = (int)ROUND(local_30);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_30;
        pdVar2 = &local_28;
        goto LAB_0055cf46;
      }
    }
    local_34 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0(uVar1);
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cf9b:
    local_30 = *pdVar2;
    local_38 = (int)ROUND(local_30);
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = local_30;
      pdVar2 = &local_28;
      goto LAB_0055cf9b;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cfe8:
    local_30 = *pdVar2;
    local_38 = (int)ROUND(local_30);
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = local_30;
      pdVar2 = &local_28;
      goto LAB_0055cfe8;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d035:
    local_30 = *pdVar2;
    local_38 = (int)ROUND(local_30);
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = local_30;
      pdVar2 = &local_28;
      goto LAB_0055d035;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d08a:
    local_30 = *pdVar2;
    local_38 = (int)ROUND(local_30);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_30;
        pdVar2 = &local_28;
        goto LAB_0055d08a;
      }
    }
    local_38 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d0e7:
    local_30 = *pdVar2;
    local_3c = (int)ROUND(local_30);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_30;
        pdVar2 = &local_28;
        goto LAB_0055d0e7;
      }
    }
    local_3c = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) != 3) {
    if (*(int *)(pdVar2 + 1) != 4) goto LAB_0055d148;
    iVar3 = FUN_006f7760();
    if (iVar3 == 0) goto LAB_0055d148;
    local_20 = 3;
    local_28 = local_30;
    pdVar2 = &local_28;
  }
  local_28 = *pdVar2;
  local_30 = (double)CONCAT44(local_30._4_4_,(int)ROUND(local_28));
LAB_0055d148:
  if ((DAT_00fe1ee8 & 1) == 0) {
    DAT_00fe1ee8 = DAT_00fe1ee8 | 1;
    local_c = 0;
    FUN_0055c610();
    _atexit((_func_4879 *)&LAB_00bcf290);
    local_c = 0xffffffff;
  }
  if (local_38 != 0) {
    if (local_3c < 0) {
      local_3c = 4;
    }
    local_30 = (double)(CONCAT44(local_30._4_4_,local_34) & 0xffffffff0000ffff);
    local_38 = local_3c;
    FUN_00826280(&local_30);
    if (local_34 != DAT_00fe1ef8) {
      iVar3 = *(int *)(local_34 + 0x10);
      uVar4 = FUN_0055e5b0(&local_38);
      FUN_00412b40(iVar3 + 4,uVar4);
    }
  }
  ExceptionList = local_14;
  return 0;
}

