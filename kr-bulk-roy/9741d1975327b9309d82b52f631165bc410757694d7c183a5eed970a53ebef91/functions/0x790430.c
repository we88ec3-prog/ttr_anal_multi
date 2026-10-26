
void FUN_00790430(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  while (param_1 < in_ECX) {
    iVar1 = (in_ECX + -1) / 2;
    iVar2 = iVar1 * 0x30;
    iVar3 = iVar2 + unaff_EDI;
    if (*(int *)(unaff_ESI + 0x10) <= *(int *)(iVar2 + 0x10 + unaff_EDI)) break;
    iVar2 = in_ECX * 0x30 + unaff_EDI;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar3 + 4);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar3 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar3 + 0x28);
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar3 + 0x2c);
    in_ECX = iVar1;
  }
  iVar1 = in_ECX * 0x30 + unaff_EDI;
  *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(unaff_ESI + 4);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(unaff_ESI + 8);
  *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(unaff_ESI + 0xc);
  *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(unaff_ESI + 0x10);
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(unaff_ESI + 0x14);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(unaff_ESI + 0x18);
  *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(unaff_ESI + 0x1c);
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(unaff_ESI + 0x20);
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(unaff_ESI + 0x24);
  *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(unaff_ESI + 0x28);
  *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(unaff_ESI + 0x2c);
  return;
}

