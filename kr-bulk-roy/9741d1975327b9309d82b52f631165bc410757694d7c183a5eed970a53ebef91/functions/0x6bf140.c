
void FUN_006bf140(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  FUN_0043c570(11000);
  FUN_0046b6f0(0x3ee4);
  iVar2 = 0x3728;
  do {
    FUN_0043c570(iVar2 + -10);
    FUN_0043c570(iVar2);
    iVar2 = iVar2 + 100;
  } while (iVar2 < 0x39e4);
  FUN_0043c570(17000);
  FUN_0046b6f0(20000);
  FUN_006bf900();
  FUN_006bf9f0();
  iVar2 = *(int *)(in_ECX + 0xc4);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *(int *)(in_ECX + 0xc4);
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar1 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar1 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
    }
  }
  iVar2 = *(int *)(in_ECX + 200);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar2 + 0xa4) = 1;
  iVar2 = *(int *)(in_ECX + 200);
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar1 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar1 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar2 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

