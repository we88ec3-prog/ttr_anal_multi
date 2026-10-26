
/* WARNING: Removing unreachable block (ram,0x00596121) */

void FUN_005960b0(void)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912470;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0xd4);
  FUN_00596c90(in_ECX);
  ExceptionList = local_10;
  return;
}

