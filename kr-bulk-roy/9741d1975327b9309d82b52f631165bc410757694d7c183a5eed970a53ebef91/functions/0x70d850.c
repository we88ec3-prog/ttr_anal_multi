
void FUN_0070d850(void)

{
  int in_EAX;
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != in_EAX) {
    FUN_0070d750();
  }
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  if (*(int *)(in_ECX + 0x20) != 0x11f) {
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
    *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
    *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x20) = 0x11f;
    return;
  }
  uVar1 = FUN_006ffec0(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  return;
}

