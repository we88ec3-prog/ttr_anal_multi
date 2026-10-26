
void FUN_007efa80(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093224c;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00780150(*(int *)(in_ECX + 0x124),*(undefined4 *)(*(int *)(in_ECX + 0x124) + 0x30));
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
  }
  (**(code **)(**(int **)(in_ECX + 0x124) + 0x28))(DAT_00fb76a8);
  ExceptionList = local_10;
  return;
}

