
void FUN_0078d940(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int unaff_EDI;
  
  if (0x10 < (int)(in_EAX - unaff_EDI & 0xfffffff0U)) {
    puVar1 = (undefined4 *)(in_EAX + -8);
    do {
      puVar1[-1] = *(undefined4 *)(unaff_EDI + 4);
      *puVar1 = *(undefined4 *)(unaff_EDI + 8);
      puVar1[1] = *(undefined4 *)(unaff_EDI + 0xc);
      FUN_0078f4b0();
      puVar1 = puVar1 + -4;
    } while (0x10 < (int)((8 - unaff_EDI) + (int)puVar1 & 0xfffffff0U));
  }
  return;
}

