
undefined4 FUN_005000a0(void)

{
  int iVar1;
  int in_ECX;
  ushort *puVar2;
  uint in_EDX;
  
  iVar1 = 0;
  puVar2 = (ushort *)(in_ECX + 0x5ed0);
  do {
    if (*puVar2 == in_EDX) {
      return 1;
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x14);
  return 0;
}

