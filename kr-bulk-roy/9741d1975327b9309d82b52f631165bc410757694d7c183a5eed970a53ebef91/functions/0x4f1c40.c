
undefined4 FUN_004f1c40(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929a2a;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if (param_2 < 3) {
    local_1c = 0;
  }
  else {
    local_1c = (param_2 - 3) / 0x2e;
  }
  if (local_1c != 0) {
    puVar4 = (undefined4 *)(param_1 + 3);
    do {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0;
        FUN_004f3d80(uVar1);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      FUN_004f6950(*puVar4,puVar4 + 1);
      puVar2 = (undefined4 *)FUN_004f2740(1);
      if (puVar2 != (undefined4 *)0x0) {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c = 1;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c = 0xffffffff;
        }
        uVar3 = FUN_004f6a30(*puVar4);
        *puVar2 = uVar3;
      }
      puVar4 = (undefined4 *)((int)puVar4 + 0x2e);
      local_1c = local_1c - 1;
    } while (local_1c != 0);
  }
  FUN_00666d10(*(int *)(in_ECX + 0x5ebc),*(int *)(in_ECX + 0x5ec0),
               *(int *)(in_ECX + 0x5ec0) - *(int *)(in_ECX + 0x5ebc) >> 2,FUN_004f10a0);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf424e);
  ExceptionList = local_14;
  return 0;
}

