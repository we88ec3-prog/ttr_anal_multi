
void FUN_006a7660(void)

{
  undefined4 *puVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b73e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  local_8 = 0xffffffff;
  puVar1 = DAT_00fc0c0c;
  if (DAT_00fc0c20 < 8) {
    puVar1 = &DAT_00fc0c0c;
  }
  FUN_00765f70(*(undefined4 *)(unaff_ESI + 0x100),puVar1);
  (**(code **)(**(int **)(unaff_ESI + 0x100) + 200))();
  ExceptionList = local_10;
  return;
}

