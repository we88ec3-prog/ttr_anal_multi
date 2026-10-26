
void FUN_0045def0(void)

{
  uint uVar1;
  undefined4 in_ECX;
  int unaff_EDI;
  int local_18;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b49e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(unaff_EDI + 0x164) = in_ECX;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  FUN_008438c0(local_14);
  if ((local_18 != DAT_00f8d91c) && (*(int *)(local_18 + 0x10) != 0)) {
    FUN_00757710();
  }
  ExceptionList = local_10;
  return;
}

