
void FUN_006a2ca0(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_58 [16];
  undefined4 uStack_48;
  int iStack_44;
  int iStack_40;
  undefined1 **ppuStack_3c;
  undefined1 *local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009429ec;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    ppuStack_3c = (undefined1 **)0x6a2cf7;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (99 < param_3 - 1U) {
      ppuStack_3c = (undefined1 **)0x6a2e80;
      FUN_006edb60();
      ExceptionList = local_14;
      return;
    }
    iVar1 = param_3 * 0x20 + iVar2;
    if (((*(int *)(param_3 * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar1 + 8) != 0)) &&
       (iVar1 != 0)) {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 1;
        FUN_0051c120();
        ppuStack_3c = (undefined1 **)0x6a2d7f;
        _atexit((_func_4879 *)&LAB_00bccc90);
      }
      local_c = 0xffffffff;
      ppuStack_3c = (undefined1 **)0x6a2da4;
      FUN_008438c0();
      if ((local_1c[0] != DAT_00f8d91c) && (*(int *)(local_1c[0] + 0x10) != 0)) {
        iVar2 = FUN_00409560();
        ppuStack_3c = local_1c;
        iStack_44 = 0x6a2de4;
        iStack_40 = iVar2;
        FUN_004dd400();
        if ((local_1c[0] != *(undefined1 **)(iVar2 + 4)) &&
           ((*(int *)(local_1c[0] + 0x18) != 0 &&
            (*(char *)(*(int *)(local_1c[0] + 0x18) + 0x15) != '\0')))) {
          FUN_004054c0();
          ppuStack_3c = (undefined1 **)0x0;
          local_1c[0] = auStack_58;
          FUN_00402250();
          local_c = 2;
          FUN_005854b0();
          uVar3 = FUN_00585330();
          FUN_00402250(uVar3);
          local_c = 0xffffffff;
          FUN_0058b270(0xca);
          ExceptionList = local_14;
          return;
        }
        iVar2 = FUN_0051bfc0();
        if (iVar2 != 0) {
          FUN_004054c0();
          ppuStack_3c = (undefined1 **)0x0;
          local_1c[0] = auStack_58;
          FUN_00402250();
          local_c = 3;
          FUN_005854b0();
          uVar3 = FUN_00585330();
          FUN_00402250(uVar3);
          local_c = 0xffffffff;
          FUN_0058b270(0xca);
          ExceptionList = local_14;
          return;
        }
        if (*(int *)(iVar1 + 8) < 2) {
          ppuStack_3c = (undefined1 **)param_3;
          iStack_40 = param_2;
          iStack_44 = param_1;
          uStack_48 = 0x6a2f2b;
          FUN_006a1960();
          ExceptionList = local_14;
          return;
        }
        ppuStack_3c = (undefined1 **)0x6a2f47;
        ppuStack_3c = (undefined1 **)FUN_00891268();
        if (ppuStack_3c == (undefined1 **)0x0) {
          ppuStack_3c = (undefined1 **)0x0;
        }
        else {
          *ppuStack_3c = (undefined1 *)FUI::QUANTITYDATA_AUCTION::vftable;
          ppuStack_3c[1] = (undefined1 *)0x1;
          ppuStack_3c[2] = (undefined1 *)param_3;
        }
        iStack_40 = 1;
        iStack_44 = 0xf43a4;
        uStack_48 = 0x6a2f80;
        FUN_00689880();
        (**(code **)(**(int **)(param_1 + 0x114) + 0xd0))();
      }
    }
  }
  ExceptionList = local_14;
  return;
}

