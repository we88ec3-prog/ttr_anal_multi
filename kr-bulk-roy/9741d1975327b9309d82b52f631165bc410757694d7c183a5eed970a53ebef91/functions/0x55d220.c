
undefined4 FUN_0055d220(void)

{
  uint uVar1;
  double *pdVar2;
  int iVar3;
  undefined4 uVar4;
  double local_40;
  undefined8 local_38;
  undefined8 local_30;
  double local_28;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00938d0e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb0;
  ExceptionList = &local_14;
  pdVar2 = (double *)FUN_006f50f0(uVar1);
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d296:
    iVar3 = (int)ROUND(*pdVar2);
    local_40 = (double)CONCAT44(local_40._4_4_,iVar3);
    local_30._4_4_ = (undefined4)((ulonglong)*pdVar2 >> 0x20);
    local_30 = (double)CONCAT44(local_30._4_4_,iVar3);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_30;
        pdVar2 = &local_28;
        goto LAB_0055d296;
      }
    }
    local_30 = (double)((ulonglong)local_30 & 0xffffffff00000000);
  }
  pdVar2 = (double *)FUN_006f50f0(uVar1);
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d2eb:
    local_40 = *pdVar2;
    local_38 = (double)CONCAT44(local_38._4_4_,(int)ROUND(local_40));
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = local_38;
      pdVar2 = &local_28;
      goto LAB_0055d2eb;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d338:
    local_40 = *pdVar2;
    local_38 = (double)CONCAT44(local_38._4_4_,(int)ROUND(local_40));
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = local_38;
      pdVar2 = &local_28;
      goto LAB_0055d338;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d385:
    local_40 = *pdVar2;
    local_38 = (double)CONCAT44(local_38._4_4_,(int)ROUND(local_40));
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = local_38;
      pdVar2 = &local_28;
      goto LAB_0055d385;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d3d2:
    local_40 = *pdVar2;
    local_38 = (double)CONCAT44(local_38._4_4_,(int)ROUND(local_40));
  }
  else if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_20 = 3;
      local_28 = local_38;
      pdVar2 = &local_28;
      goto LAB_0055d3d2;
    }
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d427:
    iVar3 = (int)ROUND(*pdVar2);
    local_40 = (double)CONCAT44(local_40._4_4_,iVar3);
    local_38._4_4_ = (undefined4)((ulonglong)*pdVar2 >> 0x20);
    local_38 = (double)CONCAT44(local_38._4_4_,iVar3);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_38;
        pdVar2 = &local_28;
        goto LAB_0055d427;
      }
    }
    local_38 = (double)((ulonglong)local_38 & 0xffffffff00000000);
  }
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055d482:
    local_28 = *pdVar2;
    iVar3 = (int)ROUND(local_28);
    local_40 = (double)CONCAT44(local_40._4_4_,iVar3);
  }
  else {
    if (*(int *)(pdVar2 + 1) == 4) {
      iVar3 = FUN_006f7760();
      if (iVar3 != 0) {
        local_20 = 3;
        local_28 = local_40;
        pdVar2 = &local_28;
        goto LAB_0055d482;
      }
    }
    iVar3 = 0;
  }
  if ((DAT_00fe1ee8 & 1) == 0) {
    DAT_00fe1ee8 = DAT_00fe1ee8 | 1;
    local_c = 0;
    FUN_0055c610();
    _atexit((_func_4879 *)&LAB_00bcf290);
    local_c = 0xffffffff;
  }
  if ((int)local_38 != 0) {
    if (iVar3 < 0) {
      iVar3 = 1;
    }
    local_40 = (double)CONCAT44(local_40._4_4_,iVar3);
    local_30 = (double)CONCAT44(local_30._4_4_,(uint)(ushort)local_30);
    FUN_00826280(&local_30);
    if ((int)local_38 != DAT_00fe1ef8) {
      iVar3 = *(int *)((int)local_38 + 0x10);
      uVar4 = FUN_0055e5b0(&local_40);
      FUN_00412b40(iVar3 + 4,uVar4);
    }
  }
  ExceptionList = local_14;
  return 0;
}

