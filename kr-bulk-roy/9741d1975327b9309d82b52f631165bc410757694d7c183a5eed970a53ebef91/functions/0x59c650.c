
void FUN_0059c650(void)

{
  int in_EAX;
  int in_ECX;
  
  if (*(int *)(in_EAX + 0x10) == 0xf4270) {
    FUN_006665b0(*(undefined4 *)(*(int *)(in_ECX + 0x1c8) + 0x108));
    FUN_006656e0();
  }
  else if (*(int *)(in_EAX + 0x10) == 0xf4274) {
    FUN_00666a60(*(undefined4 *)(*(int *)(in_ECX + 0x1c8) + 0x108));
    FUN_006656e0();
    return;
  }
  return;
}

