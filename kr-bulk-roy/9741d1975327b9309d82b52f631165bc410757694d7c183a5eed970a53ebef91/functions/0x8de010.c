
undefined4 FUN_008de010(void)

{
  uint in_EAX;
  int in_ECX;
  
  if (in_EAX < *(uint *)(in_ECX + 0x520)) {
    return *(undefined4 *)(*(int *)(in_ECX + 0x524) + in_EAX * 4);
  }
  return 0;
}

