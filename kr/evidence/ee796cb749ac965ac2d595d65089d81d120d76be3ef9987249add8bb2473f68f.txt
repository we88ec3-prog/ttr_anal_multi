
void FUN_00502b40(int param_1)

{
  ushort uVar1;
  short sVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  short *psVar8;
  undefined4 uVar9;
  int in_ECX;
  short *psVar10;
  undefined1 *puVar11;
  float10 fVar12;
  undefined4 local_90 [4];
  undefined4 local_80;
  undefined2 *local_7c;
  undefined1 **ppuStack_78;
  undefined2 local_74 [8];
  undefined4 local_64;
  uint local_60;
  undefined4 *puStack_5c;
  undefined *puStack_58;
  undefined1 *local_28;
  undefined4 *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944127;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    puStack_58 = (undefined *)0x502b94;
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puStack_58 = (undefined *)0x502ba9;
  puVar4 = (undefined4 *)FUN_00891268();
  local_24 = (undefined4 *)0x0;
  if (puVar4 != (undefined4 *)0x0) {
    uVar1 = *(ushort *)(param_1 + 4);
    puVar4[3] = 0;
    puVar4[1] = 0xffffffff;
    puVar4[2] = 0xffffffff;
    puVar4[4] = &DAT_000f4282;
    *puVar4 = FoxUI::FXUIEventI1::vftable;
    puVar4[5] = (uint)uVar1;
    local_24 = puVar4;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    puStack_58 = (undefined *)0x502bfa;
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  puStack_58 = (undefined *)0x502c11;
  FUN_00804260();
  sVar2 = *(short *)(param_1 + 4);
  if (sVar2 == 0) {
    piVar5 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
    if (piVar5 != (int *)0x0) {
      puVar4 = (undefined4 *)(**(code **)(*piVar5 + 0x4c))();
      local_20 = *puVar4;
      local_1c = puVar4[1];
      local_18 = (float)puVar4[2];
      if ((piVar5[0x57] == 0) || (piVar5[0xdc] == 0)) {
        local_24 = (undefined4 *)0x0;
      }
      else {
        fVar12 = (float10)FUN_007a7100();
        local_24 = (undefined4 *)(float)fVar12;
      }
      uVar1 = *(ushort *)(piVar5 + 1);
      local_18 = (float)local_24 + 2.6 + local_18;
      if ((DAT_00fdf6dc & 1) == 0) {
        DAT_00fdf6dc = DAT_00fdf6dc | 1;
        local_8 = 2;
        FUN_00550820();
        puStack_58 = (undefined *)0x502cc6;
        _atexit((_func_4879 *)&LAB_00bce6b0);
        local_8 = 0xffffffff;
      }
      puStack_5c = &local_20;
      local_60 = (uint)uVar1;
      puStack_58 = (undefined *)0x0;
      local_64 = 0x502cf3;
      FUN_00551f20();
    }
    local_24 = (undefined4 *)(int)*(short *)(param_1 + 2);
    iVar7 = *(int *)(in_ECX + 0x5eac);
    puStack_58 = (undefined *)0x502d11;
    FUN_00503d20();
    if (local_28 == *(undefined1 **)(iVar7 + 4)) {
      puVar11 = (undefined1 *)0x0;
    }
    else {
      puVar11 = local_28 + 0x10;
      if (puVar11 != (undefined1 *)0x0) {
        puStack_58 = (undefined *)0x502d30;
        puVar6 = (undefined1 *)FUN_00891268();
        local_8 = 3;
        if (puVar6 != (undefined1 *)0x0) {
          puStack_58 = local_28 + 0x5c;
          if (7 < *(uint *)(local_28 + 0x70)) {
            puStack_58 = *(undefined **)puStack_58;
          }
          puStack_5c = (undefined4 *)0x502d56;
          local_28 = puVar6;
          FUN_005016f0();
          puVar6 = local_28;
        }
        local_28 = puVar6;
        if ((DAT_00fb7354 & 1) == 0) {
          DAT_00fb7354 = DAT_00fb7354 | 1;
          local_8 = 4;
          FUN_005533d0();
          puStack_58 = (undefined *)0x502d8d;
          _atexit((_func_4879 *)&LAB_00bcd100);
        }
        local_8 = 0xffffffff;
        puStack_58 = &DAT_00fb7358;
        puStack_5c = (undefined4 *)0x502daa;
        FUN_005536e0();
      }
    }
    FUN_005000d0();
    if ((puVar11 != (undefined1 *)0x0) && (*(int *)(puVar11 + 8) != 3)) {
      local_28 = (undefined1 *)(uint)*(ushort *)(param_1 + 2);
      FUN_0044b4e0();
    }
    FUN_0040f060();
    puStack_5c = (undefined4 *)0x502ded;
    FUN_00500240();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      puStack_58 = (undefined *)0x502e13;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    puStack_58 = (undefined *)0x502e28;
    puVar4 = (undefined4 *)FUN_00891268();
    if (puVar4 == (undefined4 *)0x0) {
      puStack_58 = (undefined *)0x502e66;
      FUN_0058aa50();
    }
    else {
      sVar2 = *(short *)(param_1 + 2);
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf438c;
      *puVar4 = FoxUI::FXUIEventI1::vftable;
      puVar4[5] = (int)sVar2;
      puStack_58 = (undefined *)0x502e56;
      FUN_0058aa50();
    }
  }
  else {
    if (sVar2 == 1) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 6;
        FUN_00587480();
        puStack_58 = (undefined *)0x502e9b;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      puStack_58 = (undefined *)0x0;
      ppuStack_78 = (undefined1 **)0x0;
      local_60 = 7;
      local_64 = 0;
      local_7c = &DAT_00bed1fc;
      local_74[0] = 0;
      local_80 = 0x502eca;
      FUN_00402160();
      local_8 = 7;
      local_28 = (undefined1 *)0x17;
      ppuStack_78 = (undefined1 **)0x502ed9;
      iVar7 = FUN_005854b0();
      ppuStack_78 = &local_28;
      local_7c = (undefined2 *)0x502ee9;
      FUN_005740f0();
      if (local_24 == *(undefined4 **)(iVar7 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar10 = (short *)(local_24 + 4);
      if (7 < (uint)local_24[9]) {
        psVar10 = *(short **)psVar10;
      }
      local_28 = (undefined1 *)local_90;
      local_7c = (undefined2 *)0x7;
      local_80 = 0;
      local_90[0]._0_2_ = 0;
      psVar8 = psVar10;
      do {
        sVar2 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar10,(int)psVar8 - (int)(psVar10 + 1) >> 1);
    }
    else {
      if (sVar2 == 2) {
        FUN_004054c0();
        puStack_58 = (undefined *)0x0;
        local_28 = (undefined1 *)local_74;
        ppuStack_78 = (undefined1 **)&DAT_00bed1fc;
        local_7c = (undefined2 *)0x502f62;
        FUN_00402250();
        local_8 = 8;
        ppuStack_78 = (undefined1 **)0x19;
      }
      else if (sVar2 == 3) {
        FUN_004054c0();
        puStack_58 = (undefined *)0x0;
        local_28 = (undefined1 *)local_74;
        ppuStack_78 = (undefined1 **)&DAT_00bed1fc;
        local_7c = (undefined2 *)0x502f90;
        FUN_00402250();
        local_8 = 9;
        ppuStack_78 = (undefined1 **)0x18;
      }
      else if (sVar2 == 4) {
        FUN_004054c0();
        puStack_58 = (undefined *)0x0;
        local_28 = (undefined1 *)local_74;
        ppuStack_78 = (undefined1 **)&DAT_00bed1fc;
        local_7c = (undefined2 *)0x502fbb;
        FUN_00402250();
        local_8 = 10;
        ppuStack_78 = (undefined1 **)0xe8;
      }
      else {
        if (sVar2 != 5) goto LAB_0050301c;
        FUN_004054c0();
        puStack_58 = (undefined *)0x0;
        local_28 = (undefined1 *)local_74;
        ppuStack_78 = (undefined1 **)&DAT_00bed1fc;
        local_7c = (undefined2 *)0x502fe9;
        FUN_00402250();
        local_8 = 0xb;
        ppuStack_78 = (undefined1 **)0x1a;
      }
      local_7c = (undefined2 *)0x502ff7;
      FUN_005854b0();
      local_7c = (undefined2 *)0x502ffe;
      uVar9 = FUN_00585330();
      local_24 = local_90;
      FUN_00402250(uVar9);
    }
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
LAB_0050301c:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

