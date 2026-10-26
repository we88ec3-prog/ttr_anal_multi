
void FUN_004246a0(int param_1,uint param_2)

{
  undefined1 *puVar1;
  char cVar2;
  short sVar3;
  code *pcVar4;
  int iVar5;
  short *psVar6;
  undefined4 *puVar7;
  int in_ECX;
  undefined1 *puVar8;
  undefined2 local_d0 [8];
  undefined4 local_c0;
  short *local_bc;
  int iStack_b8;
  undefined2 local_b4 [8];
  undefined4 local_a4;
  undefined2 *local_a0;
  undefined1 **ppuStack_9c;
  undefined2 local_98 [8];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_64 [4];
  undefined1 *local_60;
  undefined1 *local_5c;
  undefined1 *local_58;
  undefined1 local_54 [20];
  uint local_40;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00931e66;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_64;
  ExceptionList = &local_14;
  cVar2 = *(char *)(param_1 + 2);
  if (cVar2 == '\0') {
    if (*(int *)(in_ECX + 0xbd54) != 0) goto LAB_00424c4f;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0;
      FUN_00587480();
      uStack_7c = 0x424716;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    uStack_7c = 0;
    local_5c = (undefined1 *)local_98;
    ppuStack_9c = (undefined1 **)0x0;
    local_84 = 7;
    local_88 = 0;
    local_a0 = &DAT_00bed1fc;
    local_98[0] = 0;
    local_a4 = 0x424747;
    FUN_00402160();
    local_c = 1;
    local_58 = (undefined1 *)0x33;
    ppuStack_9c = (undefined1 **)0x42475f;
    iVar5 = FUN_005854b0();
    ppuStack_9c = &local_58;
    local_a0 = (undefined2 *)0x424771;
    FUN_005740f0();
    if (local_60 == *(undefined1 **)(iVar5 + 4)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    local_bc = (short *)(local_60 + 0x10);
    if (7 < *(uint *)(local_60 + 0x24)) {
      local_bc = *(short **)local_bc;
    }
    local_60 = (undefined1 *)local_b4;
    local_a0 = (undefined2 *)0x7;
    local_a4 = 0;
    local_b4[0] = 0;
    psVar6 = local_bc;
    do {
      sVar3 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar3 != 0);
    iStack_b8 = (int)psVar6 - (int)(local_bc + 1) >> 1;
    local_c0 = 0x4247c6;
    FUN_00402160();
  }
  else if (cVar2 == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 2;
      FUN_00587480();
      uStack_7c = 0x4247f9;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    uStack_7c = 0;
    local_5c = (undefined1 *)local_98;
    ppuStack_9c = (undefined1 **)0x0;
    local_84 = 7;
    local_88 = 0;
    local_a0 = &DAT_00bed1fc;
    local_98[0] = 0;
    local_a4 = 0x42482c;
    FUN_00402160();
    local_c = 3;
    local_60 = (undefined1 *)0x4e;
    ppuStack_9c = (undefined1 **)0x424844;
    iVar5 = FUN_005854b0();
    ppuStack_9c = &local_60;
    local_a0 = (undefined2 *)0x424856;
    FUN_005740f0();
    if (local_58 == *(undefined1 **)(iVar5 + 4)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    local_bc = (short *)(local_58 + 0x10);
    if (7 < *(uint *)(local_58 + 0x24)) {
      local_bc = *(short **)local_bc;
    }
    local_60 = (undefined1 *)local_b4;
    local_a0 = (undefined2 *)0x7;
    local_a4 = 0;
    local_b4[0] = 0;
    psVar6 = local_bc;
    do {
      sVar3 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar3 != 0);
    iStack_b8 = (int)psVar6 - (int)(local_bc + 1) >> 1;
    local_c0 = 0x4248a6;
    FUN_00402160();
  }
  else {
    if (cVar2 == '\x02') {
      if (param_2 < 3) {
        puVar8 = (undefined1 *)0x0;
      }
      else {
        puVar8 = (undefined1 *)(param_2 - 3 >> 2);
      }
      uStack_7c = 0x4248d3;
      FUN_00402250();
      local_c._0_1_ = 4;
      local_c._1_3_ = 0;
      puVar1 = local_58;
      while (local_58 = puVar8, local_58 != (undefined1 *)0x0) {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c._0_1_ = 5;
          FUN_004f3d80();
          uStack_7c = 0x424914;
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c._0_1_ = 4;
        }
        uStack_7c = 0x424929;
        FUN_004f6a30();
        uStack_80 = FUN_004ed610();
        uStack_7c = 0;
        local_c._0_1_ = 6;
        local_84 = 0x42494b;
        FUN_004041f0();
        local_c._0_1_ = 4;
        if (7 < local_24) {
          uStack_7c = 0x424961;
          FUN_0089120c();
        }
        puVar1 = local_58 + -1;
        puVar8 = puVar1;
      }
      local_58 = puVar1;
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c._0_1_ = 7;
        FUN_00587480();
        uStack_7c = 0x424995;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c._0_1_ = 4;
      }
      uStack_7c = 0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)0x0;
      local_84 = 7;
      local_88 = 0;
      local_a0 = &DAT_00bed1fc;
      local_98[0] = 0;
      local_a4 = 0x4249c0;
      FUN_00402160();
      local_c._0_1_ = 8;
      local_60 = (undefined1 *)local_d0;
      local_bc = (short *)0x7;
      local_c0 = 0;
      local_d0[0] = 0;
      FUN_004026e0(local_54,0,0xffffffff);
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c._0_1_ = 10;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
      }
      local_c._0_1_ = 9;
      local_60 = (undefined1 *)0x4f;
      FUN_005740f0(&local_60);
      if (local_58 == DAT_00fe5b10) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      puVar7 = (undefined4 *)(local_58 + 0x10);
      if (7 < *(uint *)(local_58 + 0x24)) {
        puVar7 = (undefined4 *)*puVar7;
      }
      local_c._0_1_ = 8;
      FUN_00424c80(puVar7);
      iStack_b8 = 0xca;
      local_c = CONCAT31(local_c._1_3_,4);
      local_bc = (short *)0x424a91;
      FUN_0058b270();
      if (7 < local_40) {
        uStack_7c = 0x424aa9;
        FUN_0089120c();
      }
      goto LAB_00424c4f;
    }
    if (cVar2 == '\x03') {
      if (*(int *)(in_ECX + 0xbd54) != 0) goto LAB_00424c4f;
      FUN_004054c0();
      uStack_7c = 0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)&DAT_00bed1fc;
      local_a0 = (undefined2 *)0x424ade;
      FUN_00402250();
      local_c = 0xb;
      ppuStack_9c = (undefined1 **)0x45;
    }
    else if (cVar2 == '\x05') {
      if (*(int *)(in_ECX + 0xbd54) != 0) goto LAB_00424c4f;
      FUN_004054c0();
      uStack_7c = 0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)&DAT_00bed1fc;
      local_a0 = (undefined2 *)0x424b1d;
      FUN_00402250();
      local_c = 0xc;
      ppuStack_9c = (undefined1 **)0x4d;
    }
    else if (cVar2 == '\x04') {
      if (*(int *)(in_ECX + 0xbd54) != 0) goto LAB_00424c4f;
      FUN_004054c0();
      uStack_7c = 0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)&DAT_00bed1fc;
      local_a0 = (undefined2 *)0x424b5c;
      FUN_00402250();
      local_c = 0xd;
      ppuStack_9c = (undefined1 **)0x47;
    }
    else if (cVar2 == '\n') {
      if (*(int *)(in_ECX + 0xbd54) != 0) goto LAB_00424c4f;
      FUN_004054c0();
      uStack_7c = 0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)&DAT_00bed1fc;
      local_a0 = (undefined2 *)0x424b9b;
      FUN_00402250();
      local_c = 0xe;
      ppuStack_9c = (undefined1 **)&DAT_00000048;
    }
    else if (cVar2 == '\a') {
      if (*(int *)(in_ECX + 0xbd54) != 0) goto LAB_00424c4f;
      FUN_004054c0();
      uStack_7c = 0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)&DAT_00bed1fc;
      local_a0 = (undefined2 *)0x424bd7;
      FUN_00402250();
      local_c = 0xf;
      ppuStack_9c = (undefined1 **)0x67;
    }
    else {
      if ((cVar2 != '\b') || (*(int *)(in_ECX + 0xbd54) != 0)) goto LAB_00424c4f;
      FUN_004054c0();
      uStack_7c = 0;
      local_5c = (undefined1 *)local_98;
      ppuStack_9c = (undefined1 **)&DAT_00bed1fc;
      local_a0 = (undefined2 *)0x424c0f;
      FUN_00402250();
      local_c = 0x10;
      ppuStack_9c = (undefined1 **)0x5d;
    }
    local_a0 = (undefined2 *)0x424c21;
    FUN_005854b0();
    local_a0 = (undefined2 *)0x424c28;
    iStack_b8 = FUN_00585330();
    local_60 = (undefined1 *)local_b4;
    local_bc = (short *)0x424c37;
    FUN_00402250();
  }
  iStack_b8 = 0xca;
  local_c = 0xffffffff;
  local_bc = (short *)0x424c4c;
  FUN_0058b270();
LAB_00424c4f:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_64);
  return;
}

