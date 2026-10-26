
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005a5240(void)

{
  uint uVar1;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093611c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  if ((*(uint *)(*(int *)(in_ECX + 0x144) + 0x28) & 0x100) != 0) {
    ExceptionList = &local_14;
    FUN_00641d90(*(int *)(in_ECX + 0x144));
    (**(code **)(**(int **)(in_ECX + 0x144) + 0xd4))(uVar1);
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      uStack_c = 0;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    _DAT_00f95bec = 0;
    DAT_00f95be9 = 1;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    *(undefined4 *)(DAT_00fba7a4 + 8) = 1;
    ExceptionList = local_14;
    return 1;
  }
  return 0;
}

