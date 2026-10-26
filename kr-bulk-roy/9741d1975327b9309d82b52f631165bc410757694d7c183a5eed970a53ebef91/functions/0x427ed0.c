
void FUN_00427ed0(int param_1,undefined4 param_2)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094578c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  if (DAT_00fb7258 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    iVar1 = FUN_00539aa0(DAT_00f93930);
    if ((*(char *)(iVar1 + 8) == '\0') && (*(char *)(param_1 + 0x134) == '\0')) {
      FUN_00414680();
      FUN_004a42a0(param_2);
    }
  }
  ExceptionList = local_14;
  return;
}

