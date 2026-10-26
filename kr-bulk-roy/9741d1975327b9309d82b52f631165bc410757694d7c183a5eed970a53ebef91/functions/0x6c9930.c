
void FUN_006c9930(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_006c0f40();
  FUN_0043c570(200);
  FUN_0043c570(300);
  FUN_0043c570(400);
  iVar1 = *(int *)(in_ECX + 0x15c);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x15c);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  return;
}

