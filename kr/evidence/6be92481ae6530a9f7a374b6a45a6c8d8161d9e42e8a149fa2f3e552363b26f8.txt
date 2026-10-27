
undefined4 FUN_00500160(int param_1,int param_2)

{
  int iVar1;
  short in_CX;
  undefined1 local_20 [4];
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  for (iVar1 = *(int *)(DAT_00fab134 + 0x10); iVar1 != *(int *)(DAT_00fab134 + 0x14);
      iVar1 = iVar1 + 0x18) {
    if ((*(short *)(iVar1 + 0x14) == in_CX) && (*(short *)(iVar1 + 8) < *(short *)(iVar1 + 6))) {
      ExceptionList = local_14;
      return 0;
    }
  }
  iVar1 = *(int *)(param_1 + 0x5eac);
  FUN_00503d20(local_20);
  if (((local_1c != *(int *)(iVar1 + 4)) && (local_1c != -0x10)) &&
     (*(int *)(local_1c + 0x3c) == param_2)) {
    ExceptionList = local_14;
    return 1;
  }
  ExceptionList = local_14;
  return 0;
}

