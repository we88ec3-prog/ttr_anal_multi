
void FUN_0040b040(void)

{
  int *piVar1;
  uint in_EAX;
  uint uVar2;
  int iVar3;
  uint in_ECX;
  int *piVar4;
  int *unaff_ESI;
  
  if ((uint)unaff_ESI[4] < in_ECX) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid string position");
  }
  uVar2 = unaff_ESI[4] - in_ECX;
  if (uVar2 < in_EAX) {
    in_EAX = uVar2;
  }
  if (in_EAX != 0) {
    piVar4 = unaff_ESI;
    piVar1 = unaff_ESI;
    if (0xf < (uint)unaff_ESI[5]) {
      piVar4 = (int *)*unaff_ESI;
      piVar1 = (int *)*unaff_ESI;
    }
    FID_conflict__memcpy
              ((void *)((int)piVar4 + in_ECX),(void *)((int)piVar1 + in_EAX + in_ECX),uVar2 - in_EAX
              );
    iVar3 = unaff_ESI[4] - in_EAX;
    unaff_ESI[4] = iVar3;
    if (0xf < (uint)unaff_ESI[5]) {
      *(undefined1 *)(*unaff_ESI + iVar3) = 0;
      return;
    }
    *(undefined1 *)((int)unaff_ESI + iVar3) = 0;
  }
  return;
}

