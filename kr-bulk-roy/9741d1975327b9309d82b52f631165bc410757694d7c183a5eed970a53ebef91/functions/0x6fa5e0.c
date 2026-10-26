
void FUN_006fa5e0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int unaff_ESI;
  int *piVar7;
  int iVar8;
  
  if ((3 < *(int *)(unaff_ESI + 0x50)) && ((*(byte *)(*(int *)(unaff_ESI + 0x48) + 5) & 3) != 0)) {
    FUN_006f9f70(param_1,*(int *)(unaff_ESI + 0x48));
  }
  uVar3 = *(uint *)(unaff_ESI + 0x28);
  piVar1 = *(int **)(unaff_ESI + 8);
  piVar6 = piVar1;
  if (uVar3 <= *(uint *)(unaff_ESI + 0x14)) {
    do {
      if (piVar6 < *(int **)(uVar3 + 8)) {
        piVar6 = *(int **)(uVar3 + 8);
      }
      uVar3 = uVar3 + 0x18;
    } while (uVar3 <= *(uint *)(unaff_ESI + 0x14));
  }
  piVar7 = *(int **)(unaff_ESI + 0x20);
  if (piVar7 < piVar1) {
    do {
      if ((3 < piVar7[2]) && ((*(byte *)(*piVar7 + 5) & 3) != 0)) {
        FUN_006f9f70(param_1,*piVar7);
      }
      piVar7 = piVar7 + 4;
    } while (piVar7 < *(int **)(unaff_ESI + 8));
  }
  for (; piVar7 <= piVar6; piVar7 = piVar7 + 4) {
    piVar7[2] = 0;
  }
  iVar5 = *(int *)(unaff_ESI + 0x20);
  iVar8 = *(int *)(unaff_ESI + 0x30);
  if (iVar8 < 0x4e21) {
    iVar2 = *(int *)(unaff_ESI + 0x28);
    if ((((*(int *)(unaff_ESI + 0x14) - iVar2) / 0x18) * 4 < iVar8) && (0x10 < iVar8)) {
      iVar8 = iVar8 / 2;
      if (iVar8 + 1U < 0xaaaaaab) {
        iVar4 = FUN_00700880();
      }
      else {
        iVar4 = FUN_00700860();
      }
      *(int *)(unaff_ESI + 0x28) = iVar4;
      *(int *)(unaff_ESI + 0x30) = iVar8;
      *(int *)(unaff_ESI + 0x14) = iVar4 + ((*(int *)(unaff_ESI + 0x14) - iVar2) / 0x18) * 0x18;
      *(int *)(unaff_ESI + 0x24) = iVar4 + -0x18 + iVar8 * 0x18;
    }
    iVar8 = *(int *)(unaff_ESI + 0x2c);
    if ((((int)piVar6 - iVar5 >> 4) * 4 < iVar8) && (0x5a < iVar8)) {
      iVar8 = iVar8 / 2;
      if (iVar8 + 7U < 0x10000000) {
        iVar5 = FUN_00700880();
      }
      else {
        iVar5 = FUN_00700860();
      }
      *(int *)(unaff_ESI + 0x20) = iVar5;
      *(int *)(unaff_ESI + 0x2c) = iVar8 + 6;
      *(int *)(unaff_ESI + 0x1c) = iVar8 * 0x10 + iVar5;
      FUN_006fdc30();
    }
  }
  return;
}

