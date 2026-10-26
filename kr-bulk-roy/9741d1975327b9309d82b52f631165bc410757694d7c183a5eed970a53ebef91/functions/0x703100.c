
int FUN_00703100(int param_1)

{
  int iVar1;
  byte *pbVar2;
  byte bVar3;
  double *pdVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint local_8;
  
  uVar5 = local_8;
  iVar6 = FUN_006f6210(param_1);
  puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (((puVar7 < *(undefined4 **)(param_1 + 8)) && (puVar7 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x18))) {
    uVar8 = FUN_006f6370(param_1,2);
    if ((int)uVar8 < 0) {
      uVar8 = uVar8 + 1 + local_8;
    }
  }
  else {
    local_8 = 1;
    uVar8 = local_8;
  }
  local_8 = uVar8;
  puVar7 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x20);
  uVar8 = local_8;
  if (((puVar7 < *(undefined4 **)(param_1 + 8)) && (puVar7 != &DAT_00c0bfc8)) &&
     (0 < *(int *)(*(int *)(param_1 + 0xc) + 0x28))) {
    uVar8 = FUN_006f6370(param_1,3);
  }
  if ((int)uVar8 < 0) {
    uVar8 = uVar8 + 1 + uVar5;
  }
  if ((int)local_8 < 1) {
    local_8 = 1;
  }
  if (uVar5 < uVar8) {
    uVar8 = uVar5;
  }
  if ((int)local_8 <= (int)uVar8) {
    iVar10 = (uVar8 - local_8) + 1;
    if ((int)(iVar10 + local_8) <= (int)uVar8) {
      FUN_006f5f30(param_1,"string slice too long");
    }
    iVar9 = FUN_006f5170();
    if (iVar9 == 0) {
      FUN_006f5f30(param_1,"stack overflow (%s)","string slice too long");
    }
    iVar9 = 0;
    if (3 < iVar10) {
      iVar1 = local_8 + iVar6;
      do {
        pbVar2 = (byte *)(iVar1 + -1 + iVar9);
        pdVar4 = *(double **)(param_1 + 8);
        iVar9 = iVar9 + 4;
        *pdVar4 = (double)*pbVar2;
        *(undefined4 *)(pdVar4 + 1) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        pdVar4 = *(double **)(param_1 + 8);
        *pdVar4 = (double)*(byte *)(iVar1 + -4 + iVar9);
        *(undefined4 *)(pdVar4 + 1) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        pdVar4 = *(double **)(param_1 + 8);
        *pdVar4 = (double)*(byte *)(iVar1 + -3 + iVar9);
        *(undefined4 *)(pdVar4 + 1) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        pdVar4 = *(double **)(param_1 + 8);
        *pdVar4 = (double)*(byte *)(iVar1 + -2 + iVar9);
        *(undefined4 *)(pdVar4 + 1) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      } while (iVar9 < (int)((uVar8 - local_8) + -2));
    }
    if (iVar9 < iVar10) {
      do {
        bVar3 = *(byte *)((local_8 - 1) + iVar6 + iVar9);
        pdVar4 = *(double **)(param_1 + 8);
        *(undefined4 *)(pdVar4 + 1) = 3;
        iVar9 = iVar9 + 1;
        *pdVar4 = (double)bVar3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      } while (iVar9 < iVar10);
    }
    return iVar10;
  }
  return 0;
}

