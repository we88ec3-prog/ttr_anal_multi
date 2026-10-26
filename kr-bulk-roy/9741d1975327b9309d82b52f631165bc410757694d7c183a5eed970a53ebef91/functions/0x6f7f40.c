
void FUN_006f7f40(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int unaff_EDI;
  
  if ((param_1 == 0) || (*(char *)(param_1 + 6) != '\0')) {
    *(undefined4 *)(*(int *)(unaff_EDI + 8) + 8) = 0;
  }
  else {
    uVar2 = FUN_006f99a0();
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x14);
    iVar4 = 0;
    if (0 < *(int *)(*(int *)(param_1 + 0x10) + 0x30)) {
      do {
        puVar3 = (undefined4 *)FUN_006f9b70(*(undefined4 *)(iVar1 + iVar4 * 4));
        if (puVar3 == &DAT_00c0bfc8) {
          puVar3 = (undefined4 *)FUN_006f9a60();
        }
        *puVar3 = 1;
        puVar3[2] = 1;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(*(int *)(param_1 + 0x10) + 0x30));
    }
    puVar3 = *(undefined4 **)(unaff_EDI + 8);
    *puVar3 = uVar2;
    puVar3[2] = 5;
  }
  if (*(int *)(unaff_EDI + 0x1c) - *(int *)(unaff_EDI + 8) < 0x11) {
    if (0 < *(int *)(unaff_EDI + 0x2c)) {
      FUN_006fdcb0();
      *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 0x10;
      return;
    }
    FUN_006fdcb0();
  }
  *(int *)(unaff_EDI + 8) = *(int *)(unaff_EDI + 8) + 0x10;
  return;
}

