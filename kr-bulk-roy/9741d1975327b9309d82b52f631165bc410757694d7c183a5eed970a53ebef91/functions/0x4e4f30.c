
void FUN_004e4f30(int param_1)

{
  short sVar1;
  uint uVar2;
  code *pcVar3;
  int iVar4;
  short *psVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  short *psVar8;
  undefined2 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 *local_38;
  undefined4 *local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933d5a;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = *(uint *)(param_1 + 2);
  if (uVar2 == 0) {
    uVar12 = *(undefined4 *)(param_1 + 9);
    iVar4 = FUN_00404ba0();
    uVar2 = DAT_00fe5b2c & 1;
    *(undefined4 *)(iVar4 + 0x6874) = uVar12;
    if (uVar2 == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_38 = (undefined4 *)0x14a;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar8 = (short *)(local_34 + 4);
    if (7 < (uint)local_34[9]) {
      psVar8 = *(short **)psVar8;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (uint)local_30._2_2_ << 0x10;
    psVar5 = psVar8;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
    local_8 = 1;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_004d6b30(&local_30);
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 3;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_34 = (undefined4 *)0x14a;
    FUN_005740f0(&local_34);
    if (local_38 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if ((uint)local_38[9] < 8) {
      puVar6 = local_38 + 4;
    }
    else {
      puVar6 = (undefined4 *)local_38[4];
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 4;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,puVar6,0,0);
  }
  else {
    if ((uVar2 & 2) == 0) {
      if ((uVar2 & 4) == 0) {
        if ((uVar2 & 8) == 0) {
          if ((uVar2 & 0x10) == 0) {
            if ((uVar2 & 0x20) == 0) {
              if ((uVar2 & 0x40) == 0) {
                if ((uVar2 & 0x200) == 0) {
                  if ((uVar2 & 0x400) == 0) {
                    if ((char)uVar2 < '\0') {
                      uVar12 = 0x153;
                      FUN_005854b0(0x153,local_14);
                      uVar12 = FUN_00585330(uVar12);
                      FUN_00402250(uVar12);
                      puVar6 = &local_30;
                      local_8 = 0xe;
                      FUN_0040f8c0(puVar6);
                      FUN_004d6b30(puVar6);
                      local_8 = 0xffffffff;
                      FUN_004fa440();
                      uVar12 = 0x153;
                    }
                    else {
                      if ((uVar2 & 0x800) == 0) goto LAB_004e5560;
                      uVar12 = 0x150;
                      FUN_005854b0(0x150,local_14);
                      uVar12 = FUN_00585330(uVar12);
                      FUN_00402250(uVar12);
                      puVar6 = &local_30;
                      local_8 = 0xf;
                      FUN_0040f8c0(puVar6);
                      FUN_004d6b30(puVar6);
                      local_8 = 0xffffffff;
                      FUN_004fa440();
                      uVar12 = 0x150;
                    }
                  }
                  else {
                    uVar12 = 0x152;
                    FUN_005854b0(0x152,local_14);
                    uVar12 = FUN_00585330(uVar12);
                    FUN_00402250(uVar12);
                    puVar6 = &local_30;
                    local_8 = 0xd;
                    FUN_0040f8c0(puVar6);
                    FUN_004d6b30(puVar6);
                    local_8 = 0xffffffff;
                    FUN_004fa440();
                    uVar12 = 0x152;
                  }
                }
                else {
                  uVar12 = 0x151;
                  FUN_005854b0(0x151,local_14);
                  uVar12 = FUN_00585330(uVar12);
                  FUN_00402250(uVar12);
                  puVar6 = &local_30;
                  local_8 = 0xc;
                  FUN_0040f8c0(puVar6);
                  FUN_004d6b30(puVar6);
                  local_8 = 0xffffffff;
                  FUN_004fa440();
                  uVar12 = 0x151;
                }
              }
              else {
                uVar12 = 0x14f;
                FUN_005854b0(0x14f,local_14);
                uVar12 = FUN_00585330(uVar12);
                FUN_00402250(uVar12);
                puVar6 = &local_30;
                local_8 = 0xb;
                FUN_0040f8c0(puVar6);
                FUN_004d6b30(puVar6);
                local_8 = 0xffffffff;
                FUN_004fa440();
                uVar12 = 0x14f;
              }
            }
            else {
              uVar12 = 0x149;
              FUN_005854b0(0x149,local_14);
              uVar12 = FUN_00585330(uVar12);
              FUN_00402250(uVar12);
              puVar6 = &local_30;
              local_8 = 10;
              FUN_0040f8c0(puVar6);
              FUN_004d6b30(puVar6);
              local_8 = 0xffffffff;
              FUN_004fa440();
              uVar12 = 0x149;
            }
          }
          else {
            uVar12 = 0x14e;
            FUN_005854b0(0x14e,local_14);
            uVar12 = FUN_00585330(uVar12);
            FUN_00402250(uVar12);
            puVar6 = &local_30;
            local_8 = 9;
            FUN_0040f8c0(puVar6);
            FUN_004d6b30(puVar6);
            local_8 = 0xffffffff;
            FUN_004fa440();
            uVar12 = 0x14e;
          }
        }
        else {
          uVar12 = 0x14d;
          FUN_005854b0(0x14d,local_14);
          uVar12 = FUN_00585330(uVar12);
          FUN_00402250(uVar12);
          puVar6 = &local_30;
          local_8 = 8;
          FUN_0040f8c0(puVar6);
          FUN_004d6b30(puVar6);
          local_8 = 0xffffffff;
          FUN_004fa440();
          uVar12 = 0x14d;
        }
      }
      else {
        uVar12 = 0x14c;
        FUN_005854b0(0x14c,local_14);
        uVar12 = FUN_00585330(uVar12);
        FUN_00402250(uVar12);
        puVar6 = &local_30;
        local_8 = 7;
        FUN_0040f8c0(puVar6);
        FUN_004d6b30(puVar6);
        local_8 = 0xffffffff;
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
        uVar12 = 0x14c;
      }
      uVar11 = 0;
      uVar10 = 0;
      puVar9 = &DAT_00bed1fc;
      FUN_005854b0(uVar12,&DAT_00bed1fc,0,0);
      puVar6 = (undefined4 *)FUN_00585330(uVar12);
    }
    else {
      local_34 = (undefined4 *)0x14b;
      iVar4 = FUN_005854b0();
      FUN_005740f0(&local_34);
      if (local_38 == *(undefined4 **)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar8 = (short *)(local_38 + 4);
      if (7 < (uint)local_38[9]) {
        psVar8 = *(short **)psVar8;
      }
      local_30 = (uint)local_30._2_2_ << 0x10;
      local_1c = 7;
      local_20 = 0;
      psVar5 = psVar8;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
      local_8 = 5;
      if ((DAT_00fb11e0 & 1) == 0) {
        DAT_00fb11e0 = DAT_00fb11e0 | 1;
        local_8._0_1_ = 6;
        local_8._1_3_ = 0;
        FUN_004d4d10();
        _atexit((_func_4879 *)&LAB_00bccef0);
        local_8 = CONCAT31(local_8._1_3_,5);
      }
      FUN_004d6b30(&local_30);
      local_8 = 0xffffffff;
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
      local_34 = (undefined4 *)0x14b;
      iVar4 = FUN_005854b0();
      FUN_005740f0(&local_34);
      if (local_38 == *(undefined4 **)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      puVar6 = local_38 + 4;
      if ((uint)local_38[9] < 8) {
        uVar11 = 0;
        uVar10 = 0;
        puVar9 = &DAT_00bed1fc;
      }
      else {
        puVar6 = (undefined4 *)*puVar6;
        uVar11 = 0;
        uVar10 = 0;
        puVar9 = &DAT_00bed1fc;
      }
    }
    FUN_00404b10(0xca,puVar6,puVar9,uVar10,uVar11);
  }
LAB_004e5560:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0x10;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar7 = (undefined4 *)FUN_00891268(0x14);
  puVar6 = (undefined4 *)0x0;
  if (puVar7 != (undefined4 *)0x0) {
    puVar7[3] = 0;
    *puVar7 = FoxUI::FXUIEvent::vftable;
    puVar7[1] = 0xffffffff;
    puVar7[2] = 0xffffffff;
    puVar7[4] = 0xf4416;
    puVar6 = puVar7;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0x11;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  local_34 = puVar6;
  FUN_00804260(&local_34);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

