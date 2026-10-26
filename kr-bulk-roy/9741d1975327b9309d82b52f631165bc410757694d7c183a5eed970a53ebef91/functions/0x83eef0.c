
void FUN_0083eef0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009091be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00fe34d8 == (undefined *)0x0) {
    if ((DAT_00fe3480 & 1) == 0) {
      DAT_00fe3480 = DAT_00fe3480 | 1;
      local_8 = 0;
      FUN_00862d10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bd0e20);
    }
    DAT_00fe34d8 = &DAT_00fe3488;
  }
  ExceptionList = local_10;
  return;
}

