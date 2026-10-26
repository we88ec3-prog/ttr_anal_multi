
undefined4 FUN_00846210(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x78) != 0) {
    return *(undefined4 *)(*(int *)(in_EAX + 0x78) + 0x68);
  }
  return 0;
}

