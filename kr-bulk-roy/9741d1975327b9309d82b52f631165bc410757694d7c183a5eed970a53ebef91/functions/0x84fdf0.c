
void FUN_0084fdf0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
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
  if ((in_ECX < uVar2) && (uVar3 = *unaff_EDI, uVar3 <= in_ECX)) {
    if (uVar2 == unaff_EDI[2]) {
      FUN_008508f0(1);
    }
    uVar2 = unaff_EDI[1];
    iVar1 = *unaff_EDI + ((int)(in_ECX - uVar3) / 0x14) * 0x14;
    local_8 = 0;
    if (uVar2 != 0) {
      FUN_0052f3b0(uVar2,iVar1);
      *(undefined4 *)(uVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    }
  }
  else {
    if (uVar2 == unaff_EDI[2]) {
      FUN_008508f0(1);
    }
    uVar2 = unaff_EDI[1];
    local_8 = 1;
    if (uVar2 != 0) {
      FUN_0052f3b0(uVar2,in_ECX);
      *(undefined4 *)(uVar2 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x14;
  ExceptionList = local_10;
  return;
}

