
void FUN_008cdbe0(void)

{
  short in_AX;
  uint uVar1;
  short sVar2;
  int unaff_ESI;
  uint unaff_EDI;
  
  uVar1 = 0;
  if (unaff_EDI != 0) {
    do {
      sVar2 = *(short *)(unaff_ESI + 2 + uVar1 * 2) - *(short *)(unaff_ESI + uVar1 * 2);
      if (in_AX < sVar2) {
        in_AX = sVar2;
      }
      uVar1 = uVar1 + 2;
    } while (uVar1 < unaff_EDI);
  }
  return;
}

