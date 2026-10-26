
/* WARNING: Removing unreachable block (ram,0x005b2aec) */

void FUN_005b2a30(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005c2a60(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x53);
  FUN_004095e0(0x14);
  FUN_004095e0(0x15);
  FUN_004095e0(0x113);
  FUN_004095e0(0x116);
  FUN_004095e0(0x100);
  FUN_004095e0(0x101);
  FUN_004095e0(0x36);
  ExceptionList = local_10;
  return;
}

