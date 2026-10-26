
void FUN_00761fe0(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x14c) = *(undefined4 *)(in_EAX + 0x118);
  FUN_007619a0();
  *(undefined4 *)(in_EAX + 0x160) = 0;
  if (*(char *)(in_EAX + 0x150) != '\0') {
    *(undefined4 *)(in_EAX + 0x164) = *(undefined4 *)(in_EAX + 0x14c);
    FUN_00761800();
    return;
  }
  *(undefined4 *)(in_EAX + 0x164) = 0;
  FUN_00761800();
  return;
}

