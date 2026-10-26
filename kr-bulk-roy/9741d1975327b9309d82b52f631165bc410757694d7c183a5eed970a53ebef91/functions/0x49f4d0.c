
void FUN_0049f4d0(void)

{
  uint in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910642;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((in_ECX < DAT_00fb72f0) && (DAT_00fb72ec <= in_ECX)) {
    if (DAT_00fb72f0 == DAT_00fb72f4) {
      FUN_0049f590(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    local_8 = 0;
  }
  else {
    if (DAT_00fb72f0 == DAT_00fb72f4) {
      FUN_0049f590(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    local_8 = 1;
  }
  if (DAT_00fb72f0 != 0) {
    FUN_0049f6e0(DAT_00fb72f0);
  }
  DAT_00fb72f0 = DAT_00fb72f0 + 0x40;
  ExceptionList = local_10;
  return;
}

