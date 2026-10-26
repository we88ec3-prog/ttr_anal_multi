
void FUN_00610a00(undefined1 param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined1 auStack_84 [4];
  char local_80;
  int local_7c;
  undefined4 *local_78;
  uint local_74;
  undefined4 local_70;
  uint local_5c;
  uint uStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined4 uStack_38;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e3c2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  local_74 = CONCAT31(local_74._1_3_,param_1);
  param_3[4] = 0;
  puVar2 = param_3;
  if (7 < (uint)param_3[5]) {
    puVar2 = (undefined4 *)*param_3;
  }
  uVar5 = DAT_00fab278 & 1;
  *(undefined2 *)puVar2 = 0;
  if (uVar5 == 0) {
    DAT_00fab278 = DAT_00fab278 | 1;
    local_c = 0;
    FUN_00817da0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcced0);
  }
  local_c = 0xffffffff;
  local_78 = (undefined4 *)(local_74 & 0xff);
  local_80 = (char)param_2;
  FUN_008195e0(&local_78);
  if (local_7c == DAT_00fab280) {
    local_7c = 0;
  }
  else {
    FUN_008196d0();
    puVar2 = local_78;
    if (*(undefined4 **)(local_7c + 0x14) == local_78) {
      if (((char)param_2 != '\0') || (*(int *)(local_7c + 0x18) == 0)) {
        local_7c = 0;
        goto LAB_00610af3;
      }
      puVar2 = (undefined4 *)**(undefined4 **)(local_7c + 0x14);
    }
    local_7c = puVar2[5];
  }
LAB_00610af3:
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar1 = local_74 & 0xff;
  if (uVar1 < 10) {
    uVar5 = uVar1 * 0x210 + DAT_00f94304;
    uVar5 = -(uint)(*(int *)(uVar5 + 0x5c) != 0) & uVar5;
  }
  else {
    uVar5 = 0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar4 = local_7c;
  if (((uVar1 < 10) && (iVar3 = DAT_00f94304 + uVar1 * 0x210, *(int *)(iVar3 + 0x5c) != 0)) &&
     (iVar3 != 0)) {
    local_78 = (undefined4 *)(iVar3 + 500);
  }
  else {
    local_78 = (undefined4 *)0x0;
  }
  if ((local_7c != 0) && (pcVar6 = (char *)(local_7c + 4), pcVar6 != (char *)0x0)) {
    if (*(char *)(local_7c + 5) != '\0') {
      if (param_3[4] != 0) {
        FUN_00404420(param_3);
      }
      if ((uVar5 == 0) || ((int)(uint)*(byte *)(iVar4 + 5) <= *(int *)(uVar5 + 8))) {
        uVar7 = 0x2d8;
        FUN_00585620(0x2d8);
        FUN_00585330(uVar7);
        uVar7 = FUN_00426ec0();
        local_c = 4;
        FUN_004041f0(uVar7,0,0xffffffff);
        local_c = 0xffffffff;
        FUN_004fa440();
      }
      else {
        FUN_00404420(param_3);
        uVar7 = 0x2d8;
        FUN_00585620(0x2d8);
        FUN_00585330(uVar7);
        uVar7 = FUN_00426ec0();
        local_c = 3;
        FUN_004041f0(uVar7,0,0xffffffff);
        local_c = 0xffffffff;
        FUN_004fa440();
        FUN_00404420(param_3);
      }
    }
    if (*(char *)(iVar4 + 6) != '\0') {
      if (param_3[4] != 0) {
        FUN_00404420(param_3);
      }
      uVar7 = 0x2d9;
      FUN_00585620(0x2d9);
      FUN_00585330(uVar7);
      uVar7 = FUN_00426ec0();
      local_c = 5;
      FUN_004041f0(uVar7,0,0xffffffff);
      local_c = 0xffffffff;
      if (7 < local_5c) {
        FUN_0089120c(local_70);
      }
    }
    if (*(int *)(iVar4 + 8) != 0) {
      if (param_3[4] != 0) {
        FUN_00404420(param_3);
      }
      iVar3 = FUN_00404ba0();
      local_7c = *(int *)(iVar4 + 8);
      if ((*(int *)(iVar3 + 0x6874) < local_7c) && (iVar4 = FUN_0081a820(param_2), iVar4 == 0)) {
        FUN_00404420(param_3);
        uVar7 = 0x2da;
        FUN_00585620(0x2da);
        FUN_00585330(uVar7);
        uVar7 = FUN_004068f0();
        local_c = 6;
        FUN_004041f0(uVar7,0,0xffffffff);
        local_c = 0xffffffff;
        FUN_004fa440();
        FUN_00404420(param_3);
      }
      else {
        uVar7 = 0x2da;
        FUN_00585620(0x2da);
        FUN_00585330(uVar7);
        uVar7 = FUN_004068f0();
        local_c = 7;
        FUN_004041f0(uVar7,0,0xffffffff);
        local_c = 0xffffffff;
        FUN_004fa440();
      }
    }
    if (*pcVar6 != '\0') {
      if (param_3[4] != 0) {
        FUN_00404420(param_3);
      }
      uStack_40 = 7;
      uStack_44 = 0;
      uStack_54 = uStack_54 & 0xffff0000;
      local_c = 8;
      FUN_00610850(local_74,*pcVar6);
      uVar7 = 0x2db;
      FUN_00585620(0x2db);
      FUN_00585330(uVar7);
      uVar7 = FUN_004ed610();
      local_c = CONCAT31(local_c._1_3_,9);
      FUN_004041f0(uVar7,0,0xffffffff);
      if (7 < uStack_24) {
        FUN_0089120c(uStack_38);
      }
      if (7 < uStack_40) {
        FUN_0089120c(uStack_54);
      }
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

