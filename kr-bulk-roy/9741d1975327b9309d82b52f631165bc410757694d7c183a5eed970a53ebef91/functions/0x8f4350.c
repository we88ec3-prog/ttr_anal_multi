
void FUN_008f4350(void)

{
  int in_EAX;
  int in_ECX;
  
  *(int *)(in_ECX + 0x6c) = in_EAX;
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(in_EAX + 0x1c);
  return;
}

