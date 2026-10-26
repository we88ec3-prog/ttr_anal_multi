
/* WARNING: Removing unreachable block (ram,0x00439db5) */

void FUN_00439cf0(void)

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
  FUN_004095e0(0x131);
  FUN_004095e0(0x133);
  FUN_004095e0(0x132);
  ExceptionList = local_10;
  return;
}

