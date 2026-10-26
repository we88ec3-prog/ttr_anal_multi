
undefined4 FUN_008c5d00(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  undefined1 *puVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  uint local_18;
  uint local_10;
  uint local_c;
  
  if (*(uint *)(param_2 + 4) < param_1 + 10U) {
    FUN_008b8460(param_2,8);
  }
  puVar12 = (undefined1 *)(param_1 + 6);
  uVar10 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3)),
                             *(undefined1 *)(param_1 + 4)),*(undefined1 *)(param_1 + 5));
  puVar11 = (undefined1 *)(param_1 + 8);
  puVar8 = (undefined1 *)(param_1 + 7);
  puVar7 = (undefined1 *)(param_1 + 9);
  iVar14 = CONCAT31(CONCAT21(CONCAT11(*puVar12,*puVar8),*puVar11),*puVar7);
  if (((uint)(*(int *)(param_2 + 4) - param_1) < uVar10) || (uVar10 < iVar14 * 0xb + 10U)) {
    FUN_008b8460(param_2,8);
  }
  local_10 = 1;
  for (; iVar14 != 0; iVar14 = iVar14 + -1) {
    uVar18 = (uint)CONCAT21(CONCAT11(puVar8[3],puVar11[3]),puVar7[3]);
    uVar15 = CONCAT31(CONCAT21(CONCAT11(puVar12[7],puVar8[7]),puVar11[7]),puVar7[7]);
    puVar12 = puVar12 + 0xb;
    puVar8 = puVar8 + 0xb;
    puVar11 = puVar11 + 0xb;
    puVar7 = puVar7 + 0xb;
    uVar13 = CONCAT31(CONCAT21(CONCAT11(*puVar12,*puVar8),*puVar11),*puVar7);
    if ((uVar10 <= uVar15) || (uVar10 <= uVar13)) {
      FUN_008b8460(param_2,8);
    }
    if (uVar18 < local_10) {
      FUN_008b8460(param_2,8);
    }
    local_10 = uVar18 + 1;
    if (uVar15 != 0) {
      puVar16 = (undefined1 *)(uVar15 + 4 + param_1);
      iVar19 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar15 + param_1),
                                          *(undefined1 *)(uVar15 + 1 + param_1)),
                                 *(undefined1 *)(uVar15 + 2 + param_1)),puVar16[-1]);
      local_c = 0;
      if (*(undefined1 **)(param_2 + 4) < puVar16 + iVar19 * 4) {
        FUN_008b8460(param_2,8);
      }
      for (; iVar19 != 0; iVar19 = iVar19 + -1) {
        uVar18 = (uint)CONCAT21(CONCAT11(*puVar16,puVar16[1]),puVar16[2]);
        uVar15 = (byte)puVar16[3] + uVar18;
        puVar16 = puVar16 + 4;
        if (0x10ffff < uVar15) {
          FUN_008b8460(param_2,8);
        }
        if (uVar18 < local_c) {
          FUN_008b8460(param_2,8);
        }
        local_c = uVar15 + 1;
      }
    }
    if (uVar13 != 0) {
      iVar4 = uVar13 + 4 + param_1;
      puVar16 = (undefined1 *)(iVar4 + -3);
      iVar19 = iVar4 + -2;
      puVar9 = (undefined1 *)(iVar4 + -1);
      iVar17 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(uVar13 + param_1),*puVar16),
                                 *(undefined1 *)(iVar4 + -2)),*(undefined1 *)(iVar4 + -1));
      uVar13 = *(int *)(param_2 + 4) - iVar4;
      local_18 = 0;
      if (uVar13 <= (uint)(iVar17 * 4) && iVar17 * 4 - uVar13 != 0) {
        FUN_008b8460(param_2,8);
      }
      for (; iVar17 != 0; iVar17 = iVar17 + -1) {
        puVar1 = puVar16 + 3;
        puVar2 = (undefined1 *)(iVar19 + 3);
        puVar16 = puVar16 + 5;
        puVar3 = puVar9 + 3;
        uVar5 = *(undefined1 *)(iVar19 + 5);
        iVar19 = iVar19 + 5;
        puVar9 = puVar9 + 5;
        uVar13 = (uint)CONCAT21(CONCAT11(*puVar1,*puVar2),*puVar3);
        uVar6 = *puVar9;
        if (0x10ffff < uVar13) {
          FUN_008b8460(param_2,8);
        }
        if (uVar13 < local_18) {
          FUN_008b8460(param_2,8);
        }
        local_18 = uVar13 + 1;
        if ((0 < *(int *)(param_2 + 8)) &&
           (*(uint *)(param_2 + 0x50) <= (uint)CONCAT11(uVar5,uVar6))) {
          FUN_008b8460(param_2,0x10);
        }
      }
    }
  }
  return 0;
}

