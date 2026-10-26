
void FUN_007d8bf0(void)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(in_EAX + 0x60) - *(int *)(in_EAX + 0x5c) >> 2 != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x5c) + uVar1 * 4) + 0x7c) = 0;
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(in_EAX + 0x60) - *(int *)(in_EAX + 0x5c) >> 2));
  }
  *(undefined4 *)(in_EAX + 0x6c) = 0;
  return;
}

