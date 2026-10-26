
void FUN_007fb270(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093731a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  uVar1 = FUN_0079a5f0(&DAT_00fb76a8);
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 1;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  iVar2 = FUN_007ce5e0();
  if (iVar2 != 0) {
    if ((DAT_00fe324c & 1) == 0) {
      DAT_00fe324c = DAT_00fe324c | 1;
      local_8 = 2;
      FUN_007cdeb0();
      _atexit((_func_4879 *)&LAB_00bd09b0);
      local_8 = 0xffffffff;
    }
    FUN_007ce500(in_ECX + 0x30);
  }
  ExceptionList = local_10;
  return;
}

