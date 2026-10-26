
void FUN_005db310(char param_1)

{
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (param_1 == '\0') {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    FUN_0050c5c0(DAT_00f942fc);
  }
  ExceptionList = local_14;
  return;
}

