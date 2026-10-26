
undefined4 FUN_004bd2f0(undefined2 *param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  int in_ECX;
  short *psVar7;
  undefined2 local_64 [8];
  undefined4 local_54;
  undefined2 *local_50;
  undefined4 *puStack_4c;
  undefined2 local_48 [8];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_2c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00930876;
  local_10 = ExceptionList;
  cVar1 = *(char *)((int)param_1 + 2);
  if (cVar1 == '\0') {
    if (*(int *)(in_ECX + 0xbd54) != 0) {
      return 0;
    }
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      uStack_2c = 0x4bd355;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    uStack_2c = 0;
    puStack_4c = (undefined4 *)0x0;
    local_34 = 7;
    local_38 = 0;
    local_50 = &DAT_00bed1fc;
    local_48[0] = 0;
    local_54 = 0x4bd383;
    FUN_00402160();
    local_8 = 1;
    param_1 = (undefined2 *)0x33;
    puStack_4c = (undefined4 *)0x4bd396;
    iVar4 = FUN_005854b0();
    puStack_4c = &param_1;
    local_50 = (undefined2 *)0x4bd3a6;
    FUN_005740f0();
    if (local_14 == *(int *)(iVar4 + 4)) {
      pcVar3 = (code *)swi(3);
      uVar5 = (*pcVar3)();
      return uVar5;
    }
    psVar7 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    param_1 = local_64;
    local_54 = 0;
    local_50 = (undefined2 *)0x7;
    local_64[0] = 0;
    psVar6 = psVar7;
    do {
      sVar2 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
  }
  else {
    if (cVar1 == '\x03') {
      if (*(int *)(in_ECX + 0xbd54) != 0) {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      uStack_2c = 0;
      param_1 = local_48;
      puStack_4c = (undefined4 *)&DAT_00bed1fc;
      local_50 = (undefined2 *)0x4bd427;
      FUN_00402250();
      local_8 = 2;
      puStack_4c = (undefined4 *)0x45;
    }
    else if (cVar1 == '\x05') {
      if (*(int *)(in_ECX + 0xbd54) != 0) {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      uStack_2c = 0;
      param_1 = local_48;
      puStack_4c = (undefined4 *)&DAT_00bed1fc;
      local_50 = (undefined2 *)0x4bd461;
      FUN_00402250();
      local_8 = 3;
      puStack_4c = (undefined4 *)0x4d;
    }
    else if (cVar1 == '\x04') {
      if (*(int *)(in_ECX + 0xbd54) != 0) {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      uStack_2c = 0;
      param_1 = local_48;
      puStack_4c = (undefined4 *)&DAT_00bed1fc;
      local_50 = (undefined2 *)0x4bd49b;
      FUN_00402250();
      local_8 = 4;
      puStack_4c = (undefined4 *)0x47;
    }
    else if (cVar1 == '\x06') {
      if (*(int *)(in_ECX + 0xbd54) != 0) {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      uStack_2c = 0;
      param_1 = local_48;
      puStack_4c = (undefined4 *)&DAT_00bed1fc;
      local_50 = (undefined2 *)0x4bd4d5;
      FUN_00402250();
      local_8 = 5;
      puStack_4c = (undefined4 *)0xe8;
    }
    else if (cVar1 == '\n') {
      if (*(int *)(in_ECX + 0xbd54) != 0) {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      uStack_2c = 0;
      param_1 = local_48;
      puStack_4c = (undefined4 *)&DAT_00bed1fc;
      local_50 = (undefined2 *)0x4bd50f;
      FUN_00402250();
      local_8 = 6;
      puStack_4c = (undefined4 *)&DAT_00000048;
    }
    else {
      if (cVar1 != '\a') {
        return 0;
      }
      if (*(int *)(in_ECX + 0xbd54) != 0) {
        return 0;
      }
      ExceptionList = &local_10;
      FUN_004054c0();
      uStack_2c = 0;
      param_1 = local_48;
      puStack_4c = (undefined4 *)&DAT_00bed1fc;
      local_50 = (undefined2 *)0x4bd542;
      FUN_00402250();
      local_8 = 7;
      puStack_4c = (undefined4 *)0x67;
    }
    local_50 = (undefined2 *)0x4bd550;
    FUN_005854b0();
    local_50 = (undefined2 *)0x4bd557;
    uVar5 = FUN_00585330();
    FUN_00402250(uVar5);
  }
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return 0;
}

