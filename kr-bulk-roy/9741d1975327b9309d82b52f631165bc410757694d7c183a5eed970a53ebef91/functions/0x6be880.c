
void FUN_006be880(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0046b6f0(1000);
  FUN_0046b6f0(0x44c);
  FUN_0043c570(0x514);
  FUN_0043c570(0x4b0);
  FUN_0043c570(0x578);
  FUN_0043c570(0x5dc);
  iVar1 = *(int *)(in_ECX + 0x160);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x160);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

