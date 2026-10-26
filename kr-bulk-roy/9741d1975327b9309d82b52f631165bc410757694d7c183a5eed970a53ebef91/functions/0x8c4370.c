
uint FUN_008c4370(int *param_1,uint *param_2,char param_3)

{
  byte *pbVar1;
  int iVar2;
  undefined1 uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  undefined1 *puVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  uint local_3c;
  byte *local_38;
  byte *local_34;
  byte *local_30;
  byte *local_28;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_c = *param_2;
  iVar6 = param_1[4];
  uVar4 = CONCAT11(*(undefined1 *)(iVar6 + 6),*(undefined1 *)(iVar6 + 7));
  uVar12 = uVar4 & 0xfffffffe;
  local_1c = 0;
  if ((uVar4 & 0xfffe) == 0) {
    return 0;
  }
  uVar9 = (uint)(uVar4 >> 1);
  local_18 = 0xffff;
  if (param_3 != '\0') {
    local_c = local_c + 1;
  }
  local_3c = 0;
  uVar11 = 0;
  local_14 = uVar9;
  if (uVar9 != 0) {
    do {
      uVar11 = local_14 + local_3c >> 1;
      puVar7 = (undefined1 *)(iVar6 + uVar11 * 2 + uVar12 + 0x10);
      local_18 = (uint)CONCAT11(*(undefined1 *)(iVar6 + 0xe + uVar11 * 2),
                                *(undefined1 *)(iVar6 + 0xf + uVar11 * 2));
      local_20 = (uint)CONCAT11(*puVar7,puVar7[1]);
      uVar5 = uVar11;
      if (local_20 <= local_c) {
        if (local_c <= local_18) {
          uVar5 = (int)(short)((ushort)(byte)puVar7[uVar12] << 8) | (uint)(byte)puVar7[uVar12 + 1];
          local_28 = puVar7 + uVar12 * 2;
          uVar10 = (uint)CONCAT11(puVar7[uVar12 * 2],puVar7[uVar12 * 2 + 1]);
          if ((((uVar9 - 1 <= uVar11) && (local_20 == 0xffff)) && (local_18 == 0xffff)) &&
             ((uVar10 != 0 &&
              ((byte *)(*(int *)(*param_1 + 0x1f8) + *(int *)(*param_1 + 500)) <
               local_28 + uVar10 + 2)))) {
            uVar5 = 1;
            uVar10 = 0;
          }
          if ((*(byte *)(param_1 + 5) & 2) != 0) {
            local_10 = uVar11;
            if (uVar10 == 0xffff) {
              local_10 = uVar11 + 1;
            }
            pbVar8 = local_28;
            local_8 = uVar11;
            if (uVar11 == 0) goto LAB_008c45ba;
            local_30 = (byte *)(param_1[4] + 0xc + uVar11 * 2);
            local_34 = (byte *)(param_1[4] + 0xe + (uVar11 + uVar12) * 2);
            local_38 = (byte *)(param_1[4] + uVar12 * 3 + 0xe + uVar11 * 2);
            local_28 = local_30 + uVar12 + 2;
            goto LAB_008c4523;
          }
          if (uVar10 != 0xffff) goto LAB_008c47c7;
          break;
        }
        local_3c = uVar11 + 1;
        uVar5 = local_14;
      }
      local_14 = uVar5;
    } while (local_3c < local_14);
  }
  goto LAB_008c4732;
  while( true ) {
    local_20 = (uint)CONCAT11(*local_28,local_34[1 - uVar12]);
    uVar5 = (int)(short)((ushort)*local_34 << 8) | (uint)local_38[1 - uVar12];
    uVar10 = (uint)CONCAT11(*local_38,(local_38 + (1 - uVar12))[uVar12]);
    if (uVar10 != 0xffff) {
      local_10 = local_8 - 1;
    }
    local_8 = local_8 - 1;
    local_30 = local_30 + -2;
    local_28 = local_28 + -2;
    local_34 = local_34 + -2;
    pbVar8 = local_38;
    local_38 = local_38 + -2;
    local_18 = uVar13;
    if (local_8 == 0) break;
LAB_008c4523:
    uVar13 = (uint)CONCAT11(*local_30,local_28[1 - (uVar12 + 2)]);
    if (uVar13 < local_c) break;
  }
LAB_008c45ba:
  local_28 = pbVar8;
  if (local_10 == uVar11 + 1) {
    if (local_8 != uVar11) {
      iVar6 = param_1[4] + 0xe + uVar11 * 2;
      local_18 = (uint)CONCAT11(*(undefined1 *)(param_1[4] + 0xe + uVar11 * 2),
                                *(undefined1 *)(iVar6 + 1));
      iVar2 = iVar6 + 2 + uVar12;
      local_20 = (uint)CONCAT11(*(undefined1 *)(iVar6 + 2 + uVar12),
                                *(undefined1 *)(iVar6 + 3 + uVar12));
      pbVar8 = (byte *)(iVar2 + uVar12);
      uVar5 = (int)(short)((ushort)*pbVar8 << 8) | (uint)*(byte *)(iVar2 + 1 + uVar12);
      local_28 = pbVar8 + uVar12;
      uVar10 = (uint)CONCAT11(pbVar8[uVar12],pbVar8[uVar12 + 1]);
    }
    local_8 = uVar11 + 1;
    local_10 = uVar11;
    if (local_8 < uVar9) {
      iVar6 = param_1[4];
      local_34 = (byte *)(iVar6 + 0xe + local_8 * 2);
      local_30 = (byte *)(iVar6 + 0x10 + (local_8 + uVar12) * 2);
      local_38 = (byte *)(iVar6 + uVar12 * 3 + 0x10 + local_8 * 2);
      pbVar8 = local_34 + uVar12 + 2;
      do {
        local_28 = pbVar8;
        uVar3 = *local_34;
        pbVar1 = local_28 + (1 - (uVar12 + 2));
        uVar13 = (uint)CONCAT11(*local_28,local_30[1 - uVar12]);
        if (local_c < uVar13) break;
        uVar5 = (int)(short)((ushort)*local_30 << 8) | (uint)local_38[1 - uVar12];
        uVar10 = (uint)CONCAT11(*local_38,(local_38 + (1 - uVar12))[uVar12]);
        if (uVar10 != 0xffff) {
          local_10 = local_8;
        }
        local_34 = local_34 + 2;
        pbVar8 = local_28 + 2;
        local_30 = local_30 + 2;
        local_8 = local_8 + 1;
        local_28 = local_38;
        local_38 = local_38 + 2;
        local_20 = uVar13;
        local_18 = (uint)CONCAT11(uVar3,*pbVar1);
      } while (local_8 < uVar9);
    }
    local_8 = local_8 - 1;
    bVar14 = local_10 == uVar11;
    uVar11 = local_8;
    if (bVar14) goto LAB_008c4732;
  }
  uVar11 = local_10;
  if (local_10 != local_8) {
    iVar6 = param_1[4] + 0xe + local_10 * 2;
    iVar2 = iVar6 + 2 + uVar12;
    local_18 = (uint)CONCAT11(*(undefined1 *)(param_1[4] + 0xe + local_10 * 2),
                              *(undefined1 *)(iVar6 + 1));
    local_20 = (uint)CONCAT11(*(undefined1 *)(iVar6 + 2 + uVar12),*(undefined1 *)(iVar2 + 1));
    pbVar8 = (byte *)(iVar2 + uVar12);
    uVar5 = (int)(short)((ushort)*pbVar8 << 8) | (uint)*(byte *)(iVar2 + 1 + uVar12);
    local_28 = pbVar8 + uVar12;
    uVar10 = (uint)CONCAT11(pbVar8[uVar12],local_28[1]);
  }
LAB_008c47c7:
  if (uVar10 == 0) {
    local_1c = uVar5 + local_c & 0xffff;
  }
  else {
    local_1c = (uint)CONCAT11(local_28[uVar10 + (local_c - local_20) * 2],
                              (local_28 + uVar10 + (local_c - local_20) * 2)[1]);
    if (local_1c != 0) {
      local_1c = uVar5 + local_1c & 0xffff;
    }
  }
LAB_008c4732:
  if (param_3 != '\0') {
    if ((local_18 < local_c) && (uVar11 + 1 == uVar9)) {
      return 0;
    }
    iVar6 = FUN_008c3bf0(param_1);
    if (iVar6 == 0) {
      param_1[6] = local_c;
      if (local_1c == 0) {
        param_1[6] = local_c;
        FUN_008c3d40();
        local_1c = param_1[7];
      }
      else {
        param_1[7] = local_1c;
      }
      if (local_1c != 0) {
        *param_2 = param_1[6];
      }
    }
    else if (local_1c != 0) {
      *param_2 = local_c;
      return local_1c;
    }
  }
  return local_1c;
}

