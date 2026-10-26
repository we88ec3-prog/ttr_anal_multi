
undefined * FUN_006ccd20(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922a31;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_006cefa0(DAT_00d61f20 ^ (uint)&stack0xfffffffc,&DAT_00fc1728);
  local_8 = 0;
  FUN_006ccc00(&DAT_00fc173c);
  local_8._0_1_ = 1;
  FUN_006ccc00(&DAT_00fc17bc);
  local_8 = CONCAT31(local_8._1_3_,2);
  DAT_00fc1778 = 1;
  FUN_006cd0e0();
  ExceptionList = local_10;
  return &DAT_00fc1728;
}

