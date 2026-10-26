
undefined4 FUN_008caa50(char param_1)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = *(int *)(in_EAX + 0x28) - *(int *)(*(int *)(in_EAX + 0x58) + 8) >> 2;
  if (iVar1 < 0) {
    *(undefined4 *)(in_EAX + 0x2c) = 99;
    return 1;
  }
  if (0 < iVar1) {
    *(int *)(*(int *)(in_EAX + 0x58) + 0x10) = iVar1;
    if (param_1 != '\0') {
      iVar1 = *(int *)(in_EAX + 0x58);
      if ((*(byte *)(iVar1 + 0xc) & 8) == 0) {
        *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x20;
      }
      else {
        *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) | 0x10;
      }
    }
    iVar1 = *(int *)(in_EAX + 0x58);
    *(int *)(in_EAX + 0x58) = *(int *)(in_EAX + 0x28);
    *(int *)(in_EAX + 0x28) = *(int *)(in_EAX + 0x28) + 0x20;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 0x10) = 0;
    *(undefined4 *)(*(int *)(in_EAX + 0x58) + 8) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(in_EAX + 0x58);
    *(short *)(in_EAX + 0x54) = *(short *)(in_EAX + 0x54) + 1;
  }
  if (*(uint *)(in_EAX + 0x24) <= *(uint *)(in_EAX + 0x28)) {
    *(undefined4 *)(in_EAX + 0x2c) = 0x62;
    return 1;
  }
  *(undefined1 *)(in_EAX + 0x57) = 0;
  return 0;
}

