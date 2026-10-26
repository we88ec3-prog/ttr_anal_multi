
/* WARNING: Removing unreachable block (ram,0x006a37f2) */

void FUN_006a3720(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00922ca0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0xf4));
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0xf4));
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0xf4));
  FUN_0040aa10(*(undefined4 *)(in_ECX + 0xf4));
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_004095e0(0xc2);
  FUN_004095e0(0xc3);
  FUN_004095e0(0xc4);
  FUN_004095e0(0xc5);
  ExceptionList = local_10;
  return;
}

