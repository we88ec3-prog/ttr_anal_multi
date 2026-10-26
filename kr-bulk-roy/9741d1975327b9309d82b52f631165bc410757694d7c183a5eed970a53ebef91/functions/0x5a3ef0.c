
void FUN_005a3ef0(void)

{
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009361be;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb11e0 & 1) == 0) {
    DAT_00fb11e0 = DAT_00fb11e0 | 1;
    local_8 = 0;
    FUN_004d4d10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccef0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb11e8 == 1) {
    FUN_00645250(*(undefined4 *)(unaff_ESI + 0x140));
  }
  else if ((DAT_00fb11e8 == 2) && (*(int *)(*(int *)(unaff_ESI + 0x148) + 0xec) != 0)) {
    FUN_006482c0();
    ExceptionList = local_10;
    return;
  }
  ExceptionList = local_10;
  return;
}

