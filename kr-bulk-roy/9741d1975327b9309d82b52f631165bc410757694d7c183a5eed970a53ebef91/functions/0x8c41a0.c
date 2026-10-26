
void FUN_008c41a0(int *param_1,uint *param_2,char param_3)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  uint uVar8;
  undefined1 *puVar9;
  uint uVar10;
  uint uVar11;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = *param_2;
  uVar2 = CONCAT11(*(undefined1 *)(param_1[4] + 6),*(undefined1 *)(param_1[4] + 7));
  uVar5 = uVar2 & 0xfffffffe;
  uVar3 = 0;
  uVar10 = (uint)(uVar2 >> 1);
  local_c = 0;
  if (uVar10 == 0) {
    return;
  }
  if (param_3 != '\0') {
    local_8 = local_8 + 1;
  }
  if (local_8 < 0x10000) {
    do {
      local_10 = 0;
      puVar6 = (undefined1 *)(param_1[4] + 0xe);
      puVar9 = (undefined1 *)(param_1[4] + 0x10 + uVar5);
      if (uVar10 != 0) {
        do {
          puVar7 = puVar6 + 2;
          uVar11 = (uint)CONCAT11(*puVar9,puVar9[1]);
          if ((uVar11 <= local_8) && (local_8 <= CONCAT11(*puVar6,puVar6[1]))) {
            puVar7 = puVar9 + uVar5 * 2;
            uVar4 = (int)(short)((ushort)(byte)puVar9[uVar5] << 8) | (uint)(byte)puVar9[uVar5 + 1];
            uVar8 = (uint)CONCAT11(*puVar7,puVar7[1]);
            if (((uVar10 - 1 <= local_10) &&
                (((uVar11 == 0xffff && (CONCAT11(*puVar6,puVar6[1]) == 0xffff)) && (uVar8 != 0))))
               && ((undefined1 *)(*(int *)(*param_1 + 0x1f8) + *(int *)(*param_1 + 500)) <
                   puVar7 + uVar8 + 2)) {
              uVar3 = local_8 + 1 & 0xffff;
              local_c = uVar3;
              break;
            }
            uVar3 = local_c;
            if (uVar8 != 0xffff) {
              if (uVar8 == 0) {
                uVar3 = uVar4 + local_8 & 0xffff;
                local_c = uVar3;
              }
              else {
                iVar1 = uVar8 + (local_8 - uVar11) * 2;
                uVar3 = (uint)CONCAT11(puVar7[iVar1],puVar7[iVar1 + 1]);
                local_c = uVar3;
                if (uVar3 != 0) {
                  uVar3 = uVar3 + uVar4 & 0xffff;
                  local_c = uVar3;
                }
              }
              break;
            }
          }
          local_10 = local_10 + 1;
          puVar6 = puVar7;
          puVar9 = puVar9 + 2;
        } while (local_10 < uVar10);
      }
      if (param_3 == '\0') {
        return;
      }
    } while ((uVar3 == 0) && (local_8 = local_8 + 1, local_8 < 0x10000));
  }
  if ((param_3 != '\0') && (uVar3 != 0)) {
    *param_2 = local_8;
  }
  return;
}

