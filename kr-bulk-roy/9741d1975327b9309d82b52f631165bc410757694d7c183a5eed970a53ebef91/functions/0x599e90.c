
void FUN_00599e90(void)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_ESI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093624a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((*(uint *)(*(int *)(unaff_ESI + 0x1fc) + 0x28) & 0x100) == 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    *(undefined4 *)(DAT_00fba7a4 + 0x78) = 1;
    FUN_0054c770(1);
    (**(code **)(**(int **)(unaff_ESI + 0x1fc) + 0xd0))();
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  *(undefined4 *)(DAT_00fba7a4 + 0x78) = 0;
  DAT_00fbab34 = 0;
  DAT_00fbab38 = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 6;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar2 = DAT_00fb76e8;
  local_c = 0xffffffff;
  puVar1 = (undefined4 *)(DAT_00fb76e8 + 0xd4);
  *(undefined4 *)(DAT_00fb76e8 + 0xb0) = 1;
  *(undefined4 *)(iVar2 + 0xd8) = *puVar1;
  (**(code **)(**(int **)(unaff_ESI + 0x1fc) + 0xd4))();
  ExceptionList = local_14;
  return;
}

