
void FUN_0064c710(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093d97a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int **)(param_1 + 0xf0) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0xf0) + 200))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (DAT_00f9392c == 3) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    uVar2 = DAT_00fab1bc;
    if ((DAT_00fe17b8 & 1) == 0) {
      DAT_00fe17b8 = DAT_00fe17b8 | 1;
      local_c = 2;
      FUN_0050caf0();
      _atexit((_func_4879 *)&LAB_00bce7e0);
      local_c = 0xffffffff;
    }
    uStack_20 = uVar2;
    FUN_0050db00(&uStack_20);
    if (((iStack_1c != DAT_00fe17c4) && (iVar1 = iStack_1c + 0x10, iVar1 != 0)) &&
       (*(int *)(param_1 + 0x100) != iVar1)) {
      FUN_00757800(iVar1);
      (**(code **)(**(int **)(param_1 + 0xec) + 200))();
      *(int *)(param_1 + 0x100) = iVar1;
    }
  }
  ExceptionList = local_14;
  return;
}

