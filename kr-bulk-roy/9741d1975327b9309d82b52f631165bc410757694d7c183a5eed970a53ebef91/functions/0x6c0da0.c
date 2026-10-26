
undefined1 * FUN_006c0da0(int param_1)

{
  undefined1 auStackY_100 [228];
  undefined4 uStackY_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a9ae;
  local_10 = ExceptionList;
  if (param_1 == 0xd) {
    ExceptionList = &local_10;
    if ((DAT_00fc1b14 & 1) == 0) {
      DAT_00fc1b14 = DAT_00fc1b14 | 1;
      local_8 = 0;
      FUN_0055ee90();
      uStackY_1c = 0x6c0dee;
      _atexit((_func_4879 *)&LAB_00bcdf90);
    }
    local_8 = 0xffffffff;
    FUN_0055f960();
    ExceptionList = local_10;
    return (undefined1 *)0x1;
  }
  return auStackY_100;
}

