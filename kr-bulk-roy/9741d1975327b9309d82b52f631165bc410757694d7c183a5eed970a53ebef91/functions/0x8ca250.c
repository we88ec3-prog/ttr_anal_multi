
void FUN_008ca250(void)

{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x30c) != '\0') {
    if (*(int *)(in_EAX + 0x2f8) != 0) {
      FUN_008bab90(*(undefined4 *)(in_EAX + 0x68),(int *)(in_EAX + 0x2f8));
    }
    *(undefined4 *)(in_EAX + 0x2fc) = 0;
    *(undefined4 *)(in_EAX + 0x300) = 0;
    *(undefined4 *)(in_EAX + 0x304) = 0;
  }
  return;
}

