
void FUN_0071bb90(void)

{
  int iVar1;
  int *in_EAX;
  int *in_ECX;
  
  if ((uint *)*in_ECX == (uint *)0x0) {
    *in_EAX = 0;
    return;
  }
  iVar1 = *(int *)(*(uint *)*in_ECX & 0xffffffe0);
  if (iVar1 != 0) {
    *in_EAX = iVar1 + -0x20;
    return;
  }
  *in_EAX = 0;
  return;
}

