
/* WARNING: Removing unreachable block (ram,0x0060c63f) */

void FUN_0060c5b0(void)

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
  FUN_004095e0(0xe7);
  FUN_004095e0(0xe8);
  FUN_004095e0(0xe9);
  FUN_004095e0(0xea);
  ExceptionList = local_10;
  return;
}

