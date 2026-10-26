
void FUN_007902f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  
  while (param_1 < in_ECX) {
    iVar3 = (in_ECX + -1) / 2;
    iVar1 = unaff_ESI + iVar3 * 0x18;
    if (*(int *)(unaff_EDI + 0x10) <= *(int *)(unaff_ESI + 0x10 + iVar3 * 0x18)) break;
    iVar2 = unaff_ESI + in_ECX * 0x18;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    in_ECX = iVar3;
  }
  iVar1 = unaff_ESI + in_ECX * 0x18;
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(unaff_EDI + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(unaff_EDI + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(unaff_EDI + 0xc);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(unaff_EDI + 0x10);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(unaff_EDI + 0x14);
  return;
}

