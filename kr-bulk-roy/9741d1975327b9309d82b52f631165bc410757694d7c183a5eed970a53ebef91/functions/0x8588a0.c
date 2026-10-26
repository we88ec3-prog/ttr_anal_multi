
undefined4 * FUN_008588a0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int *unaff_FS_OFFSET;
  undefined4 local_10 [3];
  
  iVar1 = *unaff_FS_OFFSET;
  puVar4 = local_10;
  *unaff_FS_OFFSET = (int)puVar4;
  iVar5 = (int)param_3 - (int)param_1 >> 4;
  iVar10 = param_2 - (int)param_1 >> 4;
  iVar9 = iVar10;
  param_2 = iVar5;
  while (iVar3 = iVar9, iVar3 != 0) {
    puVar4 = (undefined4 *)(param_2 / iVar3);
    iVar9 = param_2 % iVar3;
    param_2 = iVar3;
  }
  if ((param_2 < iVar5) && (0 < param_2)) {
    puVar4 = param_1 + param_2 * 4;
    do {
      puVar7 = puVar4 + iVar10 * 4;
      puVar8 = puVar4;
      if (puVar4 + iVar10 * 4 == param_3) {
        puVar7 = param_1;
      }
      do {
        puVar6 = puVar7;
        if (puVar8 != puVar6) {
          uVar2 = *puVar8;
          *puVar8 = *puVar6;
          *puVar6 = uVar2;
          uVar2 = puVar8[1];
          puVar8[1] = puVar6[1];
          puVar6[1] = uVar2;
          uVar2 = puVar8[2];
          puVar8[2] = puVar6[2];
          puVar6[2] = uVar2;
        }
        iVar9 = (int)param_3 - (int)puVar6 >> 4;
        if (iVar10 < iVar9) {
          puVar7 = puVar6 + iVar10 * 4;
        }
        else {
          puVar7 = param_1 + (iVar10 - iVar9) * 4;
        }
        puVar8 = puVar6;
      } while (puVar7 != puVar4);
      param_2 = param_2 + -1;
      puVar4 = puVar4 + -4;
    } while (0 < param_2);
  }
  *unaff_FS_OFFSET = iVar1;
  return puVar4;
}

