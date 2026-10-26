
void FUN_004a0b80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&local_20);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  local_20 = param_1;
  FUN_0082ef00(&local_20);
  if ((local_1c != DAT_00fab13c) && (iVar1 = *(int *)(local_1c + 0x10), iVar1 != 0)) {
    *(short *)(iVar1 + 0x388) = (short)param_3;
    if ((*(int *)(iVar1 + 0x15c) != 0) && (*(int *)(iVar1 + 0x370) != 0)) {
      FUN_007a6ea0(*(int *)(iVar1 + 0x15c),param_2,param_3);
    }
  }
  ExceptionList = local_14;
  return;
}

