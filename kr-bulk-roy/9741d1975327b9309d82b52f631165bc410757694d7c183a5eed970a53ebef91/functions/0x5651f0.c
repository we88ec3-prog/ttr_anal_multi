
void FUN_005651f0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009338ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc1b88 & 1) == 0) {
    DAT_00fc1b88 = DAT_00fc1b88 | 1;
    local_8 = 0;
    FUN_00581c10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdfa0);
  }
  local_8 = 0xffffffff;
  FUN_00582530(param_1);
  ExceptionList = local_10;
  return;
}

