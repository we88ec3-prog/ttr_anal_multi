
undefined4 FUN_00865970(void)

{
  undefined4 in_EAX;
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 1) {
    uVar1 = FUN_008658f0(in_EAX,*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),
                         *(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x18),
                         *(undefined4 *)(in_ECX + 0x1c));
    return uVar1;
  }
  if (*(int *)(in_ECX + 8) == 2) {
    if (*(int *)(in_ECX + 0x24) != 0) {
      uVar1 = FUN_008657c0(*(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c),
                           *(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x18),
                           *(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x20));
      return uVar1;
    }
    uVar1 = FUN_00865740(in_EAX,*(undefined4 *)(in_ECX + 0xc),*(undefined4 *)(in_ECX + 0x10),
                         *(undefined4 *)(in_ECX + 0x14),*(undefined4 *)(in_ECX + 0x18),
                         *(undefined4 *)(in_ECX + 0x1c));
    return uVar1;
  }
  return 0;
}

