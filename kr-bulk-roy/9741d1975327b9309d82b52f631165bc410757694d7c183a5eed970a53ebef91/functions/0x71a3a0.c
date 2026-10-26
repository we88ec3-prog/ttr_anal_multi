
uint FUN_0071a3a0(void)

{
  char *in_EAX;
  uint uVar1;
  int in_EDX;
  uint unaff_ESI;
  int iVar2;
  
  uVar1 = 0;
  if (unaff_ESI != 0) {
    iVar2 = in_EDX - (int)in_EAX;
    do {
      if (in_EAX[iVar2] != *in_EAX) {
        return (uint)in_EAX & 0xffffff00;
      }
      uVar1 = uVar1 + 1;
      in_EAX = in_EAX + 1;
    } while (uVar1 < unaff_ESI);
  }
  return (uint)(*(char *)(in_EDX + unaff_ESI) == '\0');
}

