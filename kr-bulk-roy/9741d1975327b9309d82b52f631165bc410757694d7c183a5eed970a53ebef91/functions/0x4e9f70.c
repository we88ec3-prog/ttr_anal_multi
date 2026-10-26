
void FUN_004e9f70(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined2 local_ac [8];
  undefined4 local_9c;
  undefined2 *local_98;
  undefined1 **ppuStack_94;
  undefined2 local_90;
  undefined4 local_80;
  undefined *local_7c;
  undefined4 uStack_78;
  short *psStack_74;
  undefined1 *local_54;
  undefined1 *local_50 [6];
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fea2;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    iVar4 = FUN_00404ba0();
    if (*(int *)(in_ECX + 0x5ec8) == *(int *)(iVar4 + 0x5f50)) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        psStack_74 = (short *)0x4e9fe9;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      psStack_74 = (short *)0x0;
      ppuStack_94 = (undefined1 **)0x0;
      local_7c = (undefined *)0x7;
      local_80 = 0;
      local_98 = &DAT_00bed1fc;
      local_90 = 0;
      local_9c = 0x4ea01d;
      FUN_00402160();
      local_8 = 1;
      local_54 = (undefined1 *)0x6b;
      ppuStack_94 = (undefined1 **)0x4ea030;
      iVar4 = FUN_005854b0();
      ppuStack_94 = &local_54;
      local_98 = (undefined2 *)0x4ea040;
      FUN_005740f0();
      if (local_50[0] == *(undefined1 **)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar5 = (short *)(local_50[0] + 0x10);
      if (7 < *(uint *)(local_50[0] + 0x24)) {
        psVar5 = *(short **)psVar5;
      }
      local_50[0] = (undefined1 *)local_ac;
      local_9c = 0;
      local_98 = (undefined2 *)0x7;
      local_ac[0] = 0;
      psVar6 = psVar5;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
    }
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8 = 2;
      FUN_004f3d80();
      psStack_74 = (short *)0x4ea0d4;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fe5b08 & 1) == 0) {
      DAT_00fe5b08 = DAT_00fe5b08 | 1;
      local_8 = 3;
      psStack_74 = (short *)0x4ea0fb;
      FUN_00584c40();
      psStack_74 = (short *)0x4ea105;
      _atexit((_func_4879 *)&LAB_00bcf380);
      local_8 = 0xffffffff;
    }
    local_50[0] = (undefined1 *)0x1a;
    psStack_74 = (short *)0x4ea123;
    FUN_005740f0();
    if (local_54 == DAT_00fe5aec) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psStack_74 = (short *)0x4ea152;
    FUN_004f7370();
    psStack_74 = (short *)0x4ea160;
    psStack_74 = (short *)FUN_00498ef0();
    local_8 = 4;
    if (7 < *(uint *)(psStack_74 + 10)) {
      psStack_74 = *(short **)psStack_74;
    }
    local_30 = (uint)local_30._2_2_ << 0x10;
    local_1c = 7;
    local_20 = 0;
    psVar5 = psStack_74;
    do {
      sVar2 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar2 != 0);
    uStack_78 = 0x4ea1a9;
    FUN_00402160();
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 6;
      FUN_004d4d10();
      psStack_74 = (short *)0x4ea1d1;
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = CONCAT31(local_8._1_3_,5);
    psStack_74 = (short *)0x4ea1e5;
    FUN_004d6b30();
    if (7 < local_1c) {
      psStack_74 = (short *)0x4ea1f8;
      FUN_0089120c();
    }
    local_8 = 0xffffffff;
    local_1c = 7;
    local_20 = 0;
    local_30 = local_30 & 0xffff0000;
    if (7 < local_38) {
      psStack_74 = (short *)0x4ea224;
      FUN_0089120c();
    }
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8 = 7;
      FUN_004f3d80();
      psStack_74 = (short *)0x4ea249;
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8 = 0xffffffff;
    }
    uStack_78 = *(undefined4 *)(param_1 + 3);
    psStack_74 = (short *)(param_1 + 7);
    local_7c = &DAT_00fb7470;
    local_80 = 0x4ea268;
    FUN_004f7280();
    uVar7 = *(undefined4 *)(param_1 + 3);
    iVar4 = FUN_00404ba0();
    *(undefined4 *)(iVar4 + 0x6834) = uVar7;
  }
  else {
    if (cVar1 == '\x01') {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 8;
        FUN_00587480();
        psStack_74 = (short *)0x4ea2a8;
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      psStack_74 = (short *)0x0;
      ppuStack_94 = (undefined1 **)0x0;
      local_7c = (undefined *)0x7;
      local_80 = 0;
      local_98 = &DAT_00bed1fc;
      local_90 = 0;
      local_9c = 0x4ea2d9;
      FUN_00402160();
      local_8 = 9;
      local_50[0] = (undefined1 *)0xb;
      ppuStack_94 = (undefined1 **)0x4ea2ec;
      iVar4 = FUN_005854b0();
      ppuStack_94 = local_50;
      local_98 = (undefined2 *)0x4ea2fc;
      FUN_005740f0();
      if (local_54 == *(undefined1 **)(iVar4 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar5 = (short *)(local_54 + 0x10);
      if (7 < *(uint *)(local_54 + 0x24)) {
        psVar5 = *(short **)psVar5;
      }
      local_50[0] = (undefined1 *)local_ac;
      local_98 = (undefined2 *)0x7;
      local_9c = 0;
      local_ac[0] = 0;
      psVar6 = psVar5;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
    }
    else if (cVar1 == '\x02') {
      FUN_004054c0();
      psStack_74 = (short *)0x0;
      ppuStack_94 = (undefined1 **)&DAT_00bed1fc;
      local_98 = (undefined2 *)0x4ea36b;
      FUN_00402250();
      ppuStack_94 = (undefined1 **)0x4;
      local_8 = 10;
      local_98 = (undefined2 *)0x4ea379;
      FUN_005854b0();
      local_98 = (undefined2 *)0x4ea380;
      uVar7 = FUN_00585330();
      local_50[0] = (undefined1 *)local_ac;
      FUN_00402250(uVar7);
    }
    else {
      if (cVar1 != '\x03') goto LAB_004ea3ea;
      FUN_004054c0();
      psStack_74 = (short *)0x0;
      ppuStack_94 = (undefined1 **)&DAT_00bed1fc;
      local_98 = (undefined2 *)0x4ea3af;
      FUN_00402250();
      local_50[0] = (undefined1 *)local_ac;
      local_8 = 0xb;
      uVar7 = 0x73;
      FUN_005854b0(0x73);
      FUN_00585330(uVar7);
      FUN_004ed610();
    }
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
LAB_004ea3ea:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0xc;
    FUN_00587480();
    psStack_74 = (short *)0x4ea410;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  psStack_74 = (short *)0x4ea424;
  FUN_0058aad0();
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

