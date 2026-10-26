
void FUN_006fdd90(void)

{
  int in_EAX;
  
  if (20000 < *(int *)(in_EAX + 0x30)) {
    FUN_006fdb40();
    *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 0x18;
    return;
  }
  FUN_006fdd10();
  if (20000 < *(int *)(in_EAX + 0x30)) {
    FUN_006f8b60();
  }
  *(int *)(in_EAX + 0x14) = *(int *)(in_EAX + 0x14) + 0x18;
  return;
}

