
undefined4 FUN_006a11d0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c69c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar2 = 0;
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 0;
    FUN_00533f80(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  piVar1 = DAT_00fe1c2c;
  if ((DAT_00fe1c30 - (int)DAT_00fe1c2c) / 0x1f != 0) {
    for (; (*piVar1 != param_1 || (piVar1[1] != param_2)); piVar1 = (int *)((int)piVar1 + 0x1f)) {
      iVar2 = iVar2 + 1;
    }
    iVar2 = iVar2 * 0x1f + (int)DAT_00fe1c2c;
    if (iVar2 != 0) {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 1;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
      }
      if (*(uint *)(iVar2 + 0x14) <= DAT_00f94244) {
        ExceptionList = local_14;
        return 1;
      }
    }
  }
  ExceptionList = local_14;
  return 0;
}

