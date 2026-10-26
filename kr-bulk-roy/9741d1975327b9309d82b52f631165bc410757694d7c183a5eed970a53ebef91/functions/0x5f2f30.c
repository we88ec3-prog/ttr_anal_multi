
void FUN_005f2f30(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_8;
  
  FUN_005e1770();
  local_8 = in_ECX + 0x1c8;
  iVar3 = 0;
  do {
    FUN_0046b6f0(*(int *)(in_ECX + 0x15c) + 1000 + iVar3);
    FUN_0046b6f0(*(int *)(in_ECX + 0x15c) + 0x3e9 + iVar3);
    FUN_0046b6f0(*(int *)(in_ECX + 0x15c) + 0x3ea + iVar3);
    FUN_0043c570(*(int *)(in_ECX + 0x15c) + 0x44c + iVar3);
    FUN_0043c570(*(int *)(in_ECX + 0x15c) + 0x4b0 + iVar3);
    iVar1 = *(int *)(local_8 + -0xc);
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar1 + 0xa4) = 1;
    iVar1 = *(int *)(local_8 + -0xc);
    if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
      iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
      if (iVar2 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
      }
    }
    local_8 = local_8 + 4;
    iVar3 = iVar3 + 1000;
  } while (iVar3 < 3000);
  return;
}

