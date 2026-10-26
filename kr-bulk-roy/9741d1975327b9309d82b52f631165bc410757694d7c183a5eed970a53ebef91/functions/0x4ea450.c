
void FUN_004ea450(undefined1 *param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  short *psVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 *in_ECX;
  undefined2 local_b4 [8];
  undefined4 local_a4;
  undefined2 *local_a0;
  undefined1 **ppuStack_9c;
  undefined2 local_98 [8];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 uStack_80;
  short *psStack_7c;
  undefined1 *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  undefined1 *local_58;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092fdda;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  cVar1 = param_1[2];
  local_60 = param_1;
  local_64 = in_ECX;
  if (cVar1 == '\0') {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 0;
      FUN_004f3d80();
      psStack_7c = (short *)0x4ea4c6;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_c = 1;
      FUN_004f3d80();
      psStack_7c = (short *)0x4ea4fc;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_c = 2;
      psStack_7c = (short *)0x4ea525;
      FUN_00584c40();
      psStack_7c = (short *)0x4ea52f;
      _atexit((_func_4879 *)&LAB_00bcf380);
    }
    local_c = 0xffffffff;
    local_58 = &DAT_0000001b;
    psStack_7c = (short *)0x4ea551;
    FUN_005740f0();
    if (local_5c == DAT_00fe5aec) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psStack_7c = (short *)0x4ea57e;
    FUN_004f6a30();
    psStack_7c = (short *)0x4ea591;
    FUN_004f6a30();
    psStack_7c = (short *)0x4ea59f;
    psStack_7c = (short *)FUN_00498ef0();
    local_c = 3;
    if (7 < *(uint *)(psStack_7c + 10)) {
      psStack_7c = *(short **)psStack_7c;
    }
    local_54 = (uint)local_54._2_2_ << 0x10;
    local_40 = 7;
    local_44 = 0;
    psVar6 = psStack_7c;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    uStack_80 = 0x4ea5ec;
    FUN_00402160();
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_c._0_1_ = 5;
      FUN_004d4d10();
      psStack_7c = (short *)0x4ea616;
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_c = CONCAT31(local_c._1_3_,4);
    psStack_7c = (short *)0x4ea62c;
    FUN_004d6b30();
    if (7 < local_40) {
      psStack_7c = (short *)0x4ea641;
      FUN_0089120c();
    }
    local_c = 0xffffffff;
    local_40 = 7;
    local_44 = 0;
    local_54 = local_54 & 0xffff0000;
    if (7 < local_24) {
      psStack_7c = (short *)0x4ea673;
      FUN_0089120c();
    }
    iVar7 = FUN_00404ba0();
    puVar4 = local_64;
    if (*(int *)(local_64 + 0x5ec8) == *(int *)(iVar7 + 0x5f50)) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 6;
        FUN_00587480();
        psStack_7c = (short *)0x4ea6b8;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      psStack_7c = (short *)0x0;
      local_58 = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)0x0;
      local_84 = 7;
      local_88 = 0;
      local_a0 = &DAT_00bed1fc;
      local_98[0] = 0;
      local_a4 = 0x4ea6e6;
      FUN_00402160();
      local_c = 7;
      local_64 = (undefined1 *)0x88;
      ppuStack_9c = (undefined1 **)0x4ea6fa;
      iVar7 = FUN_005854b0();
      ppuStack_9c = &local_64;
      local_a0 = (undefined2 *)0x4ea70c;
      FUN_005740f0();
      if (local_5c == *(undefined1 **)(iVar7 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar6 = (short *)(local_5c + 0x10);
      if (7 < *(uint *)(local_5c + 0x24)) {
        psVar6 = *(short **)psVar6;
      }
      local_64 = (undefined1 *)local_b4;
      local_a0 = (undefined2 *)0x7;
      local_a4 = 0;
      local_b4[0] = 0;
      psVar8 = psVar6;
      do {
        sVar2 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar6,(int)psVar8 - (int)(psVar6 + 1) >> 1);
      local_c = 0xffffffff;
      FUN_0058b270(0xca);
    }
    puVar5 = local_60;
    psStack_7c = (short *)0x4ea785;
    iVar7 = FUN_004ec270();
    psStack_7c = (short *)0x4ea796;
    iVar9 = FUN_004ec270();
    *(undefined4 *)(puVar4 + 0x5ec8) = *(undefined4 *)(puVar5 + 3);
    if (iVar7 != 0) {
      *(undefined1 *)(iVar7 + 0x12) = 1;
      *(undefined2 *)(iVar7 + 0x14) = 7;
    }
    if (iVar9 != 0) {
      *(undefined1 *)(iVar9 + 0x12) = 0;
      *(undefined2 *)(iVar9 + 0x14) = 0;
    }
  }
  else {
    if (cVar1 == '\x01') {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 8;
        FUN_00587480();
        psStack_7c = (short *)0x4ea7f5;
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_c = 0xffffffff;
      psStack_7c = (short *)0x0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)0x0;
      local_84 = 7;
      local_88 = 0;
      local_a0 = &DAT_00bed1fc;
      local_98[0] = 0;
      local_a4 = 0x4ea828;
      FUN_00402160();
      local_c = 9;
      local_60 = (undefined1 *)0x68;
      ppuStack_9c = (undefined1 **)0x4ea840;
      iVar7 = FUN_005854b0();
      ppuStack_9c = &local_60;
      local_a0 = (undefined2 *)0x4ea852;
      FUN_005740f0();
      if (local_64 == *(undefined1 **)(iVar7 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar6 = (short *)(local_64 + 0x10);
      if (7 < *(uint *)(local_64 + 0x24)) {
        psVar6 = *(short **)psVar6;
      }
      local_60 = (undefined1 *)local_b4;
      local_a0 = (undefined2 *)0x7;
      local_a4 = 0;
      local_b4[0] = 0;
      psVar8 = psVar6;
      do {
        sVar2 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar6,(int)psVar8 - (int)(psVar6 + 1) >> 1);
    }
    else {
      if (cVar1 != '\x02') goto LAB_004ea908;
      FUN_004054c0();
      psStack_7c = (short *)0x0;
      local_60 = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)&DAT_00bed1fc;
      local_a0 = (undefined2 *)0x4ea8c8;
      FUN_00402250();
      ppuStack_9c = (undefined1 **)0x4;
      local_c = 10;
      local_a0 = (undefined2 *)0x4ea8da;
      FUN_005854b0();
      local_a0 = (undefined2 *)0x4ea8e1;
      uVar10 = FUN_00585330();
      local_64 = (undefined1 *)local_b4;
      FUN_00402250(uVar10);
    }
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
  }
LAB_004ea908:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xb;
    FUN_00587480();
    psStack_7c = (short *)0x4ea92f;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  psStack_7c = (short *)0x4ea944;
  FUN_0058aad0();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

