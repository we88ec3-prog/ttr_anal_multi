
bool FUN_004a9f00(void)

{
  int iVar1;
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f80e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)auStack_18);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (*(int *)(DAT_00f94304 + 0x47c) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00f94304 + 0x420;
  }
  ExceptionList = local_14;
  return iVar1 != 0;
}

