
void FUN_005f7d60(void)

{
  int iVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00946f2c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_005f51a0(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  if ((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) == 0) ||
     (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) == 0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_005f55a0();
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  *(int *)(DAT_00f94300 + 0x50bc) = iVar1 + 1;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 1;
    FUN_004ffe60();
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_c = 0xffffffff;
  }
  FUN_00501650(0x11);
  ExceptionList = local_14;
  return;
}

