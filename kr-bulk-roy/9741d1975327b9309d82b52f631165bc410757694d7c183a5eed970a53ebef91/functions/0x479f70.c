
/* WARNING: Removing unreachable block (ram,0x00479fe5) */

void FUN_00479f70(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x10d);
  FUN_004095e0(0x10e);
  ExceptionList = local_10;
  return;
}

