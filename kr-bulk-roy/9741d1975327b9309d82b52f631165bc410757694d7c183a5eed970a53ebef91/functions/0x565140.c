
void FUN_00565140(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00938cac;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  FUN_00589a20(0x3f800000,0x3f800000);
  if ((DAT_00fc1bf4 & 1) == 0) {
    DAT_00fc1bf4 = DAT_00fc1bf4 | 1;
    local_8 = 1;
    FUN_0057ef90();
    _atexit((_func_4879 *)&LAB_00bcdfb0);
    local_8 = 0xffffffff;
  }
  FUN_005826a0();
  ExceptionList = local_10;
  return;
}

