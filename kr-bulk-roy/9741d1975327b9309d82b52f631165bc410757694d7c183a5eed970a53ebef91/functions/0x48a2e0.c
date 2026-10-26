
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0048a2e0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b5ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc19f4 & 1) == 0) {
    DAT_00fc19f4 = DAT_00fc19f4 | 1;
    local_8 = 0;
    FUN_008082f0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _DAT_00fc19f8 = CSubAIManager::vftable;
    DAT_00fc1a24 = 0;
    _DAT_00fc1a28 = 0;
    _DAT_00fc1a2c = 0;
    _atexit((_func_4879 *)&LAB_00bce100);
  }
  ExceptionList = local_10;
  return &DAT_00fc19f8;
}

