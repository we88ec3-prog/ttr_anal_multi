
undefined4 FUN_004e3d30(undefined2 *param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  short *psVar6;
  undefined2 local_64 [8];
  undefined4 local_54;
  short *local_50;
  undefined4 *puStack_4c;
  undefined2 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *puStack_30;
  undefined4 uStack_2c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009302e6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(uint *)((int)param_1 + 2) < 10) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      uStack_2c = 0x4e3d8a;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    uStack_2c = 0;
    param_1 = (undefined2 *)0x196;
    puStack_30 = (undefined4 *)0x4e3da4;
    iVar3 = FUN_005854b0();
    puStack_30 = &param_1;
    local_34 = 0x4e3db4;
    FUN_005740f0();
    if (local_14 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    local_50 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      local_50 = *(short **)local_50;
    }
    local_34 = 7;
    local_38 = 0;
    local_48 = 0;
    psVar4 = local_50;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    puStack_4c = (undefined4 *)((int)psVar4 - (int)(local_50 + 1) >> 1);
    local_54 = 0x4e3e07;
    FUN_00402160();
    local_8 = 1;
    param_1 = (undefined2 *)0x106;
    puStack_4c = (undefined4 *)0x4e3e1a;
    iVar3 = FUN_005854b0();
    puStack_4c = &param_1;
    local_50 = (short *)0x4e3e2a;
    FUN_005740f0();
    if (local_14 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      uVar5 = (*pcVar2)();
      return uVar5;
    }
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    param_1 = local_64;
    local_50 = (short *)0x7;
    local_54 = 0;
    local_64[0] = 0;
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_10;
  return 0;
}

