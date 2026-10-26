
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0082a320(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090bf72;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004803c0(DAT_00fc1718[1]);
  DAT_00fc1718[1] = DAT_00fc1718;
  *DAT_00fc1718 = DAT_00fc1718;
  DAT_00fc1718[2] = DAT_00fc1718;
  _DAT_00fc171c = 0;
  local_8 = 1;
  FUN_004ffa40(*DAT_00fc1718,DAT_00fc1718);
  FUN_0089120c(DAT_00fc1718,uVar1);
  ExceptionList = local_10;
  return;
}

