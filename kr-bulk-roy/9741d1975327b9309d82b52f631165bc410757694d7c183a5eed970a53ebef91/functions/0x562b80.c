
void FUN_00562b80(undefined4 param_1,int param_2)

{
  uint uVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ab68;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if (param_2 == 0) {
    if ((DAT_00fb761c & 1) == 0) {
      DAT_00fb761c = DAT_00fb761c | 1;
      local_c = 2;
      FUN_0054e750(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd260);
    }
    local_c = 0xffffffff;
    DAT_00fb7620 = &DAT_00fb7624;
    FUN_00796ee0();
  }
  else {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    if ((DAT_00fb761c & 1) == 0) {
      DAT_00fb761c = DAT_00fb761c | 1;
      local_c = 1;
      FUN_0054e750(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd260);
    }
    local_c = 0xffffffff;
    DAT_00fb7620 = &DAT_00fb7624;
    FUN_007974d0();
  }
  if ((DAT_00fb761c & 1) == 0) {
    DAT_00fb761c = DAT_00fb761c | 1;
    local_c = 3;
    FUN_0054e750(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd260);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7620 != (int *)0x0) {
    (**(code **)(*DAT_00fb7620 + 8))();
  }
  ExceptionList = local_14;
  return;
}

