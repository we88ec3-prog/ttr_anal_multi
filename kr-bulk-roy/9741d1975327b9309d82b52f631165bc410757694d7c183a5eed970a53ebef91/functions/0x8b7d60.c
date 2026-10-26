
uint FUN_008b7d60(void)

{
  uint in_EAX;
  uint uVar1;
  uint in_ECX;
  uint in_EDX;
  int iVar2;
  
  uVar1 = 0;
  if (in_EDX <= in_ECX) {
    return 0x7fffffff;
  }
  iVar2 = 0x20;
  do {
    in_ECX = in_ECX * 2 | in_EAX >> 0x1f;
    uVar1 = uVar1 * 2;
    if (in_EDX <= in_ECX) {
      in_ECX = in_ECX - in_EDX;
      uVar1 = uVar1 | 1;
    }
    in_EAX = in_EAX * 2;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return uVar1;
}

