
void FUN_005b68c0(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_74 [16];
  undefined4 uStack_64;
  undefined2 *puStack_60;
  undefined1 **ppuStack_5c;
  undefined2 local_58 [8];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_3c;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f64a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar5 = *(int *)(*(int *)(param_1 + 0x24c) + 0x20c);
  if ((DAT_00fb93b8 & 1) == 0) {
    DAT_00fb93b8 = DAT_00fb93b8 | 1;
    local_c = 0;
    FUN_00823720();
    uStack_3c = 0x5b6921;
    _atexit(FUN_00bcd5a0);
  }
  local_c = 0xffffffff;
  uStack_3c = 0x5b6943;
  FUN_008438c0();
  if ((local_20 == DAT_00fb93c0) || (iVar4 = *(int *)(local_20 + 0x10), iVar4 == -8)) {
LAB_005b6b46:
    (**(code **)(**(int **)(param_1 + 0x230) + 0xd4))();
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    uStack_3c = 0x5b6986;
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if (((DAT_00fab228 == 0) || (*(short *)(DAT_00fab228 + 0x14) == 0)) ||
     (*(char *)(DAT_00fab228 + 0x28) != '\0')) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 3;
      FUN_004e1590();
      uStack_3c = 0x5b6a39;
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    iVar3 = FUN_004d43d0();
    if ((int)(uint)*(byte *)(iVar4 + 0xc) <= iVar3) {
      iVar5 = FUN_00404ba0();
      if (((*(int *)(iVar5 + 0x5f4c) == 7) ||
          (iVar5 = FUN_00404ba0(), *(int *)(iVar5 + 0x5f4c) == 0x17)) ||
         (iVar5 = FUN_00404ba0(), *(int *)(iVar5 + 0x5f4c) == 0x18)) {
        FUN_0040f060();
        uStack_3c = 0x5b6b46;
        FUN_004dda10();
      }
      else {
        FUN_0040f060();
        uStack_3c = 0x5b6b2a;
        FUN_004dda70();
      }
      goto LAB_005b6b46;
    }
    FUN_004054c0();
    uStack_3c = 0;
    local_1c = (undefined1 *)local_58;
    ppuStack_5c = (undefined1 **)0x0;
    local_44 = 7;
    local_48 = 0;
    puStack_60 = &DAT_00bed1fc;
    local_58[0] = 0;
    uStack_64 = 0x5b6a8b;
    FUN_00402160();
    local_c = 4;
    local_20 = (undefined1 *)0x5;
    ppuStack_5c = (undefined1 **)0x5b6aa0;
    iVar4 = FUN_005854b0();
    ppuStack_5c = &local_20;
    puStack_60 = (undefined2 *)0x5b6ab2;
    FUN_005740f0();
    if (iVar5 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    local_20 = auStack_74;
    FUN_00426ec0();
  }
  else {
    FUN_004054c0();
    uStack_3c = 0;
    local_20 = (undefined1 *)local_58;
    ppuStack_5c = (undefined1 **)&DAT_00bed1fc;
    puStack_60 = (undefined2 *)0x5b69c5;
    FUN_00402250();
    ppuStack_5c = (undefined1 **)0x35;
    local_c = 2;
    puStack_60 = (undefined2 *)0x5b69d4;
    FUN_005854b0();
    puStack_60 = (undefined2 *)0x5b69db;
    uVar2 = FUN_00585330();
    FUN_00402250(uVar2);
  }
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_14;
  return;
}

