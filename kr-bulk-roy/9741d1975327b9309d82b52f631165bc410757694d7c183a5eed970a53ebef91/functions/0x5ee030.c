
void FUN_005ee030(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_005e1770();
  FUN_0046b6f0(*(int *)(in_ECX + 0x15c) + 1000);
  FUN_0046b6f0(*(int *)(in_ECX + 0x15c) + 0x3e9);
  FUN_0043c570(*(int *)(in_ECX + 0x15c) + 0x44c);
  FUN_0043c570(*(int *)(in_ECX + 0x15c) + 0x4b0);
  FUN_0043c570(*(int *)(in_ECX + 0x15c) + 0x514);
  iVar1 = *(int *)(in_ECX + 0x1b4);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x1b4);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

