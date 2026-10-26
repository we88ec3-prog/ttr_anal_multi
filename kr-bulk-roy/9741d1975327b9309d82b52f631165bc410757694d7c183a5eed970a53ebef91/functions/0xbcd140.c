
void FUN_00bcd140(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a08285;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004eed70(*DAT_00fb7454,DAT_00fb7454);
  FUN_0089120c(DAT_00fb7454,uVar1);
  ExceptionList = local_10;
  return;
}

