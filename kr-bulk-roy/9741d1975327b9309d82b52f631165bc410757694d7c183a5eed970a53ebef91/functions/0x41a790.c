
/* WARNING: Removing unreachable block (ram,0x0041a804) */

void FUN_0041a790(void)

{
  int in_ECX;
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
  FUN_004095e0(0x5b);
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  *(undefined4 *)(in_ECX + 0xf8) = 0;
  ExceptionList = local_10;
  return;
}

