
void FUN_005abb90(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_005ab490(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if ((1 < (uint)(*(int *)(DAT_00fab130 + 0x5ebc) - *(int *)(DAT_00fab130 + 0x5eb8) >> 3)) &&
     (iVar2 = *(int *)(DAT_00fab130 + 0x5edc) - *(int *)(DAT_00fab130 + 0x5ed8),
     iVar1 = iVar2 >> 0x1f, iVar2 / 5 + iVar1 != iVar1)) {
    (**(code **)(**(int **)(in_ECX + 0x16c) + 0xd4))();
  }
  ExceptionList = local_14;
  return;
}

