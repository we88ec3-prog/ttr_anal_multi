
void FUN_00457020(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int local_8;
  
  FUN_0046b6f0(51000);
  FUN_0043c570(52000);
  FUN_0043c570(53000);
  FUN_0043c570(54000);
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
  local_8 = 0xd73c;
  piVar3 = (int *)(in_ECX + 600);
  do {
    FUN_0046b6f0(local_8);
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
    local_8 = local_8 + 100;
    piVar3 = piVar3 + 1;
  } while (local_8 < 0xd868);
  return;
}

