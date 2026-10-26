
void FUN_006ca1d0(int param_1)

{
  short sVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  undefined4 uVar7;
  short *psVar8;
  undefined1 auStack_88 [4];
  int local_84;
  int local_80;
  uint local_7c;
  tm local_78;
  undefined4 local_54;
  uint local_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093bcee;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_88;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff70);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar5 = DAT_00f94308;
  local_c = 0xffffffff;
  local_7c = (uint)*(ushort *)(param_1 + 0x16c);
  FUN_004a4cc0(&local_7c);
  if (((local_84 != *(int *)(iVar5 + 0x14)) && (iVar5 = *(int *)(local_84 + 0x10), iVar5 != 0)) &&
     (*(int *)(iVar5 + 4) == 0)) {
    iVar4 = FUN_00404ba0();
    local_80 = *(int *)(iVar5 + 8) - *(int *)(iVar4 + 0x5f70);
    local_84 = 0x1c7;
    iVar5 = FUN_00585620();
    FUN_005740f0(&local_84);
    if (local_7c == *(uint *)(iVar5 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar8 = (short *)(local_7c + 0x10);
    if (7 < *(uint *)(local_7c + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    psVar6 = psVar8;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
    __gmtime32_s(&local_78,&local_80);
    bVar3 = true;
    if ((local_78.tm_yday != 0) || (local_78.tm_year != 0x46 && -1 < local_78.tm_year + -0x46)) {
      local_84 = 0x34;
      iVar5 = FUN_00585620();
      FUN_005740f0(&local_84);
      if (local_7c == *(uint *)(iVar5 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar7 = FUN_004068f0();
      local_c = 1;
      FUN_004041f0(uVar7,0,0xffffffff);
      local_c = 0xffffffff;
      if (7 < local_40) {
        FUN_0089120c(local_54);
      }
      FUN_00404300(&DAT_00bf3a70,1);
      bVar3 = false;
    }
    if (local_78.tm_hour != 0) {
      uVar7 = 0x35;
      FUN_00585620(0x35);
      FUN_00585330(uVar7);
      uVar7 = FUN_004068f0();
      local_c = 2;
      FUN_004041f0(uVar7,0,0xffffffff);
      local_c = 0xffffffff;
      if (7 < local_40) {
        FUN_0089120c(local_54);
      }
      FUN_00404300(&DAT_00bf3a70,1);
      bVar3 = false;
    }
    if (local_78.tm_min == 0) {
      if (!bVar3) goto LAB_006ca4ce;
      uVar7 = 0x37;
      FUN_00585620(0x37);
      FUN_00585330(uVar7);
      uVar7 = FUN_004068f0();
      local_c = 4;
      FUN_004041f0(uVar7,0,0xffffffff);
    }
    else {
      uVar7 = 0x36;
      FUN_00585620(0x36);
      FUN_00585330(uVar7);
      uVar7 = FUN_004068f0();
      local_c = 3;
      FUN_004041f0(uVar7,0,0xffffffff);
      uStack_38 = local_54;
      uStack_24 = local_40;
    }
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
  }
LAB_006ca4ce:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_88);
  return;
}

