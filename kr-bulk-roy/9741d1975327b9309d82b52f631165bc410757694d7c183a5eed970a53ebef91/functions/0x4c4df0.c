
undefined4 FUN_004c4df0(void)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009479dc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_004adb10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if ((DAT_00fe18c8 & 1) == 0) {
    DAT_00fe18c8 = DAT_00fe18c8 | 1;
    local_8 = 0;
    FUN_0053f970();
    _atexit((_func_4879 *)&LAB_00bce810);
    local_8 = 0xffffffff;
  }
  FUN_0053ff50();
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_8 = 1;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
    local_8 = 0xffffffff;
  }
  FUN_004a8b90(&DAT_00fc0f84);
  ExceptionList = local_10;
  return uVar1;
}

