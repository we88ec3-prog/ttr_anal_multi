
void FUN_0085df80(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00913c9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00fe350c == (undefined *)0x0) {
    if ((DAT_00fe5df4 & 1) == 0) {
      DAT_00fe5df4 = DAT_00fe5df4 | 1;
      local_8 = 0;
      FUN_00870750(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit(FUN_00bd0f20);
    }
    DAT_00fe350c = &DAT_00fe3514;
  }
  ExceptionList = local_10;
  return;
}

