
void FUN_008b8700(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = FUN_008b7f10((int)*(short *)(unaff_EDI + 0x46),*(undefined4 *)(unaff_ESI + 8));
  *(uint *)(unaff_ESI + 0xc) = iVar1 + 0x3fU & 0xffffffc0;
  uVar2 = FUN_008b7f10((int)*(short *)(unaff_EDI + 0x48),*(undefined4 *)(unaff_ESI + 8));
  *(uint *)(unaff_ESI + 0x10) = uVar2 & 0xffffffc0;
  iVar1 = FUN_008b7f10((int)*(short *)(unaff_EDI + 0x4a),*(undefined4 *)(unaff_ESI + 8));
  *(uint *)(unaff_ESI + 0x14) = iVar1 + 0x20U & 0xffffffc0;
  iVar1 = FUN_008b7f10((int)*(short *)(unaff_EDI + 0x4c),*(undefined4 *)(unaff_ESI + 4));
  *(uint *)(unaff_ESI + 0x18) = iVar1 + 0x20U & 0xffffffc0;
  return;
}

