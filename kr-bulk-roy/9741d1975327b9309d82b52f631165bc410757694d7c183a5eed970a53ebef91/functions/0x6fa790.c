
int FUN_006fa790(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  
  iVar1 = *(int *)(in_EAX + 0x24);
  *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) | 4;
  switch(*(undefined1 *)(iVar1 + 4)) {
  case 5:
    *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(iVar1 + 0x18);
    iVar2 = FUN_006fa1e0();
    if (iVar2 != 0) {
      *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfb;
    }
    return (*(int *)(iVar1 + 0x1c) + 2 + (1 << (*(byte *)(iVar1 + 7) & 0x1f)) * 2) * 0x10;
  case 6:
    break;
  default:
    return 0;
  case 8:
    *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(iVar1 + 0x6c);
    *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(in_EAX + 0x28);
    *(int *)(in_EAX + 0x28) = iVar1;
    *(byte *)(iVar1 + 5) = *(byte *)(iVar1 + 5) & 0xfb;
    FUN_006fa5e0();
    return *(int *)(iVar1 + 0x2c) * 0x10 + (*(int *)(iVar1 + 0x30) * 3 + 0xf) * 8;
  case 9:
    *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(iVar1 + 0x44);
    FUN_006fa390();
    return (*(int *)(iVar1 + 0x38) * 3 + *(int *)(iVar1 + 0x28) * 4 + *(int *)(iVar1 + 0x34) +
            *(int *)(iVar1 + 0x30) + *(int *)(iVar1 + 0x2c) + *(int *)(iVar1 + 0x24)) * 4 + 0x4c;
  }
  *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(iVar1 + 8);
  FUN_006fa460();
  if (*(char *)(iVar1 + 6) != '\0') {
    return (uint)*(byte *)(iVar1 + 7) * 0x10 + 0x18;
  }
  return (uint)*(byte *)(iVar1 + 7) * 4 + 0x14;
}

