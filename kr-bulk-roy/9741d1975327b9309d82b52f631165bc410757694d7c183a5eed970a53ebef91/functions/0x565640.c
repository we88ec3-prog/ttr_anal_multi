
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565640(void)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  _DAT_00fab1e0 = 1;
  ExceptionList = local_14;
  return;
}

