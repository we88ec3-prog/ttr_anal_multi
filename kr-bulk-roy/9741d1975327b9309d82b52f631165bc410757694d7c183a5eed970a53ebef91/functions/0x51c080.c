
undefined4 FUN_0051c080(void)

{
  int unaff_ESI;
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
  if (((*(int *)(unaff_ESI + 0x48) == 0) || (DAT_00f93950 <= *(int *)(unaff_ESI + 0x48))) &&
     ((*(int *)(unaff_ESI + 0x44) == 0 || (*(int *)(unaff_ESI + 0x44) <= DAT_00f93950)))) {
    ExceptionList = local_14;
    return 1;
  }
  ExceptionList = local_14;
  return 0;
}

