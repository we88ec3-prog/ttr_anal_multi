
undefined * FUN_0049c410(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092799e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_8 = 0;
    FUN_00590760(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce760);
  }
  ExceptionList = local_10;
  return &DAT_00fdfb18;
}

