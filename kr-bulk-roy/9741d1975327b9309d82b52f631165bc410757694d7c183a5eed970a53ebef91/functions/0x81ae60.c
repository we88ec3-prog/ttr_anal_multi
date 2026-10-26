
int FUN_0081ae60(void)

{
  int iVar1;
  int in_EAX;
  uint in_ECX;
  
  if (in_ECX < (uint)(*(int *)(in_EAX + 0x18) - *(int *)(in_EAX + 0x14) >> 2)) {
    iVar1 = *(int *)(*(int *)(in_EAX + 0x14) + in_ECX * 4);
    return *(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2;
  }
  return 0;
}

