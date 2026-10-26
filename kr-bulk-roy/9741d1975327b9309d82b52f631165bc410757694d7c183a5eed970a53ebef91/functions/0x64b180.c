
void FUN_0064b180(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0046b6f0(0x51e);
  FUN_0046b6f0(0x532);
  FUN_0043c570(0x528);
  FUN_0046b6f0(0x546);
  FUN_0043c570(0x53c);
  iVar1 = *(int *)(in_ECX + 0x248);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x248);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

