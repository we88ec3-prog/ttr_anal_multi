
void FUN_0083ec20(void)

{
  uint uVar1;
  uint uVar2;
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
  if ((in_ECX < uVar1) && (uVar2 = *unaff_EDI, uVar2 <= in_ECX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_0083f130(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    in_ECX = *unaff_EDI + ((int)(in_ECX - uVar2) / 0x78) * 0x78;
    uVar1 = unaff_EDI[1];
    local_8 = 0;
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_0083f130(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar1 = unaff_EDI[1];
    local_8 = 1;
  }
  if (uVar1 != 0) {
    FUN_00839330(uVar1,in_ECX);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x78;
  ExceptionList = local_10;
  return;
}

