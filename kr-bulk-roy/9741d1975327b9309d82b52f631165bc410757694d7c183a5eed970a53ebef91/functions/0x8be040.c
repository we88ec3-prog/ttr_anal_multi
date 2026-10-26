
void FUN_008be040(void)

{
  uint uVar1;
  int *in_EDX;
  int iVar2;
  uint unaff_EDI;
  
  iVar2 = 0;
  if (((in_EDX != (int *)0x0) && (in_EDX[2] != 0)) && (unaff_EDI != 0)) {
    uVar1 = unaff_EDI;
    if ((uint)in_EDX[2] <= unaff_EDI) {
      in_EDX[2] = 0;
      return;
    }
    do {
      *(undefined4 *)(iVar2 + *in_EDX) = *(undefined4 *)(*in_EDX + uVar1 * 4);
      uVar1 = uVar1 + 1;
      iVar2 = iVar2 + 4;
    } while (uVar1 < (uint)in_EDX[2]);
    in_EDX[2] = in_EDX[2] - unaff_EDI;
  }
  return;
}

