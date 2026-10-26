
void FUN_006241f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090abce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8 = 0xffffffff;
  FUN_006ee240(&DAT_00fb9050);
  ExceptionList = local_10;
  return;
}

