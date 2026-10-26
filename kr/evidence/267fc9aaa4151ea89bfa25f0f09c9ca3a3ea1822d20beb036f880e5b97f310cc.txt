
/* WARNING: Removing unreachable block (ram,0x005c32b5) */

void FUN_005c3210(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00599590(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x54);
  FUN_004095e0(0x57);
  FUN_004095e0(0x10);
  FUN_004095e0(0x11d);
  FUN_004095e0(0xd3);
  FUN_004095e0(0x11b);
  ExceptionList = local_10;
  return;
}

