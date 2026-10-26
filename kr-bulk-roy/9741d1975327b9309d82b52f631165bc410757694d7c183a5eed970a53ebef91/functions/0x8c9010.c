
undefined4 FUN_008c9010(uint param_1,byte *param_2,byte *param_3,uint param_4,int param_5)

{
  ushort uVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  uint uVar8;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  uint local_18;
  uint local_14;
  uint local_8;
  
  piVar3 = *(int **)(param_1 + 8);
  iVar4 = piVar3[2];
  uVar8 = (uint)**(ushort **)(param_1 + 0xc);
  uVar12 = (uint)(*(ushort **)(param_1 + 0xc))[1];
  uVar5 = *(byte *)(param_1 + 0x12) * uVar12;
  if ((((-1 < (int)param_4) && ((int)(uVar12 + param_4) <= piVar3[1])) && (-1 < param_5)) &&
     (((int)(param_5 + uVar8) <= *piVar3 && (param_2 + ((int)(uVar5 * uVar8 + 7) >> 3) <= param_3)))
     ) {
    pbVar7 = (byte *)(iVar4 * param_5 + piVar3[3] + ((int)param_4 >> 3));
    param_4 = param_4 & 7;
    uVar13 = 0;
    uVar12 = 0;
    param_1 = 0;
    local_14 = uVar8;
    if (uVar8 != 0) {
      do {
        local_8 = uVar5;
        pbVar11 = pbVar7;
        if (param_4 != 0) {
          uVar9 = uVar5;
          if ((int)(8 - param_4) <= (int)uVar5) {
            uVar9 = 8 - param_4;
          }
          if (local_14 == uVar8) {
            bVar2 = *param_2;
            param_2 = param_2 + 1;
            uVar12 = param_4;
            param_1 = (uint)bVar2;
          }
          else if ((int)uVar12 < (int)uVar9) {
            if (param_2 < param_3) {
              param_1 = (uint)(ushort)((ushort)param_1 | *param_2);
              param_2 = param_2 + 1;
              uVar13 = param_1;
            }
            uVar12 = uVar12 + (8 - uVar9);
            param_1 = uVar13;
          }
          else {
            param_1 = (uint)((ushort)param_1 >> 8);
            uVar12 = uVar12 - uVar9;
          }
          uVar13 = param_1 << 8;
          *pbVar7 = *pbVar7 | ~(-1 << ((byte)uVar9 & 0x1f)) <<
                              (((char)-uVar9 - (char)param_4) + 8U & 0x1f) &
                              (byte)((ushort)param_1 >> ((byte)uVar12 & 0x1f));
          local_8 = uVar5 + -uVar9;
          pbVar11 = pbVar7 + 1;
          param_1 = uVar13;
        }
        bVar2 = (byte)uVar12;
        if (7 < (int)local_8) {
          local_18 = local_8 >> 3;
          local_8 = local_8 + local_18 * -8;
          pbVar10 = pbVar11;
          do {
            uVar1 = (ushort)param_1 | *param_2;
            param_1 = (uint)uVar1;
            param_2 = param_2 + 1;
            uVar13 = param_1 << 8;
            pbVar11 = pbVar10 + 1;
            *pbVar10 = *pbVar10 | (byte)(uVar1 >> (bVar2 & 0x1f));
            local_18 = local_18 - 1;
            pbVar10 = pbVar11;
            param_1 = uVar13;
          } while (local_18 != 0);
        }
        if (0 < (int)local_8) {
          if ((int)uVar12 < (int)local_8) {
            if (param_2 < param_3) {
              param_1 = (uint)(ushort)((ushort)param_1 | *param_2);
              param_2 = param_2 + 1;
              uVar13 = param_1;
            }
            iVar6 = 8 - local_8;
            *pbVar11 = *pbVar11 |
                       (byte)((ushort)uVar13 >> (bVar2 & 0x1f)) &
                       (byte)(0xff00 >> ((byte)local_8 & 0x1f));
            uVar13 = uVar13 << 8;
            param_1 = uVar13;
          }
          else {
            *pbVar11 = *pbVar11 |
                       (byte)((ushort)uVar13 >> (bVar2 & 0x1f)) &
                       (byte)(0xff00 >> ((byte)local_8 & 0x1f));
            iVar6 = -local_8;
          }
          uVar12 = uVar12 + iVar6;
        }
        pbVar7 = pbVar7 + iVar4;
        local_14 = local_14 - 1;
      } while (0 < (int)local_14);
    }
    return 0;
  }
  return 3;
}

