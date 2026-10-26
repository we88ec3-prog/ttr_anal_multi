
void FUN_0066d8a0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    iVar2 = *(int *)(*(int *)(unaff_ESI + 4) + *(int *)(unaff_ESI + 0xc) * 4);
    if (*(int *)(iVar2 + 0x40) != 0) {
      FUN_0089120c(*(int *)(iVar2 + 0x40));
    }
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *(undefined4 *)(iVar2 + 0x44) = 0;
    *(undefined4 *)(iVar2 + 0x48) = 0;
    *(int *)(unaff_ESI + 0xc) = *(int *)(unaff_ESI + 0xc) + 1;
    if (*(uint *)(unaff_ESI + 8) <= *(uint *)(unaff_ESI + 0xc)) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
    piVar1 = (int *)(unaff_ESI + 0x10);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      *(undefined4 *)(unaff_ESI + 0xc) = 0;
    }
  }
  return;
}

