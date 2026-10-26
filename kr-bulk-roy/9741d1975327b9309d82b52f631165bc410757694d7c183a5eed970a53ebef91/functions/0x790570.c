
void FUN_00790570(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int unaff_ESI;
  int unaff_EDI;
  
  while (param_1 < in_ECX) {
    iVar3 = (in_ECX + -1) / 2;
    iVar1 = unaff_EDI + iVar3 * 0x44;
    if (*(int *)(unaff_ESI + 0x10) <= *(int *)(unaff_EDI + 0x10 + iVar3 * 0x44)) break;
    iVar2 = unaff_EDI + in_ECX * 0x44;
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 4);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar1 + 8);
    *(undefined4 *)(iVar2 + 0xc) = *(undefined4 *)(iVar1 + 0xc);
    *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)(iVar1 + 0x10);
    *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x18);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x24);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar1 + 0x28);
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar1 + 0x2c);
    *(undefined4 *)(iVar2 + 0x30) = *(undefined4 *)(iVar1 + 0x30);
    *(undefined4 *)(iVar2 + 0x34) = *(undefined4 *)(iVar1 + 0x34);
    *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(iVar1 + 0x38);
    *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(iVar1 + 0x3c);
    *(undefined4 *)(iVar2 + 0x40) = *(undefined4 *)(iVar1 + 0x40);
    in_ECX = iVar3;
  }
  iVar1 = unaff_EDI + in_ECX * 0x44;
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
  *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(unaff_ESI + 0x30);
  *(undefined4 *)(iVar1 + 0x34) = *(undefined4 *)(unaff_ESI + 0x34);
  *(undefined4 *)(iVar1 + 0x38) = *(undefined4 *)(unaff_ESI + 0x38);
  *(undefined4 *)(iVar1 + 0x3c) = *(undefined4 *)(unaff_ESI + 0x3c);
  *(undefined4 *)(iVar1 + 0x40) = *(undefined4 *)(unaff_ESI + 0x40);
  return;
}

