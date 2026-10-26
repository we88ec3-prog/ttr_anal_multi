
undefined4 FUN_0055c940(void)

{
  uint uVar1;
  double *pdVar2;
  int iVar3;
  int local_48;
  undefined4 uStack_44;
  int local_40;
  undefined4 uStack_3c;
  int local_38;
  undefined4 uStack_34;
  double local_28;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00938d6e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffa8;
  ExceptionList = &local_14;
  pdVar2 = (double *)FUN_006f50f0(uVar1);
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055c9b6:
    local_48 = (int)ROUND(*pdVar2);
    local_38 = local_48;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_28 = (double)CONCAT44(uStack_34,local_38);
        local_20 = 3;
        pdVar2 = &local_28;
        goto LAB_0055c9b6;
      }
    }
    local_38 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0(uVar1);
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055ca13:
    local_48 = (int)ROUND(*pdVar2);
    local_40 = local_48;
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_28 = (double)CONCAT44(uStack_3c,local_40);
        local_20 = 3;
        pdVar2 = &local_28;
        goto LAB_0055ca13;
      }
    }
    local_40 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055ca68:
    local_48 = (int)ROUND(*pdVar2);
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = (double)CONCAT44(uStack_44,local_48);
      pdVar2 = &local_28;
      goto LAB_0055ca68;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cab5:
    local_48 = (int)ROUND(*pdVar2);
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = (double)CONCAT44(uStack_44,local_48);
      pdVar2 = &local_28;
      goto LAB_0055cab5;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cb02:
    local_48 = (int)ROUND(*pdVar2);
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = (double)CONCAT44(uStack_44,local_48);
      pdVar2 = &local_28;
      goto LAB_0055cb02;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cb57:
    local_48 = (int)ROUND(*pdVar2);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = (double)CONCAT44(uStack_44,local_48);
        pdVar2 = &local_28;
        goto LAB_0055cb57;
      }
    }
    local_48 = 0;
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cbac:
    local_28 = *pdVar2;
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      pdVar2 = &local_28;
      goto LAB_0055cbac;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055cbf9:
    local_28 = *pdVar2;
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      pdVar2 = &local_28;
      goto LAB_0055cbf9;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) != 3) {
    if (*(int *)(pdVar2 + 1) != 4) goto LAB_0055cc52;
    iVar3 = FUN_006f7760();
    if (iVar3 == 0) goto LAB_0055cc52;
    local_20 = 3;
    pdVar2 = &local_28;
  }
  local_28 = *pdVar2;
LAB_0055cc52:
  if ((DAT_00fe1ee8 & 1) == 0) {
    DAT_00fe1ee8 = DAT_00fe1ee8 | 1;
    local_c = 0;
    FUN_0055c610();
    _atexit((_func_4879 *)&LAB_00bcf290);
    local_c = 0xffffffff;
  }
  FUN_0055c810(&DAT_00fe1eec,local_38,local_40,local_48);
  ExceptionList = local_14;
  return 0;
}

