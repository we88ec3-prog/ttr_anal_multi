
void FUN_007e40a0(void)

{
  uint *puVar1;
  uint *in_EAX;
  uint *puVar2;
  uint *unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    puVar2 = in_EAX + 0xf;
    do {
      if (0xf < *puVar2) {
        FUN_0089120c(puVar2[-5]);
      }
      *puVar2 = 0xf;
      puVar2[-1] = 0;
      *(undefined1 *)(puVar2 + -5) = 0;
      puVar1 = puVar2 + 2;
      puVar2 = puVar2 + 0x11;
    } while (puVar1 != unaff_EDI);
  }
  return;
}

