
undefined4 FUN_004f1590(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929a7a;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if (param_2 < 3) {
    local_20 = 0;
  }
  else {
    local_20 = (param_2 - 3) / 0x2e;
  }
  if (local_20 != 0) {
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
      iVar2 = FUN_004f2610(1);
      if (iVar2 != 0) {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c = 1;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c = 0xffffffff;
        }
        uVar3 = FUN_004f6a30(*puVar4);
        *(undefined4 *)(iVar2 + 4) = uVar3;
      }
      puVar4 = (undefined4 *)((int)puVar4 + 0x2e);
      local_20 = local_20 - 1;
    } while (local_20 != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 2;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf424b);
  ExceptionList = local_14;
  return 0;
}

