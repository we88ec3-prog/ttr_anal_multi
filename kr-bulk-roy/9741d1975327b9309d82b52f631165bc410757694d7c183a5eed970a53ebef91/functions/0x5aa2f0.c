
/* WARNING: Removing unreachable block (ram,0x005aa386) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aa2f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005a3cc0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((_DAT_00f8d8a8 & 1) == 0) {
    _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
    FUN_005e93a0();
    _atexit((_func_4879 *)&DAT_00bccc40);
  }
  FUN_005e99c0();
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x3f);
  ExceptionList = local_10;
  return;
}

