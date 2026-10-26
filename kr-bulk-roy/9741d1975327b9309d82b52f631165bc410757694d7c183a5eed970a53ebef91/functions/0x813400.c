
void FUN_00813400(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009097aa;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_005540c0(*DAT_00fab014,DAT_00fab014);
  FUN_0089120c(DAT_00fab014,uVar1);
  local_8 = 2;
  FUN_005540c0(*DAT_00fab004,DAT_00fab004);
  FUN_0089120c(DAT_00fab004);
  ExceptionList = local_10;
  return;
}

