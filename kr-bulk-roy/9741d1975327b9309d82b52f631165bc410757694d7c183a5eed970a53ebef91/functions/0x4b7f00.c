
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b7f00(int param_1,uint param_2)

{
  byte bVar1;
  short sVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  byte *pbVar9;
  undefined4 local_7c;
  undefined4 local_78;
  undefined2 local_74;
  byte local_72;
  undefined2 uStack_70;
  undefined4 uStack_6e;
  undefined4 uStack_6a;
  int local_64;
  undefined2 local_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined4 local_58;
  undefined4 local_48;
  uint local_44;
  undefined4 local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00944d86;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff78;
  ExceptionList = &local_14;
  local_64 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  local_58 = (uint)local_58._2_2_ << 0x10;
  local_44 = 7;
  local_48 = 0;
  psVar8 = &DAT_00f9388c;
  do {
    psVar6 = psVar8;
    psVar8 = psVar6 + 1;
  } while (*psVar6 != 0);
  FUN_00402160(&DAT_00f9388c,(int)(psVar6 + -0x7c9c46) >> 1);
  if (7 < local_44) {
    FUN_0089120c(local_58);
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  DAT_00fba7b0 = 0x1e;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 2;
    FUN_004e1590(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f93930 = *(undefined4 *)(param_1 + 2);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  _wcsncpy_s(&DAT_00f938f2,0x15,(wchar_t *)(param_1 + 0xc),0x14);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 4;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f94208 = (uint)*(ushort *)(param_1 + 0x38);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 5;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f9420c = (uint)*(ushort *)(param_1 + 0x36);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 6;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f94210 = *(short *)(param_1 + 0x3a) != 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 7;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f94288 = (uint)(*(char *)(param_1 + 0x3c) == '\0');
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 8;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  _DAT_00f9428c = *(undefined4 *)(param_1 + 0x3d);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 9;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f94363 = 0;
  _DAT_00f9435f = 0;
  _DAT_00f94364 = 0x3f800000;
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_c = 10;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
    local_c = 0xffffffff;
  }
  local_7c = 0x4c;
  FUN_005740f0(&local_7c);
  if (local_78 == DAT_00fe5aec) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar8 = (short *)(local_78 + 0x10);
  if (7 < *(uint *)(local_78 + 0x24)) {
    psVar8 = *(short **)psVar8;
  }
  local_44 = 7;
  local_48 = 0;
  local_58 = local_58 & 0xffff0000;
  psVar6 = psVar8;
  do {
    sVar2 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
  local_c = 0xb;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_c._0_1_ = 0xc;
    local_c._1_3_ = 0;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
    local_c = CONCAT31(local_c._1_3_,0xb);
  }
  FUN_004d6b30(&local_58);
  local_c = 0xffffffff;
  if (7 < local_44) {
    FUN_0089120c(local_58);
  }
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_c = 0xd;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
    local_c = 0xffffffff;
  }
  local_7c = 0x4d;
  FUN_005740f0(&local_7c);
  if (local_78 == DAT_00fe5aec) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar8 = (short *)(local_78 + 0x10);
  if (7 < *(uint *)(local_78 + 0x24)) {
    psVar8 = *(short **)psVar8;
  }
  local_58 = local_58 & 0xffff0000;
  local_44 = 7;
  local_48 = 0;
  psVar6 = psVar8;
  do {
    sVar2 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
  local_c = 0xe;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_c._0_1_ = 0xf;
    local_c._1_3_ = 0;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
    local_c = CONCAT31(local_c._1_3_,0xe);
  }
  FUN_004d6b30(&local_58);
  local_c = 0xffffffff;
  if (7 < local_44) {
    FUN_0089120c(local_58);
  }
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_c = 0x10;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
    local_c = 0xffffffff;
  }
  local_7c = 0x4e;
  FUN_005740f0(&local_7c);
  if (local_78 == DAT_00fe5aec) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar8 = (short *)(local_78 + 0x10);
  if (7 < *(uint *)(local_78 + 0x24)) {
    psVar8 = *(short **)psVar8;
  }
  local_44 = 7;
  local_48 = 0;
  local_58 = local_58 & 0xffff0000;
  psVar6 = psVar8;
  do {
    sVar2 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
  local_c = 0x11;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_c._0_1_ = 0x12;
    local_c._1_3_ = 0;
    FUN_004d4d10();
    _atexit((_func_4879 *)&LAB_00bccef0);
    local_c = CONCAT31(local_c._1_3_,0x11);
  }
  FUN_004d6b30(&local_58);
  local_c = 0xffffffff;
  if (7 < local_44) {
    FUN_0089120c(local_58);
  }
  if ((DAT_00fe5b08 & 1) == 0) {
    DAT_00fe5b08 = DAT_00fe5b08 | 1;
    local_c = 0x13;
    FUN_00584c40(&DAT_00fe5ae8);
    _atexit((_func_4879 *)&LAB_00bcf380);
    local_c = 0xffffffff;
  }
  local_7c = 0x4f;
  FUN_005740f0(&local_7c);
  if (local_78 != DAT_00fe5aec) {
    psVar8 = (short *)(local_78 + 0x10);
    if (7 < *(uint *)(local_78 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    local_58 = local_58 & 0xffff0000;
    local_44 = 7;
    local_48 = 0;
    psVar6 = psVar8;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
    local_c = 0x14;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 0x15;
      local_c._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_c = CONCAT31(local_c._1_3_,0x14);
    }
    FUN_004d6b30(&local_58);
    local_c = 0xffffffff;
    if (7 < local_44) {
      FUN_0089120c(local_58);
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_c = 0x16;
      FUN_00584c40(&DAT_00fe5ae8);
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_c = 0xffffffff;
    }
    local_7c = 0x50;
    FUN_005740f0(&local_7c);
    if (local_78 != DAT_00fe5aec) {
      psVar8 = (short *)(local_78 + 0x10);
      if (7 < *(uint *)(local_78 + 0x24)) {
        psVar8 = *(short **)psVar8;
      }
      local_24 = 7;
      local_28 = 0;
      local_38 = (uint)local_38._2_2_ << 0x10;
      psVar6 = psVar8;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
      local_c = 0x17;
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_c._0_1_ = 0x18;
        local_c._1_3_ = 0;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_c = CONCAT31(local_c._1_3_,0x17);
      }
      FUN_004d6b30(&local_38);
      local_c = 0xffffffff;
      if (7 < local_24) {
        FUN_0089120c(local_38);
      }
      local_24 = 7;
      local_28 = 0;
      local_38 = local_38 & 0xffff0000;
      if ((DAT_00faaf34 & 1) == 0) {
        DAT_00faaf34 = DAT_00faaf34 | 1;
        local_c = 0x19;
        FUN_004073c0();
        _atexit((_func_4879 *)&LAB_00bcccd0);
        local_c = 0xffffffff;
      }
      DAT_00faaf40 = 0;
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0x1a;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      if ((DAT_00f94288 == 0) && (*(char *)(local_64 + 0x3c) == '\x01')) {
        local_7c = 0x51;
        iVar5 = FUN_005855b0();
        FUN_005740f0(&local_7c);
        if (local_78 == *(int *)(iVar5 + 4)) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        psVar8 = (short *)(local_78 + 0x10);
        if (7 < *(uint *)(local_78 + 0x24)) {
          psVar8 = *(short **)psVar8;
        }
        local_44 = 7;
        local_48 = 0;
        local_58 = local_58 & 0xffff0000;
        psVar6 = psVar8;
        do {
          sVar2 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar8,(int)psVar6 - (int)(psVar8 + 1) >> 1);
        local_c = 0x1b;
        if ((DAT_00fb11e0 & 1) == 0) {
          DAT_00fb11e0 = DAT_00fb11e0 | 1;
          local_c._0_1_ = 0x1c;
          local_c._1_3_ = 0;
          FUN_004d4d10();
          _atexit((_func_4879 *)&LAB_00bccef0);
          local_c = CONCAT31(local_c._1_3_,0x1b);
        }
        FUN_004d6b30(&local_58);
        local_c = 0xffffffff;
        if (7 < local_44) {
          FUN_0089120c(local_58);
        }
        local_44 = 7;
        local_48 = 0;
        local_58 = local_58 & 0xffff0000;
      }
      if (param_2 < 0x41) {
        uVar4 = 0;
      }
      else {
        uVar4 = (param_2 - 0x41) / 0x35;
      }
      local_78 = 0;
      if (uVar4 != 0) {
        pbVar9 = (byte *)(local_64 + 0x6f);
        local_7c = uVar4;
        do {
          if ((DAT_00f94390 & 1) == 0) {
            DAT_00f94390 = DAT_00f94390 | 1;
            local_c = 0x1d;
            FUN_004e1590();
            _atexit((_func_4879 *)&LAB_00bccc80);
            local_c = 0xffffffff;
          }
          if ((*pbVar9 < 10) && ((uint)*pbVar9 * 0x210 + DAT_00f94304 != 0)) {
            FUN_004d4150();
          }
          if ((_DAT_00fb1314 & 1) == 0) {
            _DAT_00fb1314 = _DAT_00fb1314 | 1;
            _atexit((_func_4879 *)&DAT_00bccf10);
          }
          local_72 = *pbVar9;
          local_74 = 0x26;
          if (DAT_00fba798 == 0) {
            (**(code **)(*DAT_00fba854 + 0x10))(0,&local_74,3);
          }
          bVar1 = *pbVar9;
          pbVar9 = pbVar9 + 0x35;
          local_78 = CONCAT22(local_78._2_2_,(ushort)local_78 | 1 << (bVar1 - 1 & 0x1f));
          local_7c = local_7c - 1;
        } while (local_7c != 0);
      }
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0x1e;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      DAT_00f94240 = (ushort)local_78;
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0x1f;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      FUN_004e5fb0();
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_5e = 0x24;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_5e,2);
      }
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_5a = 0x1f;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_5a,2);
      }
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      uStack_5c = 0x25;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&uStack_5c,2);
      }
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_74 = 0x15;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_74,2);
      }
      uVar4 = 1;
      iVar5 = 0x210;
      do {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 0x20;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        if ((((uVar4 < 10) && (iVar7 = DAT_00f94304 + iVar5, *(int *)(iVar7 + 0x5c) != 0)) &&
            (iVar7 != 0)) && (*(int *)(iVar7 + 0x5c) != 0)) {
          local_7c = CONCAT13(1,CONCAT12((char)uVar4,0xda));
          if (DAT_00fba798 == 0) {
            (**(code **)(*DAT_00fba854 + 0x10))(0,&local_7c,4);
          }
          local_78._0_3_ = CONCAT12((char)uVar4,0xd2);
          if (DAT_00fba798 == 0) {
            (**(code **)(*DAT_00fba854 + 0x10))(0,&local_78,3);
          }
        }
        iVar5 = iVar5 + 0x210;
        uVar4 = uVar4 + 1;
      } while (iVar5 < 0x14a0);
      uStack_70 = 0xbb9;
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 0x21;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      uStack_6a = *(undefined4 *)(local_64 + 6);
      uStack_6e = DAT_00f941c0;
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(2,&uStack_70,10);
      }
      if ((DAT_00fb1378 & 1) == 0) {
        DAT_00fb1378 = DAT_00fb1378 | 1;
        local_c = 0x22;
        FUN_00539c20();
        _atexit((_func_4879 *)&LAB_00bccfb0);
        local_c = 0xffffffff;
      }
      FUN_0053b680();
      local_64 = CONCAT22(local_64._2_2_,0xa0);
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))(0,&local_64,2);
      }
      if ((_DAT_00fd8bf8 & 1) == 0) {
        _DAT_00fd8bf8 = _DAT_00fd8bf8 | 1;
        _DAT_00fd8bfc = 0;
        _atexit((_func_4879 *)&DAT_00bce310);
      }
      _DAT_00fd8bfc = timeGetTime();
      DAT_00fd8c00 = 1;
      ExceptionList = local_14;
      __security_check_cookie(local_1c ^ (uint)&local_7c);
      return;
    }
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

