
void FUN_008edb30(void)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int in_EDX;
  
  iVar1 = in_ECX[1];
  if (iVar1 - 1U < 2) {
    iVar2 = 0;
    if (*in_ECX != 0) {
      iVar2 = iVar1;
    }
    *(byte *)(in_EDX + 0x150) = ~(byte)iVar1 & *(byte *)(in_EDX + 0x150) | (byte)iVar2;
    return;
  }
  if (*(char *)(in_EDX + 0x231) != '\0') {
    *(undefined4 *)(in_EDX + 0xc) = 0x86;
  }
  return;
}

