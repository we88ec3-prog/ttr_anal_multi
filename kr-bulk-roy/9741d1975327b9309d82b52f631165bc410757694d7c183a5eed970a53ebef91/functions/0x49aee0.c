
undefined * FUN_0049aee0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b70e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8 = 0;
    FUN_007b5430(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce660);
  }
  ExceptionList = local_10;
  return &DAT_00fd9420;
}

