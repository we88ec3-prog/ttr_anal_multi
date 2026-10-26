
void FUN_0066a850(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined1 auStack_74 [20];
  undefined4 uStack_60;
  undefined2 *puStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  int iStack_50;
  int iStack_4c;
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
    ppuStack_3c = (undefined1 **)0x66a8a3;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 == 1) && (iVar3 = DAT_00f94300 + 0x16f8, iVar3 != 0)) {
    if (99 < param_3 - 1U) {
      ppuStack_3c = (undefined1 **)0x66a9ca;
      FUN_006edb60();
      ExceptionList = local_14;
      return;
    }
    iVar1 = param_3 * 0x20 + iVar3;
    if (((*(int *)(param_3 * 0x20 + 0xc + iVar3) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
       (iVar1 != 0)) {
      local_20 = *(undefined1 **)(iVar1 + 0x10);
      local_1c = *(undefined4 *)(iVar1 + 0x14);
      iVar3 = FUN_00409560();
      ppuStack_3c = &local_24;
      uStack_44 = 0x66a92e;
      iStack_40 = iVar3;
      FUN_004dd400();
      if (((local_24 != *(undefined1 **)(iVar3 + 4)) && (*(int *)(local_24 + 0x18) != 0)) &&
         (*(char *)(*(int *)(local_24 + 0x18) + 0x15) != '\0')) {
        FUN_004054c0();
        ppuStack_3c = (undefined1 **)0x0;
        local_20 = (undefined1 *)&uStack_58;
        puStack_5c = &DAT_00bed1fc;
        uStack_60 = 0x66a96e;
        FUN_00402250();
        puStack_5c = (undefined2 *)0xaf;
        local_c = 1;
        uStack_60 = 0x66a980;
        FUN_005854b0();
        uStack_60 = 0x66a987;
        uVar4 = FUN_00585330();
        local_24 = auStack_74;
        FUN_00402250(uVar4);
        local_c = 0xffffffff;
        FUN_0058b270(0xca);
        ExceptionList = local_14;
        return;
      }
      puVar2 = *(undefined1 **)(iVar1 + 0xc);
      iVar3 = FUN_00404c10();
      ppuStack_3c = (undefined1 **)0x66aa00;
      local_24 = puVar2;
      FUN_008438c0();
      if ((local_20 != (undefined1 *)*(int *)(iVar3 + 4)) && (*(int *)((int)local_20 + 0x10) != 0))
      {
        iVar3 = FUN_0051bfc0();
        if (iVar3 != 0) {
          FUN_004054c0();
          ppuStack_3c = (undefined1 **)0x0;
          local_20 = (undefined1 *)&uStack_58;
          puStack_5c = &DAT_00bed1fc;
          uStack_60 = 0x66aa41;
          FUN_00402250();
          puStack_5c = (undefined2 *)0xaf;
          local_c = 2;
          uStack_60 = 0x66aa53;
          FUN_005854b0();
          uStack_60 = 0x66aa5a;
          uVar4 = FUN_00585330();
          local_24 = auStack_74;
          FUN_00402250(uVar4);
          local_c = 0xffffffff;
          FUN_0058b270(0xca);
          ExceptionList = local_14;
          return;
        }
        if (1 < *(int *)(iVar1 + 8)) {
          ppuStack_3c = (undefined1 **)0x66aaa4;
          puVar5 = (undefined4 *)FUN_00891268();
          if (puVar5 == (undefined4 *)0x0) {
            puVar5 = (undefined4 *)0x0;
          }
          else {
            puVar5[1] = 1;
            *puVar5 = FUI::QUANTITYDATA_MAILATTACHMENT::vftable;
            puVar5[2] = param_3;
            puVar5[3] = param_4;
          }
          ppuStack_3c = (undefined1 **)0x66aad0;
          iVar3 = FUN_00891268();
          if (iVar3 != 0) {
            iStack_40 = *(undefined4 *)(iVar1 + 8);
            uStack_44 = 0xf43a4;
            uStack_48 = 0x66aaea;
            ppuStack_3c = (undefined1 **)puVar5;
            FUN_00753eb0();
            FUN_004072a0();
            ExceptionList = local_14;
            return;
          }
          FUN_004072a0();
          ExceptionList = local_14;
          return;
        }
        ppuStack_3c = *(undefined1 ***)(iVar1 + 0x14);
        iStack_40 = *(undefined4 *)(iVar1 + 0x10);
        uStack_44 = *(undefined4 *)(iVar1 + 4);
        uStack_48 = *(undefined4 *)(iVar1 + 0xc);
        iStack_4c = param_3;
        iStack_50 = param_2;
        uStack_54 = param_4;
        uStack_58 = param_1;
        puStack_5c = (undefined2 *)0x66ab4b;
        FUN_0066ab60();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

