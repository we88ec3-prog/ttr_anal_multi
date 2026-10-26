
void FUN_004072a0(void)

{
  int *unaff_ESI;
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
  if (DAT_00f95bd4 != (int *)0x0) {
    (**(code **)(*DAT_00f95bd4 + 0x15c))();
  }
  if (unaff_ESI != (int *)0x0) {
    (**(code **)(*unaff_ESI + 0x10))(1);
  }
  ExceptionList = local_10;
  return;
}

