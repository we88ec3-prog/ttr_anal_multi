
void FUN_00714e60(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904888;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00714eb0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0089120c(*param_1);
  ExceptionList = local_10;
  return;
}

