
void FUN_00850030(void)

{
  uint uVar1;
  uint in_ECX;
  uint uVar2;
  uint *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905012;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = unaff_EDI[1];
  if ((in_ECX < uVar2) && (uVar1 = *unaff_EDI, uVar1 <= in_ECX)) {
    if (uVar2 == unaff_EDI[2]) {
      FUN_00850970(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_EDI[1];
    in_ECX = (in_ECX - uVar1 & 0xfffffff0) + *unaff_EDI;
    local_8 = 0;
  }
  else {
    if (uVar2 == unaff_EDI[2]) {
      FUN_00850970(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_EDI[1];
    local_8 = 1;
  }
  if (uVar2 != 0) {
    FUN_0062d9b0(in_ECX);
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x10;
  ExceptionList = local_10;
  return;
}

