
undefined4 FUN_008c4b30(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined1 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint uVar13;
  uint uVar14;
  undefined1 *puVar15;
  undefined1 *puVar16;
  int iVar17;
  uint local_14;
  uint local_c;
  
  if (*(uint *)(param_2 + 4) < param_1 + 0x2010U) {
    FUN_008b8460(param_2,8);
  }
  uVar9 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 4),*(undefined1 *)(param_1 + 5)),
                            *(undefined1 *)(param_1 + 6)),*(undefined1 *)(param_1 + 7));
  if (((uint)(*(int *)(param_2 + 4) - param_1) < uVar9) || (uVar9 < 0x2010)) {
    FUN_008b8460(param_2,8);
  }
  puVar12 = (undefined1 *)(param_1 + 0x200e);
  puVar10 = (undefined1 *)(param_1 + 0x200c);
  puVar15 = (undefined1 *)(param_1 + 0x200f);
  puVar11 = (undefined1 *)(param_1 + 0x200d);
  uVar9 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 0x200c),
                                     *(undefined1 *)(param_1 + 0x200d)),*puVar12),*puVar15);
  if (*(uint *)(param_2 + 4) < param_1 + 0x2010 + uVar9 * 0xc) {
    FUN_008b8460(param_2,8);
  }
  local_14 = 0;
  local_c = 0;
  if (uVar9 != 0) {
    do {
      uVar1 = puVar10[4];
      uVar2 = puVar11[4];
      puVar16 = puVar15 + 8;
      uVar3 = puVar11[8];
      uVar14 = CONCAT31(CONCAT21(CONCAT11(uVar1,uVar2),puVar12[4]),puVar15[4]);
      uVar4 = puVar10[8];
      puVar15 = puVar15 + 0xc;
      puVar10 = puVar10 + 0xc;
      uVar13 = CONCAT31(CONCAT21(CONCAT11(uVar4,uVar3),puVar12[8]),*puVar16);
      uVar5 = *puVar10;
      puVar11 = puVar11 + 0xc;
      uVar6 = *puVar11;
      puVar12 = puVar12 + 0xc;
      uVar7 = *puVar12;
      uVar8 = *puVar15;
      if (uVar13 < uVar14) {
        FUN_008b8460(param_2,8);
      }
      if ((local_c != 0) && (uVar14 <= local_14)) {
        FUN_008b8460(param_2,8);
      }
      if (0 < *(int *)(param_2 + 8)) {
        if (*(uint *)(param_2 + 0x50) <=
            (CONCAT31(CONCAT21(CONCAT11(uVar5,uVar6),uVar7),uVar8) - uVar14) + uVar13) {
          FUN_008b8460(param_2,0x10);
        }
        iVar17 = (uVar13 - uVar14) + 1;
        if (CONCAT11(uVar1,uVar2) == 0) {
          if (CONCAT11(uVar4,uVar3) != 0) {
            FUN_008b8460(param_2,8);
          }
          for (; iVar17 != 0; iVar17 = iVar17 + -1) {
            if ((*(byte *)(((uVar14 & 0xffff) >> 3) + 0xc + param_1) &
                (byte)(0x80 >> ((byte)(uVar14 & 0xffff) & 7))) != 0) {
              FUN_008b8460(param_2,8);
            }
            uVar14 = uVar14 + 1;
          }
        }
        else {
          for (; iVar17 != 0; iVar17 = iVar17 + -1) {
            if ((*(byte *)((uVar14 >> 0x13) + 0xc + param_1) &
                (byte)(0x80 >> ((byte)(uVar14 >> 0x10) & 7))) == 0) {
              FUN_008b8460(param_2,8);
            }
            if ((*(byte *)(((uVar14 & 0xffff) >> 3) + 0xc + param_1) &
                (byte)(0x80 >> ((byte)(uVar14 & 0xffff) & 7))) == 0) {
              FUN_008b8460(param_2,8);
            }
            uVar14 = uVar14 + 1;
          }
        }
      }
      local_c = local_c + 1;
      local_14 = uVar13;
    } while (local_c < uVar9);
  }
  return 0;
}

