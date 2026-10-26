
void FUN_008b8340(void)

{
  int in_EAX;
  
  *(int *)(in_EAX + 0x58) = *(int *)(in_EAX + 0x30) * 0x20 + *(int *)(in_EAX + 0x34);
  return;
}

