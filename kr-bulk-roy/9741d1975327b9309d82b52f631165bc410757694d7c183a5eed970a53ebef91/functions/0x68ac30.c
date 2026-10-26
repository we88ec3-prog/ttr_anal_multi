
void FUN_0068ac30(void)

{
  uint uVar1;
  int unaff_EDI;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e208;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00412df0(uVar1);
  local_8 = 0;
  if (*(char *)(unaff_EDI + 0x141) == '\0') {
    FUN_00757710();
  }
  else {
    FUN_006edb10("Not supported operation");
  }
  *(undefined4 *)(unaff_EDI + 0x168) = 0;
  *(undefined4 *)(unaff_EDI + 0x160) = 0;
  *(undefined4 *)(unaff_EDI + 0x164) = 0;
  *(undefined4 *)(unaff_EDI + 0x14c) = 0;
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

