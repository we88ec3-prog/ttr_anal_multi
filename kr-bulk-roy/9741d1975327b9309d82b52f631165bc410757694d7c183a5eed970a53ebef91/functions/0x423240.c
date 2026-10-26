
undefined * FUN_00423240(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b8ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb744c & 1) == 0) {
    DAT_00fb744c = DAT_00fb744c | 1;
    local_8 = 0;
    FUN_004eec60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd140);
  }
  ExceptionList = local_10;
  return &DAT_00fb7450;
}

