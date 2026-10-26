
/* WARNING: Removing unreachable block (ram,0x005a67a8) */

void FUN_005a6720(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005960b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0xf);
  FUN_004095e0(0x13);
  FUN_004095e0(0xe);
  FUN_004095e0(0xd);
  ExceptionList = local_10;
  return;
}

