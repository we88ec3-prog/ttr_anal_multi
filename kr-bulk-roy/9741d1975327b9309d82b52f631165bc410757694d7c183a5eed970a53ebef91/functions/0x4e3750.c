
undefined4 FUN_004e3750(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929b6e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if (param_2 < 2) {
    uVar2 = 0;
  }
  else {
    uVar2 = (param_2 - 2) / 0x2f;
  }
  if (uVar2 != 0) {
    param_1 = param_1 + 6;
    do {
      if ((DAT_00fb75b0 & 1) == 0) {
        DAT_00fb75b0 = DAT_00fb75b0 | 1;
        local_c = 0;
        FUN_004f3d80(uVar1);
        _atexit((_func_4879 *)&LAB_00bcd1e0);
        local_c = 0xffffffff;
      }
      FUN_004f7280(&DAT_00fb7470,*(undefined4 *)(param_1 + -4),param_1,
                   *(undefined1 *)(param_1 + 0x2a));
      param_1 = param_1 + 0x2f;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  ExceptionList = local_14;
  return 0;
}

