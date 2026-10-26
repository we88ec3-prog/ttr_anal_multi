
void FUN_00648aa0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int local_28;
  int local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00926b66;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb725c & 1) == 0) {
    DAT_00fb725c = DAT_00fb725c | 1;
    local_c = 0;
    FUN_004a79a0(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&DAT_00bccf80);
  }
  local_c = 0xffffffff;
  FUN_00450340();
  local_c = 1;
  uVar2 = local_24 - local_28 >> 2;
  uVar1 = 0;
  if (uVar2 != 0) {
    do {
      if (param_1 == *(int *)(*(int *)(local_28 + uVar1 * 4) + 4)) {
        FUN_006494b0();
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < uVar2);
  }
  if (local_28 != 0) {
    FUN_0089120c(local_28);
  }
  ExceptionList = local_14;
  return;
}

