
void FUN_007900a0(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  while (param_1 < in_ECX) {
    iVar1 = (in_ECX + -1) / 2;
    iVar2 = iVar1 * 0x10;
    iVar3 = iVar2 + unaff_ESI;
    if (*(int *)(unaff_EDI + 8) <= *(int *)(iVar2 + 8 + unaff_ESI)) break;
    *(undefined4 *)(unaff_ESI + 4 + in_ECX * 0x10) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(unaff_ESI + 8 + in_ECX * 0x10) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(unaff_ESI + 0xc + in_ECX * 0x10) = *(undefined4 *)(iVar3 + 0xc);
    in_ECX = iVar1;
  }
  iVar1 = unaff_ESI + in_ECX * 0x10;
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(unaff_EDI + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(unaff_EDI + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(unaff_EDI + 0xc);
  return;
}

