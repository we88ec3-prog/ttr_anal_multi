
int FUN_00796da0(void)

{
  int in_EAX;
  int iVar1;
  int in_EDX;
  uint uVar2;
  int unaff_ESI;
  
  iVar1 = (unaff_ESI - in_EDX) + -1;
  if (iVar1 < 1) {
    return 1;
  }
  if (in_EDX <= in_EAX) {
    if (in_EAX <= unaff_ESI) {
      return 0;
    }
    uVar2 = in_EAX - unaff_ESI >> 0x1f;
    return (int)((in_EAX - unaff_ESI ^ uVar2) - uVar2) / iVar1 + 1;
  }
  uVar2 = in_EAX - in_EDX >> 0x1f;
  return (int)((in_EAX - in_EDX ^ uVar2) - uVar2) / iVar1 + 1;
}

