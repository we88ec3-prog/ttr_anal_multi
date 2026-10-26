
void FUN_005ccc20(void)

{
  void *pvVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093f5ec;
  local_14 = ExceptionList;
  pvVar1 = (void *)(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  ExceptionList = &local_14;
  (**(code **)(**(int **)(in_ECX + 0x2f8) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x2fc) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x300) + 0x94))(0);
  (**(code **)(**(int **)(in_ECX + 0x308) + 0x94))(0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  FUN_005cf450();
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  FUN_0058f0c0(in_ECX + 0x37c);
  ExceptionList = pvVar1;
  return;
}

