
void FUN_005478f0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090834e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7a20 & 1) == 0) {
    DAT_00fb7a20 = DAT_00fb7a20 | 1;
    local_8 = 0;
    FUN_00548da0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd370);
  }
  FUN_00549530(&DAT_00fb7a28);
  ExceptionList = local_10;
  return;
}

