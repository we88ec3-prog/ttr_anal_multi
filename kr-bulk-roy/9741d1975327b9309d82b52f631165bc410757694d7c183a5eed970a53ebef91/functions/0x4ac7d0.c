
undefined4 FUN_004ac7d0(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009383c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004acb70(DAT_00fe1868,DAT_00d61f20 ^ (uint)&stack0xfffffffc,param_1,0,0);
  ExceptionList = local_10;
  return 1;
}

