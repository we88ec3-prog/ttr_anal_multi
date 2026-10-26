
undefined4 FUN_004fe1c0(undefined1 *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 auStack_60 [20];
  undefined4 uStack_4c;
  undefined4 *puStack_48;
  undefined4 uStack_30;
  undefined4 *puStack_2c;
  char *pcStack_28;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b05e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ff080();
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170();
    pcStack_28 = (char *)0x4fe213;
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb73e8 == 0) {
    if (*(char *)((int)param_1 + 6) == '\0') {
      FUN_004054c0();
      pcStack_28 = (char *)0x0;
      param_1 = (undefined1 *)0x197;
      puStack_2c = (undefined4 *)0x4fe2fd;
      iVar2 = FUN_005854b0();
      puStack_2c = &param_1;
      uStack_30 = 0x4fe30d;
      FUN_005740f0();
      if (local_14 == *(int *)(iVar2 + 4)) {
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      puStack_48 = (undefined4 *)(local_14 + 0x10);
      if (7 < *(uint *)(local_14 + 0x24)) {
        puStack_48 = (undefined4 *)*puStack_48;
      }
      uStack_4c = 0x4fe338;
      FUN_00402250();
      local_8 = 2;
      param_1 = (undefined1 *)0xc6;
      puStack_48 = (undefined4 *)0x4fe34b;
      iVar2 = FUN_005854b0();
      puStack_48 = &param_1;
      uStack_4c = 0x4fe35b;
      FUN_005740f0();
      if (local_14 == *(int *)(iVar2 + 4)) {
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
    }
    else {
      if (*(char *)((int)param_1 + 6) != '\x01') {
        pcStack_28 = "DenyTrade: Unknown type idx %d";
        puStack_2c = (undefined4 *)0x4fe24a;
        FUN_006edb60();
        ExceptionList = local_10;
        return 0;
      }
      FUN_004054c0();
      pcStack_28 = (char *)0x0;
      param_1 = (undefined1 *)0x197;
      puStack_2c = (undefined4 *)0x4fe276;
      iVar2 = FUN_005854b0();
      puStack_2c = &param_1;
      uStack_30 = 0x4fe286;
      FUN_005740f0();
      if (local_14 == *(int *)(iVar2 + 4)) {
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
      puStack_48 = (undefined4 *)(local_14 + 0x10);
      if (7 < *(uint *)(local_14 + 0x24)) {
        puStack_48 = (undefined4 *)*puStack_48;
      }
      uStack_4c = 0x4fe2b1;
      FUN_00402250();
      local_8 = 1;
      param_1 = (undefined1 *)0xc5;
      puStack_48 = (undefined4 *)0x4fe2c4;
      iVar2 = FUN_005854b0();
      puStack_48 = &param_1;
      uStack_4c = 0x4fe2d4;
      FUN_005740f0();
      if (local_14 == *(int *)(iVar2 + 4)) {
        pcVar1 = (code *)swi(3);
        uVar3 = (*pcVar1)();
        return uVar3;
      }
    }
    puVar4 = (undefined4 *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    param_1 = auStack_60;
    FUN_00402250(puVar4);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
  ExceptionList = local_10;
  return 0;
}

