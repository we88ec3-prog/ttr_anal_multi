
void FUN_00863520(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908d5a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  piVar1 = *(int **)(param_1 + 0x40);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  local_8 = 0xffffffff;
  FUN_00863870(param_1);
  ExceptionList = local_10;
  return;
}

