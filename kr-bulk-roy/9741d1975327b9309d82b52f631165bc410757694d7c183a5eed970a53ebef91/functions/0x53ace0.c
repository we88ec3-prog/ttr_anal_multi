
void FUN_0053ace0(undefined4 param_1)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  short *psVar6;
  undefined4 *in_EDX;
  undefined4 local_ac;
  int local_a8;
  int local_a4;
  undefined4 local_a0;
  uint local_8c;
  uint local_84;
  undefined4 local_74;
  uint local_70;
  undefined4 local_68;
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ff01;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar3;
  local_a8 = FUN_0053a9d0(param_1);
  if (local_a8 != 0) {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8 = 0;
      FUN_004f3d80(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_8 = 0xffffffff;
    }
    local_ac = 0x20;
    FUN_005740f0(&local_ac);
    if (local_a4 == DAT_00fe5aec) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_004f6a30(*in_EDX);
    psVar4 = (short *)FUN_004ed610();
    local_8 = 2;
    if (7 < *(uint *)(psVar4 + 10)) {
      psVar4 = *(short **)psVar4;
    }
    local_4c = (uint)local_4c._2_2_ << 0x10;
    local_38 = 7;
    local_3c = 0;
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 4;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_004d6b30(&local_4c);
    if (7 < local_38) {
      FUN_0089120c(local_4c);
    }
    local_8 = 0xffffffff;
    local_38 = 7;
    local_3c = 0;
    local_4c = local_4c & 0xffff0000;
    if (7 < local_8c) {
      FUN_0089120c(local_a0);
    }
    iVar5 = FUN_00404ba0();
    if (*(int *)(iVar5 + 0x5f4c) == 3) {
      for (iVar5 = *(int *)(local_a8 + 0x2c) - *(int *)(local_a8 + 0x28) >> 2; iVar5 != 0;
          iVar5 = iVar5 + -1) {
      }
      local_a8 = 0x1e;
      iVar5 = FUN_005855b0();
      FUN_005740f0(&local_a8);
      if (local_a4 == *(int *)(iVar5 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar4 = (short *)FUN_004068f0();
      local_8 = 5;
      if (7 < *(uint *)(psVar4 + 10)) {
        psVar4 = *(short **)psVar4;
      }
      local_30 = (uint)local_30._2_2_ << 0x10;
      local_1c = 7;
      local_20 = 0;
      psVar6 = psVar4;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 7;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_8 = CONCAT31(local_8._1_3_,6);
      FUN_004d6b30(&local_30);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_8 = 0xffffffff;
      local_1c = 7;
      local_20 = 0;
      local_30 = local_30 & 0xffff0000;
      if (7 < local_70) {
        FUN_0089120c(local_84);
      }
      local_70 = 7;
      local_74 = 0;
      local_84 = local_84 & 0xffff0000;
      local_a8 = 9;
      iVar5 = FUN_005855b0();
      FUN_005740f0(&local_a8);
      if (local_a4 == *(int *)(iVar5 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar4 = (short *)(local_a4 + 0x10);
      if (7 < *(uint *)(local_a4 + 0x24)) {
        psVar4 = *(short **)psVar4;
      }
      local_54 = 7;
      local_58 = 0;
      local_68 = (uint)local_68._2_2_ << 0x10;
      psVar6 = psVar4;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
      local_8 = 8;
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 9;
        local_8._1_3_ = 0;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = CONCAT31(local_8._1_3_,8);
      }
      FUN_004d6b30(&local_68);
      if (7 < local_54) {
        FUN_0089120c(local_68);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

