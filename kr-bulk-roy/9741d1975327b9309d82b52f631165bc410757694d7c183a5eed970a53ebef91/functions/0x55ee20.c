
undefined4 * FUN_0055ee20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093ab9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe2740 & 1) == 0) {
    DAT_00fe2740 = DAT_00fe2740 | 1;
    local_8 = 0;
    FUN_0055e680(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&DAT_00bcf2a0);
  }
  ExceptionList = local_10;
  return &DAT_00fe2744;
}

