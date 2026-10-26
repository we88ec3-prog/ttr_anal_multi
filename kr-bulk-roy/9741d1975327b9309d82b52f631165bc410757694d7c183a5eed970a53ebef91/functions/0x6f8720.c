
undefined * FUN_006f8720(void)

{
  uint in_EAX;
  int in_ECX;
  
  if ((in_EAX & 0x100) != 0) {
    if (*(int *)(*(int *)(in_ECX + 8) + 8 + (in_EAX & 0xfffffeff) * 0x10) == 4) {
      return (undefined *)(*(int *)(*(int *)(in_ECX + 8) + (in_EAX & 0xfffffeff) * 0x10) + 0x10);
    }
  }
  return &DAT_00c42700;
}

