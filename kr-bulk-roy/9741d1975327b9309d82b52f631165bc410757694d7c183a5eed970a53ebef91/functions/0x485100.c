
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00485100(void)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00910bff;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00485810(DAT_00fc0de0[1]);
  DAT_00fc0de0[1] = DAT_00fc0de0;
  *DAT_00fc0de0 = DAT_00fc0de0;
  DAT_00fc0de0[2] = DAT_00fc0de0;
  DAT_00fc0de4 = 0;
  FUN_00485810(DAT_00fc0df0[1]);
  DAT_00fc0df0[1] = DAT_00fc0df0;
  *DAT_00fc0df0 = DAT_00fc0df0;
  DAT_00fc0df0[2] = DAT_00fc0df0;
  _DAT_00fc0df4 = 0;
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00485a40(*DAT_00fc0df0,DAT_00fc0df0);
  FUN_0089120c(DAT_00fc0df0,uVar1);
  local_8 = 3;
  FUN_00485970(*DAT_00fc0de0,DAT_00fc0de0);
  FUN_0089120c(DAT_00fc0de0);
  ExceptionList = local_10;
  return;
}

