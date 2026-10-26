
void FUN_004b4d80(undefined4 *param_1,uint param_2)

{
  short sVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined4 *puVar5;
  short *psVar6;
  short *psVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  undefined2 local_b4 [8];
  undefined4 local_a4;
  short *local_a0;
  undefined2 local_98 [8];
  undefined4 local_88;
  undefined4 local_84;
  undefined1 auStack_64 [4];
  undefined4 *local_60;
  undefined4 *local_5c;
  int *local_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00940a66;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  ExceptionList = &local_14;
  local_5c = param_1;
  if (*(char *)((int)param_1 + 2) == '\0') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    local_58 = (int *)local_98;
    local_84 = 7;
    local_88 = 0;
    local_a0 = &DAT_00bed1fc;
    local_98[0] = 0;
    local_a4 = 0x4b5304;
    FUN_00402160();
    local_c = 1;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      local_a0 = (short *)0x4b532c;
      FUN_00584c40();
      local_a0 = (short *)0x4b5336;
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,1);
    }
    local_60 = (undefined4 *)0x3;
    local_a0 = (short *)0x4b535c;
    FUN_005740f0();
    if (local_5c == DAT_00fe5b10) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    psVar6 = (short *)(local_5c + 4);
    if (7 < (uint)local_5c[9]) {
      psVar6 = *(short **)psVar6;
    }
    local_60 = (undefined4 *)local_b4;
    local_a0 = (short *)0x7;
    local_a4 = 0;
    local_b4[0] = 0;
    psVar7 = psVar6;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
  else if (*(char *)((int)param_1 + 2) == '\x01') {
    if (param_2 < 4) {
      uVar9 = 0;
    }
    else {
      uVar9 = param_2 - 4 >> 2;
    }
    local_60 = (undefined4 *)FUN_00891268();
    if (local_60 == (undefined4 *)0x0) {
      local_60 = (undefined4 *)0x0;
    }
    else {
      local_60[1] = 0xffffffff;
      local_60[2] = 0xffffffff;
      local_60[3] = 0;
      local_60[4] = 0xf42a3;
      *local_60 = FUI::FXUIChangeTownFailNotOpenedTown::vftable;
      local_60[5] = 0;
      local_60[6] = 0;
      local_60[7] = 0;
      local_60[8] = 0;
    }
    puVar5 = local_60;
    local_60[5] = (uint)*(byte *)((int)local_5c + 3);
    local_40 = 7;
    local_44 = 0;
    local_54 = local_54 & 0xffff0000;
    FUN_00402160();
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    if (uVar9 != 0) {
      local_58 = local_5c + 1;
      uVar10 = 0;
      do {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c._0_1_ = 4;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
        }
        local_c._0_1_ = 3;
        if (*local_58 == DAT_00f93930) {
          if ((DAT_00fe5b2c & 1) == 0) {
            DAT_00fe5b2c = DAT_00fe5b2c | 1;
            local_c._0_1_ = 5;
            local_84 = 0x4b4fc3;
            FUN_00584c40();
            local_84 = 0x4b4fcd;
            _atexit(FUN_00bcf370);
          }
          local_c._0_1_ = 3;
          local_60 = (undefined4 *)0x196;
          local_84 = 0x4b4ff0;
          FUN_005740f0();
          if (local_5c == DAT_00fe5b10) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          local_a0 = (short *)(local_5c + 4);
          if (7 < (uint)local_5c[9]) {
            local_a0 = *(short **)local_a0;
          }
          local_58 = (int *)local_98;
          local_84 = 7;
          local_88 = 0;
          local_98[0] = 0;
          psVar6 = local_a0;
          do {
            sVar1 = *psVar6;
            psVar6 = psVar6 + 1;
          } while (sVar1 != 0);
          local_a4 = 0x4b5046;
          FUN_00402160();
          if ((DAT_00fe5b2c & 1) == 0) {
            DAT_00fe5b2c = DAT_00fe5b2c | 1;
            local_c._0_1_ = 7;
            local_a0 = (short *)0x4b5074;
            FUN_00584c40();
            local_a0 = (short *)0x4b507e;
            _atexit(FUN_00bcf370);
          }
          local_c._0_1_ = 6;
          local_60 = (undefined4 *)0x6;
          local_a0 = (short *)0x4b509f;
          FUN_005740f0();
          if (local_5c == DAT_00fe5b10) {
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          psVar6 = (short *)(local_5c + 4);
          if (7 < (uint)local_5c[9]) {
            psVar6 = *(short **)psVar6;
          }
          local_60 = (undefined4 *)local_b4;
          local_a0 = (short *)0x7;
          local_a4 = 0;
          local_b4[0] = 0;
          psVar7 = psVar6;
          do {
            sVar1 = *psVar7;
            psVar7 = psVar7 + 1;
          } while (sVar1 != 0);
          FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
          local_c = CONCAT31(local_c._1_3_,3);
          FUN_0058b270(0xca);
          if (7 < local_40) {
            FUN_0089120c();
          }
          goto LAB_004b53c2;
        }
        local_58 = local_58 + 1;
        uVar10 = uVar10 + 1;
      } while (uVar10 < uVar9);
      if (uVar9 != 0) {
        puVar8 = local_5c;
        local_5c = (undefined4 *)uVar9;
        do {
          puVar8 = puVar8 + 1;
          if ((DAT_00fb75b0 & 1) == 0) {
            DAT_00fb75b0 = DAT_00fb75b0 | 1;
            local_c._0_1_ = 8;
            FUN_004f3d80();
            _atexit((_func_4879 *)&LAB_00bcd1e0);
            local_c._0_1_ = 3;
          }
          FUN_004f6a30();
          FUN_004ed610();
          local_c._0_1_ = 9;
          local_84 = 0x4b4f2a;
          FUN_004041f0();
          local_c._0_1_ = 3;
          if (7 < local_24) {
            FUN_0089120c();
          }
          local_24 = 7;
          local_28 = 0;
          local_38 = local_38 & 0xffff0000;
          puVar2 = (undefined4 *)puVar5[7];
          if ((puVar8 < puVar2) && (puVar3 = (undefined4 *)puVar5[6], puVar3 <= puVar8)) {
            if (puVar2 == (undefined4 *)puVar5[8]) {
              FUN_006d6240();
            }
            if ((undefined4 *)puVar5[7] != (undefined4 *)0x0) {
              *(undefined4 *)puVar5[7] =
                   *(undefined4 *)(puVar5[6] + ((int)puVar8 - (int)puVar3 >> 2) * 4);
            }
          }
          else {
            if (puVar2 == (undefined4 *)puVar5[8]) {
              FUN_006d6240();
            }
            if ((undefined4 *)puVar5[7] != (undefined4 *)0x0) {
              *(undefined4 *)puVar5[7] = *puVar8;
            }
          }
          puVar5[7] = puVar5[7] + 4;
          local_5c = (undefined4 *)((int)local_5c - 1);
        } while (local_5c != (undefined4 *)0x0);
        local_5c = (undefined4 *)0x0;
      }
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c._0_1_ = 10;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c._0_1_ = 3;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c._0_1_ = 0xb;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c._0_1_ = 3;
    }
    local_58 = (int *)local_98;
    local_84 = 7;
    local_88 = 0;
    local_a0 = &DAT_00bed1fc;
    local_98[0] = 0;
    local_a4 = 0x4b51e0;
    FUN_00402160();
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 0xd;
      local_a0 = (short *)0x4b521e;
      FUN_00584c40();
      local_a0 = (short *)0x4b5228;
      _atexit(FUN_00bcf370);
    }
    local_c._0_1_ = 0xc;
    local_60 = (undefined4 *)0x44;
    local_a0 = (short *)0x4b524d;
    FUN_005740f0();
    if (local_5c == DAT_00fe5b10) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    local_60 = (undefined4 *)local_b4;
    FUN_004ed610();
    local_c = CONCAT31(local_c._1_3_,3);
    FUN_0058b270(0xcf);
    if (7 < local_40) {
      FUN_0089120c();
    }
  }
LAB_004b53c2:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

