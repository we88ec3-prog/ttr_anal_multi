
void FUN_006f0c90(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int unaff_ESI;
  
  puVar1 = *(undefined4 **)(unaff_ESI + 0x4c);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    FUN_006f0d00(iVar3);
    if (iVar3 != 0) {
      FUN_0089120c(iVar3);
    }
  }
  piVar4 = *(int **)(unaff_ESI + 0x4c);
  piVar5 = (int *)*piVar4;
  *piVar4 = (int)piVar4;
  *(int *)(*(int *)(unaff_ESI + 0x4c) + 4) = *(int *)(unaff_ESI + 0x4c);
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  if (piVar5 != *(int **)(unaff_ESI + 0x4c)) {
    do {
      piVar4 = (int *)*piVar5;
      FUN_0089120c(piVar5);
      piVar5 = piVar4;
    } while (piVar4 != (int *)*(int *)(unaff_ESI + 0x4c));
  }
  return;
}

