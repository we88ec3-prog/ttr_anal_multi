
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_00459c20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092a128;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0c7c & 1) == 0) {
    DAT_00fc0c7c = DAT_00fc0c7c | 1;
    local_8 = 0;
    FUN_00823e10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    local_8 = CONCAT31(local_8._1_3_,1);
    _DAT_00fc0c80 = CCubeSystemMgr::vftable;
    FUN_0044be70();
    _atexit((_func_4879 *)&LAB_00bcd780);
  }
  ExceptionList = local_10;
  return &DAT_00fc0c80;
}

