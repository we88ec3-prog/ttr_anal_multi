
int FUN_005dd930(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = in_ECX + -0x50 + param_1 * 0x50;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (iVar1 - 1U < 0x1e0) {
    iVar2 = DAT_00f94300 + 0x23a0 + iVar1 * 0x18;
    if ((*(int *)(DAT_00f94300 + 0x23ac + iVar1 * 0x18) != 0) && (*(int *)(iVar2 + 8) != 0)) {
      ExceptionList = local_14;
      return iVar2;
    }
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
  }
  ExceptionList = local_14;
  return 0;
}

