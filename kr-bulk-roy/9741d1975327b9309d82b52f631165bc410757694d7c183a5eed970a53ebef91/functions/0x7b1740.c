
void FUN_007b1740(void)

{
  uint uVar1;
  uint in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905012;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = unaff_EDI[1];
  if ((in_ECX < uVar1) && (*unaff_EDI <= in_ECX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_007b1c00(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    local_8 = 0;
    if (unaff_EDI[1] != 0) {
      FUN_007edf30(unaff_EDI[1]);
      unaff_EDI[1] = unaff_EDI[1] + 0x38;
      ExceptionList = local_10;
      return;
    }
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_007b1c00(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    local_8 = 1;
    if (unaff_EDI[1] != 0) {
      FUN_007edf30(unaff_EDI[1]);
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x38;
  ExceptionList = local_10;
  return;
}

