
void FUN_0081ba60(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009142c2;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_0081cd10(*DAT_00fb733c,DAT_00fb733c);
  FUN_0089120c(DAT_00fb733c,uVar1);
  local_8 = 2;
  FUN_0081cc70(*DAT_00fb732c,DAT_00fb732c);
  FUN_0089120c(DAT_00fb732c);
  ExceptionList = local_10;
  return;
}

