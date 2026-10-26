
int FUN_008c66b0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte *pbVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  byte bVar5;
  uint3 uVar6;
  undefined1 *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  undefined1 *puVar12;
  int iVar13;
  uint uVar14;
  undefined1 *puVar15;
  uint uVar16;
  uint local_20;
  uint local_18;
  uint local_14;
  uint local_8;
  
  iVar8 = *(int *)(param_1 + 0x10);
  puVar7 = (undefined1 *)FUN_008c6180(param_3);
  if (puVar7 == (undefined1 *)0x0) {
    return 0;
  }
  iVar13 = CONCAT31(CONCAT21(CONCAT11(*puVar7,puVar7[1]),puVar7[2]),puVar7[3]);
  iVar9 = CONCAT31(CONCAT21(CONCAT11(puVar7[4],puVar7[5]),puVar7[6]),puVar7[7]);
  if (iVar13 == 0) {
    if (iVar9 != 0) {
      iVar8 = FUN_008c6600(param_2);
      return iVar8;
    }
  }
  else {
    if (iVar9 == 0) {
      iVar8 = FUN_008c6560(param_2);
      return iVar8;
    }
    puVar7 = (undefined1 *)(iVar8 + iVar13);
    puVar12 = (undefined1 *)(iVar8 + 4 + iVar9);
    uVar16 = CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(iVar8 + iVar9),puVar12[-3]),
                               *(undefined1 *)(iVar8 + 2 + iVar9)),puVar12[-1]);
    iVar8 = FUN_008c6520();
    uVar10 = CONCAT31(CONCAT21(CONCAT11(*puVar7,puVar7[1]),puVar7[2]),puVar7[3]);
    if (uVar16 == 0) {
      iVar8 = FUN_008c6560(param_2);
      return iVar8;
    }
    if (iVar8 == 0) {
      iVar8 = FUN_008c6600(param_2);
      return iVar8;
    }
    iVar8 = FUN_008c5c80();
    if (iVar8 == 0) {
      iVar8 = *(int *)(param_1 + 0x20);
      local_8 = (uint)(byte)puVar7[7];
      uVar11 = (uint)CONCAT21(CONCAT11(puVar7[4],puVar7[5]),puVar7[6]);
      puVar7 = puVar7 + 8;
      uVar6 = CONCAT21(CONCAT11(*puVar12,puVar12[1]),puVar12[2]);
      local_18 = 1;
      local_14 = 1;
      iVar9 = 0;
      do {
        uVar14 = (uint)uVar6;
        while (local_8 + uVar11 < uVar14) {
          local_20 = 0;
          do {
            iVar13 = iVar9;
            *(uint *)(iVar8 + iVar13 * 4) = local_20 + uVar11;
            local_20 = local_20 + 1;
            iVar9 = iVar13 + 1;
          } while (local_20 <= local_8);
          local_18 = local_18 + 1;
          if (uVar10 < local_18) {
            if (uVar16 < local_14) goto LAB_008c6959;
            *(uint *)(iVar8 + iVar9 * 4) = uVar14;
            iVar9 = iVar13 + 2;
            if (local_14 < uVar16) {
              puVar7 = puVar12 + 4;
              puVar15 = puVar12 + 3;
              puVar12 = puVar12 + 2;
              local_20 = uVar16 - local_14;
              do {
                *(uint *)(iVar8 + iVar9 * 4) =
                     (uint)CONCAT21(CONCAT11(puVar12[3],puVar15[3]),puVar7[3]);
                iVar9 = iVar9 + 1;
                puVar12 = puVar12 + 5;
                puVar15 = puVar15 + 5;
                puVar7 = puVar7 + 5;
                local_20 = local_20 + -1;
              } while (local_20 != 0);
              *(undefined4 *)(iVar8 + iVar9 * 4) = 0;
              return iVar8;
            }
            goto LAB_008c69b3;
          }
          uVar11 = (uint)CONCAT21(CONCAT11(*puVar7,puVar7[1]),puVar7[2]);
          pbVar1 = puVar7 + 3;
          puVar7 = puVar7 + 4;
          local_8 = (uint)*pbVar1;
        }
        if (uVar14 < uVar11) {
          *(uint *)(iVar8 + iVar9 * 4) = uVar14;
          iVar9 = iVar9 + 1;
        }
        local_14 = local_14 + 1;
        if (uVar16 < local_14) {
LAB_008c6959:
          if (local_18 <= uVar10) {
            uVar16 = 0;
            do {
              *(uint *)(iVar8 + iVar9 * 4) = uVar16 + uVar11;
              uVar16 = uVar16 + 1;
              iVar9 = iVar9 + 1;
            } while (uVar16 <= local_8);
            if (local_18 < uVar10) {
              param_1 = uVar10 - local_18;
              do {
                uVar2 = *puVar7;
                uVar3 = puVar7[1];
                uVar4 = puVar7[2];
                bVar5 = puVar7[3];
                puVar7 = puVar7 + 4;
                uVar10 = 0;
                do {
                  *(uint *)(iVar8 + iVar9 * 4) = uVar10 + CONCAT21(CONCAT11(uVar2,uVar3),uVar4);
                  uVar10 = uVar10 + 1;
                  iVar9 = iVar9 + 1;
                } while (uVar10 <= bVar5);
                param_1 = param_1 + -1;
              } while (param_1 != 0);
            }
          }
LAB_008c69b3:
          *(undefined4 *)(iVar8 + iVar9 * 4) = 0;
          return iVar8;
        }
        uVar6 = CONCAT21(CONCAT11(puVar12[5],puVar12[6]),puVar12[7]);
        puVar12 = puVar12 + 5;
      } while( true );
    }
  }
  return 0;
}

