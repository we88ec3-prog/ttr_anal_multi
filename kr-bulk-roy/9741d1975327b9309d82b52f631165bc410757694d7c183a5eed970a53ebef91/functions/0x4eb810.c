
undefined4 FUN_004eb810(undefined2 *param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  short *psVar6;
  int in_ECX;
  short *psVar7;
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
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fbc6;
  local_10 = ExceptionList;
  cVar1 = *(char *)((int)param_1 + 2);
  if (cVar1 == '\0') {
    ExceptionList = &local_10;
    *(undefined4 *)(in_ECX + 0x5f18) = 0;
    *(undefined4 *)(in_ECX + 0x5f1c) = 0;
    *(undefined4 *)(in_ECX + 0x5f20) = *(undefined4 *)(in_ECX + 0x5f14);
    FUN_004ec3b0();
  }
  else {
    if (cVar1 == '\x03') {
      ExceptionList = &local_10;
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480();
        uStack_30 = 0x4eb892;
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      uStack_30 = 0;
      puStack_50 = (undefined4 *)0x0;
      local_38 = 7;
      local_3c = 0;
      local_54 = &DAT_00bed1fc;
      local_4c[0] = 0;
      local_58 = 0x4eb8c1;
      FUN_00402160();
      local_8 = 1;
      param_1 = (undefined2 *)0x6d;
      puStack_50 = (undefined4 *)0x4eb8d4;
      iVar4 = FUN_005854b0();
      puStack_50 = &param_1;
      local_54 = (undefined2 *)0x4eb8e4;
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
      param_1 = local_68;
      local_54 = (undefined2 *)0x7;
      local_58 = 0;
      local_68[0] = 0;
      psVar6 = psVar7;
      do {
        sVar2 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
    }
    else {
      if (cVar1 == '\x02') {
        ExceptionList = &local_10;
        FUN_004054c0();
        uStack_30 = 0;
        param_1 = local_4c;
        puStack_50 = (undefined4 *)&DAT_00bed1fc;
        local_54 = (undefined2 *)0x4eb955;
        FUN_00402250();
        local_8 = 2;
        puStack_50 = (undefined4 *)0x4;
      }
      else {
        if (cVar1 != '\x01') {
          return 0;
        }
        ExceptionList = &local_10;
        FUN_004054c0();
        uStack_30 = 0;
        param_1 = local_4c;
        puStack_50 = (undefined4 *)&DAT_00bed1fc;
        local_54 = (undefined2 *)0x4eb97d;
        FUN_00402250();
        local_8 = 3;
        puStack_50 = (undefined4 *)0x93;
      }
      local_54 = (undefined2 *)0x4eb98e;
      FUN_005854b0();
      local_54 = (undefined2 *)0x4eb995;
      uVar5 = FUN_00585330();
      FUN_00402250(uVar5);
    }
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_10;
  return 0;
}

