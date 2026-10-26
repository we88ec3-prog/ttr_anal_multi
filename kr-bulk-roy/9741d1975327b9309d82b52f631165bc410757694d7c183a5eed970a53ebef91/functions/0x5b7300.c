
void FUN_005b7300(int param_1)

{
  uint uVar1;
  int unaff_ESI;
  int *piVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d77c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (DAT_00f942c0 == '\0') {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (DAT_00f9392c == 5) {
      piVar2 = *(int **)(unaff_ESI + 0x2e0);
      if (((uint)piVar2[10] >> 8 & 1) != 0) {
        ExceptionList = local_14;
        return;
      }
    }
    else {
      FUN_006905f0(param_1);
      piVar2 = *(int **)(unaff_ESI + 0x24c);
      if (param_1 != 0) {
        (**(code **)(*piVar2 + 0xd0))();
        ExceptionList = local_14;
        return;
      }
      if (((uint)piVar2[10] >> 8 & 1) != 0) {
        if (((uint)piVar2[10] >> 8 & 1) == 0) {
          ExceptionList = local_14;
          return;
        }
        (**(code **)(*piVar2 + 0xd4))();
        ExceptionList = local_14;
        return;
      }
    }
    FUN_00596e00(unaff_ESI,piVar2);
  }
  ExceptionList = local_14;
  return;
}

