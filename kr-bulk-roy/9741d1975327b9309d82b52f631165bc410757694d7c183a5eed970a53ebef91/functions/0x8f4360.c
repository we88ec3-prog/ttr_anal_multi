
int FUN_008f4360(ushort *param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  ushort *puVar8;
  longlong lVar9;
  ushort *puVar10;
  undefined4 *in_EAX;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  uint uVar15;
  undefined4 *puVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  short *psVar20;
  ushort *puVar21;
  ushort *puVar22;
  short sVar23;
  ushort *puVar24;
  ushort *local_34;
  int local_30;
  char local_18;
  ushort *local_10;
  uint local_c;
  int local_8;
  
  iVar18 = in_EAX[1];
  iVar4 = in_EAX[3];
  iVar5 = in_EAX[2];
  iVar6 = in_EAX[4];
  uVar13 = *in_EAX;
  in_EAX[6] = 0;
  in_EAX[9] = 0;
  in_EAX[0xb] = 0;
  in_EAX[0xe] = 0;
  in_EAX[0x12] = 0;
  in_EAX[0x15] = 0;
  local_8 = 0;
  if ((uint)in_EAX[8] < (uint)(int)(short)*param_1) {
    uVar11 = (int)(short)*param_1 + 3U & 0xfffffffc;
    uVar12 = FUN_008bc7d0(uVar13,4,in_EAX[8],uVar11,in_EAX[10],&local_8);
    in_EAX[10] = uVar12;
    if (local_8 != 0) {
      return local_8;
    }
    in_EAX[8] = uVar11;
  }
  if ((uint)in_EAX[5] < (int)(short)param_1[1] + 2U) {
    uVar11 = (int)(short)param_1[1] + 0xbU & 0xfffffff8;
    uVar13 = FUN_008bc7d0(uVar13,0x28,in_EAX[5],uVar11,in_EAX[7],&local_8);
    in_EAX[7] = uVar13;
    if (local_8 != 0) {
      return local_8;
    }
    in_EAX[5] = uVar11;
  }
  in_EAX[6] = (int)(short)param_1[1];
  in_EAX[9] = (int)(short)*param_1;
  in_EAX[0x11] = 2;
  in_EAX[0x18] = 0xffffffff;
  iVar14 = FUN_008b95b0(param_1);
  if (iVar14 == 1) {
    in_EAX[0x11] = 0xfffffffe;
    in_EAX[0x18] = 1;
  }
  in_EAX[1] = iVar18;
  in_EAX[4] = iVar6;
  in_EAX[2] = iVar5;
  puVar22 = (ushort *)in_EAX[7];
  in_EAX[3] = iVar4;
  in_EAX[0x1c] = 0;
  in_EAX[0x1d] = 0;
  if (in_EAX[6] != 0) {
    puVar21 = *(ushort **)(param_1 + 2);
    pbVar7 = *(byte **)(param_1 + 4);
    puVar1 = puVar22 + in_EAX[6] * 0x14;
    local_34 = puVar22 + **(short **)(param_1 + 6) * 0x14;
    local_30 = 0;
    local_10 = local_34;
    for (puVar24 = puVar22; puVar24 < puVar1; puVar24 = puVar24 + 0x14) {
      puVar24[6] = *puVar21;
      puVar24[7] = puVar21[2];
      lVar9 = (longlong)*(int *)puVar21 * (longlong)iVar18;
      lVar9 = lVar9 + (ulonglong)((int)(lVar9 >> 0x3f) + 0x8000);
      iVar14 = iVar5 + ((uint)lVar9 >> 0x10) + (int)((ulonglong)lVar9 >> 0x20) * 0x10000;
      *(int *)(puVar24 + 8) = iVar14;
      *(int *)(puVar24 + 2) = iVar14;
      lVar9 = (longlong)*(int *)(puVar21 + 2) * (longlong)iVar4;
      lVar9 = lVar9 + (ulonglong)((int)(lVar9 >> 0x3f) + 0x8000);
      iVar14 = iVar6 + ((uint)lVar9 >> 0x10) + (int)((ulonglong)lVar9 >> 0x20) * 0x10000;
      *(int *)(puVar24 + 10) = iVar14;
      *(int *)(puVar24 + 4) = iVar14;
      if ((*pbVar7 & 3) == 0) {
        *puVar24 = 1;
      }
      else if ((*pbVar7 & 3) == 2) {
        *puVar24 = 2;
      }
      else {
        *puVar24 = 0;
      }
      *(ushort **)(puVar24 + 0x12) = local_10;
      *(ushort **)(local_10 + 0x10) = puVar24;
      local_10 = puVar24;
      if ((puVar24 == local_34) && (local_30 = local_30 + 1, local_30 < (short)*param_1)) {
        local_34 = puVar22 + *(short *)(*(int *)(param_1 + 6) + local_30 * 2) * 0x14;
        local_10 = local_34;
      }
      pbVar7 = pbVar7 + 1;
      puVar21 = puVar21 + 4;
    }
    puVar16 = (undefined4 *)in_EAX[10];
    psVar20 = *(short **)(param_1 + 6);
    puVar2 = puVar16 + in_EAX[9];
    sVar23 = 0;
    for (; puVar16 < puVar2; puVar16 = puVar16 + 1) {
      *puVar16 = puVar22 + sVar23 * 0x14;
      sVar23 = *psVar20 + 1;
      psVar20 = psVar20 + 1;
    }
    local_10 = (ushort *)0x0;
    local_c = 0;
    uVar17 = (uint)*(ushort *)(*(int *)(in_EAX[0x1b] + 4) + 0x44) * 0x14 >> 0xb;
    local_18 = '\x04';
    param_1 = puVar22;
    puVar21 = (ushort *)0;
    uVar11 = 0;
    for (; puVar22 < puVar1; puVar22 = puVar22 + 0x14) {
      if (puVar22 == param_1) {
        puVar24 = *(ushort **)(param_1 + 0x12);
        uVar11 = (int)(short)param_1[7] - (int)(short)puVar24[7];
        puVar21 = (ushort *)((int)(short)param_1[6] - (int)(short)puVar24[6]);
        iVar18 = ((uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f)) +
                 (((uint)puVar21 ^ (int)puVar21 >> 0x1f) - ((int)puVar21 >> 0x1f));
        puVar10 = puVar24;
        local_c = uVar11;
        local_10 = puVar21;
        while ((iVar18 < (int)uVar17 && (local_10 = puVar21, local_c = uVar11, puVar10 != param_1)))
        {
          puVar8 = *(ushort **)(puVar10 + 0x12);
          local_10 = (ushort *)((int)(short)puVar10[6] - (int)(short)puVar8[6]);
          local_c = (int)(short)puVar10[7] - (int)(short)puVar8[7];
          iVar18 = ((local_c ^ (int)local_c >> 0x1f) - ((int)local_c >> 0x1f)) +
                   (((uint)local_10 ^ (int)local_10 >> 0x1f) - ((int)local_10 >> 0x1f));
          puVar10 = puVar8;
        }
        local_18 = FUN_008f4240();
        param_1 = puVar24 + 0x14;
      }
      *(char *)(puVar22 + 1) = local_18;
      puVar24 = puVar21;
      uVar15 = uVar11;
      if ((int)(((uVar11 ^ (int)uVar11 >> 0x1f) - ((int)uVar11 >> 0x1f)) +
               (((uint)puVar21 ^ (int)puVar21 >> 0x1f) - ((int)puVar21 >> 0x1f))) < (int)uVar17) {
        *puVar22 = *puVar22 | 0x400;
        puVar24 = local_10;
        uVar15 = local_c;
      }
      local_c = uVar15;
      local_10 = puVar24;
      uVar19 = (int)*(short *)(*(int *)(puVar22 + 0x10) + 0xc) - (int)(short)puVar22[6];
      uVar15 = (int)*(short *)(*(int *)(puVar22 + 0x10) + 0xe) - (int)(short)puVar22[7];
      local_18 = FUN_008f4240();
      uVar3 = *puVar22;
      *(char *)((int)puVar22 + 3) = local_18;
      if ((uVar3 & 3) == 0) {
        if (local_18 == (char)puVar22[1]) {
          if (local_18 == '\x04') {
            if ((uVar3 & 0x400) != 0) {
              uVar11 = local_c;
            }
            if ((uVar3 & 0x400) != 0) {
              puVar21 = local_10;
            }
            iVar18 = FUN_008b8270(puVar21,uVar11,uVar19,uVar15);
            if (iVar18 == 0) goto LAB_008f4773;
          }
          goto LAB_008f476b;
        }
        if ((int)(char)puVar22[1] == -(int)local_18) goto LAB_008f476b;
      }
      else {
LAB_008f476b:
        *puVar22 = *puVar22 | 0x100;
      }
LAB_008f4773:
      puVar21 = (ushort *)uVar19;
      uVar11 = uVar15;
    }
  }
  return local_8;
}

