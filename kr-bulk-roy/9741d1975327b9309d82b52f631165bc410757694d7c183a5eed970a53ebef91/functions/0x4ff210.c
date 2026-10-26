
void FUN_004ff210(undefined4 param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_74 [20];
  undefined4 uStack_60;
  undefined2 *puStack_5c;
  undefined1 auStack_58 [16];
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  undefined1 **ppuStack_3c;
  undefined1 *local_24;
  undefined1 *local_20;
  undefined4 local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d02e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    ppuStack_3c = (undefined1 **)0x4ff266;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (99 < param_3 - 1U) {
      ppuStack_3c = (undefined1 **)0x4ff38a;
      FUN_006edb60();
      ExceptionList = local_14;
      return;
    }
    iVar4 = param_3 * 0x20 + DAT_00f94300 + 0x16f8;
    if (((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 8) != 0)) && (iVar4 != 0)) {
      local_20 = *(undefined1 **)(iVar4 + 0x10);
      local_1c = *(undefined4 *)(iVar4 + 0x14);
      iVar2 = FUN_00409560();
      ppuStack_3c = &local_24;
      uStack_44 = 0x4ff2ee;
      iStack_40 = iVar2;
      FUN_004dd400();
      if (((local_24 != *(undefined1 **)(iVar2 + 4)) && (*(int *)(local_24 + 0x18) != 0)) &&
         (*(char *)(*(int *)(local_24 + 0x18) + 0x15) != '\0')) {
        FUN_004054c0();
        ppuStack_3c = (undefined1 **)0x0;
        local_20 = auStack_58;
        puStack_5c = &DAT_00bed1fc;
        uStack_60 = 0x4ff32e;
        FUN_00402250();
        puStack_5c = (undefined2 *)0xaf;
        local_c = 1;
        uStack_60 = 0x4ff340;
        FUN_005854b0();
        uStack_60 = 0x4ff347;
        uVar3 = FUN_00585330();
        local_24 = auStack_74;
        FUN_00402250(uVar3);
        local_c = 0xffffffff;
        FUN_0058b270(0xca);
        ExceptionList = local_14;
        return;
      }
      puVar1 = *(undefined1 **)(iVar4 + 0xc);
      iVar4 = FUN_00404c10();
      ppuStack_3c = (undefined1 **)0x4ff3c0;
      local_24 = puVar1;
      FUN_008438c0();
      if ((local_20 != (undefined1 *)*(int *)(iVar4 + 4)) && (*(int *)((int)local_20 + 0x10) != 0))
      {
        iVar4 = FUN_0051bfc0();
        if (iVar4 != 0) {
          FUN_004054c0();
          ppuStack_3c = (undefined1 **)0x0;
          local_20 = auStack_58;
          puStack_5c = &DAT_00bed1fc;
          uStack_60 = 0x4ff401;
          FUN_00402250();
          puStack_5c = (undefined2 *)0xaf;
          local_c = 2;
          uStack_60 = 0x4ff413;
          FUN_005854b0();
          uStack_60 = 0x4ff41a;
          uVar3 = FUN_00585330();
          local_24 = auStack_74;
          FUN_00402250(uVar3);
          local_c = 0xffffffff;
          FUN_0058b270(0xca);
          ExceptionList = local_14;
          return;
        }
        FUN_00414680();
        ppuStack_3c = (undefined1 **)param_3;
        iStack_40 = param_2;
        uStack_44 = param_1;
        uStack_48 = 0x4ff46a;
        FUN_004a3e20();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

