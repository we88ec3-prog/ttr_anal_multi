
void FUN_004c2fe0(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910952;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_004ffa40(*DAT_00fe1b48,DAT_00fe1b48);
  FUN_0089120c(DAT_00fe1b48,uVar1);
  local_8 = 2;
  FUN_00480040(*DAT_00fe1b38,DAT_00fe1b38);
  FUN_0089120c(DAT_00fe1b38);
  ExceptionList = local_10;
  return;
}

