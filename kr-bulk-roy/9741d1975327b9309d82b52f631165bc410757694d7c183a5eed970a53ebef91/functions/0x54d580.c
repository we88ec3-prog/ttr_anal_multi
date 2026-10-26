
undefined4 FUN_0054d580(int param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_ECX;
  undefined4 in_EDX;
  undefined4 in_XMM0_Da;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ed2e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x20) == 0) {
    uVar1 = DAT_00fb79e8 & 1;
    *(undefined4 *)(param_1 + 0x20) = 1;
    *(undefined4 *)(param_1 + 0x24) = in_ECX;
    *(undefined4 *)(param_1 + 0x28) = in_EDX;
    *(undefined4 *)(param_1 + 0x2c) = in_XMM0_Da;
    *(undefined4 *)(param_1 + 0x30) = in_XMM0_Da;
    if (uVar1 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    FUN_00798900(DAT_00fb76e8 + 0xa0,DAT_00fb76e8 + 0xc);
    FUN_00402a70("Behold",6);
  }
  ExceptionList = local_10;
  return 1;
}

