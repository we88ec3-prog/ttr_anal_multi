
void FUN_007c3f40(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938f8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xe8) == 0) {
    if ((DAT_00fc0f60 & 1) == 0) {
      DAT_00fc0f60 = DAT_00fc0f60 | 1;
      local_8 = 0;
      FUN_0079cf40(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcdb80);
    }
    local_8 = 0xffffffff;
    FUN_007c5300();
  }
  ExceptionList = local_10;
  return;
}

