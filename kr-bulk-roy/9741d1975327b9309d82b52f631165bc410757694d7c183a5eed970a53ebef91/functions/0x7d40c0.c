
void FUN_007d40c0(void)

{
  int in_EAX;
  uint uVar1;
  
  uVar1 = 0;
  if (*(int *)(in_EAX + 0x7c) - *(int *)(in_EAX + 0x78) >> 3 != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x78) + 4 + uVar1 * 8) + 0x70) = 1;
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)(*(int *)(in_EAX + 0x7c) - *(int *)(in_EAX + 0x78) >> 3));
  }
  return;
}

