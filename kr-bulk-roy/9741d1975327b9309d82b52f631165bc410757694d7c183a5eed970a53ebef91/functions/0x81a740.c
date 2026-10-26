
void FUN_0081a740(void)

{
  uint *puVar1;
  uint *in_EAX;
  uint *puVar2;
  uint *unaff_EDI;
  
  if (in_EAX != unaff_EDI) {
    puVar2 = in_EAX + 6;
    do {
      if (0xf < *puVar2) {
        FUN_0089120c(puVar2[-5]);
      }
      *puVar2 = 0xf;
      puVar2[-1] = 0;
      *(undefined1 *)(puVar2 + -5) = 0;
      puVar1 = puVar2 + 4;
      puVar2 = puVar2 + 10;
    } while (puVar1 != unaff_EDI);
  }
  return;
}

