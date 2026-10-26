
void FUN_0078afd0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  FUN_007852a0();
  uVar1 = *(undefined4 *)(unaff_EDI + 0x50);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x54);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x58);
  uVar4 = *(undefined4 *)(unaff_EDI + 0x5c);
  FUN_00788f50(gbTCBRotKey::vftable);
  *(undefined4 *)(unaff_EDI + 0x50) = *(undefined4 *)(unaff_ESI + 0x50);
  *(undefined4 *)(unaff_EDI + 0x54) = *(undefined4 *)(unaff_ESI + 0x54);
  *(undefined4 *)(unaff_EDI + 0x58) = *(undefined4 *)(unaff_ESI + 0x58);
  *(undefined4 *)(unaff_EDI + 0x5c) = *(undefined4 *)(unaff_ESI + 0x5c);
  FUN_00788f50();
  *(undefined4 *)(unaff_ESI + 0x50) = uVar1;
  *(undefined4 *)(unaff_ESI + 0x54) = uVar2;
  *(undefined4 *)(unaff_ESI + 0x58) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x5c) = uVar4;
  return;
}

