
undefined4 FUN_0054a3a0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int local_c;
  undefined4 local_8;
  
  iVar2 = (**(code **)(**(int **)(unaff_ESI + 0x50) + 0x70))();
  iVar1 = *(int *)(unaff_ESI + 0x108);
  if (iVar2 <= (int)(uint)*(byte *)(unaff_ESI + (*(int *)(unaff_ESI + 0x10c) + 8) * 0x10)) {
    if (*(int *)(unaff_ESI + 4 + iVar1 * 4) != 0) {
      iVar1 = *(int *)(unaff_ESI + 4 + iVar1 * 4);
      local_8 = 4;
      FUN_008438c0(&local_8);
      if (local_c == *(int *)(iVar1 + 4)) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(local_c + 0x10);
      }
      FUN_00808030(uVar3);
    }
    *(undefined4 *)(unaff_ESI + 0xac + *(int *)(unaff_ESI + 0x108) * 0x10) = 6;
    return 0;
  }
  if (*(int *)(unaff_ESI + 0xac + iVar1 * 0x10) == 6) {
    *(undefined4 *)(unaff_ESI + 0xac + iVar1 * 0x10) = 1;
  }
  return 0;
}

