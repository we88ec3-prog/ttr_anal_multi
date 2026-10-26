
uint FUN_008c3df0(int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined1 uVar5;
  ushort uVar6;
  ushort uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint local_28;
  uint local_24;
  undefined1 *local_1c;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  if (*(uint *)(param_2 + 4) < param_1 + 4U) {
    FUN_008b8460(param_2,8);
  }
  local_10 = (uint)CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3));
  if (local_10 < 0x10) {
    FUN_008b8460(param_2,8);
  }
  if (*(uint *)(param_2 + 4) < local_10 + param_1) {
    if (0 < *(int *)(param_2 + 8)) {
      FUN_008b8460(param_2,8);
    }
    local_10 = *(int *)(param_2 + 4) - param_1;
  }
  uVar3 = *(undefined1 *)(param_1 + 6);
  bVar4 = *(byte *)(param_1 + 7);
  if ((1 < *(int *)(param_2 + 8)) && ((bVar4 & 1) != 0)) {
    FUN_008b8460(param_2,8);
  }
  uVar12 = (uint)(ushort)(CONCAT11(uVar3,bVar4) >> 1);
  if (local_10 < uVar12 * 8 + 0x10) {
    FUN_008b8460(param_2,8);
  }
  if (1 < *(int *)(param_2 + 8)) {
    bVar4 = *(byte *)(param_1 + 0xb);
    uVar6 = CONCAT11(*(undefined1 *)(param_1 + 8),*(undefined1 *)(param_1 + 9));
    uVar7 = CONCAT11(*(undefined1 *)(param_1 + 0xc),*(undefined1 *)(param_1 + 0xd));
    if (((uVar7 | uVar6) & 1) != 0) {
      FUN_008b8460(param_2,8);
    }
    uVar15 = (uint)(uVar6 >> 1);
    if ((((uVar12 < uVar15) || (uVar15 * 2 < uVar12)) || ((uVar7 >> 1) + uVar15 != uVar12)) ||
       (uVar15 != 1 << (bVar4 & 0x1f))) {
      FUN_008b8460(param_2,8);
    }
  }
  iVar13 = param_1 + 0x10 + uVar12 * 2;
  iVar1 = iVar13 + uVar12 * 2;
  puVar2 = (undefined1 *)(iVar1 + uVar12 * 2);
  if ((1 < *(int *)(param_2 + 8)) &&
     (CONCAT11(*(undefined1 *)(param_1 + 0xc + uVar12 * 2),
               *(undefined1 *)(param_1 + 0xd + uVar12 * 2)) != -1)) {
    FUN_008b8460(param_2,8);
  }
  local_24 = 0;
  local_28 = 0;
  local_c = 0;
  if (uVar12 == 0) {
    return 0;
  }
  local_1c = (undefined1 *)(param_1 + 0xc);
  iVar13 = iVar13 + -1;
  puVar9 = (undefined1 *)(iVar1 + -1);
  puVar10 = puVar2;
  do {
    puVar8 = (undefined1 *)(iVar13 + 1);
    puVar11 = (undefined1 *)(iVar13 + 2);
    iVar13 = iVar13 + 2;
    uVar14 = (uint)CONCAT11(*puVar8,*puVar11);
    local_1c = local_1c + 2;
    puVar8 = puVar9 + 2;
    uVar16 = (uint)CONCAT11(*local_1c,puVar9[(param_1 + 0x10) - iVar1]);
    uVar3 = puVar9[1];
    uVar5 = *puVar8;
    uVar15 = (uint)CONCAT11(*puVar10,puVar8[(int)puVar2 - iVar1]);
    if (uVar16 < uVar14) {
      FUN_008b8460(param_2,8);
    }
    if ((uVar14 <= local_28) && (local_c != 0)) {
      if (*(int *)(param_2 + 8) < 1) {
        if ((uVar14 < local_24) || (uVar16 < local_28)) {
          local_8 = local_8 | 1;
        }
        else {
          local_8 = local_8 | 2;
        }
      }
      else {
        FUN_008b8460(param_2,8);
      }
    }
    if (uVar15 != 0) {
      if (uVar15 == 0xffff) {
        if ((((1 < *(int *)(param_2 + 8)) || (local_c != uVar12 - 1)) || (uVar14 != 0xffff)) ||
           (uVar16 != 0xffff)) {
          FUN_008b8460(param_2,8);
        }
      }
      else {
        puVar9 = puVar10 + uVar15;
        if (*(int *)(param_2 + 8) < 1) {
          if (((local_c != uVar12 - 1) || (uVar14 != 0xffff)) || (uVar16 != 0xffff)) {
            if (puVar2 + uVar12 * 2 <= puVar9) {
              puVar11 = *(undefined1 **)(param_2 + 4);
              goto LAB_008c40dd;
            }
            goto LAB_008c40e1;
          }
        }
        else {
          if (puVar2 + uVar12 * 2 <= puVar9) {
            puVar11 = (undefined1 *)(local_10 + param_1);
LAB_008c40dd:
            if (puVar9 + (uVar16 - uVar14) * 2 + 2 <= puVar11) goto LAB_008c40ef;
          }
LAB_008c40e1:
          FUN_008b8460(param_2,8);
        }
LAB_008c40ef:
        if ((0 < *(int *)(param_2 + 8)) && (uVar14 < uVar16)) {
          puVar9 = puVar9 + -1;
          local_14 = uVar16 - uVar14;
          do {
            puVar11 = puVar9 + 1;
            puVar9 = puVar9 + 2;
            if ((CONCAT11(*puVar11,*puVar9) != 0) &&
               (*(uint *)(param_2 + 0x50) <=
                (uint)(ushort)(CONCAT11(*puVar11,*puVar9) + CONCAT11(uVar3,uVar5)))) {
              FUN_008b8460(param_2,0x10);
            }
            local_14 = local_14 + -1;
          } while (local_14 != 0);
        }
      }
    }
    local_c = local_c + 1;
    puVar9 = puVar8;
    puVar10 = puVar10 + 2;
    local_28 = uVar16;
    local_24 = uVar14;
    if (uVar12 <= local_c) {
      return local_8;
    }
  } while( true );
}

