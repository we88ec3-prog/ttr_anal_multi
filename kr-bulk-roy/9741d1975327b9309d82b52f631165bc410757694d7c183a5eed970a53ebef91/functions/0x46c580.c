
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_0046c580(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009255dd;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0d70 & 1) == 0) {
    DAT_00fc0d70 = DAT_00fc0d70 | 1;
    local_8 = 0;
    FUN_0046eb40(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fc0d84 = 0;
    DAT_00fc0d88 = 0;
    _DAT_00fc0d8c = 0;
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0046e530();
    _atexit((_func_4879 *)&LAB_00bcd920);
  }
  ExceptionList = local_10;
  return &DAT_00fc0d74;
}

