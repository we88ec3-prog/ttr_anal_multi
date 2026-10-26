
/* WARNING: Removing unreachable block (ram,0x005d4cdb) */

void FUN_005d4c60(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916688;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 2;
  FUN_004095e0(0x4c);
  FUN_004095e0(0x4e);
  ExceptionList = local_10;
  return;
}

