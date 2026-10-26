
uint FUN_00781340(void)

{
  byte *pbVar1;
  byte *pbVar2;
  int in_ECX;
  
  pbVar1 = (byte *)**(int **)(in_ECX + 0x20);
  if (pbVar1 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (pbVar1 < pbVar1 + **(int **)(in_ECX + 0x30)) {
    return (uint)*pbVar1;
  }
  pbVar2 = (byte *)**(undefined4 **)(in_ECX + 0x24);
  if ((pbVar2 != (byte *)0x0) && ((pbVar1 < pbVar2 || (pbVar1 < *(byte **)(in_ECX + 0x44))))) {
    if (*(byte **)(in_ECX + 0x44) < pbVar2) {
      *(byte **)(in_ECX + 0x44) = pbVar2;
    }
    **(int **)(in_ECX + 0x30) = *(int *)(in_ECX + 0x44) - **(int **)(in_ECX + 0x20);
    return (uint)*(byte *)**(undefined4 **)(in_ECX + 0x20);
  }
  return 0xffffffff;
}

