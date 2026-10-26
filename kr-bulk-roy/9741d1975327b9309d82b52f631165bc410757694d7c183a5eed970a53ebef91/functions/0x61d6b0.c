
void FUN_0061d6b0(int param_1)

{
  short sVar1;
  uint uVar2;
  code *pcVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  short *psVar8;
  undefined4 uVar9;
  undefined1 *puVar10;
  undefined1 auStack_64 [4];
  int local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  undefined1 local_38 [28];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00943076;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff90;
  ExceptionList = &local_14;
  local_58 = param_1;
  if ((*(int *)(param_1 + 0xfc) != 0) && (*(int *)(in_ECX + 2) == 0)) {
    FUN_0061d360(param_1);
    goto LAB_0061dd06;
  }
  uVar2 = *(uint *)(in_ECX + 2);
  if (uVar2 == 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    DAT_00f94254 = *(undefined4 *)(in_ECX + 7);
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_c = 0xffffffff;
    local_5c = 0x155;
    FUN_005740f0(&local_5c);
    if (local_60 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar8 = (short *)(local_60 + 0x10);
    if (7 < *(uint *)(local_60 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    local_54 = (uint)local_54._2_2_ << 0x10;
    local_40 = 7;
    local_44 = 0;
    psVar5 = psVar8;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
    local_c = 2;
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 3;
      local_c._1_3_ = 0;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_c = CONCAT31(local_c._1_3_,2);
    }
    FUN_004d6b30(&local_54);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 4;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_60 = 0x155;
    FUN_005740f0(&local_60);
    if (local_5c == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    if (*(uint *)(local_5c + 0x24) < 8) {
      iVar6 = local_5c + 0x10;
    }
    else {
      iVar6 = *(int *)(local_5c + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 5;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar6,0,0);
    param_1 = local_58;
  }
  else if ((uVar2 & 4) == 0) {
    if ((uVar2 & 0x10) == 0) {
      if ((uVar2 & 0x20) == 0) {
        if ((uVar2 & 0x40) == 0) {
          if ((char)uVar2 < '\0') {
            uVar9 = 0x159;
            FUN_005854b0(0x159,uVar4);
            uVar9 = FUN_00585330(uVar9);
            FUN_00402250(uVar9);
            puVar7 = &local_54;
            local_c = 10;
            FUN_0040f8c0(puVar7);
            FUN_004d6b30(puVar7);
            local_c = 0xffffffff;
            FUN_004fa440();
            uVar9 = 0x159;
          }
          else if ((uVar2 & 0x100) == 0) {
            if ((uVar2 & 0x200) == 0) {
              if ((uVar2 & 0x400) == 0) {
                param_1 = param_1;
                if ((uVar2 & 8) == 0) goto LAB_0061dcea;
                uVar9 = 0x15d;
                FUN_005854b0(0x15d,uVar4);
                uVar9 = FUN_00585330(uVar9);
                FUN_00402250(uVar9);
                puVar10 = local_38;
                local_c = 0xe;
                FUN_0040f8c0(puVar10);
                FUN_004d6b30(puVar10);
                local_c = 0xffffffff;
                FUN_004fa440();
                uVar9 = 0x15d;
              }
              else {
                uVar9 = 0x15c;
                FUN_005854b0(0x15c,uVar4);
                uVar9 = FUN_00585330(uVar9);
                FUN_00402250(uVar9);
                puVar7 = &local_54;
                local_c = 0xd;
                FUN_0040f8c0(puVar7);
                FUN_004d6b30(puVar7);
                local_c = 0xffffffff;
                FUN_004fa440();
                uVar9 = 0x15c;
              }
            }
            else {
              uVar9 = 0x15b;
              FUN_005854b0(0x15b,uVar4);
              uVar9 = FUN_00585330(uVar9);
              FUN_00402250(uVar9);
              puVar7 = &local_54;
              local_c = 0xc;
              FUN_0040f8c0(puVar7);
              FUN_004d6b30(puVar7);
              local_c = 0xffffffff;
              FUN_004fa440();
              uVar9 = 0x15b;
            }
          }
          else {
            uVar9 = 0x15a;
            FUN_005854b0(0x15a,uVar4);
            uVar9 = FUN_00585330(uVar9);
            FUN_00402250(uVar9);
            puVar7 = &local_54;
            local_c = 0xb;
            FUN_0040f8c0(puVar7);
            FUN_004d6b30(puVar7);
            local_c = 0xffffffff;
            FUN_004fa440();
            uVar9 = 0x15a;
          }
        }
        else {
          uVar9 = 0x158;
          FUN_005854b0(0x158,uVar4);
          uVar9 = FUN_00585330(uVar9);
          FUN_00402250(uVar9);
          puVar7 = &local_54;
          local_c = 9;
          FUN_0040f8c0(puVar7);
          FUN_004d6b30(puVar7);
          local_c = 0xffffffff;
          FUN_004fa440();
          uVar9 = 0x158;
        }
      }
      else {
        uVar9 = 0x157;
        FUN_005854b0(0x157,uVar4);
        uVar9 = FUN_00585330(uVar9);
        FUN_00402250(uVar9);
        puVar7 = &local_54;
        local_c = 8;
        FUN_0040f8c0(puVar7);
        FUN_004d6b30(puVar7);
        local_c = 0xffffffff;
        FUN_004fa440();
        uVar9 = 0x157;
      }
    }
    else {
      uVar9 = 0x149;
      FUN_005854b0(0x149,uVar4);
      uVar9 = FUN_00585330(uVar9);
      FUN_00402250(uVar9);
      puVar7 = &local_54;
      local_c = 7;
      FUN_0040f8c0(puVar7);
      FUN_004d6b30(puVar7);
      local_c = 0xffffffff;
      FUN_004fa440();
      uVar9 = 0x149;
    }
    FUN_005854b0(uVar9,&DAT_00bed1fc,0,0);
    uVar9 = FUN_00585330(uVar9);
    FUN_00404b10(0xca,uVar9);
  }
  else {
    local_60 = 0x156;
    iVar6 = FUN_005854b0();
    FUN_005740f0(&local_60);
    if (local_5c == *(int *)(iVar6 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puVar7 = (undefined4 *)(local_5c + 0x10);
    if (7 < *(uint *)(local_5c + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    FUN_00402250(puVar7);
    puVar7 = &local_54;
    local_c = 6;
    FUN_0040f8c0(puVar7);
    FUN_004d6b30(puVar7);
    local_c = 0xffffffff;
    if (7 < local_40) {
      FUN_0089120c(local_54);
    }
    local_60 = 0x156;
    iVar6 = FUN_005854b0();
    FUN_005740f0(&local_60);
    if (local_5c == *(int *)(iVar6 + 4)) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    puVar7 = (undefined4 *)(local_5c + 0x10);
    if (7 < *(uint *)(local_5c + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    FUN_00404b10(0xca,puVar7,&DAT_00bed1fc,0,0);
    param_1 = local_58;
  }
LAB_0061dcea:
  *(undefined4 *)(param_1 + 0x214) = 0;
  FUN_00823850();
  FUN_0061c660();
LAB_0061dd06:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

