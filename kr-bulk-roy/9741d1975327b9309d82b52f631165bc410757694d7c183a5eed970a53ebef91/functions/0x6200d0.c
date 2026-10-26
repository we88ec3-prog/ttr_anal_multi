
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006200d0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  float *pfVar6;
  undefined4 *puVar7;
  int *in_ECX;
  int iVar8;
  undefined1 auStack_6c [4];
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  undefined4 local_58;
  uint auStack_54 [4];
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092dcf0;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_6c;
  ExceptionList = &local_14;
  local_58 = param_1;
  if (in_ECX != (int *)0x0) {
    iVar5 = (**(code **)(*in_ECX + 4))(DAT_00d61f20 ^ (uint)&stack0xffffff88);
    if (iVar5 == 0x105bd) goto LAB_00620138;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  in_ECX = (int *)0x0;
LAB_00620138:
  if (in_ECX[5] == 0x6a7) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb9129 = DAT_00fb9128;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 1;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb9135 = DAT_00fb9134;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 2;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb92e5 = 3;
    if (DAT_00fb92e7 < 3) {
      DAT_00fb92e5 = DAT_00fb92e7;
    }
    if (DAT_00fb92e5 < DAT_00fb92e6) {
      DAT_00fb92e5 = DAT_00fb92e6;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 3;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb90f9 = DAT_00fb90f8;
    FUN_0061fc20(DAT_00fb90f8 != '\0');
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 4;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb9225 = DAT_00fb9224;
    FUN_0061fcb0(DAT_00fb9224 != '\0');
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 5;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    _DAT_00fb9144 = DAT_00fb9140;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 6;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 7;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 8;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 9;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    _DAT_00fb9174 = DAT_00fb9170;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 10;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0xb;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0xc;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0xd;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    _DAT_00fb915c = DAT_00fb9158;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0xe;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0xf;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x10;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0x11;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    _DAT_00fb918c = DAT_00fb9188;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x12;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x13;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x14;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0x15;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    _DAT_00fb91bc = DAT_00fb91b8;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x16;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x17;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x18;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0x19;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    _DAT_00fb91a4 = DAT_00fb91a0;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x1a;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x1b;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x1c;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0x1d;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    DAT_00fb9234 = DAT_00fb9230;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x1e;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x1f;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x20;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0x21;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    DAT_00fb90ea = DAT_00fb90e8;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x22;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x23;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x24;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0x25;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    DAT_00fb935c = DAT_00fb9358;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x26;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x27;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x28;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
        }
      }
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    auStack_54[0] = auStack_54[0] & 0xffffff00;
    FUN_0040b310("Character");
    local_c._1_3_ = 0;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x2a;
      local_c._1_3_ = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_60 = DAT_00fb9234;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x2b;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_68 = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x2c;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_c._0_1_ = 0x29;
    fStack_64 = (float)FUN_0080c1c0(auStack_54);
    if ((fStack_64 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
      fStack_5c = DAT_00fab054;
      pfVar6 = &fStack_5c;
    }
    else {
      pfVar6 = &fStack_64;
    }
    iVar5 = DAT_00fab04c;
    if (*pfVar6 != DAT_00fab054) {
      iVar5 = *(int *)((int)*pfVar6 + 0x28);
    }
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 1;
    uVar1 = DAT_00fab0d4 & 1;
    fStack_68 = fStack_60 * fStack_68;
    *(float *)(iVar5 + 0x24) = fStack_68;
    if (uVar1 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x2d;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c._0_1_ = 0x29;
    }
    FUN_0080c0a0();
    local_c = 0xffffffff;
    if (0xf < uStack_40) {
      FUN_0089120c(auStack_54[0]);
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    auStack_54[0] = auStack_54[0] & 0xffffff00;
    FUN_0040b310("Battle");
    local_c._1_3_ = 0;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x2f;
      local_c._1_3_ = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_5c = DAT_00fb9234;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x30;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_64 = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x31;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_c._0_1_ = 0x2e;
    fStack_68 = (float)FUN_0080c1c0(auStack_54);
    if ((fStack_68 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
      fStack_60 = DAT_00fab054;
      pfVar6 = &fStack_60;
    }
    else {
      pfVar6 = &fStack_68;
    }
    iVar5 = DAT_00fab04c;
    if (*pfVar6 != DAT_00fab054) {
      iVar5 = *(int *)((int)*pfVar6 + 0x28);
    }
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 1;
    uVar1 = DAT_00fab0d4 & 1;
    fStack_68 = fStack_5c * 0.57 * fStack_64;
    *(float *)(iVar5 + 0x24) = fStack_68;
    if (uVar1 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x32;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c._0_1_ = 0x2e;
    }
    FUN_0080c0a0();
    local_c = 0xffffffff;
    if (0xf < uStack_40) {
      FUN_0089120c(auStack_54[0]);
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    auStack_54[0] = auStack_54[0] & 0xffffff00;
    FUN_0040b310("Damage");
    local_c._1_3_ = 0;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x34;
      local_c._1_3_ = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_5c = DAT_00fb9234;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x35;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_64 = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x36;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_c._0_1_ = 0x33;
    fStack_68 = (float)FUN_0080c1c0(auStack_54);
    if ((fStack_68 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
      fStack_60 = DAT_00fab054;
      pfVar6 = &fStack_60;
    }
    else {
      pfVar6 = &fStack_68;
    }
    iVar5 = DAT_00fab04c;
    if (*pfVar6 != DAT_00fab054) {
      iVar5 = *(int *)((int)*pfVar6 + 0x28);
    }
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 1;
    uVar1 = DAT_00fab0d4 & 1;
    fStack_68 = fStack_5c * 0.714 * fStack_64;
    *(float *)(iVar5 + 0x24) = fStack_68;
    if (uVar1 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x37;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c._0_1_ = 0x33;
    }
    FUN_0080c0a0();
    local_c = 0xffffffff;
    if (0xf < uStack_40) {
      FUN_0089120c(auStack_54[0]);
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x38;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb924c = DAT_00fb9248;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x39;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x3a;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x3b;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
        }
      }
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    auStack_54[0] = auStack_54[0] & 0xffffff00;
    FUN_0040b310(&DAT_00c05800);
    local_c._1_3_ = 0;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x3d;
      local_c._1_3_ = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_5c = DAT_00fb924c;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x3e;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_64 = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x3f;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_c._0_1_ = 0x3c;
    fStack_68 = (float)FUN_0080c1c0(auStack_54);
    if ((fStack_68 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
      fStack_60 = DAT_00fab054;
      pfVar6 = &fStack_60;
    }
    else {
      pfVar6 = &fStack_68;
    }
    iVar5 = DAT_00fab04c;
    if (*pfVar6 != DAT_00fab054) {
      iVar5 = *(int *)((int)*pfVar6 + 0x28);
    }
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 1;
    uVar1 = DAT_00fab0d4 & 1;
    fStack_68 = fStack_5c * fStack_64;
    *(float *)(iVar5 + 0x24) = fStack_68;
    if (uVar1 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x40;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c._0_1_ = 0x3c;
    }
    FUN_0080c0a0();
    local_c = 0xffffffff;
    if (0xf < uStack_40) {
      FUN_0089120c(auStack_54[0]);
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x41;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb9264 = DAT_00fb9260;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x42;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x43;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x44;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
        }
      }
    }
    uStack_40 = 0xf;
    uStack_44 = 0;
    auStack_54[0] = auStack_54[0] & 0xffffff00;
    FUN_0040b310("Voice");
    local_c._1_3_ = 0;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x46;
      local_c._1_3_ = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_64 = DAT_00fb9234;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c._0_1_ = 0x47;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    fStack_5c = DAT_00fb935c;
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x48;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
    }
    local_c._0_1_ = 0x45;
    fStack_68 = (float)FUN_0080c1c0(auStack_54);
    if ((fStack_68 == DAT_00fab054) || (cVar3 = FUN_005436a0(), cVar3 != '\0')) {
      fStack_60 = DAT_00fab054;
      pfVar6 = &fStack_60;
    }
    else {
      pfVar6 = &fStack_68;
    }
    iVar5 = DAT_00fab04c;
    if (*pfVar6 != DAT_00fab054) {
      iVar5 = *(int *)((int)*pfVar6 + 0x28);
    }
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | 1;
    uVar1 = DAT_00fab0d4 & 1;
    fStack_68 = fStack_5c * fStack_64;
    *(float *)(iVar5 + 0x24) = fStack_68;
    if (uVar1 == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_c._0_1_ = 0x49;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_c._0_1_ = 0x45;
    }
    FUN_0080c0a0();
    local_c = 0xffffffff;
    if (0xf < uStack_40) {
      FUN_0089120c(auStack_54[0]);
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x4a;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb92d6 = DAT_00fb92d4;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x4b;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
      if ((DAT_00fb8828 & 1) == 0) {
        DAT_00fb8828 = DAT_00fb8828 | 1;
        local_c = 0x4c;
        FUN_0054f850();
        _atexit((_func_4879 *)&LAB_00bcd580);
        local_c = 0xffffffff;
        if ((DAT_00fb8828 & 1) == 0) {
          DAT_00fb8828 = DAT_00fb8828 | 1;
          local_c = 0x4d;
          FUN_0054f850();
          _atexit((_func_4879 *)&LAB_00bcd580);
          local_c = 0xffffffff;
          if ((DAT_00fb8828 & 1) == 0) {
            DAT_00fb8828 = DAT_00fb8828 | 1;
            local_c = 0x4e;
            FUN_0054f850();
            _atexit((_func_4879 *)&LAB_00bcd580);
            local_c = 0xffffffff;
          }
        }
      }
    }
    sVar4 = DAT_00fb90ea;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x4f;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    fStack_68 = DAT_00fb935c;
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c = 0x50;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c = 0xffffffff;
    }
    piVar2 = DAT_00fc0ffc;
    if (DAT_00fc0ffc != (int *)0x0) {
      fStack_68 = (float)(int)sVar4;
      FUN_008fed10();
      FUN_006daa70();
      _DAT_00fc106c = FUN_008fed10();
      (**(code **)(*piVar2 + 0x48))(_DAT_00fc106c);
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x51;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    sVar4 = DAT_00fb92d6;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x52;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    fStack_68 = DAT_00fb935c;
    if ((DAT_00fc0fc0 & 1) == 0) {
      DAT_00fc0fc0 = DAT_00fc0fc0 | 1;
      local_c = 0x53;
      FUN_006d8e50();
      _atexit((_func_4879 *)&LAB_00bcdbb0);
      local_c = 0xffffffff;
    }
    piVar2 = DAT_00fc1034;
    if (DAT_00fc1034 != (int *)0x0) {
      fStack_68 = (float)(int)sVar4;
      sVar4 = FUN_008fed10();
      (**(code **)(*piVar2 + 0x48))((int)sVar4);
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x54;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    fStack_64 = 1.43493e-42;
    DAT_00fb92aa = DAT_00fb92ae;
    if (0x3ff < (short)DAT_00fb92ae) {
      fStack_64._0_2_ = 0x400;
      DAT_00fb92aa = fStack_64._0_2_;
    }
    if ((short)DAT_00fb92aa < (short)DAT_00fb92ac) {
      fStack_64 = (float)(uint)DAT_00fb92ac;
      DAT_00fb92aa = DAT_00fb92ac;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x55;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    fStack_64 = 1.0762e-42;
    DAT_00fb92ba = DAT_00fb92be;
    if (0x2ff < (short)DAT_00fb92be) {
      fStack_64._0_2_ = 0x300;
      DAT_00fb92ba = fStack_64._0_2_;
    }
    if ((short)DAT_00fb92ba < (short)DAT_00fb92bc) {
      fStack_64 = (float)(uint)DAT_00fb92bc;
      DAT_00fb92ba = DAT_00fb92bc;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x56;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    DAT_00fb92c9 = 0x20;
    if (DAT_00fb92cb < 0x20) {
      DAT_00fb92c9 = DAT_00fb92cb;
    }
    if (DAT_00fb92c9 < DAT_00fb92ca) {
      DAT_00fb92c9 = DAT_00fb92ca;
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x57;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    iVar5 = (int)(short)DAT_00fb92aa;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x58;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    iVar8 = (int)(short)DAT_00fb92ba;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0x59;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    FUN_006dedf0(iVar5,iVar8,DAT_00fb92c9);
    FUN_006e32a0();
    if ((DAT_00faaf7c & 1) == 0) {
      DAT_00faaf7c = DAT_00faaf7c | 1;
      local_c = 0x5a;
      FUN_0058d410();
      _atexit((_func_4879 *)&LAB_00bccdc0);
      local_c = 0xffffffff;
    }
    puVar7 = (undefined4 *)FUN_0040ef80();
    local_c = 0x5b;
    if (7 < (uint)puVar7[5]) {
      puVar7 = (undefined4 *)*puVar7;
    }
    FUN_0058cd50(&DAT_00faaf84,puVar7);
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    uStack_24 = 7;
    uStack_28 = 0;
    uStack_38 = uStack_38 & 0xffff0000;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0x5c;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    FUN_00589a20(0x3f800000,0x3f800000);
    if ((DAT_00faaf7c & 1) == 0) {
      DAT_00faaf7c = DAT_00faaf7c | 1;
      local_c = 0x5d;
      FUN_0058d410();
      _atexit((_func_4879 *)&LAB_00bccdc0);
      local_c = 0xffffffff;
    }
    FUN_0058e110(&DAT_00faaf80);
    FUN_006221d0();
    puVar7 = (undefined4 *)FUN_00891268(0x14);
    if (puVar7 != (undefined4 *)0x0) {
      *puVar7 = FoxUI::FXUIEvent::vftable;
      puVar7[1] = 0xffffffff;
      puVar7[2] = 0xffffffff;
      puVar7[3] = 0;
      puVar7[4] = 0xf43d1;
    }
    FUN_004072a0();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_6c);
  return;
}

