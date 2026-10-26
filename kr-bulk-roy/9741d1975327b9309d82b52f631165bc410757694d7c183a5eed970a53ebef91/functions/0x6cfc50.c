
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006cfc50(void)

{
  undefined *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009269ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fc1a78 = 0;
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 0;
    FUN_006ccd20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce3c0);
  }
  puVar1 = DAT_00fc1738;
  if (DAT_00fc1738 == (undefined *)0x0) {
    puVar1 = &DAT_00fc173c;
  }
  _DAT_00fc1a7c = *(undefined4 *)(puVar1 + 0x38);
  _memset(&DAT_00fc1a80,0,0x40);
  ExceptionList = local_10;
  return &DAT_00fc1a78;
}

