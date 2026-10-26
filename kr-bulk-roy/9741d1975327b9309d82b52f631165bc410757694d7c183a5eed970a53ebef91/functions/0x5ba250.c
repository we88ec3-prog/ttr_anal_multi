
void FUN_005ba250(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009472de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x24c) != 0) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_8 = 0;
      FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bccfb0);
    }
    local_8 = 0xffffffff;
    FUN_006904b0(DAT_00fb722c);
  }
  ExceptionList = local_10;
  return;
}

