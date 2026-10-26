
undefined4 FUN_004c4f20(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092769e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    local_8 = 0;
    FUN_0047aeb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdb70);
  }
  local_8 = 0xffffffff;
  puVar1 = (undefined4 *)FUN_004c2880();
  *puVar1 = 1;
  ExceptionList = local_10;
  return 0;
}

