
undefined4 FUN_004b63e0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  ushort *puVar3;
  undefined4 uVar4;
  ushort *puVar5;
  uint local_34;
  uint local_30;
  int local_2c;
  ushort local_28;
  ushort *local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936c4a;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if (*(int *)(param_1 + 2) != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(uVar2);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    FUN_004e0fc0(&DAT_00fab158);
  }
  if (param_2 < 6) {
    local_34 = 0;
  }
  else {
    local_34 = param_2 - 6 >> 2;
  }
  if (local_34 != 0) {
    puVar5 = (ushort *)(param_1 + 6);
    do {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        local_c = 1;
        FUN_004dec90(uVar2);
        _atexit((_func_4879 *)&LAB_00bcce30);
        local_c = 0xffffffff;
      }
      local_30 = (uint)*puVar5;
      FUN_00826280(&local_30);
      if ((local_2c == DAT_00fab15c) ||
         (puVar3 = *(ushort **)(local_2c + 0x10), puVar3 == (ushort *)0x0)) {
        puVar3 = (ushort *)FUN_00891268(4);
        uVar1 = DAT_00fab22c & 1;
        *puVar3 = *puVar5;
        if (uVar1 == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 2;
          FUN_004dec90();
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        local_28 = *puVar3;
        local_24 = puVar3;
        uVar4 = FUN_004ca670();
        FUN_008262f0(&DAT_00fab158,uVar4);
      }
      uVar4 = *(undefined4 *)puVar5;
      puVar5 = puVar5 + 2;
      local_34 = local_34 - 1;
      *(undefined4 *)puVar3 = uVar4;
    } while (local_34 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

