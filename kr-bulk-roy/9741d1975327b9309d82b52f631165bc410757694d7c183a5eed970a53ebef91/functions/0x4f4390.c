
void FUN_004f4390(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910735;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004f7f40(*DAT_00fb7474,DAT_00fb7474);
  FUN_0089120c(DAT_00fb7474,uVar1);
  ExceptionList = local_10;
  return;
}

