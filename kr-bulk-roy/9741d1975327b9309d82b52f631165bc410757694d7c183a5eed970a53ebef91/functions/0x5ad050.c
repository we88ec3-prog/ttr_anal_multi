
/* WARNING: Removing unreachable block (ram,0x005ad103) */

void FUN_005ad050(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_005ac500(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0xd9);
  FUN_004095e0(0x2f);
  FUN_004095e0(0x31);
  FUN_004095e0(0x2b);
  FUN_004095e0(0x2a);
  FUN_004095e0(0x16);
  FUN_004095e0(0x33);
  FUN_004095e0(0x35);
  ExceptionList = local_10;
  return;
}

