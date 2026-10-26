
void FUN_004a42a0(undefined1 param_1)

{
  undefined2 local_20;
  undefined4 local_1e;
  undefined1 local_1a;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edae;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_20 = 0x85;
  local_1a = 3;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&local_20);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  local_1e = DAT_00f93930;
  local_1a = param_1;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_20,7);
  }
  ExceptionList = local_14;
  return;
}

