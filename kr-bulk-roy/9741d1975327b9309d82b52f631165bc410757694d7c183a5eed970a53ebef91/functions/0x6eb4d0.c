
void FUN_006eb4d0(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(unaff_ESI + 0x14);
  iVar2 = *(int *)(unaff_ESI + 0x10);
  if (*(int *)(unaff_ESI + 0x10) == 0 && *(int *)(unaff_ESI + 0x14) == 0) {
    FUN_006eb3c0(&local_c);
    iVar1 = local_8;
    iVar2 = local_c;
  }
  *(int *)(unaff_ESI + 0x24) = iVar1;
  *(int *)(unaff_ESI + 0x1c) = iVar1;
  *(int *)(unaff_ESI + 0x20) = iVar2;
  *(int *)(unaff_ESI + 0x18) = iVar2;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  return;
}

