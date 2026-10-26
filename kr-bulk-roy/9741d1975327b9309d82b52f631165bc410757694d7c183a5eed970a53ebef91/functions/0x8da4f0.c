
int FUN_008da4f0(int param_1,byte *param_2,byte *param_3)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte *pbVar6;
  byte *pbVar7;
  int *piVar8;
  byte bVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint local_18;
  uint local_14;
  uint local_10;
  int local_c [2];
  
  local_c[0] = 0;
  uVar4 = **(undefined4 **)(param_1 + 0x1c);
  pbVar12 = param_2 + 1;
  if (pbVar12 <= param_3) {
    bVar1 = *param_2;
    if ((char)bVar1 < '\0') {
      if (((bVar1 & 8) != 0) && (local_c[0] = FUN_008d9da0(), local_c[0] != 0)) {
        return local_c[0];
      }
      iVar3 = *(int *)(param_1 + 0x10);
      uVar10 = (bVar1 & 0x3f) + iVar3;
      if (*(uint *)(param_1 + 0x14) < uVar10) {
        uVar10 = uVar10 + 3 & 0xfffffffc;
        if (0x40 < uVar10) {
          return 8;
        }
        uVar4 = FUN_008bc7d0(uVar4,0x18,*(uint *)(param_1 + 0x14),uVar10,
                             *(undefined4 *)(param_1 + 0x18),local_c);
        *(undefined4 *)(param_1 + 0x18) = uVar4;
        if (local_c[0] != 0) {
          return local_c[0];
        }
        *(uint *)(param_1 + 0x14) = uVar10;
      }
      local_18 = 0;
      if ((bVar1 & 0x3f) == 0) {
        return local_c[0];
      }
      pbVar6 = param_2 + 3;
      pbVar14 = param_2 + 4;
      param_2 = param_2 + 2;
      piVar8 = (int *)(*(int *)(param_1 + 0x18) + iVar3 * 0x18);
      while( true ) {
        local_10 = 0;
        local_14 = 0;
        if (param_3 < param_2) break;
        bVar2 = *pbVar12;
        pbVar11 = pbVar12 + 1;
        pbVar7 = param_2 + 1;
        pbVar13 = pbVar14 + 1;
        pbVar5 = pbVar6 + 1;
        *piVar8 = 0x10000;
        if ((bVar2 & 0x10) != 0) {
          if (param_3 < pbVar5) {
            return 8;
          }
          bVar9 = *pbVar11;
          pbVar11 = pbVar12 + 3;
          pbVar7 = param_2 + 3;
          pbVar13 = pbVar14 + 3;
          pbVar5 = pbVar6 + 3;
          *piVar8 = ((int)(short)((ushort)bVar9 << 8) | (uint)pbVar12[2]) << 4;
        }
        piVar8[1] = 0x10000;
        pbVar12 = pbVar11;
        if ((bVar2 & 0x20) != 0) {
          if (param_3 < pbVar5) {
            return 8;
          }
          pbVar12 = pbVar11 + 2;
          pbVar7 = pbVar7 + 2;
          pbVar13 = pbVar13 + 2;
          pbVar5 = pbVar5 + 2;
          piVar8[1] = ((int)(short)((ushort)*pbVar11 << 8) | (uint)pbVar11[1]) << 4;
        }
        if ((bVar2 & 3) == 1) {
          if (param_3 < pbVar5) {
            return 8;
          }
          bVar9 = *pbVar12;
          pbVar6 = pbVar12 + 1;
          pbVar12 = pbVar12 + 2;
          pbVar7 = pbVar7 + 2;
          pbVar13 = pbVar13 + 2;
          pbVar5 = pbVar5 + 2;
          local_10 = (int)(short)((ushort)bVar9 << 8) | (uint)*pbVar6;
        }
        else if ((bVar2 & 3) == 2) {
          if (param_3 < pbVar7) {
            return 8;
          }
          local_10 = (uint)(char)*pbVar12;
          pbVar12 = pbVar12 + 1;
          pbVar7 = pbVar7 + 1;
          pbVar13 = pbVar13 + 1;
          pbVar5 = pbVar5 + 1;
        }
        bVar9 = bVar2 >> 2 & 3;
        if (bVar9 == 1) {
          if (param_3 < pbVar5) {
            return 8;
          }
          bVar9 = *pbVar12;
          pbVar6 = pbVar12 + 1;
          pbVar12 = pbVar12 + 2;
          pbVar7 = pbVar7 + 2;
          pbVar13 = pbVar13 + 2;
          pbVar5 = pbVar5 + 2;
          local_14 = (int)(short)((ushort)bVar9 << 8) | (uint)*pbVar6;
        }
        else if (bVar9 == 2) {
          if (param_3 < pbVar7) {
            return 8;
          }
          local_14 = (uint)(char)*pbVar12;
          pbVar12 = pbVar12 + 1;
          pbVar7 = pbVar7 + 1;
          pbVar13 = pbVar13 + 1;
          pbVar5 = pbVar5 + 1;
        }
        piVar8[2] = local_10;
        piVar8[3] = local_14;
        if ((bVar2 & 0x40) == 0) {
          if (param_3 < pbVar7) {
            return 8;
          }
          pbVar11 = pbVar12 + 1;
          pbVar7 = pbVar7 + 1;
          pbVar13 = pbVar13 + 1;
          piVar8[5] = (uint)*pbVar12;
          pbVar5 = pbVar5 + 1;
        }
        else {
          if (param_3 < pbVar5) {
            return 8;
          }
          pbVar11 = pbVar12 + 2;
          pbVar7 = pbVar7 + 2;
          pbVar13 = pbVar13 + 2;
          pbVar5 = pbVar5 + 2;
          piVar8[5] = (uint)CONCAT11(*pbVar12,pbVar12[1]);
        }
        if ((bVar2 & 0x80) == 0) {
          if (param_3 < pbVar5) {
            return 8;
          }
          pbVar12 = pbVar11 + 2;
          param_2 = pbVar7 + 2;
          pbVar14 = pbVar13 + 2;
          pbVar6 = pbVar5 + 2;
          uVar10 = (uint)*pbVar11;
        }
        else {
          if (param_3 < pbVar13) {
            return 8;
          }
          pbVar12 = pbVar11 + 3;
          uVar10 = (uint)CONCAT11(*pbVar11,pbVar11[1]);
          param_2 = pbVar7 + 3;
          pbVar14 = pbVar13 + 3;
          pbVar6 = pbVar5 + 3;
        }
        piVar8[4] = uVar10 << 8 | (uint)pbVar12[-1];
        *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
        local_18 = local_18 + 1;
        piVar8 = piVar8 + 6;
        if ((bVar1 & 0x3f) <= local_18) {
          return local_c[0];
        }
      }
    }
  }
  return 8;
}

