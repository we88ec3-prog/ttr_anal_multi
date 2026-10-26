
void FUN_0079e540(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907a28;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_007a1320(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0089120c(*param_1);
  *param_1 = 0;
  ExceptionList = local_10;
  return;
}

