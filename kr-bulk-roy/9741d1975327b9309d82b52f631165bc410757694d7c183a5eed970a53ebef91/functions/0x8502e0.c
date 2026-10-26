
void FUN_008502e0(void)

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
      FUN_00850a70(1);
    }
    uVar2 = unaff_EDI[1];
    iVar1 = *unaff_EDI + ((int)(in_ECX - uVar3) / 0x18) * 0x18;
    local_8 = 0;
    if (uVar2 != 0) {
      FUN_0062d9b0(iVar1);
      *(undefined4 *)(uVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
      *(undefined4 *)(uVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    }
  }
  else {
    if (uVar2 == unaff_EDI[2]) {
      FUN_00850a70(1);
    }
    uVar2 = unaff_EDI[1];
    local_8 = 1;
    if (uVar2 != 0) {
      FUN_0062d9b0(in_ECX);
      *(undefined4 *)(uVar2 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
      *(undefined4 *)(uVar2 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x18;
  ExceptionList = local_10;
  return;
}

