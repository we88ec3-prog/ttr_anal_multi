
undefined4 FUN_00535320(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092989c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = (param_2 - 2) / 0x2e;
  }
  if (uVar2 != 0) {
    puVar3 = (undefined4 *)(param_1 + 2);
    do {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0;
        FUN_004f3d80(uVar1);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      FUN_004f6950(*puVar3,puVar3 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 0x2e);
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(&DAT_000f4284);
  ExceptionList = local_14;
  return 0;
}

