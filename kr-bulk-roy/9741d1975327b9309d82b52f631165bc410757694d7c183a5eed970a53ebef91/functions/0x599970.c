
void FUN_00599970(int param_1)

{
  int *piVar1;
  int iVar2;
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
  local_c = 0xffffffff;
  if (DAT_00fb7258 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    iVar2 = FUN_00539aa0(DAT_00f93930);
    if (((iVar2 != 0) && (*(char *)(iVar2 + 6) == '\0')) && (*(char *)(iVar2 + 8) != '\0')) {
      ExceptionList = local_14;
      return;
    }
  }
  piVar1 = *(int **)(param_1 + 0x168);
  if (((uint)piVar1[10] >> 8 & 1) == 0) {
    FUN_00596e00(param_1,piVar1);
  }
  else if (((uint)piVar1[10] >> 8 & 1) != 0) {
    (**(code **)(*piVar1 + 0xd4))();
    ExceptionList = local_14;
    return;
  }
  ExceptionList = local_14;
  return;
}

