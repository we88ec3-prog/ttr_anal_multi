
void FUN_008eefb0(void)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  uint unaff_EBX;
  int *unaff_ESI;
  uint unaff_EDI;
  
  iVar2 = *(int *)(unaff_ESI[1] + unaff_EDI * 8) - *(int *)(*unaff_ESI + unaff_EDI * 8);
  if (iVar2 != 0) {
    for (; in_EAX < unaff_EDI; in_EAX = in_EAX + 1) {
      piVar1 = (int *)(unaff_ESI[1] + in_EAX * 8);
      *piVar1 = *piVar1 + iVar2;
    }
    while (unaff_EDI = unaff_EDI + 1, unaff_EDI <= unaff_EBX) {
      piVar1 = (int *)(unaff_ESI[1] + unaff_EDI * 8);
      *piVar1 = *piVar1 + iVar2;
    }
  }
  return;
}

