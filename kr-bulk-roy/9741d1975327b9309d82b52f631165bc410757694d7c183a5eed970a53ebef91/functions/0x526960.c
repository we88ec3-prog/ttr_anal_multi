
void FUN_00526960(int param_1)

{
  char cVar1;
  int *piVar2;
  char *in_ECX;
  long lVar3;
  long lVar4;
  char *pcVar5;
  undefined2 local_29c [6];
  undefined4 uStack_290;
  int local_25c;
  int local_258;
  int local_254;
  int local_250;
  int local_24c;
  undefined1 *local_248;
  int local_244;
  int local_240;
  int local_23c;
  int local_238;
  char local_231;
  undefined1 local_22c [4];
  uint local_228;
  undefined4 local_218;
  uint local_214;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined1 local_100;
  uint local_fc;
  undefined4 local_ec;
  uint local_e8;
  undefined1 local_dc [24];
  uint local_c4;
  undefined1 local_b4 [28];
  uint local_98;
  undefined4 local_88;
  uint local_84;
  long local_78;
  uint local_74 [4];
  undefined4 local_64;
  uint local_60;
  long local_58;
  long local_54;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f59a;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_240 = param_1;
  local_1c8 = 0;
  local_1c4 = 0;
  FUN_0071bc20();
  local_100 = 0;
  local_e8 = 0xf;
  local_ec = 0;
  local_fc = local_fc & 0xffffff00;
  local_8 = 0;
  local_84 = 0xf;
  local_88 = 0;
  local_98 = local_98 & 0xffffff00;
  do {
    cVar1 = *in_ECX;
    in_ECX = in_ECX + 1;
  } while (cVar1 != '\0');
  FUN_00402a70();
  local_8 = CONCAT31(local_8._1_3_,1);
  piVar2 = (int *)FUN_00714770();
  if (piVar2 == (int *)0x0) {
    local_231 = '\0';
  }
  else {
    (**(code **)(*piVar2 + 0x38))();
    (**(code **)(*piVar2 + 0x2c))();
    local_231 = FUN_00499340();
    (**(code **)(*piVar2 + 4))();
  }
  local_231 = local_231 == '\0';
  if (0xf < local_84) {
    FUN_0089120c();
  }
  if (local_231 == '\0') {
    local_23c = local_1c8;
    piVar2 = (int *)FUN_0071ba40();
    local_23c = *piVar2;
    FUN_00719da0();
    if (local_238 != 0) {
      local_23c = local_240 + 0x18;
      do {
        local_78 = 0;
        local_60 = 7;
        local_64 = 0;
        local_74[0] = local_74[0] & 0xffff0000;
        local_8._0_1_ = 2;
        local_58 = 0;
        local_54 = 0;
        FUN_00757200();
        local_8 = CONCAT31(local_8._1_3_,3);
        lVar3 = 0;
        FUN_0071baa0();
        if (local_240 != 0) {
          if (*(char **)(local_240 + 8) == (char *)0x0) {
            lVar3 = 0;
          }
          else {
            uStack_290 = 0x526b8f;
            lVar3 = _strtol(*(char **)(local_240 + 8),(char **)0x0,10);
          }
        }
        lVar4 = 0;
        local_78 = lVar3;
        FUN_0071baa0();
        if (local_254 != 0) {
          if (*(char **)(local_254 + 8) == (char *)0x0) {
            lVar4 = 0;
          }
          else {
            uStack_290 = 0x526bcd;
            lVar4 = _strtol(*(char **)(local_254 + 8),(char **)0x0,10);
          }
        }
        lVar3 = 0;
        local_58 = lVar4;
        FUN_0071baa0();
        if (local_25c != 0) {
          if (*(char **)(local_25c + 8) == (char *)0x0) {
            lVar3 = 0;
          }
          else {
            uStack_290 = 0x526c0b;
            lVar3 = _strtol(*(char **)(local_25c + 8),(char **)0x0,10);
          }
        }
        if (local_238 == 0) {
          local_250 = 0;
          piVar2 = &local_250;
        }
        else {
          local_258 = *(int *)(local_238 + 0x10);
          piVar2 = &local_258;
        }
        local_54 = lVar3;
        if (*piVar2 == 0) {
          FUN_00757f20();
          FUN_00402160();
          FUN_00527f30();
          local_8._0_1_ = 8;
          FUN_00528390();
          FUN_00528090();
          local_248 = local_22c;
          local_8 = CONCAT31(local_8._1_3_,9);
          FUN_00757640();
          if (7 < local_214) {
            FUN_0089120c();
          }
          local_214 = 7;
          local_218 = 0;
          local_228 = local_228 & 0xffff0000;
        }
        else {
          if (local_238 == 0) {
            local_244 = 0;
            piVar2 = &local_244;
          }
          else {
            local_24c = *(int *)(local_238 + 0x10);
            piVar2 = &local_24c;
          }
          if ((*piVar2 == 0) || (pcVar5 = *(char **)(*piVar2 + 0xc), pcVar5 == (char *)0x0)) {
            pcVar5 = "";
          }
          local_84 = 0xf;
          local_88 = 0;
          local_98 = local_98 & 0xffffff00;
          do {
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          FUN_00402a70();
          local_8._0_1_ = 4;
          FUN_00440130();
          local_8._0_1_ = 3;
          if (0xf < local_84) {
            FUN_0089120c();
          }
          local_248 = (undefined1 *)local_29c;
          local_29c[0] = 0;
          FUN_004026e0(local_74,0,0xffffffff);
          FUN_00526200(local_b4);
          local_8._0_1_ = 5;
          FUN_00758030();
          local_8._0_1_ = 3;
          FUN_00757640();
          FUN_00527f30();
          local_8._0_1_ = 6;
          FUN_00528390();
          FUN_00528090();
          local_248 = local_dc;
          local_8 = CONCAT31(local_8._1_3_,7);
          FUN_00757640();
          if (7 < local_c4) {
            FUN_0089120c();
          }
        }
        local_8 = CONCAT31(local_8._1_3_,10);
        FUN_00757640();
        if (7 < local_60) {
          FUN_0089120c();
        }
        local_60 = 7;
        local_64 = 0;
        local_74[0] = local_74[0] & 0xffff0000;
        piVar2 = (int *)FUN_00719e00();
        local_238 = *piVar2;
      } while (local_238 != 0);
    }
    local_8 = 0xffffffff;
    if (0xf < local_e8) {
      FUN_0089120c();
    }
    local_e8 = 0xf;
    local_ec = 0;
    local_fc = local_fc & 0xffffff00;
    FUN_0071bc90();
  }
  else {
    local_8 = 0xffffffff;
    if (0xf < local_e8) {
      FUN_0089120c();
    }
    local_e8 = 0xf;
    local_ec = 0;
    local_fc = local_fc & 0xffffff00;
    FUN_0071bc90();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

