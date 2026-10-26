
int FUN_004fd5c0(void)

{
  int iVar1;
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910642;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((in_ECX < DAT_00fe1ab0) && (DAT_00fe1aac <= in_ECX)) {
    iVar1 = (in_ECX - DAT_00fe1aac) * 0x2e8ba2e9;
    if (DAT_00fe1ab0 == DAT_00fe1ab4) {
      iVar1 = FUN_004fd690(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    local_8 = 0;
  }
  else {
    if (DAT_00fe1ab0 == DAT_00fe1ab4) {
      FUN_004fd690(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    local_8 = 1;
    iVar1 = 0;
  }
  if (DAT_00fe1ab0 != 0) {
    iVar1 = FUN_004fd8b0(DAT_00fe1ab0);
  }
  DAT_00fe1ab0 = DAT_00fe1ab0 + 0x58;
  ExceptionList = local_10;
  return iVar1;
}

