
undefined4 FUN_0077f090(void)

{
  int in_EAX;
  uint in_ECX;
  
  if (in_ECX < (uint)(*(int *)(in_EAX + 0xdc) - *(int *)(in_EAX + 0xd8) >> 2)) {
    return *(undefined4 *)(*(int *)(in_EAX + 0xd8) + in_ECX * 4);
  }
  return 0;
}

