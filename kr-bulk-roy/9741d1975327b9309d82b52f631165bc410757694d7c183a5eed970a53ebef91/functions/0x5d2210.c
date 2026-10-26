
void FUN_005d2210(void)

{
  int iVar1;
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
  local_c = 0xffffffff;
  iVar1 = *(int *)(unaff_ESI + 0xd0);
  *(undefined4 *)(iVar1 + 0xe0) = DAT_00f93930;
  *(undefined4 *)(iVar1 + 0xdc) = 2;
  FUN_0068b260(*(undefined4 *)(unaff_ESI + 0xd0));
  ExceptionList = local_14;
  return;
}

