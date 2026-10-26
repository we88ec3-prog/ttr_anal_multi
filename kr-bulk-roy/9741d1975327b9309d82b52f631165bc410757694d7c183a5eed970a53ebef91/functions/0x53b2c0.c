
void FUN_0053b2c0(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  int in_ECX;
  int local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_54;
  uint local_40;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092f247;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_94;
  ExceptionList = &local_14;
  if (param_1 != 0) {
    if (in_ECX == 0) {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 5;
        FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xffffff60);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
      }
      if ((DAT_00fe5b08 & 1) == 0) {
        DAT_00fe5b08 = DAT_00fe5b08 | 1;
        local_c = 6;
        FUN_00584c40(&DAT_00fe5ae8);
        _atexit((_func_4879 *)&LAB_00bcf380);
      }
      local_c = 0xffffffff;
      local_90 = 0x22;
      FUN_005740f0(&local_90);
      if (local_94 == DAT_00fe5aec) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      FUN_004f6a30(param_1);
      psVar5 = (short *)FUN_004ed610();
      local_c = 7;
      if (7 < *(uint *)(psVar5 + 10)) {
        psVar5 = *(short **)psVar5;
      }
      local_5c = 7;
      local_60 = 0;
      local_70 = (uint)local_70._2_2_ << 0x10;
      psVar6 = psVar5;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_c._0_1_ = 9;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_c = CONCAT31(local_c._1_3_,8);
      FUN_004d6b30(&local_70);
      if (7 < local_5c) {
        FUN_0089120c(local_70);
      }
      local_5c = 7;
      local_60 = 0;
      local_70 = local_70 & 0xffff0000;
    }
    else {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0;
        FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xffffff60);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c = 1;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
        }
      }
      local_c = 0xffffffff;
      local_94 = 0x21;
      iVar3 = FUN_005855b0();
      FUN_005740f0(&local_94);
      if (local_90 == *(int *)(iVar3 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      FUN_004f6a30(param_1);
      uVar4 = FUN_004f6a30(in_ECX);
      psVar5 = (short *)FUN_00498ef0(uVar4);
      local_c = 2;
      if (7 < *(uint *)(psVar5 + 10)) {
        psVar5 = *(short **)psVar5;
      }
      local_78 = 7;
      local_7c = 0;
      local_8c = (uint)local_8c._2_2_ << 0x10;
      psVar6 = psVar5;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_c._0_1_ = 4;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_c = CONCAT31(local_c._1_3_,3);
      FUN_004d6b30(&local_8c);
      if (7 < local_78) {
        FUN_0089120c(local_8c);
      }
      local_78 = 7;
      local_7c = 0;
      local_8c = local_8c & 0xffff0000;
      local_38 = local_54;
      local_24 = local_40;
    }
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_94);
  return;
}

