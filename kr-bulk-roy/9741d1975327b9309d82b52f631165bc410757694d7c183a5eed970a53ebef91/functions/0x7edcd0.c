
void FUN_007edcd0(void)

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
      FUN_007edd90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar1 = unaff_EDI[1];
    local_8 = 0;
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_007edd90(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar1 = unaff_EDI[1];
    local_8 = 1;
  }
  if (uVar1 != 0) {
    FUN_007edf30(uVar1);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x38;
  ExceptionList = local_10;
  return;
}

