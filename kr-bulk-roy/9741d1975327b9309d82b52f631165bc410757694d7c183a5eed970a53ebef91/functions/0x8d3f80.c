
uint FUN_008d3f80(void)

{
  uint uVar1;
  int *in_ECX;
  uint in_EDX;
  int unaff_ESI;
  
  uVar1 = 0;
  if (in_EDX != 0) {
    do {
      if (*in_ECX == unaff_ESI) {
        return CONCAT31((int3)(uVar1 >> 8),1);
      }
      uVar1 = uVar1 + 1;
      in_ECX = in_ECX + 4;
    } while (uVar1 < in_EDX);
  }
  return uVar1 & 0xffffff00;
}

