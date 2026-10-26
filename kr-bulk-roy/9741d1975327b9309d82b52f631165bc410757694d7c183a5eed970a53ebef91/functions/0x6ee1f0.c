
uint FUN_006ee1f0(void)

{
  uint in_EAX;
  int iVar1;
  int iVar2;
  ushort *in_EDX;
  int *unaff_ESI;
  
  if (in_EDX != (ushort *)0x0) {
    iVar2 = unaff_ESI[2];
    in_EAX = iVar2 + 1;
    if (in_EAX < 0x34) {
      iVar1 = 0;
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *in_EDX = ((short)iVar1 + 1) * 0xde ^ *(ushort *)(*unaff_ESI + iVar1 * 2);
        iVar1 = iVar1 + 1;
        in_EDX = in_EDX + 1;
      }
      *in_EDX = 0;
      return CONCAT31((int3)((uint)iVar1 >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}

