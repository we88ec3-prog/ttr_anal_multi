
undefined4 FUN_00603380(void)

{
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((*(int *)(in_ECX + 0xf0) == 1) && (DAT_00f94300 != -0x16f8)) {
    ExceptionList = local_14;
    return *(undefined4 *)(DAT_00f94300 + 0x2398);
  }
  ExceptionList = local_14;
  return 0;
}

