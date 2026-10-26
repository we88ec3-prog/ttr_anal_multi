
void FUN_007f6d70(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091866e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x20) != 0) {
    if ((DAT_00fe324c & 1) == 0) {
      DAT_00fe324c = DAT_00fe324c | 1;
      local_8 = 0;
      FUN_007cdeb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bd09b0);
    }
    local_8 = 0xffffffff;
    FUN_007cf480();
    *(undefined4 *)(in_ECX + 0x20) = 0;
  }
  ExceptionList = local_10;
  return;
}

