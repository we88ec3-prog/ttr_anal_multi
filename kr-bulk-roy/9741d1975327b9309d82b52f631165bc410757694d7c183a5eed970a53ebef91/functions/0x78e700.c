
int FUN_0078e700(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  iVar2 = (in_EAX - unaff_EDI) / 0x30;
  if (1 < iVar2) {
    puVar3 = (undefined4 *)(in_EAX + -0x20);
    do {
      puVar3[-3] = *(undefined4 *)(unaff_EDI + 4);
      puVar3[-2] = *(undefined4 *)(unaff_EDI + 8);
      puVar3[-1] = *(undefined4 *)(unaff_EDI + 0xc);
      *puVar3 = *(undefined4 *)(unaff_EDI + 0x10);
      puVar3[1] = *(undefined4 *)(unaff_EDI + 0x14);
      puVar3[2] = *(undefined4 *)(unaff_EDI + 0x18);
      puVar3[3] = *(undefined4 *)(unaff_EDI + 0x1c);
      puVar3[4] = *(undefined4 *)(unaff_EDI + 0x20);
      puVar3[5] = *(undefined4 *)(unaff_EDI + 0x24);
      puVar3[6] = *(undefined4 *)(unaff_EDI + 0x28);
      puVar3[7] = *(undefined4 *)(unaff_EDI + 0x2c);
      FUN_0078fb20();
      puVar3 = puVar3 + -0xc;
      iVar1 = (0x20 - unaff_EDI) + (int)puVar3;
      iVar2 = iVar1 * 0x2aaaaaab;
    } while (1 < iVar1 / 0x30);
  }
  return iVar2;
}

