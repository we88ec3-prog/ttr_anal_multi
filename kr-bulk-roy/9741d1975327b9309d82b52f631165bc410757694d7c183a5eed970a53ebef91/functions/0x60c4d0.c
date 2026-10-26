
/* WARNING: Removing unreachable block (ram,0x0060c588) */

void FUN_0060c4d0(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091f810;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_0060c880(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(param_1);
  FUN_0060c960();
  FUN_005a9f40(param_1 + 1);
  FUN_0060ca40();
  FUN_005a9f40(param_1 + 2);
  FUN_0060cb20();
  FUN_005a9f40(param_1 + 3);
  FUN_0040b670(0);
  (**(code **)(*(int *)*param_1 + 0x94))(1);
  ExceptionList = local_10;
  return;
}

