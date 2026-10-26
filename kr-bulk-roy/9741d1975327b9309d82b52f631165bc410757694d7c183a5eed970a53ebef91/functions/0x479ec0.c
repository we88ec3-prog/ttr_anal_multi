
/* WARNING: Removing unreachable block (ram,0x00479f55) */

void FUN_00479ec0(void)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009211e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_0047a1b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX);
  FUN_0047a290();
  FUN_005a9f40(in_ECX + 1);
  (**(code **)(*(int *)*in_ECX + 0x94))(1);
  FUN_0040b670(0);
  ExceptionList = local_10;
  return;
}

