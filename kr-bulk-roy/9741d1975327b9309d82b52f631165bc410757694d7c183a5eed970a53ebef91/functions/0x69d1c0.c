
/* WARNING: Removing unreachable block (ram,0x0069d256) */

void FUN_0069d1c0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0xf8));
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0xf8));
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x114);
  FUN_004095e0(0x115);
  ExceptionList = local_10;
  return;
}

