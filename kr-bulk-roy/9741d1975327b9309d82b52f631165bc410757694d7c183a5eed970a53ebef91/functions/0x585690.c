
undefined4 * FUN_00585690(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912ade;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faafd4 & 1) == 0) {
    DAT_00faafd4 = DAT_00faafd4 | 1;
    local_8 = 0;
    FUN_0044dfb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bccd10);
  }
  ExceptionList = local_10;
  return &DAT_00faafd8;
}

