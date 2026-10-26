
undefined4 FUN_008c8e90(uint param_1,byte *param_2,byte *param_3,uint param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  sbyte sVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  
  piVar1 = *(int **)(param_1 + 8);
  pbVar9 = (byte *)(param_1 + 0x12);
  iVar2 = piVar1[2];
  uVar8 = (uint)(*(ushort **)(param_1 + 0xc))[1];
  param_1 = (uint)**(ushort **)(param_1 + 0xc);
  uVar3 = *pbVar9 * uVar8;
  if ((((-1 < (int)param_4) && ((int)(uVar8 + param_4) <= piVar1[1])) && (-1 < param_5)) &&
     (((int)(param_5 + param_1) <= *piVar1 &&
      (param_2 + ((int)(uVar3 + 7) >> 3) * param_1 <= param_3)))) {
    pbVar9 = (byte *)(iVar2 * param_5 + piVar1[3] + ((int)param_4 >> 3));
    param_4 = param_4 & 7;
    if (param_4 == 0) {
      if (param_1 != 0) {
        do {
          pbVar5 = pbVar9;
          param_4 = uVar3;
          if (7 < uVar3) {
            uVar8 = uVar3 >> 3;
            param_4 = uVar3 + uVar8 * -8;
            do {
              *pbVar5 = *pbVar5 | *param_2;
              param_2 = param_2 + 1;
              pbVar5 = pbVar5 + 1;
              uVar8 = uVar8 - 1;
            } while (uVar8 != 0);
          }
          if (0 < (int)param_4) {
            *pbVar5 = *pbVar5 | (byte)(0xff00 >> ((byte)param_4 & 0x1f)) & *param_2;
            param_2 = param_2 + 1;
          }
          pbVar9 = pbVar9 + iVar2;
          param_1 = param_1 - 1;
        } while (0 < (int)param_1);
        return 0;
      }
    }
    else if (param_1 != 0) {
      do {
        uVar10 = 0;
        sVar4 = (sbyte)param_4;
        uVar8 = uVar3;
        pbVar5 = pbVar9;
        if (7 < uVar3) {
          uVar7 = uVar3 >> 3;
          uVar8 = uVar3 + uVar7 * -8;
          pbVar6 = pbVar9;
          do {
            uVar11 = uVar10 | *param_2;
            param_2 = param_2 + 1;
            pbVar5 = pbVar6 + 1;
            uVar10 = uVar11 << 8;
            *pbVar6 = *pbVar6 | (byte)(uVar11 >> sVar4);
            uVar7 = uVar7 - 1;
            pbVar6 = pbVar5;
          } while (uVar7 != 0);
        }
        if (0 < (int)uVar8) {
          uVar10 = uVar10 | 0xff00U >> ((byte)uVar8 & 0x1f) & (uint)*param_2;
          param_2 = param_2 + 1;
        }
        *pbVar5 = *pbVar5 | (byte)(uVar10 >> sVar4);
        if (8 < (int)(uVar8 + param_4)) {
          pbVar5[1] = pbVar5[1] | (byte)((uVar10 << 8) >> sVar4);
        }
        pbVar9 = pbVar9 + iVar2;
        param_1 = param_1 - 1;
      } while (0 < (int)param_1);
    }
    return 0;
  }
  return 3;
}

