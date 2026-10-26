
void FUN_004191f0(int param_1)

{
  ushort uVar1;
  short sVar2;
  code *pcVar3;
  bool bVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  short *psVar9;
  undefined1 auStack_8c [4];
  uint local_88;
  int local_84;
  int local_80;
  int local_7c;
  tm local_78;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined4 local_38;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00941ec6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_8c;
  ExceptionList = &local_14;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x88 + *(int *)(param_1 + 0xbc) * 4) + 0x298);
  local_7c = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff68);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar7 = DAT_00f94308;
  local_c = 0xffffffff;
  local_88 = (uint)uVar1;
  FUN_004a4cc0(&local_88);
  if (local_84 == *(int *)(iVar7 + 0x14)) {
    iVar7 = 0;
  }
  else {
    iVar7 = *(int *)(local_84 + 0x10);
  }
  local_40 = 7;
  local_44 = 0;
  local_54 = (uint)local_54._2_2_ << 0x10;
  FUN_00402160(&DAT_00bed1fc,0);
  local_c = 1;
  if ((iVar7 == 0) || (*(int *)(iVar7 + 0xc) == 0)) goto LAB_00419562;
  local_84 = 0x195;
  iVar5 = FUN_00585620();
  FUN_005740f0(&local_84);
  if (local_80 == *(int *)(iVar5 + 4)) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar9 = (short *)(local_80 + 0x10);
  if (7 < *(uint *)(local_80 + 0x24)) {
    psVar9 = *(short **)psVar9;
  }
  psVar6 = psVar9;
  do {
    sVar2 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar2 != 0);
  FUN_00404300(psVar9,(int)psVar6 - (int)(psVar9 + 1) >> 1);
  iVar5 = FUN_00404ba0();
  local_88 = *(int *)(iVar7 + 8) - *(int *)(iVar5 + 0x5f70);
  __gmtime32_s(&local_78,(__time32_t *)&local_88);
  bVar4 = true;
  if ((local_78.tm_yday != 0) || (local_78.tm_year != 0x46 && -1 < local_78.tm_year + -0x46)) {
    local_80 = 0x34;
    iVar7 = FUN_00585620();
    FUN_005740f0(&local_80);
    if (local_84 == *(int *)(iVar7 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    uVar8 = FUN_004068f0();
    local_c._0_1_ = 2;
    FUN_004041f0(uVar8,0,0xffffffff);
    local_c = CONCAT31(local_c._1_3_,1);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    FUN_00404300(&DAT_00bf3a70,1);
    bVar4 = false;
  }
  if (local_78.tm_hour != 0) {
    uVar8 = 0x35;
    FUN_00585620(0x35);
    FUN_00585330(uVar8);
    uVar8 = FUN_004068f0();
    local_c._0_1_ = 3;
    FUN_004041f0(uVar8,0,0xffffffff);
    local_c = CONCAT31(local_c._1_3_,1);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    FUN_00404300(&DAT_00bf3a70,1);
    bVar4 = false;
  }
  if (local_78.tm_min == 0) {
    if (bVar4) {
      uVar8 = 0x37;
      FUN_00585620(0x37);
      FUN_00585330(uVar8);
      uVar8 = FUN_004068f0();
      local_c._0_1_ = 5;
      FUN_004041f0(uVar8,0,0xffffffff);
      goto joined_r0x00419522;
    }
  }
  else {
    uVar8 = 0x36;
    FUN_00585620(0x36);
    FUN_00585330(uVar8);
    uVar8 = FUN_004068f0();
    local_c._0_1_ = 4;
    FUN_004041f0(uVar8,0,0xffffffff);
joined_r0x00419522:
    local_c = CONCAT31(local_c._1_3_,1);
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
  }
  iVar7 = local_7c;
  FUN_00757800(&local_54);
  (**(code **)(**(int **)(iVar7 + 0xb4) + 200))();
LAB_00419562:
  if (7 < local_40) {
    FUN_0089120c(local_54);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_8c);
  return;
}

