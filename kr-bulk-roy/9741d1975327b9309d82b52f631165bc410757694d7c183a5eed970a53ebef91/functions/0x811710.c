
void FUN_00811710(void)

{
  int iVar1;
  int unaff_ESI;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = 0;
  if ((*(int *)(unaff_ESI + 0x108) - *(int *)(unaff_ESI + 0x104)) / 0x3c < 1) {
    *(undefined4 *)(unaff_ESI + 0x118) = 0;
    return;
  }
  do {
    *(undefined1 *)(iVar1 + 0x38 + *(int *)(unaff_ESI + 0x104)) = 1;
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x3c;
  } while (iVar2 < (*(int *)(unaff_ESI + 0x108) - *(int *)(unaff_ESI + 0x104)) / 0x3c);
  *(undefined4 *)(unaff_ESI + 0x118) = 0;
  return;
}

