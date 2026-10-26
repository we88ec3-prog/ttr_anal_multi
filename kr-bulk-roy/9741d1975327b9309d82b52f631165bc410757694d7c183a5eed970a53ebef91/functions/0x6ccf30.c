
void FUN_006ccf30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0090cba6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_006cf600(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8._0_1_ = 1;
  FUN_006cce00(&DAT_00fc17bc);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_006cce00(&DAT_00fc173c);
  local_8 = 3;
  FUN_006cf0c0(*DAT_00fc172c,DAT_00fc172c);
  FUN_0089120c(DAT_00fc172c);
  ExceptionList = local_10;
  return;
}

