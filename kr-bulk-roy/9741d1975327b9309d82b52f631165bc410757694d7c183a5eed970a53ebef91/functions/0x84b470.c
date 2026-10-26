
void FUN_0084b470(void)

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
      FUN_0084b520(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    in_ECX = *unaff_EDI + ((int)(in_ECX - uVar2) / 0x14) * 0x14;
    uVar1 = unaff_EDI[1];
    local_8 = 0;
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_0084b520(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar1 = unaff_EDI[1];
    local_8 = 1;
  }
  if (uVar1 != 0) {
    FUN_0084a830(uVar1,in_ECX);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x14;
  ExceptionList = local_10;
  return;
}

