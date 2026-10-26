
void FUN_008edab0(void)

{
  int in_EAX;
  int iVar1;
  int *unaff_EBX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if (*unaff_EBX == 0) {
    puVar2 = (undefined4 *)(in_EAX + 0xb4);
  }
  else {
    if (*unaff_EBX != 1) {
      if (*(char *)(in_EAX + 0x231) == '\0') {
        return;
      }
      *(undefined4 *)(in_EAX + 0xc) = 0x86;
      return;
    }
    puVar2 = (undefined4 *)(in_EAX + 0x90);
  }
  puVar3 = (undefined4 *)(in_EAX + 0x24);
  puVar4 = puVar3;
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2 = puVar3;
  puVar4 = (undefined4 *)(in_EAX + 0x48);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar2 = (undefined4 *)(in_EAX + 0x6c);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
  }
  *(short *)(in_EAX + 0x158) = (short)*unaff_EBX;
  *(short *)(in_EAX + 0x15a) = (short)*unaff_EBX;
  *(short *)(in_EAX + 0x15c) = (short)*unaff_EBX;
  return;
}

