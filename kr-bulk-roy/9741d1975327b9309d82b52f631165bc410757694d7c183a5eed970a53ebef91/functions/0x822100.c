
void FUN_00822100(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009096fd;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00535ac0(*DAT_00fb9384,DAT_00fb9384);
  FUN_0089120c(DAT_00fb9384,uVar1);
  local_8 = 2;
  FUN_005540c0(*DAT_00fb9374,DAT_00fb9374);
  FUN_0089120c(DAT_00fb9374);
  ExceptionList = local_10;
  return;
}

