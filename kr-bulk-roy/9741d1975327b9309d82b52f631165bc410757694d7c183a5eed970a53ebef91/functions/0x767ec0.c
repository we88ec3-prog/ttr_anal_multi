
void FUN_00767ec0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0xf4) == 0) || (iVar2 = FUN_008fed10(), iVar2 == 0)) {
    *(undefined4 *)(unaff_ESI + 0x138) = 0;
    *(undefined4 *)(unaff_ESI + 0x134) = 0;
  }
  else {
    iVar2 = (*(int *)(unaff_ESI + 0xb0) - *(int *)(unaff_ESI + 0xa8)) / iVar2;
    iVar1 = *(int *)(unaff_ESI + 0x13c);
    *(int *)(unaff_ESI + 0x138) = iVar2;
    if (*(int *)(unaff_ESI + 0x134) + -1 + iVar2 < iVar1) {
      *(int *)(unaff_ESI + 0x134) = (iVar1 - iVar2) + 1;
      return;
    }
    if (iVar1 < *(int *)(unaff_ESI + 0x134)) {
      *(int *)(unaff_ESI + 0x134) = iVar1;
      return;
    }
  }
  return;
}

