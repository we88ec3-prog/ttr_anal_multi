
undefined4 FUN_004b6610(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936c4a;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 2) != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(uVar3);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    FUN_004e0fc0(&DAT_00fab168);
  }
  if (param_2 < 6) {
    local_34 = 0;
  }
  else {
    local_34 = param_2 - 6 >> 3;
  }
  if (local_34 != 0) {
    puVar6 = (undefined4 *)(param_1 + 6);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 1;
        FUN_004dec90(uVar3);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_30 = *puVar6;
      FUN_0082ef00(&local_30);
      if ((local_2c == DAT_00fab16c) ||
         (puVar4 = *(undefined4 **)(local_2c + 0x10), puVar4 == (undefined4 *)0x0)) {
        puVar4 = (undefined4 *)FUN_00891268(8);
        uVar2 = DAT_00fab22c & 1;
        *puVar4 = *puVar6;
        if (uVar2 == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 2;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        local_28 = *puVar4;
        local_24 = puVar4;
        uVar5 = FUN_0057ef20();
        FUN_0082f200(&DAT_00fab168,uVar5);
      }
      *puVar4 = *puVar6;
      puVar1 = puVar6 + 1;
      puVar6 = puVar6 + 2;
      local_34 = local_34 - 1;
      puVar4[1] = *puVar1;
    } while (local_34 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

