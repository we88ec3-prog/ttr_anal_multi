
void FUN_008b82f0(void)

{
  int in_EAX;
  
  *(int *)(in_EAX + 0x3c) = *(int *)(in_EAX + 0x18) + *(short *)(in_EAX + 0x16) * 8;
  *(int *)(in_EAX + 0x40) = (int)*(short *)(in_EAX + 0x16) + *(int *)(in_EAX + 0x1c);
  *(int *)(in_EAX + 0x44) = *(int *)(in_EAX + 0x20) + *(short *)(in_EAX + 0x14) * 2;
  if (*(char *)(in_EAX + 0x10) != '\0') {
    *(int *)(in_EAX + 0x4c) = *(int *)(in_EAX + 0x28) + *(short *)(in_EAX + 0x16) * 8;
    *(int *)(in_EAX + 0x50) = *(int *)(in_EAX + 0x2c) + *(short *)(in_EAX + 0x16) * 8;
  }
  return;
}

