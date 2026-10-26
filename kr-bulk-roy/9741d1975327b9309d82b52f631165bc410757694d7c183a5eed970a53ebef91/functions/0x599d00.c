
void FUN_00599d00(int param_1)

{
  int *piVar1;
  uint uVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00916a3a;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 0;
    FUN_0074d990(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  if (DAT_00f95c00 != (int *)0x0) {
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 1;
      FUN_0074d990(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_c = 0xffffffff;
    if (DAT_00f95c00 != (int *)0x0) {
      (**(code **)(*DAT_00f95c00 + 0xd4))();
      if (DAT_00f95c00 != (int *)0x0) {
        (**(code **)(*DAT_00f95c00 + 0x130))();
      }
    }
    DAT_00f95c00 = (int *)0x0;
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 2;
    FUN_0074d990(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_c = 0xffffffff;
  piVar1 = *(int **)(param_1 + 0x16c);
  if (DAT_00f95c00 != (int *)0x0) {
    (**(code **)(*DAT_00f95c00 + 0xd4))();
    if (DAT_00f95c00 != (int *)0x0) {
      (**(code **)(*DAT_00f95c00 + 0x130))();
    }
  }
  DAT_00f95c00 = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0xd0))();
    (**(code **)(*DAT_00f95c00 + 300))();
    (**(code **)(*DAT_00f95c00 + 200))();
  }
  DAT_00f95c04 = 1;
  ExceptionList = local_14;
  return;
}

