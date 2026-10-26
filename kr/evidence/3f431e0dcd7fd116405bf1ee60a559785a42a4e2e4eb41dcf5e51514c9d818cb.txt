
void FUN_0059c690(int param_1)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009361fc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  *(undefined4 *)(DAT_00fba7a4 + 0x78) = 0;
  DAT_00fbab34 = 0;
  DAT_00fbab38 = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 5;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar1 = DAT_00fb76e8;
  local_c = 0xffffffff;
  *(undefined4 *)(DAT_00fb76e8 + 0xd8) = *(undefined4 *)(DAT_00fb76e8 + 0xd4);
  *(undefined4 *)(iVar1 + 0xb0) = 1;
  (**(code **)(**(int **)(param_1 + 0x1fc) + 0xd4))();
  ExceptionList = local_14;
  return;
}

