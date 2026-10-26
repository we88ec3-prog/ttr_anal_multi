
undefined4 FUN_004c4d60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00933ece;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_8 = 0;
    FUN_0047aeb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdb70);
  }
  local_8 = 0xffffffff;
  FUN_004ad0a0(DAT_00fc0f84,0,"t_removeAllCoroutines");
  FUN_004a9db0();
  ExceptionList = local_10;
  return 0;
}

