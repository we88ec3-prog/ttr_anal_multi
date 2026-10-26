
void FUN_005b1380(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
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
  
  puStack_10 = &LAB_0094398e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    uStack_3c = 0x5b13d8;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar3 = *(int *)(DAT_00fab130 + 0x5eac);
  if ((DAT_00fb93b8 & 1) == 0) {
    DAT_00fb93b8 = DAT_00fb93b8 | 1;
    local_c = 1;
    FUN_00823720();
    uStack_3c = 0x5b140c;
    _atexit(FUN_00bcd5a0);
  }
  local_c = 0xffffffff;
  uStack_3c = 0x5b142a;
  FUN_008438c0();
  if ((local_20 != DAT_00fb93c0) &&
     (iVar2 = *(int *)(local_20 + 0x10), (short *)(iVar2 + 8) != (short *)0x0)) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 2;
      FUN_004dec90();
      uStack_3c = 0x5b1471;
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    if (*(short *)(DAT_00fab130 + 0x5eb4) < *(short *)(iVar2 + 8)) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 3;
        FUN_00587480();
        uStack_3c = 0x5b14b3;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      uStack_3c = 0;
      local_1c = (undefined1 *)local_58;
      ppuStack_5c = (undefined1 **)0x0;
      local_44 = 7;
      local_48 = 0;
      puStack_60 = &DAT_00bed1fc;
      local_58[0] = 0;
      uStack_64 = 0x5b14e5;
      FUN_00402160();
      local_c = 4;
      local_20 = (undefined1 *)0x1c9;
      ppuStack_5c = (undefined1 **)0x5b14fa;
      iVar2 = FUN_005854b0();
      ppuStack_5c = &local_20;
      puStack_60 = (undefined2 *)0x5b150c;
      FUN_005740f0();
      if (iVar3 != *(int *)(iVar2 + 4)) {
        local_20 = auStack_74;
        FUN_004330b0();
        local_c = 0xffffffff;
        FUN_0058b270(0xca);
        ExceptionList = local_14;
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c = 5;
      FUN_00539c20();
      uStack_3c = 0x5b1587;
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_c = 0xffffffff;
    }
    if (DAT_00fb7258 != 0) {
      FUN_00404ba0();
      uStack_3c = 0x5b15ab;
      iVar3 = FUN_00539aa0();
      if (iVar3 != 0) {
        if (*(char *)(iVar3 + 6) != '\0') {
          FUN_00423240();
          FUN_00516fa0();
          FUN_00414680();
          FUN_004a35f0();
          ExceptionList = local_14;
          return;
        }
        if (*(char *)(iVar3 + 8) == '\0') {
          uStack_3c = 0x5b15ef;
          FUN_005972e0();
        }
      }
      FUN_00414680();
      FUN_004a35c0();
    }
  }
  ExceptionList = local_14;
  return;
}

