
void FUN_00840f10(void)

{
  uint uVar1;
  uint uVar2;
  uint in_ECX;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910642;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = unaff_EDI[1];
  if ((in_ECX < uVar2) && (uVar1 = *unaff_EDI, uVar1 <= in_ECX)) {
    if (uVar2 == unaff_EDI[2]) {
      FUN_008411d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_EDI[1];
    in_ECX = ((int)(in_ECX - uVar1) / 0x9c) * 0x9c + *unaff_EDI;
    local_8 = 0;
  }
  else {
    if (uVar2 == unaff_EDI[2]) {
      FUN_008411d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_EDI[1];
    local_8 = 1;
  }
  if (uVar2 != 0) {
    FUN_00859b40(uVar2,in_ECX);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x9c;
  ExceptionList = local_10;
  return;
}

