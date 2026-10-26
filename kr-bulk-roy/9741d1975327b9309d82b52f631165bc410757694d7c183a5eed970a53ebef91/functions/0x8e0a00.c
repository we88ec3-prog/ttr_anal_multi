
void FUN_008e0a00(void)

{
  int in_EAX;
  int in_EDX;
  
  *(int *)(*(int *)(in_EDX + 0x1c) + 0x2e8) = (int)(short)((uint)(in_EAX + 0x8000) >> 0x10);
  return;
}

