
void FUN_006d9780(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00919ad6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  if (*(int *)(in_ECX + 0x6c) != 0) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb9335 != '\0') {
      FUN_006d9280(0x40400000);
      FUN_00402a70(&DAT_00bf2375,0);
      ExceptionList = local_10;
      return;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xb4));
    local_8 = 1;
    (**(code **)(**(int **)(in_ECX + 0x6c) + 0x2c))();
    *(undefined4 *)(in_ECX + 0x6c) = 0;
    LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 0xb4));
  }
  ExceptionList = local_10;
  return;
}

