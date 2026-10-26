
bool FUN_004c96b0(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined *puVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00936a5c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar1 = (**(code **)(*DAT_00fba7a4 + 0x20))(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  if (iVar1 == 0) {
    ExceptionList = local_14;
    return false;
  }
  iVar1 = *(int *)(iVar1 + 0x90);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  if ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3 == 0) {
    puVar3 = &DAT_00fab1e8 + iVar1 * 3;
  }
  else {
    puVar3 = (undefined *)0x0;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar1 = *(int *)(param_1 + 0x90);
  if ((int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3 == 0) {
    puVar2 = &DAT_00fab1e8 + iVar1 * 3;
  }
  else {
    puVar2 = (undefined *)0x0;
  }
  if ((puVar3 != (undefined *)0x0) && (puVar2 != (undefined *)0x0)) {
    iVar1 = FUN_004c6f60();
    ExceptionList = local_14;
    return iVar1 == 0x12;
  }
  ExceptionList = local_14;
  return true;
}

