
void FUN_0085dcd0(void)

{
  uint uVar1;
  uint uVar2;
  uint in_ECX;
  uint *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905012;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar2 = unaff_ESI[1];
  if ((in_ECX < uVar2) && (uVar1 = *unaff_ESI, uVar1 <= in_ECX)) {
    if (uVar2 == unaff_ESI[2]) {
      FUN_0085e090(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_ESI[1];
    in_ECX = (in_ECX - uVar1 & 0xfffffff0) + *unaff_ESI;
    local_8 = 0;
  }
  else {
    if (uVar2 == unaff_ESI[2]) {
      FUN_0085e090(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    uVar2 = unaff_ESI[1];
    local_8 = 1;
  }
  if (uVar2 != 0) {
    FUN_00867d70(uVar2,in_ECX);
  }
  unaff_ESI[1] = unaff_ESI[1] + 0x10;
  ExceptionList = local_10;
  return;
}

