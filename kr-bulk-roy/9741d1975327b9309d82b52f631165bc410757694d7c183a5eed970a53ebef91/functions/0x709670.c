
undefined4 FUN_00709670(void)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  
  FUN_006fec70();
  FUN_006fb850();
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  iVar1 = *(int *)(unaff_ESI + 8);
  piVar2 = (int *)(iVar1 + -0x10);
  if ((piVar2 != &DAT_00c0bfc8) && (*(int *)(iVar1 + -8) == 0)) {
    *(int **)(unaff_ESI + 8) = piVar2;
    return 0xffffffff;
  }
  if ((*(int *)(iVar1 + -8) != 0) && ((*(int *)(iVar1 + -8) != 1 || (*piVar2 != 0)))) {
    *(int **)(unaff_ESI + 8) = piVar2;
    return 1;
  }
  *(int **)(unaff_ESI + 8) = piVar2;
  return 0;
}

