
int FUN_005fa380(void)

{
  int iVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar1 = *(int *)(DAT_00f94300 + 0x50b8) + *(int *)(in_ECX + 0xf0) * -0x50 + 0x50;
  if (iVar1 < 0) {
    ExceptionList = local_14;
    return 0;
  }
  if (0x50 < iVar1) {
    iVar1 = 0x50;
  }
  ExceptionList = local_14;
  return iVar1;
}

