
void FUN_00589e80(void)

{
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091db9c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  local_8 = 0xffffffff;
  FUN_005c6fd0();
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 1;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  if (DAT_00f95bd4 != 0) {
    FUN_00746b80();
  }
  FUN_005cb1c0();
  (**(code **)(**(int **)(unaff_ESI + 0x30) + 0x20))();
  FUN_00739120(*(undefined4 *)(unaff_ESI + 0x154));
  if (*(int *)(unaff_ESI + 0x154) != 0) {
    FUN_004a47d0(*(int *)(unaff_ESI + 0x154));
    *(undefined4 *)(unaff_ESI + 0x154) = 0;
  }
  ExceptionList = local_10;
  return;
}

