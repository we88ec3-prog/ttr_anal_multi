
uint FUN_004c6ea0(int param_1)

{
  int iVar1;
  undefined4 local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&local_20);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_20 = *(undefined4 *)(param_1 + 4);
  FUN_0082ef00(&local_20);
  if ((local_1c != DAT_00fab13c) && (iVar1 = *(int *)(local_1c + 0x10), local_1c = 0, iVar1 != 0)) {
    ExceptionList = local_14;
    return CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)(iVar1 + 0xbc));
  }
  ExceptionList = local_14;
  return local_1c & 0xffffff00;
}

