
void FUN_008eae10(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  uint in_EDX;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((unaff_ESI != 0) && (uVar1 = 0, in_EDX != 0)) {
    do {
      piVar2 = (int *)(in_ECX + uVar1 * 8);
      *piVar2 = *piVar2 + unaff_ESI;
      uVar1 = uVar1 + 1;
    } while (uVar1 < in_EDX);
  }
  if ((unaff_EDI != 0) && (in_EDX != 0)) {
    piVar2 = (int *)(in_ECX + 4);
    do {
      *piVar2 = *piVar2 + unaff_EDI;
      piVar2 = piVar2 + 2;
      in_EDX = in_EDX - 1;
    } while (in_EDX != 0);
  }
  return;
}

