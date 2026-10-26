
void FUN_00745c20(void)

{
  int in_EAX;
  
  if ((*(byte *)(in_EAX + 0x28) & 0x10) == 0) {
    while (in_EAX = *(int *)(in_EAX + 0x60), in_EAX != 0) {
      if ((*(byte *)(in_EAX + 0x28) & 0x10) != 0) {
        return;
      }
    }
  }
  return;
}

