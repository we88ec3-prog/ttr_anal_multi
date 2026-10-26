
int FUN_008f1b20(int param_1)

{
  short *psVar1;
  int *piVar2;
  char cVar3;
  byte bVar4;
  short sVar5;
  byte *pbVar6;
  int iVar7;
  char *pcVar8;
  short *psVar9;
  bool bVar10;
  short sVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  uint uVar15;
  short sVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  byte *pbVar20;
  byte *pbVar21;
  int iVar22;
  byte *pbVar23;
  byte *pbVar24;
  byte *local_1c;
  byte *local_18;
  byte *local_14;
  int local_10;
  int local_c;
  
  pbVar6 = *(byte **)(param_1 + 0xcc);
  iVar7 = *(int *)(param_1 + 0xc);
  pcVar8 = *(char **)(param_1 + 200);
  sVar5 = *(short *)(param_1 + 0x20);
  iVar22 = (int)sVar5;
  if (((iVar22 != 0) &&
      (*(uint *)(iVar7 + 8) <
       (uint)((int)*(short *)(iVar7 + 0x14) + *(short *)(iVar7 + 0x38) + iVar22))) &&
     (iVar12 = FUN_008bc9a0(iVar7,0,iVar22), iVar12 != 0)) {
    return iVar12;
  }
  psVar9 = *(short **)(iVar7 + 0x44);
  psVar1 = psVar9 + iVar22;
  if (0xffe < iVar22) {
    return 0x14;
  }
  if (pbVar6 < pcVar8 + iVar22 * 2 + 2) {
    return 0x14;
  }
  cVar3 = *pcVar8;
  sVar16 = CONCAT11(cVar3,pcVar8[1]);
  if (0 < iVar22) {
    *psVar9 = sVar16;
  }
  if (cVar3 < '\0') {
    return 0x14;
  }
  while( true ) {
    psVar9 = psVar9 + 1;
    pcVar8 = pcVar8 + 2;
    if (psVar1 <= psVar9) break;
    sVar11 = CONCAT11(*pcVar8,pcVar8[1]);
    *psVar9 = sVar11;
    bVar10 = sVar11 <= sVar16;
    sVar16 = sVar11;
    if (bVar10) {
      return 0x14;
    }
  }
  local_c = 0;
  if ((0 < iVar22) && (local_c = psVar9[-1] + 1, local_c < 0)) {
    return 0x14;
  }
  if ((local_c + 4 == 0) ||
     ((uint)(*(short *)(iVar7 + 0x16) + 4 + *(short *)(iVar7 + 0x3a) + local_c) <=
      *(uint *)(iVar7 + 4))) {
    local_10 = 0;
  }
  else {
    local_10 = FUN_008bc9a0(iVar7,local_c + 4,0);
    if (local_10 != 0) {
      return local_10;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x8c) = 0;
  local_1c = (byte *)(pcVar8 + 2);
  *(undefined4 *)(*(int *)(param_1 + 8) + 0x88) = 0;
  if (pbVar6 < local_1c) {
    return 0x14;
  }
  uVar19 = (uint)CONCAT11(*pcVar8,pcVar8[1]);
  if ((int)pbVar6 - (int)local_1c < (int)uVar19) {
    return 0x16;
  }
  if ((*(byte *)(param_1 + 0x10) & 2) == 0) {
    uVar18 = *(uint *)(*(int *)(param_1 + 0xa0) + 0x184);
    iVar22 = FUN_008ebfc0(*(undefined4 *)(*(int *)(param_1 + 0xa0) + 8));
    *(uint *)(*(int *)(param_1 + 0xa0) + 0x184) = uVar18 & 0xffff;
    if (iVar22 != 0) {
      return iVar22;
    }
    *(uint *)(*(int *)(param_1 + 8) + 0x8c) = uVar19;
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x88) =
         *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x188);
    FID_conflict__memcpy(*(void **)(*(int *)(param_1 + 0xa0) + 0x188),local_1c,uVar19);
    local_10 = 0;
  }
  pbVar23 = local_1c + uVar19;
  pbVar20 = *(byte **)(iVar7 + 0x40);
  pbVar21 = pbVar20 + local_c;
  if (pbVar20 < pbVar21) {
    pbVar13 = pbVar23 + 1;
    pbVar24 = pbVar23;
    do {
      if (pbVar6 < pbVar13) {
        return 0x14;
      }
      bVar4 = *pbVar24;
      *pbVar20 = bVar4;
      pbVar20 = pbVar20 + 1;
      pbVar23 = pbVar24 + 1;
      pbVar14 = pbVar13 + 1;
      local_1c = (byte *)CONCAT31(local_1c._1_3_,bVar4);
      if ((bVar4 & 8) != 0) {
        if (pbVar6 < pbVar14) {
          return 0x14;
        }
        bVar4 = *pbVar23;
        uVar19 = (uint)bVar4;
        pbVar14 = pbVar13 + 2;
        pbVar23 = pbVar24 + 2;
        if (pbVar21 < pbVar20 + uVar19) {
          return 0x14;
        }
        if (bVar4 != 0) {
          _memset(pbVar20,(int)local_1c,uVar19);
          pbVar20 = pbVar20 + uVar19;
        }
      }
      pbVar13 = pbVar14;
      pbVar24 = pbVar23;
    } while (pbVar20 < pbVar21);
  }
  piVar17 = *(int **)(iVar7 + 0x3c);
  pbVar21 = *(byte **)(iVar7 + 0x40);
  piVar2 = piVar17 + local_c * 2;
  local_1c = (byte *)0x0;
  if (pbVar6 < pbVar23) {
    return 0x14;
  }
  if (piVar17 < piVar2) {
    local_18 = pbVar23 + 2;
    local_14 = pbVar23 + 1;
    pbVar20 = pbVar23;
    do {
      bVar4 = *pbVar21;
      uVar19 = 0;
      if ((bVar4 & 2) == 0) {
        pbVar23 = pbVar20;
        if ((bVar4 & 0x10) == 0) {
          if (pbVar6 < local_18) {
            return 0x14;
          }
          local_14 = local_14 + 2;
          local_18 = local_18 + 2;
          pbVar23 = pbVar20 + 2;
          uVar19 = (int)(short)((ushort)*pbVar20 << 8) | (uint)pbVar20[1];
        }
      }
      else {
        if (pbVar6 < local_14) {
          return 0x14;
        }
        uVar19 = (uint)*pbVar20;
        local_14 = local_14 + 1;
        local_18 = local_18 + 1;
        pbVar23 = pbVar20 + 1;
        if ((bVar4 & 0x10) == 0) {
          uVar19 = -uVar19;
        }
      }
      local_1c = (byte *)((int)local_1c + uVar19);
      *piVar17 = (int)local_1c;
      *pbVar21 = bVar4 & 0xed;
      piVar17 = piVar17 + 2;
      pbVar21 = pbVar21 + 1;
      pbVar20 = pbVar23;
    } while (piVar17 < piVar2);
  }
  uVar18 = *(uint *)(iVar7 + 0x3c);
  pbVar21 = *(byte **)(iVar7 + 0x40);
  uVar19 = uVar18 + local_c * 8;
  local_1c = (byte *)0x0;
  if (uVar18 < uVar19) {
    local_14 = pbVar23 + 2;
    local_18 = pbVar23 + 1;
    pbVar20 = pbVar23;
    do {
      bVar4 = *pbVar21;
      uVar15 = 0;
      if ((bVar4 & 4) == 0) {
        pbVar23 = pbVar20;
        if ((bVar4 & 0x20) == 0) {
          if (pbVar6 < local_14) {
            return 0x14;
          }
          local_18 = local_18 + 2;
          local_14 = local_14 + 2;
          pbVar23 = pbVar20 + 2;
          uVar15 = (int)(short)((ushort)*pbVar20 << 8) | (uint)pbVar20[1];
        }
      }
      else {
        if (pbVar6 < local_18) {
          return 0x14;
        }
        uVar15 = (uint)*pbVar20;
        local_18 = local_18 + 1;
        local_14 = local_14 + 1;
        pbVar23 = pbVar20 + 1;
        if ((bVar4 & 0x20) == 0) {
          uVar15 = -uVar15;
        }
      }
      local_1c = (byte *)((int)local_1c + uVar15);
      *(byte **)(uVar18 + 4) = local_1c;
      *pbVar21 = bVar4 & 1;
      uVar18 = uVar18 + 8;
      pbVar21 = pbVar21 + 1;
      pbVar20 = pbVar23;
    } while (uVar18 < uVar19);
  }
  *(short *)(iVar7 + 0x38) = sVar5;
  *(undefined2 *)(iVar7 + 0x3a) = (undefined2)local_c;
  *(byte **)(param_1 + 200) = pbVar23;
  return local_10;
}

