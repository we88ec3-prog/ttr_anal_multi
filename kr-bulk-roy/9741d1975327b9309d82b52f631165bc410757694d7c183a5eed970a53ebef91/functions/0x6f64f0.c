
undefined4 FUN_006f64f0(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int unaff_ESI;
  
  piVar2 = (int *)FUN_006f50f0();
  iVar3 = piVar2[2];
  if (iVar3 == 5) {
    iVar3 = *(int *)(*piVar2 + 8);
  }
  else if (iVar3 == 7) {
    iVar3 = *(int *)(*piVar2 + 8);
  }
  else {
    iVar3 = *(int *)(*(int *)(unaff_ESI + 0x10) + 0x98 + iVar3 * 4);
  }
  if (iVar3 != 0) {
    piVar2 = *(int **)(unaff_ESI + 8);
    *piVar2 = iVar3;
    piVar2[2] = 5;
    *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
    iVar3 = FUN_006f6470();
    if (iVar3 != 0) {
      puVar4 = (undefined4 *)FUN_006f50f0();
      puVar1 = *(undefined4 **)(unaff_ESI + 8);
      *puVar1 = *puVar4;
      puVar1[1] = puVar4[1];
      puVar1[2] = puVar4[2];
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
      FUN_006fe550();
      return 1;
    }
  }
  return 0;
}

