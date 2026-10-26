
undefined4 FUN_004b5e50(int param_1)

{
  uint *puVar1;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090db3e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb744c & 1) == 0) {
    DAT_00fb744c = DAT_00fb744c | 1;
    local_8 = 0;
    FUN_004eec60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit(FUN_00bcd140);
  }
  local_8 = 0xffffffff;
  local_14 = (int)ROUND(*(float *)(param_1 + 3) * 30.0) & 0xffff;
  puVar1 = (uint *)FUN_004eebe0();
  *puVar1 = local_14;
  ExceptionList = local_10;
  return 0;
}

