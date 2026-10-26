
void FUN_008f5cf0(void)

{
  int in_EAX;
  int in_ECX;
  
  *(int *)(in_EAX + 8) = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) + *(int *)(in_EAX + 4);
  return;
}

