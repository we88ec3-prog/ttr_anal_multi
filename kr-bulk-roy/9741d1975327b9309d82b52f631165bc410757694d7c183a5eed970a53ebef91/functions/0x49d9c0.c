
void FUN_0049d9c0(void)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  if (iVar1 != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      uStack_c = 0xffffffff;
    }
    FUN_004e0650(&DAT_00fab130);
  }
  ExceptionList = local_14;
  return;
}

