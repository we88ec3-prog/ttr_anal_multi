
void FUN_006ccda0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a9b5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_006cf0c0(*DAT_00fc172c,DAT_00fc172c);
  FUN_0089120c(DAT_00fc172c,uVar1);
  ExceptionList = local_10;
  return;
}

