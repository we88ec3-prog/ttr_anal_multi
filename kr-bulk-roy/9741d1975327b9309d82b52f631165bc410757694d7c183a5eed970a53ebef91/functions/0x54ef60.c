
undefined4 FUN_0054ef60(undefined4 param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009383c8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  (*DAT_00fe1e38)(DAT_00d61f20 ^ (uint)&stack0xfffffffc,param_1,0,0);
  ExceptionList = local_10;
  return 1;
}

