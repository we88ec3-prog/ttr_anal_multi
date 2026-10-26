
void FUN_0040f120(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x20);
  FUN_0046b6f0(*(int *)(in_ECX + 0x20) + 0x834);
  FUN_0043c570(*(int *)(in_ECX + 0x80) + 0xc1c);
  FUN_0040f570(*(int *)(in_ECX + 0x80) + 0x44c);
  FUN_0040f570(*(int *)(in_ECX + 0x80) + 0x4b0);
  FUN_0040f570(*(int *)(in_ECX + 0x80) + 0x514);
  FUN_0040f570(*(int *)(in_ECX + 0x80) + 0x514);
  FUN_0043c570(*(int *)(in_ECX + 0x80) + 0x578);
  iVar1 = *(int *)(in_ECX + 0x88);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x88);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

