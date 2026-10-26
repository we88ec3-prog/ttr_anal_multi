
void FUN_0084b1d0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint in_ECX;
  uint uVar4;
  int iVar5;
  int unaff_EDI;
  undefined4 local_8;
  
  *(undefined4 *)(unaff_EDI + 0xa8) = 0;
  uVar1 = (*(int *)(unaff_EDI + 0x78) - *(int *)(unaff_EDI + 0x74)) / 0x14;
  uVar4 = 0;
  local_8 = in_ECX;
  if (3 < (int)uVar1) {
    iVar2 = 0;
    iVar5 = (uVar1 - 4 >> 2) + 1;
    uVar4 = iVar5 * 4;
    do {
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 8 + iVar2) = 0;
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 0x10 + iVar2) = 0;
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 0x1c + iVar2) = 0;
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 0x24 + iVar2) = 0;
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 0x30 + iVar2) = 0;
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 0x38 + iVar2) = 0;
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 0x44 + iVar2) = 0;
      *(undefined4 *)(*(int *)(unaff_EDI + 0x74) + 0x4c + iVar2) = 0;
      iVar2 = iVar2 + 0x50;
      iVar5 = iVar5 + -1;
      local_8 = uVar4;
    } while (iVar5 != 0);
  }
  if (uVar4 < uVar1) {
    iVar2 = uVar4 * 0x14;
    iVar5 = uVar1 - uVar4;
    do {
      *(undefined4 *)(iVar2 + 8 + *(int *)(unaff_EDI + 0x74)) = 0;
      *(undefined4 *)(iVar2 + 0x10 + *(int *)(unaff_EDI + 0x74)) = 0;
      iVar2 = iVar2 + 0x14;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (*(int *)(unaff_EDI + 0x84) != *(int *)(unaff_EDI + 0x88)) {
    uVar3 = FUN_0084b990(local_8);
    *(undefined4 *)(unaff_EDI + 0x88) = uVar3;
  }
  *(undefined4 *)(unaff_EDI + 0xa0) = 0;
  return;
}

