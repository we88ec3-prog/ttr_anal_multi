
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00647710(void)

{
  int *piVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  piVar1 = *(int **)(in_ECX + 0xf4);
  piVar1[0x31] = (int)_DAT_00f942a0;
  (**(code **)(*piVar1 + 0x128))();
  (**(code **)(*piVar1 + 200))();
  FUN_006477c0();
  ExceptionList = local_14;
  return;
}

