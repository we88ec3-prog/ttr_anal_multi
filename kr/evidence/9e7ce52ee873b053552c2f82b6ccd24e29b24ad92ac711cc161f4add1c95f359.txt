
void FUN_004a9730(undefined4 param_1,undefined4 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b2ae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_8 = 0xffffffff;
  FUN_00561760(param_1,param_2);
  ExceptionList = local_10;
  return;
}

