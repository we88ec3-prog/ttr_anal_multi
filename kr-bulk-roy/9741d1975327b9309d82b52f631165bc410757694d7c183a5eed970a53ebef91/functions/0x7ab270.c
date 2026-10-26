
void FUN_007ab270(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093893a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  FUN_00799c30();
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 1;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007cf710(&DAT_00fe3250);
  (**(code **)(*DAT_00fba838 + 0x10))();
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8 = 2;
    FUN_007b5430();
    _atexit((_func_4879 *)&LAB_00bce660);
  }
  FUN_007b6770(&DAT_00fd9420);
  ExceptionList = local_10;
  return;
}

