
void FUN_004777b0(int *param_1,undefined4 param_2)

{
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092b32e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_20 = param_2;
  FUN_008438c0(&local_20);
  if ((local_1c != DAT_00f8d91c) && (*(int *)(local_1c + 0x10) != 0)) {
    FUN_004451b0(*(undefined4 *)(*(int *)(local_1c + 0x10) + 0x1c),0,0,0);
    (**(code **)(*param_1 + 200))();
    ExceptionList = local_14;
    return;
  }
  FUN_004451b0(0xffffffff,0xffffffff,0xffffffff,0);
  ExceptionList = local_14;
  return;
}

