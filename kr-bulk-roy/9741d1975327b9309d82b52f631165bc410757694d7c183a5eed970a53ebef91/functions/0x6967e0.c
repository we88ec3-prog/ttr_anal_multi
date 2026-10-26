
/* WARNING: Removing unreachable block (ram,0x00696870) */

void FUN_006967e0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0x94));
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0x94));
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0x22);
  FUN_004095e0(0x23);
  ExceptionList = local_10;
  return;
}

