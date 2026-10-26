
void FUN_008d5680(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_EDI + 100);
  iVar2 = *(int *)(unaff_EDI + 0x84);
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 0xa0) != 0) {
      FUN_008bab90(*(undefined4 *)(unaff_EDI + 0x68),iVar2 + 0xa0);
    }
    FUN_008b9f80(uVar1,*(undefined4 *)(iVar2 + 0xa8));
    *(undefined4 *)(iVar2 + 0xa8) = 0;
    FUN_008b9f80(uVar1,iVar2);
    *(undefined4 *)(unaff_EDI + 0x84) = 0;
  }
  return;
}

