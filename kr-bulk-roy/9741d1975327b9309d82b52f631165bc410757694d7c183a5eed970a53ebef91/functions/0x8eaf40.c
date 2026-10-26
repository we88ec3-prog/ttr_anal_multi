
int FUN_008eaf40(int param_1)

{
  byte bVar1;
  ushort uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  ushort local_20;
  uint local_14;
  uint local_10;
  int local_8;
  
  pbVar3 = *(byte **)(param_1 + 0xcc);
  pbVar11 = *(byte **)(param_1 + 200);
  iVar7 = *(int *)(param_1 + 0xc);
  iVar4 = 0;
  local_8 = 0;
  pbVar9 = pbVar11 + 4;
  do {
    iVar4 = iVar4 + 1;
    iVar5 = FUN_008bcb10(iVar7,iVar4);
    if (iVar5 != 0) {
      return iVar5;
    }
    if (pbVar3 < pbVar9) {
      return 0x15;
    }
    puVar6 = (uint *)(*(int *)(iVar7 + 0x58) + local_8);
    pbVar10 = pbVar11 + 4;
    puVar6[3] = 0;
    puVar6[2] = 0;
    *(ushort *)(puVar6 + 1) = CONCAT11(*pbVar11,pbVar11[1]);
    *puVar6 = (uint)CONCAT11(pbVar11[2],pbVar11[3]);
    uVar2 = (ushort)puVar6[1];
    local_14._0_2_ = uVar2 & 1;
    iVar5 = 2;
    if ((uVar2 & 1) != 0) {
      iVar5 = 4;
    }
    local_20 = uVar2 & 8;
    if ((uVar2 & 8) == 0) {
      if ((uVar2 & 0x40) == 0) {
        if ((char)uVar2 < '\0') {
          iVar5 = iVar5 + 8;
        }
      }
      else {
        iVar5 = iVar5 + 4;
      }
    }
    else {
      iVar5 = iVar5 + 2;
    }
    if (pbVar3 < pbVar10 + iVar5) {
      return 0x15;
    }
    if ((ushort)local_14 == 0) {
      puVar6[2] = (int)(char)*pbVar10;
      pbVar10 = pbVar11 + 5;
      pbVar11 = pbVar11 + 6;
      puVar6[3] = (int)(char)*pbVar10;
      pbVar9 = pbVar9 + 6;
    }
    else {
      puVar6[2] = (int)(short)((ushort)*pbVar10 << 8) | (uint)pbVar11[5];
      pbVar9 = pbVar9 + 8;
      puVar6[3] = (int)(short)((ushort)pbVar11[6] << 8) | (uint)pbVar11[7];
      pbVar11 = pbVar11 + 8;
    }
    uVar12 = 0x10000;
    uVar8 = 0x10000;
    local_14 = 0;
    local_10 = 0;
    if (local_20 == 0) {
      if ((uVar2 & 0x40) == 0) {
        if (-1 < (char)uVar2) goto LAB_008eb118;
        uVar8 = (int)(short)((ushort)*pbVar11 << 8) | (uint)pbVar11[1];
        local_14 = ((int)(short)((ushort)pbVar11[2] << 8) | (uint)pbVar11[3]) * 4;
        local_10 = ((int)(short)((ushort)pbVar11[4] << 8) | (uint)pbVar11[5]) * 4;
        pbVar11 = pbVar11 + 8;
        pbVar9 = pbVar9 + 8;
      }
      else {
        uVar8 = (int)(short)((ushort)*pbVar11 << 8) | (uint)pbVar11[1];
        pbVar11 = pbVar11 + 4;
        pbVar9 = pbVar9 + 4;
      }
      uVar8 = uVar8 * 4;
      uVar12 = ((int)(short)((ushort)pbVar11[-2] << 8) | (uint)pbVar11[-1]) * 4;
    }
    else {
      bVar1 = *pbVar11;
      pbVar10 = pbVar11 + 1;
      pbVar11 = pbVar11 + 2;
      pbVar9 = pbVar9 + 2;
      uVar8 = ((int)(short)((ushort)bVar1 << 8) | (uint)*pbVar10) * 4;
      uVar12 = uVar8;
    }
LAB_008eb118:
    local_8 = local_8 + 0x20;
    puVar6[4] = uVar8;
    puVar6[5] = local_10;
    puVar6[6] = local_14;
    puVar6[7] = uVar12;
    if ((uVar2 & 0x20) == 0) {
      *(int *)(iVar7 + 0x54) = iVar4;
      iVar7 = FUN_008b9850(*(undefined4 *)(param_1 + 0x18));
      *(byte **)(param_1 + 0xa8) = pbVar11 + (iVar7 - (int)pbVar3);
      *(byte **)(param_1 + 200) = pbVar11;
      return 0;
    }
  } while( true );
}

