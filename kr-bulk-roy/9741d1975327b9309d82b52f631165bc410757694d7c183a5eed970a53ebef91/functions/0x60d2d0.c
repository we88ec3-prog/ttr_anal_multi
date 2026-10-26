
void FUN_0060d2d0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00610060();
  FUN_00610150();
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

