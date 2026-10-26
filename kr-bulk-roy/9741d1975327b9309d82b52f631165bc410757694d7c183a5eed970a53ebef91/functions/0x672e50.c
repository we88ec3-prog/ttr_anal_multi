
void FUN_00672e50(void)

{
  uint uVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x80) + 0xd4))(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    uVar1 = DAT_00f94390 & 1;
    *(undefined4 *)(in_ECX + 0xd8) = 0;
    if (uVar1 == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      uStack_c = 0;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      uStack_c = 0xffffffff;
    }
    DAT_00f942a5 = 0;
    FUN_00413960();
  }
  ExceptionList = local_14;
  return;
}

