
void FUN_00431620(void)

{
  _Locinfo *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906854;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 4;
  std::_Locinfo::_Locinfo_dtor(in_ECX);
  if (*(void **)(in_ECX + 0x1c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x1c));
  }
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  if (*(void **)(in_ECX + 0x14) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x14));
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (*(void **)(in_ECX + 0xc) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xc));
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (*(void **)(in_ECX + 4) != (void *)0x0) {
    _free(*(void **)(in_ECX + 4));
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  local_8 = 0xffffffff;
  FUN_0087dd6f();
  ExceptionList = local_10;
  return;
}

