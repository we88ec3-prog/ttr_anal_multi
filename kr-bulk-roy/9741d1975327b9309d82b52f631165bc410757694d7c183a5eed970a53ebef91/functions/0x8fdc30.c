
void FUN_008fdc30(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int unaff_EDI;
  
  if (*(int *)(unaff_EDI + 0x14) != 0) {
    uVar3 = 0;
    iVar1 = FUN_00572120();
    if (iVar1 != 0) {
      do {
        FUN_0089120c(*(undefined4 *)(*(int *)(unaff_EDI + 0x14) + uVar3 * 4));
        uVar3 = uVar3 + 1;
        uVar2 = FUN_00572120();
      } while (uVar3 < uVar2);
    }
    FUN_00891d3d(*(undefined4 *)(unaff_EDI + 0x14));
    *(undefined4 *)(unaff_EDI + 0x14) = 0;
    FUN_008fd9a0();
    return;
  }
  return;
}

