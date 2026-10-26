
void FUN_005a6510(void)

{
  short *psVar1;
  short *psVar2;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  psVar1 = &DAT_00f938f2;
  do {
    psVar2 = psVar1;
    psVar1 = psVar2 + 1;
  } while (*psVar2 != 0);
  if ((int)(psVar2 + -0x7c9c79) >> 1 != 0) {
    *(undefined4 *)(in_ECX + 0x144) = 1;
  }
  ExceptionList = local_14;
  return;
}

