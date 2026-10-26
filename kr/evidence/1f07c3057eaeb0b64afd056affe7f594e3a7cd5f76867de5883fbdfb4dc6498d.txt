
void FUN_0058a800(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009161fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_8 = 0xffffffff;
  FUN_007526b0();
  ExceptionList = local_10;
  return;
}

