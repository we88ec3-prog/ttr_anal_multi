
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004629d0(undefined4 param_1,uint param_2)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  int in_ECX;
  short *psVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  float *pfVar9;
  undefined1 auStack_134 [36];
  undefined4 *local_110;
  char local_109;
  undefined4 *local_108;
  int local_104;
  undefined4 local_100;
  float local_fc [2];
  uint local_f4;
  uint local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  uint local_e0;
  undefined4 local_d4;
  undefined4 local_c8;
  uint local_84;
  void *local_4c;
  undefined1 *puStack_48;
  undefined4 local_44;
  
  local_44 = 0xffffffff;
  puStack_48 = &LAB_00931550;
  local_4c = ExceptionList;
  local_84 = DAT_00d61f20 ^ (uint)auStack_134;
  ExceptionList = &local_4c;
  local_100 = param_1;
  local_104 = in_ECX;
  iVar2 = FUN_00404ba0(DAT_00d61f20 ^ (uint)&stack0xfffffec0);
  if (*(int *)(iVar2 + 0x68b4) == 0) goto LAB_00462e1c;
  if ((DAT_00fe7218 & 1) == 0) {
    DAT_00fe7218 = DAT_00fe7218 | 1;
    local_44 = 0;
    _DAT_00fe7100 = 0;
    _DAT_00fe7114 = 7;
    _DAT_00fe7110 = 0;
    FUN_00402160(&DAT_00bff8c0,3);
    local_44._0_1_ = 1;
    _DAT_00fe7130 = 7;
    _DAT_00fe712c = 0;
    _DAT_00fe711c = 0;
    FUN_00402160(L"DROPRATE",8);
    local_44._0_1_ = 2;
    _DAT_00fe714c = 7;
    _DAT_00fe7148 = 0;
    _DAT_00fe7138 = 0;
    FUN_00402160(L"MONEYAMOUNT",0xb);
    local_44._0_1_ = 3;
    _DAT_00fe7154 = 0;
    _DAT_00fe7168 = 7;
    _DAT_00fe7164 = 0;
    FUN_00402160(L"DAMAGE",6);
    local_44._0_1_ = 4;
    _DAT_00fe7184 = 7;
    _DAT_00fe7180 = 0;
    _DAT_00fe7170 = 0;
    FUN_00402160(L"REGEN_AMOUNT",0xc);
    local_44._0_1_ = 5;
    _DAT_00fe71a0 = 7;
    _DAT_00fe719c = 0;
    _DAT_00fe718c = 0;
    FUN_00402160(L"ATKSPEED",8);
    local_44._0_1_ = 6;
    _DAT_00fe71a8 = 0;
    _DAT_00fe71bc = 7;
    _DAT_00fe71b8 = 0;
    FUN_00402160(L"FATIGUE",7);
    local_44._0_1_ = 7;
    _DAT_00fe71d8 = 7;
    _DAT_00fe71d4 = 0;
    _DAT_00fe71c4 = 0;
    FUN_00402160(L"ENTERANCE_CP",0xc);
    local_44._0_1_ = 8;
    _DAT_00fe71f4 = 7;
    _DAT_00fe71f0 = 0;
    _DAT_00fe71e0 = 0;
    FUN_00402160(L"CONSUME_CP",10);
    local_44 = CONCAT31(local_44._1_3_,9);
    _DAT_00fe71fc = 0;
    _DAT_00fe7210 = 7;
    _DAT_00fe720c = 0;
    FUN_00402160(L"CP_BONUS",8);
    _atexit((_func_4879 *)&LAB_00bcd880);
    local_44 = 0xffffffff;
  }
  if (*(int *)(in_ECX + 6) != 0) {
    if (*(int *)(in_ECX + 6) == 1) {
      if (*(int *)(in_ECX + 2) == 0) {
        FUN_005855b0();
        FUN_00585330();
        FUN_00402250();
        local_44 = 0xd;
        FUN_0040f8c0();
        FUN_004d6b30();
      }
      else {
        FUN_005855b0();
        FUN_00585330();
        FUN_00402250();
        local_44 = 0xc;
        FUN_0040f8c0();
        FUN_004d6b30();
      }
      local_44 = 0xffffffff;
      FUN_004fa440();
      if (param_2 < 10) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        puVar7 = (undefined4 *)((param_2 - 10) / 0x14);
      }
      in_ECX = local_104;
      if (puVar7 != (undefined4 *)0x0) {
        local_108 = (undefined4 *)(local_104 + 0xe);
        local_110 = puVar7;
        do {
          if ((DAT_00fb75b0 & 1) == 0) {
            DAT_00fb75b0 = DAT_00fb75b0 | 1;
            local_44 = 0xe;
            FUN_004f3d80();
            _atexit((_func_4879 *)&LAB_00bcd1e0);
            local_44 = 0xffffffff;
          }
          psVar3 = (short *)FUN_004f6a30();
          if (psVar3 != (short *)0x0) {
            local_f4 = local_f4 & 0xffff0000;
            local_e0 = 7;
            local_e4 = 0;
            psVar6 = psVar3;
            do {
              sVar1 = *psVar6;
              psVar6 = psVar6 + 1;
            } while (sVar1 != 0);
            FUN_00402160(psVar3,(int)psVar6 - (int)(psVar3 + 1) >> 1);
            local_44 = 0xf;
            if ((DAT_00fb11e0 & 1) == 0) {
              DAT_00fb11e0 = DAT_00fb11e0 | 1;
              local_44._0_1_ = 0x10;
              local_44._1_3_ = 0;
              FUN_004d4d10();
              _atexit((_func_4879 *)&LAB_00bccef0);
              local_44 = CONCAT31(local_44._1_3_,0xf);
            }
            FUN_004d6b30();
            local_44 = 0xffffffff;
            if (7 < local_e0) {
              FUN_0089120c();
            }
            local_e0 = 7;
            local_e4 = 0;
            local_f4 = local_f4 & 0xffff0000;
          }
          local_108 = (undefined4 *)((int)local_108 + 0x14);
          local_110 = (undefined4 *)((int)local_110 + -1);
          in_ECX = local_104;
        } while (local_110 != (undefined4 *)0x0);
      }
    }
    goto LAB_00462e1c;
  }
  FUN_0040f8c0(L"[ Current LevelBonus List : %s ]");
  FUN_004d6c70();
  if (param_2 < 10) {
    local_110 = (undefined4 *)0x0;
LAB_004630ca:
    FUN_00402250();
    local_44 = 10;
    FUN_0040f8c0();
    FUN_004d6b30();
    local_44 = 0xffffffff;
    FUN_004fa440();
    in_ECX = local_104;
  }
  else {
    local_110 = (undefined4 *)((param_2 - 10) / 0x14);
    if (local_110 == (undefined4 *)0x0) goto LAB_004630ca;
  }
  if (local_110 != (undefined4 *)0x0) {
    pfVar9 = (float *)(in_ECX + 0x1a);
    local_108 = local_110;
    do {
      if ((pfVar9[-2] == pfVar9[-1]) && (pfVar9[-2] == 0.0)) {
        local_fc[0] = *pfVar9;
        uVar5 = 0x2b;
        if (local_fc[0] <= 0.0) {
          uVar5 = 0x2d;
        }
        puVar7 = (undefined4 *)(&DAT_00fe7100 + (int)pfVar9[-4] * 0x1c);
        if (7 < *(uint *)(&DAT_00fe7114 + (int)pfVar9[-4] * 0x1c)) {
          puVar7 = (undefined4 *)*puVar7;
        }
        FUN_0040f8c0(L"WholeLevelBonus: %s %c%f percent",puVar7,uVar5,(double)(local_fc[0] * 100.0))
        ;
        FUN_004d6c70();
      }
      else {
        local_109 = '+';
        if (*pfVar9 <= 0.0) {
          local_109 = '-';
        }
        local_110 = (undefined4 *)(&DAT_00fe7100 + (int)pfVar9[-4] * 0x1c);
        if (7 < *(uint *)(&DAT_00fe7114 + (int)pfVar9[-4] * 0x1c)) {
          local_110 = (undefined4 *)*local_110;
        }
        if ((DAT_00fb11e0 & 1) == 0) {
          DAT_00fb11e0 = DAT_00fb11e0 | 1;
          local_44 = 0xb;
          FUN_004d4d10();
          _atexit((_func_4879 *)&LAB_00bccef0);
          local_44 = 0xffffffff;
        }
        FUN_004d6c70(L"LvBonus: %s (%d-%d), %c%f percent",local_110,pfVar9[-2],pfVar9[-1],
                     (int)local_109,(double)(*pfVar9 * 100.0));
      }
      pfVar9 = pfVar9 + 5;
      local_108 = (undefined4 *)((int)local_108 + -1);
    } while (local_108 != (undefined4 *)0x0);
    local_108 = (undefined4 *)0x0;
    in_ECX = local_104;
  }
LAB_00462e1c:
  if (*(int *)(in_ECX + 2) != 0) {
    FUN_0052d480();
    if ((DAT_00fe7218 & 2) == 0) {
      DAT_00fe7218 = DAT_00fe7218 | 2;
      local_44 = 0x11;
      _DAT_00fe6ffc = 7;
      _DAT_00fe6ff8 = 0;
      _DAT_00fe6fe8 = 0;
      FUN_00402160(&DAT_00bff8c0,3);
      local_44._0_1_ = 0x12;
      _DAT_00fe7018 = 7;
      _DAT_00fe7014 = 0;
      _DAT_00fe7004 = 0;
      FUN_00402160(L"DROPRATE",8);
      local_44._0_1_ = 0x13;
      _DAT_00fe7020 = 0;
      _DAT_00fe7034 = 7;
      _DAT_00fe7030 = 0;
      FUN_00402160(L"MONEYAMOUNT",0xb);
      local_44._0_1_ = 0x14;
      _DAT_00fe7050 = 7;
      _DAT_00fe704c = 0;
      _DAT_00fe703c = 0;
      FUN_00402160(L"DAMAGE",6);
      local_44._0_1_ = 0x15;
      _DAT_00fe706c = 7;
      _DAT_00fe7068 = 0;
      _DAT_00fe7058 = 0;
      FUN_00402160(L"REGEN_AMOUNT",0xc);
      local_44._0_1_ = 0x16;
      _DAT_00fe7074 = 0;
      _DAT_00fe7088 = 7;
      _DAT_00fe7084 = 0;
      FUN_00402160(L"ATKSPEED",8);
      local_44._0_1_ = 0x17;
      _DAT_00fe70a4 = 7;
      _DAT_00fe70a0 = 0;
      _DAT_00fe7090 = 0;
      FUN_00402160(L"FATIGUE",7);
      local_44._0_1_ = 0x18;
      _DAT_00fe70c0 = 7;
      _DAT_00fe70bc = 0;
      _DAT_00fe70ac = 0;
      FUN_00402160(L"ENTERANCE_CP",0xc);
      local_44._0_1_ = 0x19;
      _DAT_00fe70c8 = 0;
      _DAT_00fe70dc = 7;
      _DAT_00fe70d8 = 0;
      FUN_00402160(L"CONSUME_CP",10);
      local_44 = CONCAT31(local_44._1_3_,0x1a);
      _DAT_00fe70f8 = 7;
      _DAT_00fe70f4 = 0;
      _DAT_00fe70e4 = 0;
      FUN_00402160(L"CP_BONUS",8);
      _atexit((_func_4879 *)&LAB_00bcd860);
      local_44 = 0xffffffff;
    }
    if ((((*(int *)(local_104 + 6) == 0) && (9 < param_2)) &&
        (puVar7 = (undefined4 *)((param_2 - 10) / 0x14), puVar7 != (undefined4 *)0x0)) &&
       (puVar7 != (undefined4 *)0x0)) {
      puVar8 = (undefined4 *)(local_104 + 0x16);
      local_110 = puVar7;
      do {
        iVar2 = puVar8[-3];
        if (iVar2 == 0) {
          local_f4 = 1;
LAB_00463268:
          local_e8 = puVar8[-1];
          local_e0 = puVar8[1];
          local_e4 = *puVar8;
          local_ec = local_d4;
          local_f0 = local_f4;
          local_c8 = local_e0;
          uVar4 = FUN_0052e860();
          FUN_00463340(local_fc,uVar4);
        }
        else {
          if (iVar2 == 1) {
            local_f4 = 2;
            goto LAB_00463268;
          }
          if (iVar2 == 2) {
            local_f4 = 3;
            goto LAB_00463268;
          }
        }
        puVar8 = puVar8 + 5;
        local_110 = (undefined4 *)((int)local_110 + -1);
      } while (local_110 != (undefined4 *)0x0);
    }
  }
  ExceptionList = local_4c;
  __security_check_cookie(local_84 ^ (uint)auStack_134);
  return;
}

