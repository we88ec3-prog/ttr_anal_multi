
undefined4 FUN_006f56e0(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  piVar1 = (int *)FUN_006f50f0();
  iVar2 = piVar1[2];
  if (iVar2 == 5) {
    iVar2 = *(int *)(*piVar1 + 8);
  }
  else if (iVar2 == 7) {
    iVar2 = *(int *)(*piVar1 + 8);
  }
  else {
    iVar2 = *(int *)(*(int *)(unaff_ESI + 0x10) + 0x98 + iVar2 * 4);
  }
  if (iVar2 == 0) {
    return 0;
  }
  piVar1 = *(int **)(unaff_ESI + 8);
  *piVar1 = iVar2;
  piVar1[2] = 5;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return 1;
}

