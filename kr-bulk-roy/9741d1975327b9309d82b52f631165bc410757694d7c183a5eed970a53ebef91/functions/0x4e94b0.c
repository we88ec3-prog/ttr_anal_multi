
void FUN_004e94b0(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  short *psVar4;
  int iVar5;
  short *psVar6;
  undefined4 *puVar7;
  int in_ECX;
  undefined4 uVar8;
  undefined1 *puVar9;
  int local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_7c;
  uint local_78;
  undefined4 local_70;
  uint local_5c;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093004d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_94;
  ExceptionList = &local_14;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 0;
      FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xffffff60);
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
    }
    local_c = 0xffffffff;
    local_94 = 0x16;
    FUN_005740f0(&local_94);
    if (local_90 == DAT_00fe5aec) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    FUN_004f6a30(*(undefined4 *)(param_1 + 3));
    psVar4 = (short *)FUN_004ed610();
    local_c = 2;
    if (7 < *(uint *)(psVar4 + 10)) {
      psVar4 = *(short **)psVar4;
    }
    local_8c = (uint)local_8c._2_2_ << 0x10;
    local_78 = 7;
    local_7c = 0;
    psVar6 = psVar4;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
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
    local_c = 0xffffffff;
    local_78 = 7;
    local_7c = 0;
    local_8c = local_8c & 0xffff0000;
    if (7 < local_5c) {
      FUN_0089120c(local_70);
    }
  }
  else {
    local_94 = in_ECX;
    if (cVar1 == '\x01') {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 5;
        FUN_004f3d80(DAT_00d61f20 ^ (uint)&stack0xffffff60);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
      }
      local_c = 0xffffffff;
      local_90 = 0x17;
      iVar5 = FUN_005855b0();
      FUN_005740f0(&local_90);
      if (local_94 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      FUN_004f6a30(*(undefined4 *)(param_1 + 3));
      psVar4 = (short *)FUN_004ed610();
      local_c = 6;
      if (7 < *(uint *)(psVar4 + 10)) {
        psVar4 = *(short **)psVar4;
      }
      local_78 = 7;
      local_7c = 0;
      local_8c = (uint)local_8c._2_2_ << 0x10;
      psVar6 = psVar4;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_c._0_1_ = 8;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
      }
      local_c = CONCAT31(local_c._1_3_,7);
      FUN_004d6b30(&local_8c);
      if (7 < local_78) {
        FUN_0089120c(local_8c);
      }
      local_c = 0xffffffff;
      local_78 = 7;
      local_7c = 0;
      local_8c = local_8c & 0xffff0000;
      if (7 < local_5c) {
        FUN_0089120c(local_70);
      }
    }
    else {
      if (cVar1 == '\x03') {
        uVar8 = *(undefined4 *)(param_1 + 3);
        FUN_00425330();
        FUN_004f6a30(uVar8);
        uVar8 = 0x18;
        FUN_005855b0(0x18);
        FUN_00585330(uVar8);
        puVar7 = (undefined4 *)FUN_004ed610();
        local_c = 9;
        if (7 < (uint)puVar7[5]) {
          puVar7 = (undefined4 *)*puVar7;
        }
        FUN_00402250(puVar7);
        puVar7 = &local_8c;
        local_c = CONCAT31(local_c._1_3_,10);
        FUN_0040f8c0(puVar7);
        FUN_004d6b30(puVar7);
        if (7 < local_78) {
          FUN_0089120c(local_8c);
        }
        local_c = 0xffffffff;
        local_78 = 7;
        local_7c = 0;
        local_8c = local_8c & 0xffff0000;
        if (7 < local_5c) {
          FUN_0089120c(local_70);
        }
      }
      else {
        if (cVar1 != '\x02') goto LAB_004e998c;
        uVar8 = *(undefined4 *)(param_1 + 3);
        FUN_00425330();
        FUN_004f6a30(uVar8);
        uVar8 = 0x19;
        FUN_005855b0(0x19);
        FUN_00585330(uVar8);
        puVar7 = (undefined4 *)FUN_004ed610();
        local_c = 0xb;
        if (7 < (uint)puVar7[5]) {
          puVar7 = (undefined4 *)*puVar7;
        }
        FUN_00402250(puVar7);
        puVar9 = local_54;
        local_c = CONCAT31(local_c._1_3_,0xc);
        FUN_0040f8c0(puVar9);
        FUN_004d6b30(puVar9);
        FUN_004fa440();
        local_c = 0xffffffff;
        FUN_004fa440();
      }
      FUN_004ec6f0();
    }
  }
LAB_004e998c:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xd;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4259);
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_94);
  return;
}

