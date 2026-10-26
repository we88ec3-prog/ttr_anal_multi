
void FUN_00423600(void)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094584c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
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
    if ((iVar1 != 0) && (*(char *)(iVar1 + 6) != '\0')) {
      FUN_00423240();
      FUN_00516fa0();
      FUN_00414680();
      FUN_004a35f0();
    }
  }
  ExceptionList = local_14;
  return;
}

