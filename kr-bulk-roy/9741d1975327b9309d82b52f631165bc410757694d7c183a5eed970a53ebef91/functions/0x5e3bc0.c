
void FUN_005e3bc0(undefined4 param_1,int param_2)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  undefined4 uVar14;
  int local_58;
  uint local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  undefined4 local_30;
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b8ee;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar12 = (uint)*(ushort *)(param_2 + 0x94);
  uVar9 = (uint)*(ushort *)(param_2 + 0x96);
  local_54 = uVar12;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(local_14);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  iVar3 = DAT_00fc0bdc;
  piVar4 = (int *)FUN_0048a740();
  piVar13 = (int *)*piVar4;
  iVar5 = piVar4[1] - (int)piVar13 >> 0x1f;
  iVar11 = (piVar4[1] - (int)piVar13) / 0x33 + iVar5;
  if (iVar11 != iVar5) {
    uVar10 = 0;
    do {
      if (*piVar13 == iVar3) {
        iVar5 = uVar10 + 1;
        goto LAB_005e3c72;
      }
      uVar10 = uVar10 + 1;
      piVar13 = (int *)((int)piVar13 + 0x33);
    } while (uVar10 < (uint)(iVar11 - iVar5));
  }
  iVar5 = 0;
LAB_005e3c72:
  local_1c = 7;
  local_20 = 0;
  local_30 = (uint)local_30._2_2_ << 0x10;
  local_8._1_3_ = 0;
  if (((uVar12 == 0) || ((int)uVar12 <= iVar5)) && ((uVar9 == 0 || (iVar5 <= (int)uVar9)))) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 1;
    local_50 = 0x1c3;
    FUN_005740f0(&local_50);
    if (local_58 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_58 + 0x24) < 8) {
      psVar6 = (short *)(local_58 + 0x10);
      psVar7 = psVar6;
    }
    else {
      psVar6 = *(short **)(local_58 + 0x10);
      psVar7 = psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 3;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_8._0_1_ = 1;
    local_58 = 0x1c2;
    FUN_005740f0(&local_58);
    if (local_50 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_50 + 0x24) < 8) {
      psVar6 = (short *)(local_50 + 0x10);
      psVar7 = psVar6;
    }
    else {
      psVar6 = *(short **)(local_50 + 0x10);
      psVar7 = psVar6;
    }
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
  }
  FUN_00404300(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 4;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8._0_1_ = 1;
  }
  local_50 = 0x2b1;
  FUN_005740f0(&local_50);
  if (local_58 != DAT_00fe5ac8) {
    psVar6 = (short *)(local_58 + 0x10);
    if (7 < *(uint *)(local_58 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar7 = psVar6;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
    if (local_54 == 0) {
      if (uVar9 == 0) {
        FUN_00402160(&DAT_00bed1fc,0);
      }
      else {
        local_54 = 0x2b6;
        iVar5 = FUN_00585620();
        FUN_005740f0(&local_54);
        if (local_50 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        puVar8 = (undefined4 *)(local_50 + 0x10);
        if (7 < *(uint *)(local_50 + 0x24)) {
          puVar8 = (undefined4 *)*puVar8;
        }
        uVar14 = FUN_0040e460(puVar8);
        local_8._0_1_ = 9;
        FUN_004041f0(uVar14,0,0xffffffff);
        local_8._0_1_ = 1;
        if (7 < local_38) {
          FUN_0089120c(local_4c);
        }
      }
    }
    else if (uVar9 == 0) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8._0_1_ = 7;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8._0_1_ = 1;
      }
      local_54 = 0x2b5;
      FUN_005740f0(&local_54);
      if (local_50 == DAT_00fe5ac8) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar8 = (undefined4 *)(local_50 + 0x10);
      if (7 < *(uint *)(local_50 + 0x24)) {
        puVar8 = (undefined4 *)*puVar8;
      }
      uVar14 = FUN_0040e460(puVar8);
      local_8._0_1_ = 8;
      FUN_004041f0(uVar14,0,0xffffffff);
      local_8._0_1_ = 1;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
    }
    else if (local_54 == uVar9) {
      uVar14 = 0x2b3;
      FUN_00585620(0x2b3);
      FUN_00585330(uVar14);
      uVar14 = FUN_004068f0();
      local_8._0_1_ = 5;
      FUN_004041f0(uVar14,0,0xffffffff);
      local_8._0_1_ = 1;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
    }
    else {
      uVar14 = 0x2b4;
      FUN_00585620(0x2b4);
      uVar14 = FUN_00585330(uVar14);
      uVar14 = FUN_0040e460(uVar14);
      local_8._0_1_ = 6;
      FUN_004041f0(uVar14,0,0xffffffff);
      local_8._0_1_ = 1;
      if (7 < local_38) {
        FUN_0089120c(local_4c);
      }
    }
    if (local_20 != 0) {
      FUN_004041f0(&local_30,0,0xffffffff);
    }
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

