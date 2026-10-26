
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00643220(void)

{
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009169ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  _DAT_00f95bec = *(undefined4 *)(unaff_ESI + 0x138);
  DAT_00f95be9 = 1;
  *(undefined1 *)(unaff_ESI + 0x144) = 1;
  ExceptionList = local_10;
  return;
}

