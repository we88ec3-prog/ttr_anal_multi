
undefined4 FUN_0070c4c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  
  puVar2 = *(undefined4 **)(unaff_ESI + 8);
  puVar5 = (undefined4 *)(*(int *)(unaff_ESI + 0xc) + 0x10);
  if (puVar5 < puVar2) {
    if ((puVar5 != &DAT_00c0bfc8) && (*(int *)(*(int *)(unaff_ESI + 0xc) + 0x18) == 0)) {
      puVar2 = (undefined4 *)FUN_006f50f0();
      puVar5 = (undefined4 *)FUN_006f50f0();
      if ((puVar2 != &DAT_00c0bfc8) && (puVar5 != &DAT_00c0bfc8)) {
        uVar3 = FUN_006fbe20(puVar2);
        return uVar3;
      }
      return 0;
    }
    if (puVar5 < puVar2) goto LAB_0070c4f1;
  }
  puVar5 = &DAT_00c0bfc8;
LAB_0070c4f1:
  *puVar2 = *puVar5;
  puVar2[1] = puVar5[1];
  puVar2[2] = puVar5[2];
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  puVar5 = (undefined4 *)FUN_006f50f0();
  puVar2 = *(undefined4 **)(unaff_ESI + 8);
  *puVar2 = *puVar5;
  puVar2[1] = puVar5[1];
  puVar2[2] = puVar5[2];
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  puVar5 = (undefined4 *)FUN_006f50f0();
  puVar2 = *(undefined4 **)(unaff_ESI + 8);
  *puVar2 = *puVar5;
  puVar2[1] = puVar5[1];
  puVar2[2] = puVar5[2];
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  FUN_006fe550();
  iVar1 = *(int *)(*(int *)(unaff_ESI + 8) + -8);
  piVar4 = (int *)(*(int *)(unaff_ESI + 8) + -0x10);
  if ((iVar1 != 0) && ((iVar1 != 1 || (*piVar4 != 0)))) {
    *(int **)(unaff_ESI + 8) = piVar4;
    return 1;
  }
  *(int **)(unaff_ESI + 8) = piVar4;
  return 0;
}

