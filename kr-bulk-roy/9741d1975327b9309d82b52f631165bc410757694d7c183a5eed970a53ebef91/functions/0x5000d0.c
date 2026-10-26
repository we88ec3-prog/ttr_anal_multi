
void FUN_005000d0(void)

{
  int iVar1;
  ushort *puVar2;
  int in_EDX;
  uint unaff_ESI;
  
  iVar1 = 0;
  puVar2 = (ushort *)(in_EDX + 0x5ed0);
  do {
    if (*puVar2 == unaff_ESI) {
      *(undefined2 *)(in_EDX + 0x5ed0 + iVar1 * 2) = 0;
      FUN_0040f060();
      FUN_0053dc90(unaff_ESI);
      return;
    }
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x14);
  return;
}

