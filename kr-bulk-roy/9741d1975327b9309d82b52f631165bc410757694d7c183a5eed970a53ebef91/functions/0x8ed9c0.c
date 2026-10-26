
void FUN_008ed9c0(void)

{
  int iVar1;
  int in_EDX;
  int *unaff_EBX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*unaff_EBX == 0) {
    puVar2 = (undefined4 *)(in_EDX + 0xb4);
  }
  else {
    if (*unaff_EBX != 1) {
      if (*(char *)(in_EDX + 0x231) == '\0') {
        return;
      }
      *(undefined4 *)(in_EDX + 0xc) = 0x86;
      return;
    }
    puVar2 = (undefined4 *)(in_EDX + 0x90);
  }
  puVar3 = (undefined4 *)(in_EDX + 0x24);
  for (iVar1 = 9; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(short *)(in_EDX + 0x158) = (short)*unaff_EBX;
  return;
}

