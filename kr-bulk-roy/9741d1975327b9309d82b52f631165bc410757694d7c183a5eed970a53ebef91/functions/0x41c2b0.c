
void FUN_0041c2b0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int *piVar3;
  int local_8;
  
  FUN_0043c570(0x44d);
  FUN_0046b6f0(0x44f);
  FUN_0043c570(0x44c);
  iVar1 = *(int *)(unaff_ESI + 0x170);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(unaff_ESI + 0x170);
  if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
    iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
    if (iVar2 == 0xbf6b) {
      *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
    }
  }
  FUN_0043c570(0x4b0);
  local_8 = 0;
  piVar3 = (int *)(unaff_ESI + 0x164);
  do {
    FUN_0046b6f0(local_8 + 0x4b1);
    iVar1 = *piVar3;
    FUN_007444b0(0xbf6b);
    *(undefined1 *)(iVar1 + 0xa4) = 1;
    iVar1 = *piVar3;
    if ((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) {
      iVar2 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))();
      if (iVar2 == 0xbf6b) {
        *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
      }
    }
    local_8 = local_8 + 1;
    piVar3 = piVar3 + 1;
  } while (local_8 < 3);
  return;
}

