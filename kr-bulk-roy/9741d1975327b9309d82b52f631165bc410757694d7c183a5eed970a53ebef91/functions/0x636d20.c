
void FUN_00636d20(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x94);
  iVar2 = *(int *)(unaff_ESI + 0x98) + 1;
  if (iVar2 < *(int *)(iVar1 + 0x18) - *(int *)(iVar1 + 0x14) >> 2) {
    *(int *)(unaff_ESI + 0x98) = iVar2;
    FUN_00635f10(*(undefined4 *)(*(int *)(iVar1 + 0x14) + iVar2 * 4));
  }
  FUN_00636050(unaff_ESI);
  return;
}

