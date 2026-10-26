
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0046d690(void)

{
  char *pcVar1;
  undefined1 uVar2;
  char ****ppppcVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_c8 [16];
  undefined *local_b8;
  undefined ***local_b4;
  undefined **local_9c [3];
  undefined **local_90 [3];
  undefined4 local_84;
  undefined1 *local_80;
  int local_7c;
  char *local_78;
  int local_74;
  char *local_70;
  char local_6c;
  undefined1 local_68 [20];
  uint local_54;
  uint local_38;
  char ***local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009313b9;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_7c = in_ECX;
  local_84 = FUN_0046c580();
  local_70 = (char *)(in_ECX + 0xf4);
  local_74 = 0;
  do {
    local_1c = 0xf;
    local_20 = 0;
    local_30[0] = (char ***)((uint)local_30[0] & 0xffffff00);
    local_8._1_3_ = 0;
    if (((*(uint *)(*(int *)(in_ECX + 0x1bc) + 0x28) >> 9 & 1) == 0) &&
       ((*(uint *)(*(int *)(in_ECX + 0x1c0) + 0x28) >> 9 & 1) == 0)) {
      if ((DAT_00fc0d70 & 1) == 0) {
        DAT_00fc0d70 = DAT_00fc0d70 | 1;
        local_8._0_1_ = 9;
        local_8._1_3_ = 0;
        FUN_0046eb40();
        DAT_00fc0d84 = 0;
        DAT_00fc0d88 = 0;
        _DAT_00fc0d8c = 0;
        local_8._0_1_ = 0xb;
        FUN_0046e530();
        local_b4 = (undefined ***)0x46d764;
        _atexit((_func_4879 *)&LAB_00bcd920);
      }
      local_8._0_1_ = 0;
      local_b4 = (undefined ***)0x46d77a;
      FUN_0046e980();
      local_8._0_1_ = 0xc;
      local_b4 = (undefined ***)0x46d787;
      FUN_00402bb0();
      local_8._0_1_ = 0;
      uVar2 = (undefined1)local_8;
      local_8._0_1_ = 0;
      if (0xf < local_38) {
        local_b4 = (undefined ***)0x46d79d;
        FUN_0089120c();
        uVar2 = (undefined1)local_8;
      }
    }
    else {
      if ((DAT_00fc0d70 & 1) == 0) {
        DAT_00fc0d70 = DAT_00fc0d70 | 1;
        local_8._0_1_ = 1;
        local_8._1_3_ = 0;
        DAT_00fc0d7c = 0;
        local_b4 = (undefined ***)0x46d7cb;
        iVar4 = FUN_00891268();
        if (iVar4 == 0) {
          local_78 = (char *)0x0;
          local_b4 = (undefined ***)0x46dc70;
          std::exception::exception((exception *)local_90,&local_78);
          local_b4 = local_90;
          local_90[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          local_b8 = (undefined *)0x46dc8b;
          __CxxThrowException_8();
        }
        DAT_00fc0d78 = iVar4;
        *(int *)iVar4 = iVar4;
        *(int *)(DAT_00fc0d78 + 4) = DAT_00fc0d78;
        *(int *)(DAT_00fc0d78 + 8) = DAT_00fc0d78;
        *(undefined1 *)(DAT_00fc0d78 + 0x50) = 1;
        *(undefined1 *)(DAT_00fc0d78 + 0x51) = 1;
        DAT_00fc0d84 = 0;
        DAT_00fc0d88 = 0;
        _DAT_00fc0d8c = 0;
        local_8._0_1_ = 3;
        FUN_0046e530();
        local_b4 = (undefined ***)0x46d825;
        _atexit((_func_4879 *)&LAB_00bcd920);
      }
      local_8._0_1_ = 0;
      local_b4 = (undefined ***)0x46d83b;
      FUN_0046e9f0();
      local_8._0_1_ = 4;
      local_b4 = (undefined ***)0x46d848;
      FUN_00402bb0();
      local_8._0_1_ = 0;
      if (0xf < local_38) {
        local_b4 = (undefined ***)0x46d85e;
        FUN_0089120c();
      }
      local_b4 = (undefined ***)0x46d877;
      iVar4 = FUN_00407e70();
      uVar2 = (undefined1)local_8;
      if (iVar4 == 0 && local_20 == 0) {
        if ((DAT_00fc0d70 & 1) == 0) {
          DAT_00fc0d70 = DAT_00fc0d70 | 1;
          local_8._0_1_ = 5;
          FUN_0046eb40();
          DAT_00fc0d84 = 0;
          DAT_00fc0d88 = 0;
          _DAT_00fc0d8c = 0;
          local_8._0_1_ = 7;
          FUN_0046e530();
          local_b4 = (undefined ***)0x46d8da;
          _atexit((_func_4879 *)&LAB_00bcd920);
          local_8._0_1_ = 0;
        }
        local_b4 = (undefined ***)0x46d8f0;
        FUN_0046e980();
        local_8._0_1_ = 8;
        local_b4 = (undefined ***)0x46d8fd;
        FUN_00402bb0();
        local_8._0_1_ = 0;
        if (0xf < local_38) {
          local_b4 = (undefined ***)0x46d913;
          FUN_0089120c();
        }
        ppppcVar3 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar3 = local_30;
        }
        local_b4 = (undefined ***)0x46d92a;
        iVar4 = _toupper((int)*(char *)ppppcVar3);
        local_6c = (char)iVar4;
        if (local_1c == 0) {
          local_b4 = (undefined ***)0x1;
          local_b8 = (undefined *)0x46d947;
          FUN_00402dc0();
        }
        ppppcVar3 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar3 = local_30;
        }
        *(char *)ppppcVar3 = local_6c;
        local_20 = 1;
        ppppcVar3 = (char ****)local_30[0];
        if (local_1c < 0x10) {
          ppppcVar3 = local_30;
        }
        *(char *)((int)ppppcVar3 + 1) = '\0';
        uVar2 = (undefined1)local_8;
      }
    }
    local_8._0_1_ = uVar2;
    local_80 = local_c8;
    local_b4 = (undefined ***)0xf;
    local_b8 = (undefined *)0x0;
    local_c8[0] = 0;
    FUN_00403040(local_30,0,0xffffffff);
    FUN_0046e3c0();
    pcVar1 = local_70;
    local_8._0_1_ = 0xd;
    local_b4 = (undefined ***)0x46d9a8;
    FUN_00757800();
    local_8 = (uint)local_8._1_3_ << 8;
    if (7 < local_38) {
      local_b4 = (undefined ***)0x46d9ba;
      FUN_0089120c();
    }
    (**(code **)(**(int **)pcVar1 + 200))();
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      local_b4 = (undefined ***)0x46d9df;
      FUN_0089120c();
    }
    local_74 = local_74 + 0x40;
    local_70 = pcVar1 + 4;
    in_ECX = local_7c;
  } while (local_74 < 0xc80);
  if ((DAT_00fc0d70 & 1) == 0) {
    DAT_00fc0d70 = DAT_00fc0d70 | 1;
    local_8 = 0xe;
    DAT_00fc0d7c = 0;
    local_b4 = (undefined ***)0x46da24;
    iVar4 = FUN_00891268();
    if (iVar4 == 0) {
      local_78 = (char *)0x0;
      local_b4 = (undefined ***)0x46dc9d;
      std::exception::exception((exception *)local_90,&local_78);
      local_b4 = local_90;
      local_90[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      local_b8 = (undefined *)0x46dcb8;
      __CxxThrowException_8();
    }
    DAT_00fc0d78 = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(DAT_00fc0d78 + 4) = DAT_00fc0d78;
    *(int *)(DAT_00fc0d78 + 8) = DAT_00fc0d78;
    *(undefined1 *)(DAT_00fc0d78 + 0x50) = 1;
    *(undefined1 *)(DAT_00fc0d78 + 0x51) = 1;
    DAT_00fc0d84 = 0;
    DAT_00fc0d88 = 0;
    _DAT_00fc0d8c = 0;
    local_8 = CONCAT31(local_8._1_3_,0x10);
    FUN_0046e530();
    local_b4 = (undefined ***)0x46da7f;
    _atexit((_func_4879 *)&LAB_00bcd920);
    local_8 = 0xffffffff;
  }
  local_b4 = (undefined ***)0x46da9b;
  FUN_0046e980();
  local_80 = local_c8;
  local_8 = 0x11;
  local_b4 = (undefined ***)0xf;
  local_b8 = (undefined *)0x0;
  local_c8[0] = 0;
  FUN_00403040(local_68,0,0xffffffff);
  FUN_0046e3c0();
  iVar4 = local_7c;
  local_8._0_1_ = 0x12;
  local_b4 = (undefined ***)0x46dae5;
  FUN_00757800();
  local_8._0_1_ = 0x11;
  if (7 < local_38) {
    local_b4 = (undefined ***)0x46daf8;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(iVar4 + 0x1bc) + 200))();
  if ((DAT_00fc0d70 & 1) == 0) {
    DAT_00fc0d70 = DAT_00fc0d70 | 1;
    local_8._0_1_ = 0x13;
    DAT_00fc0d7c = 0;
    local_b4 = (undefined ***)0x46db2c;
    iVar4 = FUN_00891268();
    if (iVar4 == 0) {
      local_70 = (char *)0x0;
      local_b4 = (undefined ***)0x46dcca;
      std::exception::exception((exception *)local_9c,&local_70);
      local_b4 = local_9c;
      local_9c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      local_b8 = &UNK_0046dce5;
      __CxxThrowException_8();
    }
    DAT_00fc0d78 = iVar4;
    *(int *)iVar4 = iVar4;
    *(int *)(DAT_00fc0d78 + 4) = DAT_00fc0d78;
    *(int *)(DAT_00fc0d78 + 8) = DAT_00fc0d78;
    *(undefined1 *)(DAT_00fc0d78 + 0x50) = 1;
    *(undefined1 *)(DAT_00fc0d78 + 0x51) = 1;
    DAT_00fc0d84 = 0;
    DAT_00fc0d88 = 0;
    _DAT_00fc0d8c = 0;
    local_8._0_1_ = 0x15;
    FUN_0046e530();
    local_b4 = (undefined ***)0x46db87;
    _atexit((_func_4879 *)&LAB_00bcd920);
    local_8._0_1_ = 0x11;
  }
  local_b4 = (undefined ***)0x46dba0;
  FUN_0046e980();
  local_8._0_1_ = 0x16;
  local_b4 = (undefined ***)0x46dbad;
  FUN_00402bb0();
  local_8._0_1_ = 0x11;
  if (0xf < local_38) {
    local_b4 = (undefined ***)0x46dbc4;
    FUN_0089120c();
  }
  local_80 = local_c8;
  local_b4 = (undefined ***)0xf;
  local_b8 = (undefined *)0x0;
  local_c8[0] = 0;
  FUN_00403040(local_68,0,0xffffffff);
  FUN_0046e3c0();
  local_8._0_1_ = 0x17;
  local_b4 = (undefined ***)0x46dc0b;
  FUN_00757800();
  local_8 = CONCAT31(local_8._1_3_,0x11);
  if (7 < local_38) {
    local_b4 = (undefined ***)0x46dc1e;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(local_7c + 0x1c0) + 200))();
  if (0xf < local_54) {
    local_b4 = (undefined ***)0x46dc3f;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

