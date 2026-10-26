
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00563830(undefined4 param_1)

{
  uint uVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093aacc;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 0;
    FUN_0054e750(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd260);
  }
  DAT_00fb7620 = &DAT_00fb766c;
  _DAT_00fb7670 = param_1;
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 1;
    FUN_0054e750(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd260);
    if (DAT_00fb7620 == (int *)0x0) {
      ExceptionList = local_14;
      return;
    }
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fb7620 + 8))();
  ExceptionList = local_14;
  return;
}

