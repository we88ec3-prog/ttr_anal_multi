
undefined4 FUN_008ca9a0(void)

{
  uint *puVar1;
  int iVar2;
  int in_EAX;
  char unaff_BL;
  int unaff_ESI;
  
  if (*(int *)(in_EAX + 0x5c) == 0) {
    iVar2 = *(int *)(in_EAX + 0x28);
    *(int *)(in_EAX + 0x58) = iVar2;
    *(int *)(in_EAX + 0x5c) = iVar2;
    *(int *)(in_EAX + 0x28) = iVar2 + 0x20;
  }
  if (*(uint *)(in_EAX + 0x24) <= *(uint *)(in_EAX + 0x28)) {
    *(undefined4 *)(in_EAX + 0x2c) = 0x62;
    return 1;
  }
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0xc) = 0;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x14) = 0;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x10) = 0;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 8) = *(undefined4 *)(in_EAX + 0x28);
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 4) = 0;
  *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x1c) = 0;
  *(uint *)(*(int *)(in_EAX + 0x58) + 0xc) = (uint)*(byte *)(in_EAX + 0xb4);
  if (unaff_ESI == 1) {
    puVar1 = (uint *)(*(int *)(in_EAX + 0x58) + 0xc);
    *puVar1 = *puVar1 | 8;
    if (unaff_BL != '\0') {
      puVar1 = (uint *)(*(int *)(in_EAX + 0x58) + 0xc);
      *puVar1 = *puVar1 | 0x20;
    }
  }
  else {
    if (unaff_ESI != 2) {
      *(undefined4 *)(in_EAX + 0x2c) = 0x14;
      return 1;
    }
    if (unaff_BL != '\0') {
      puVar1 = (uint *)(*(int *)(in_EAX + 0x58) + 0xc);
      *puVar1 = *puVar1 | 0x10;
    }
  }
  if (*(int *)(in_EAX + 0x60) == 0) {
    *(undefined4 *)(in_EAX + 0x60) = *(undefined4 *)(in_EAX + 0x58);
  }
  *(int *)(in_EAX + 100) = unaff_ESI;
  *(undefined2 *)(in_EAX + 0x56) = 1;
  return 0;
}

