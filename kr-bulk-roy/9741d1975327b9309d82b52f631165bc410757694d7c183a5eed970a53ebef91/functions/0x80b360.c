
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080b360(void)

{
  uint uVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090741e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  *(undefined4 *)(in_ECX + 0x70) = 1;
  do {
    if ((DAT_00fe33c4 & 1) == 0) {
      DAT_00fe33c4 = DAT_00fe33c4 | 1;
      local_c = 0;
      FUN_0080e030(uVar1);
      _DAT_00fe33f8 = 0;
      _atexit((_func_4879 *)&LAB_00bd0bd0);
      local_c = 0xffffffff;
    }
    FUN_0080e100();
    Sleep(5);
  } while (*(int *)(in_ECX + 0x70) != 0);
  FID_conflict__wprintf("ThreadedUpdate: Thread Terminated\n");
  ExceptionList = local_14;
  return;
}

