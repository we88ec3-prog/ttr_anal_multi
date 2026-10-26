
int FUN_004d4520(void)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  
  if (((in_EAX < 10) && (iVar1 = in_EAX * 0x210 + in_ECX, *(int *)(iVar1 + 0x5c) != 0)) &&
     (iVar1 != 0)) {
    return iVar1 + 500;
  }
  return 0;
}

