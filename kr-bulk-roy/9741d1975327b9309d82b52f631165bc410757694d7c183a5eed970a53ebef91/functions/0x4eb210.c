
undefined4 FUN_004eb210(undefined2 *param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  int in_ECX;
  short *psVar8;
  undefined2 local_68 [8];
  undefined4 local_58;
  undefined2 *local_54;
  undefined4 *puStack_50;
  undefined2 local_4c [8];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_30;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar4 = (undefined1 *)param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fc42;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar1 = *(char *)((int)param_1 + 2);
  if (cVar1 == '\0') {
    uStack_30 = 0x4eb253;
    iVar5 = FUN_004ec270();
    if (iVar5 != 0) {
      *(undefined2 *)(iVar5 + 0x14) = *(undefined2 *)(puVar4 + 7);
    }
    if (*(char *)(*(int *)(in_ECX + 0x5ebc) + 0x12) == '\0') {
      iVar5 = FUN_00404ba0();
      if (*(int *)(puVar4 + 3) != *(int *)(iVar5 + 0x5f50)) goto LAB_004eb4bb;
      FUN_004054c0();
      uStack_30 = 0;
      param_1 = local_4c;
      puStack_50 = (undefined4 *)&DAT_00bed1fc;
      local_54 = (undefined2 *)0x4eb35f;
      FUN_00402250();
      local_8 = 2;
      puStack_50 = (undefined4 *)0x8a;
LAB_004eb48d:
      local_54 = (undefined2 *)0x4eb492;
      FUN_005854b0();
      local_54 = (undefined2 *)0x4eb499;
      uVar6 = FUN_00585330();
      FUN_00402250(uVar6);
    }
    else {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        uStack_30 = 0x4eb290;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      uStack_30 = 0;
      puStack_50 = (undefined4 *)0x0;
      local_38 = 7;
      local_3c = 0;
      local_54 = &DAT_00bed1fc;
      local_4c[0] = 0;
      local_58 = 0x4eb2bf;
      FUN_00402160();
      local_8 = 1;
      param_1 = (undefined2 *)0x70;
      puStack_50 = (undefined4 *)0x4eb2d2;
      iVar5 = FUN_005854b0();
      puStack_50 = &param_1;
      local_54 = (undefined2 *)0x4eb2e2;
      FUN_005740f0();
      if (local_14 == *(int *)(iVar5 + 4)) {
        pcVar3 = (code *)swi(3);
        uVar6 = (*pcVar3)();
        return uVar6;
      }
      psVar8 = (short *)(local_14 + 0x10);
      if (7 < *(uint *)(local_14 + 0x24)) {
        psVar8 = *(short **)psVar8;
      }
      param_1 = local_68;
      local_54 = (undefined2 *)0x7;
      local_58 = 0;
      local_68[0] = 0;
      psVar7 = psVar8;
      do {
        sVar2 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
    }
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        FUN_004054c0();
        uStack_30 = 0;
        param_1 = local_4c;
        puStack_50 = (undefined4 *)&DAT_00bed1fc;
        local_54 = (undefined2 *)0x4eb459;
        FUN_00402250();
        local_8 = 5;
        puStack_50 = (undefined4 *)0x8c;
      }
      else {
        if (cVar1 != '\x03') goto LAB_004eb4bb;
        FUN_004054c0();
        uStack_30 = 0;
        param_1 = local_4c;
        puStack_50 = (undefined4 *)&DAT_00bed1fc;
        local_54 = (undefined2 *)0x4eb484;
        FUN_00402250();
        local_8 = 6;
        puStack_50 = (undefined4 *)0x4;
      }
      goto LAB_004eb48d;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 3;
      FUN_00587480();
      uStack_30 = 0x4eb39d;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    uStack_30 = 0;
    puStack_50 = (undefined4 *)0x0;
    local_38 = 7;
    local_3c = 0;
    local_54 = &DAT_00bed1fc;
    local_4c[0] = 0;
    local_58 = 0x4eb3cc;
    FUN_00402160();
    local_8 = 4;
    param_1 = (undefined2 *)0x8b;
    puStack_50 = (undefined4 *)0x4eb3df;
    iVar5 = FUN_005854b0();
    puStack_50 = &param_1;
    local_54 = (undefined2 *)0x4eb3ef;
    FUN_005740f0();
    if (local_14 == *(int *)(iVar5 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar6 = (*pcVar3)();
      return uVar6;
    }
    psVar8 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    param_1 = local_68;
    local_54 = (undefined2 *)0x7;
    local_58 = 0;
    local_68[0] = 0;
    psVar7 = psVar8;
    do {
      sVar2 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
  }
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004eb4bb:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 7;
    FUN_00587480();
    uStack_30 = 0x4eb4e1;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  uStack_30 = 0x4eb4f5;
  FUN_0058aad0();
  ExceptionList = local_10;
  return 0;
}

