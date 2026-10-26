
undefined4 FUN_004c3b90(undefined4 param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e42e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1b30 & 1) == 0) {
    DAT_00fe1b30 = DAT_00fe1b30 | 1;
    local_8 = 0;
    FUN_0047faf0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bceab0);
  }
  local_8 = 0xffffffff;
  FUN_0047fbb0(&DAT_00fe1b34,param_2);
  ExceptionList = local_10;
  return 0;
}

