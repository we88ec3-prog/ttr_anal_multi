
void FUN_0047fa90(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090dcd5;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00480040(*DAT_00fe1b38,DAT_00fe1b38);
  FUN_0089120c(DAT_00fe1b38,uVar1);
  ExceptionList = local_10;
  return;
}

