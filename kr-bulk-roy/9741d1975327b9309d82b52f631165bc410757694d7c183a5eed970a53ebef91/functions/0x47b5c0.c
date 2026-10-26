
void FUN_0047b5c0(undefined4 param_1)

{
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094107c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x248) == 0xea61) {
    if (*(char *)(in_ECX + 0x26c) == '\0') {
      FUN_0047b850(in_ECX);
    }
  }
  else {
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_c = 0;
      FUN_00560170(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
      _atexit((_func_4879 *)&LAB_00bcd110);
    }
    local_c = 0xffffffff;
    FUN_00565720(*(undefined4 *)(in_ECX + 0x248),param_1);
  }
  if ((DAT_00fc0f64 & 1) == 0) {
    DAT_00fc0f64 = DAT_00fc0f64 | 1;
    local_c = 1;
    FUN_0047dce0();
    _atexit(FUN_00bcdaf0);
    local_c = 0xffffffff;
  }
  FUN_0047e750(*(undefined4 *)(in_ECX + 0x24c));
  ExceptionList = local_14;
  return;
}

