
void FUN_004a9fe0(byte param_1)

{
  undefined1 auStack_20 [4];
  short local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_1c = (ushort)param_1 << 8;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)auStack_20);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  FUN_004dfbc0(local_1c);
  ExceptionList = local_14;
  return;
}

