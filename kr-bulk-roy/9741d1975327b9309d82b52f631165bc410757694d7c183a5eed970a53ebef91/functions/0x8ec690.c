
undefined4 FUN_008ec690(void)

{
  int iVar1;
  int in_EAX;
  int in_ECX;
  uint unaff_ESI;
  
  if (2 < in_ECX - 1U) {
    *(undefined4 *)(in_EAX + 0xc) = 0x84;
    return 1;
  }
  iVar1 = *(int *)(in_EAX + 0x1b4 + in_ECX * 8);
  if (iVar1 == 0) {
    *(undefined4 *)(in_EAX + 0xc) = 0x8a;
    return 1;
  }
  if (*(uint *)(in_EAX + 0x1b8 + in_ECX * 8) < unaff_ESI) {
    *(undefined4 *)(in_EAX + 0xc) = 0x83;
    return 1;
  }
  *(int *)(in_EAX + 0x164) = iVar1;
  *(undefined4 *)(in_EAX + 0x16c) = *(undefined4 *)(in_EAX + 0x1b8 + in_ECX * 8);
  *(uint *)(in_EAX + 0x168) = unaff_ESI;
  *(int *)(in_EAX + 0x160) = in_ECX;
  return 0;
}

