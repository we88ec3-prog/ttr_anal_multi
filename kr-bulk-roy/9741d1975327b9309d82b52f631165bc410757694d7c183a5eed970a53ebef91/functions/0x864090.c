
void FUN_00864090(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  puStack_c = &LAB_0090bae7;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  piVar1 = *(int **)(param_1 + 0x40);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_00843340(param_1 + 0x44);
  local_8 = 0xffffffff;
  FUN_00864660(param_1);
  ExceptionList = local_10;
  return;
}

