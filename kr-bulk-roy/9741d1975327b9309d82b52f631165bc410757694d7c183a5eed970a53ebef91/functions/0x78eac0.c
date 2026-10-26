
void FUN_0078eac0(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int unaff_EDI;
  
  if (1 < (in_EAX - unaff_EDI) / 0x44) {
    puVar1 = (undefined4 *)(in_EAX + -0x34);
    do {
      FUN_00786620();
      puVar1[-3] = *(undefined4 *)(unaff_EDI + 4);
      puVar1[-2] = *(undefined4 *)(unaff_EDI + 8);
      puVar1[-1] = *(undefined4 *)(unaff_EDI + 0xc);
      *puVar1 = *(undefined4 *)(unaff_EDI + 0x10);
      puVar1[1] = *(undefined4 *)(unaff_EDI + 0x14);
      puVar1[2] = *(undefined4 *)(unaff_EDI + 0x18);
      puVar1[3] = *(undefined4 *)(unaff_EDI + 0x1c);
      puVar1[4] = *(undefined4 *)(unaff_EDI + 0x20);
      puVar1[5] = *(undefined4 *)(unaff_EDI + 0x24);
      puVar1[6] = *(undefined4 *)(unaff_EDI + 0x28);
      puVar1[7] = *(undefined4 *)(unaff_EDI + 0x2c);
      puVar1[8] = *(undefined4 *)(unaff_EDI + 0x30);
      puVar1[9] = *(undefined4 *)(unaff_EDI + 0x34);
      puVar1[10] = *(undefined4 *)(unaff_EDI + 0x38);
      puVar1[0xb] = *(undefined4 *)(unaff_EDI + 0x3c);
      puVar1[0xc] = *(undefined4 *)(unaff_EDI + 0x40);
      FUN_0078fca0();
      puVar1 = puVar1 + -0x11;
    } while (1 < ((0x34 - unaff_EDI) + (int)puVar1) / 0x44);
  }
  return;
}

