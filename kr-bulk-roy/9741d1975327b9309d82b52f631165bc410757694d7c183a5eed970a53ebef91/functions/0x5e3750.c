
void FUN_005e3750(undefined4 param_1)

{
  short sVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  int in_ECX;
  short *psVar7;
  int in_EDX;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  tm local_70;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f078;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_74 = in_ECX;
  if (in_EDX == 0) {
    if (*(char *)(in_ECX + 0x179) != '\0') {
      local_7c = 0x194;
      iVar4 = FUN_00585620();
      FUN_005740f0(&local_7c);
      if (local_78 == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar7 = (short *)(local_78 + 0x10);
      if (7 < *(uint *)(local_78 + 0x24)) {
        psVar7 = *(short **)psVar7;
      }
      psVar6 = psVar7;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00404300(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
      local_78 = 0x34;
      iVar4 = FUN_00585620();
      FUN_005740f0(&local_78);
      if (local_7c == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar5 = FUN_00426ec0();
      local_8 = 0;
      FUN_004041f0(uVar5,0,0xffffffff);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
    }
  }
  else if (*(char *)(in_EDX + 0x15) != '\0') {
    iVar4 = FUN_00404ba0(local_14);
    local_74 = *(int *)(iVar4 + 0x5f70);
    iVar4 = *(int *)(in_EDX + 0x1c);
    if (iVar4 < local_74) {
      local_74 = *(int *)(in_ECX + 0x164);
      iVar4 = FUN_004146b0();
      FUN_008438c0(&local_74);
      if ((local_78 == *(int *)(iVar4 + 0x18)) || (*(int *)(local_78 + 0x10) == 0)) {
        uVar5 = 0x198;
        FUN_00585620(0x198);
        FUN_00585330(uVar5);
        FUN_00404420(param_1);
        FUN_00404420(param_1);
      }
      else {
        uVar5 = 0x192;
        FUN_00585620(0x192);
        FUN_00585330(uVar5);
        FUN_00404420(param_1);
        uVar5 = 0x193;
        FUN_00585620(0x193);
        FUN_00585330(uVar5);
        FUN_00404420(param_1);
      }
    }
    else {
      uVar5 = 0x194;
      FUN_00585620(0x194);
      psVar6 = (short *)FUN_00585330(uVar5);
      psVar7 = psVar6;
      do {
        sVar1 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar1 != 0);
      FUN_00404300(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
      local_80 = iVar4 - local_74;
      __gmtime32_s(&local_70,&local_80);
      bVar3 = true;
      if ((local_70.tm_yday != 0) || (local_70.tm_year != 0x46 && -1 < local_70.tm_year + -0x46)) {
        uVar5 = 0x34;
        FUN_00585620(0x34);
        FUN_00585330(uVar5);
        uVar5 = FUN_004068f0();
        local_8 = 1;
        FUN_004041f0(uVar5,0,0xffffffff);
        local_8 = 0xffffffff;
        FUN_004fa440();
        FUN_00404300(&DAT_00bf3a70,1);
        bVar3 = false;
      }
      if (local_70.tm_hour != 0) {
        uVar5 = 0x35;
        FUN_00585620(0x35);
        FUN_00585330(uVar5);
        uVar5 = FUN_004068f0();
        local_8 = 2;
        FUN_004041f0(uVar5,0,0xffffffff);
        local_8 = 0xffffffff;
        FUN_004fa440();
        FUN_00404420(param_1);
        bVar3 = false;
      }
      if (local_70.tm_min == 0) {
        if (!bVar3) goto LAB_005e3a8e;
        uVar5 = 0x37;
        FUN_00585620(0x37);
        FUN_00585330(uVar5);
        uVar5 = FUN_004068f0();
        local_8 = 4;
        FUN_004041f0(uVar5,0,0xffffffff);
      }
      else {
        uVar5 = 0x36;
        FUN_00585620(0x36);
        FUN_00585330(uVar5);
        uVar5 = FUN_004068f0();
        local_8 = 3;
        FUN_004041f0(uVar5,0,0xffffffff);
      }
      FUN_004fa440();
    }
  }
LAB_005e3a8e:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

