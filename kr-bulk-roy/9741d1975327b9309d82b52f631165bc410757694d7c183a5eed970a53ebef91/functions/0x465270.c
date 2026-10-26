
void FUN_00465270(void)

{
  int *piVar1;
  uint uVar2;
  int unaff_EDI;
  
  FUN_004663d0(*(undefined4 *)(*(int *)(unaff_EDI + 0x174) + 4));
  *(int *)(*(int *)(unaff_EDI + 0x174) + 4) = *(int *)(unaff_EDI + 0x174);
  *(undefined4 *)*(undefined4 *)(unaff_EDI + 0x174) = *(undefined4 *)(unaff_EDI + 0x174);
  *(int *)(*(int *)(unaff_EDI + 0x174) + 8) = *(int *)(unaff_EDI + 0x174);
  *(undefined4 *)(unaff_EDI + 0x178) = 0;
  uVar2 = 0;
  if (*(int *)(unaff_EDI + 0x164) - *(int *)(unaff_EDI + 0x160) >> 2 != 0) {
    do {
      piVar1 = *(int **)(*(int *)(unaff_EDI + 0x160) + uVar2 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x94))(0);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < (uint)(*(int *)(unaff_EDI + 0x164) - *(int *)(unaff_EDI + 0x160) >> 2));
    *(undefined4 *)(unaff_EDI + 0x180) = 0;
    return;
  }
  *(undefined4 *)(unaff_EDI + 0x180) = 0;
  return;
}

