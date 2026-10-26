
void FUN_00636790(void)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009348ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007459c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  FUN_00798900(DAT_00fb76e8 + 0xa0,DAT_00fb76e8 + 0xc);
  FUN_00402a70("Talkbox",7);
  FUN_00636050(in_ECX);
  FUN_00636970(in_ECX);
  ExceptionList = local_10;
  return;
}

