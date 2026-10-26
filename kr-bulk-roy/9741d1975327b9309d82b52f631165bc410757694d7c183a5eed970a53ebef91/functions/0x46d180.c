
void FUN_0046d180(int param_1)

{
  int iVar1;
  int iVar2;
  char ****ppppcVar3;
  int in_ECX;
  int *piVar4;
  undefined1 *in_EDX;
  undefined1 local_a8 [12];
  undefined4 uStack_9c;
  int local_98;
  undefined2 *local_94;
  undefined1 auStack_7c [4];
  int local_78;
  undefined1 *local_74;
  uint local_70;
  undefined4 local_60;
  uint local_5c;
  char ***local_54 [4];
  int local_44;
  uint local_40;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  puStack_10 = &LAB_009414dc;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  local_40 = 0xf;
  local_44 = 0;
  local_54[0] = (char ***)((uint)local_54[0] & 0xffffff00);
  local_c = 0;
  local_78 = in_ECX;
  local_74 = in_EDX;
  if ((0x7fffffff < *(int *)(*(int *)(in_ECX + 0x1d4) + 0x14c) - 1U) &&
     (*(char *)(*(int *)(in_ECX + 0x1d4) + 0x141) != '\0')) {
    local_94 = (undefined2 *)0x46d1fe;
    FUN_006edb10();
  }
  if (local_74 == (undefined1 *)0x73) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 1;
      FUN_004e1590();
      local_94 = (undefined2 *)0x46d240;
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = (uint)local_c._1_3_ << 8;
    }
    if (DAT_00f942a8 == 1) {
      iVar2 = *(int *)(local_78 + 0x1d4);
      if (*(char *)(iVar2 + 0x141) != '\0') {
        local_94 = (undefined2 *)0x46d273;
        FUN_006edb10();
      }
      local_98 = iVar2 + 0x108;
      local_94 = (undefined2 *)0x0;
      local_70 = local_70 & 0xffff0000;
      local_5c = 7;
      local_60 = 0;
      uStack_9c = 0x46d29c;
      FUN_004026e0();
      local_94 = &DAT_00bed1fc;
      local_c = CONCAT31(local_c._1_3_,2);
      local_98 = 0;
      uStack_9c = 0x46d2b8;
      iVar2 = FUN_0044df20();
      if (iVar2 != 0) {
        local_94 = (undefined2 *)0x46d2d1;
        FUN_00761600();
      }
      local_c = local_c & 0xffffff00;
      if (7 < local_5c) {
LAB_0046d462:
        local_94 = (undefined2 *)0x46d467;
        FUN_0089120c();
      }
    }
    else {
      iVar2 = FUN_00404ba0();
      if (*(int *)(iVar2 + 0x68c8) == 2) {
        FUN_00762fb0();
      }
    }
  }
  else {
    iVar2 = *(int *)(local_78 + 0x1d4);
    if (*(char *)(iVar2 + 0x141) != '\0') {
      local_94 = (undefined2 *)0x46d330;
      FUN_006edb10();
    }
    if (0x31 < *(uint *)(iVar2 + 0x118)) {
      if (0xf < local_40) {
        local_94 = (undefined2 *)0x46d351;
        FUN_0089120c();
      }
      goto LAB_0046d664;
    }
    local_94 = (undefined2 *)0x46d361;
    FUN_0046c580();
    if (param_1 == 0) {
      local_94 = (undefined2 *)0x46d43d;
      FUN_0046e980();
      local_c._0_1_ = 5;
      local_94 = (undefined2 *)0x46d44f;
      FUN_00402bb0();
      local_c = (uint)local_c._1_3_ << 8;
      if (0xf < local_24) goto LAB_0046d462;
    }
    else {
      local_94 = (undefined2 *)0x46d375;
      FUN_0046e9f0();
      local_c._0_1_ = 3;
      local_94 = (undefined2 *)0x46d387;
      FUN_00402bb0();
      local_c = (uint)local_c._1_3_ << 8;
      if (0xf < local_24) {
        local_94 = (undefined2 *)0x46d3a3;
        FUN_0089120c();
      }
      local_94 = (undefined2 *)0x46d3bf;
      iVar2 = FUN_00407e70();
      if (iVar2 == 0 && local_44 == 0) {
        local_94 = (undefined2 *)0x46d3e6;
        FUN_0046c580();
        local_94 = (undefined2 *)0x46d3f1;
        FUN_0046e980();
        local_c._0_1_ = 4;
        local_94 = (undefined2 *)0x46d403;
        FUN_00402bb0();
        local_c = (uint)local_c._1_3_ << 8;
        FUN_00402c50();
        ppppcVar3 = (char ****)local_54[0];
        if (local_40 < 0x10) {
          ppppcVar3 = local_54;
        }
        local_94 = (undefined2 *)0x46d429;
        _toupper((int)*(char *)ppppcVar3);
        local_94 = (undefined2 *)0x46d436;
        FUN_0046de20();
      }
    }
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 6;
    FUN_004e1590();
    local_94 = (undefined2 *)0x46d491;
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = (uint)local_c._1_3_ << 8;
  }
  iVar2 = local_78;
  if (DAT_00f942a8 == 1) {
    iVar1 = *(int *)(local_78 + 0x1d4);
    if (*(char *)(iVar1 + 0x141) != '\0') {
      local_94 = (undefined2 *)0x46d526;
      FUN_006edb10();
    }
    local_98 = iVar1 + 0x108;
    local_94 = (undefined2 *)0x0;
    local_5c = 7;
    local_60 = 0;
    local_70 = local_70 & 0xffff0000;
    uStack_9c = 0x46d550;
    FUN_004026e0();
    local_74 = local_a8;
    local_c._0_1_ = 7;
    local_94 = (undefined2 *)0xf;
    local_98 = 0;
    local_a8[0] = 0;
    FUN_00403040(local_54,0,0xffffffff);
    local_98 = FUN_0046e3c0();
    local_94 = (undefined2 *)0x0;
    local_c._0_1_ = 8;
    uStack_9c = 0x46d59b;
    FUN_004041f0();
    local_c = CONCAT31(local_c._1_3_,7);
    if (7 < local_24) {
      local_94 = (undefined2 *)0x46d5b4;
      FUN_0089120c();
    }
    local_24 = 7;
    local_28 = 0;
    local_38 = local_38 & 0xffff0000;
    iVar2 = *(int *)(iVar2 + 0x1d4);
    if (*(char *)(iVar2 + 0x141) == '\0') {
      FUN_00757710();
    }
    else {
      local_94 = (undefined2 *)0x46d5ed;
      FUN_006edb10();
    }
    *(undefined4 *)(iVar2 + 0x168) = 0;
    *(undefined4 *)(iVar2 + 0x160) = 0;
    *(undefined4 *)(iVar2 + 0x164) = 0;
    *(undefined4 *)(iVar2 + 0x14c) = 0;
    piVar4 = *(int **)(local_78 + 0x1d4);
LAB_0046d61f:
    (**(code **)(*piVar4 + 200))();
    if (7 < local_5c) {
      local_94 = (undefined2 *)0x46d63a;
      FUN_0089120c();
    }
  }
  else if (DAT_00f942a8 == 2) {
    local_74 = local_a8;
    local_94 = (undefined2 *)0xf;
    local_98 = 0;
    local_a8[0] = 0;
    FUN_00403040(local_54,0,0xffffffff);
    FUN_0046e3c0();
    local_c = CONCAT31(local_c._1_3_,9);
    local_94 = (undefined2 *)0x46d4ff;
    FUN_00761430();
    piVar4 = *(int **)(local_78 + 0x1d4);
    goto LAB_0046d61f;
  }
  if (0xf < local_40) {
    local_94 = (undefined2 *)0x46d65f;
    FUN_0089120c();
  }
LAB_0046d664:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

