
int FUN_008dc090(undefined4 param_1,undefined4 *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  int iVar7;
  undefined4 uVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  byte *pbVar12;
  char *pcVar13;
  bool bVar14;
  
  *param_2 = 1;
  if (param_2[0x22] == 0) {
    iVar7 = FUN_008b8fc0(*(undefined4 *)(param_2[0x18] + 4),"psaux");
    if (iVar7 == 0) {
      return 0xb;
    }
    param_2[0x22] = iVar7;
  }
  if (param_2[0x50] == 0) {
    uVar8 = FUN_008b8fc0(*(undefined4 *)(param_2[0x18] + 4),"pshinter");
    param_2[0x50] = uVar8;
  }
  iVar7 = FUN_008b97e0(param_1,0);
  if (iVar7 != 0) {
    return iVar7;
  }
  iVar7 = FUN_008dbca0(param_2,param_3);
  if (iVar7 != 0) {
    return iVar7;
  }
  if (param_3 < 0) {
    return 0;
  }
  if (param_3 != 0) {
    return 6;
  }
  param_2[2] = param_2[2] | 0x811;
  param_2[4] = param_2[0x4a];
  param_2[9] = 0;
  param_2[1] = 0;
  if (*(char *)(param_2 + 0x2f) != '\0') {
    param_2[2] = param_2[2] | 4;
  }
  pcVar13 = (char *)param_2[0x2c];
  param_2[5] = pcVar13;
  param_2[6] = "Regular";
  if (pcVar13 == (char *)0x0) {
    if (param_2[0x23] != 0) {
      param_2[5] = param_2[0x23];
    }
  }
  else {
    pcVar11 = (char *)param_2[0x2b];
    if (pcVar11 != (char *)0x0) {
      cVar1 = *pcVar11;
      while (cVar1 != '\0') {
        cVar2 = *pcVar13;
        if (cVar1 == cVar2) {
          pcVar13 = pcVar13 + 1;
LAB_008dc187:
          pcVar11 = pcVar11 + 1;
        }
        else {
          if ((cVar1 == ' ') || (cVar1 == '-')) goto LAB_008dc187;
          if ((cVar2 != ' ') && (cVar2 != '-')) {
            if (*pcVar13 == '\0') {
              param_2[6] = pcVar11;
            }
            break;
          }
          pcVar13 = pcVar13 + 1;
        }
        cVar1 = *pcVar11;
      }
    }
  }
  param_2[3] = 0;
  if (param_2[0x2e] != 0) {
    param_2[3] = 1;
  }
  pbVar10 = (byte *)param_2[0x2d];
  if (pbVar10 != (byte *)0x0) {
    pbVar12 = &DAT_00c4651c;
    pbVar9 = pbVar10;
    do {
      bVar3 = *pbVar9;
      bVar14 = bVar3 < *pbVar12;
      if (bVar3 != *pbVar12) {
LAB_008dc200:
        iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        goto LAB_008dc205;
      }
      if (bVar3 == 0) break;
      bVar3 = pbVar9[1];
      bVar14 = bVar3 < pbVar12[1];
      if (bVar3 != pbVar12[1]) goto LAB_008dc200;
      pbVar9 = pbVar9 + 2;
      pbVar12 = pbVar12 + 2;
    } while (bVar3 != 0);
    iVar7 = 0;
LAB_008dc205:
    if (iVar7 != 0) {
      pcVar13 = "Black";
      do {
        bVar3 = *pbVar10;
        bVar14 = bVar3 < (byte)*pcVar13;
        if (bVar3 != *pcVar13) {
LAB_008dc230:
          iVar7 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
          goto LAB_008dc235;
        }
        if (bVar3 == 0) break;
        bVar3 = pbVar10[1];
        bVar14 = bVar3 < (byte)pcVar13[1];
        if (bVar3 != pcVar13[1]) goto LAB_008dc230;
        pbVar10 = pbVar10 + 2;
        pcVar13 = pcVar13 + 2;
      } while (bVar3 != 0);
      iVar7 = 0;
LAB_008dc235:
      if (iVar7 != 0) goto LAB_008dc23d;
    }
    param_2[3] = param_2[3] | 2;
  }
LAB_008dc23d:
  param_2[7] = 0;
  param_2[8] = 0;
  param_2[0xd] = (int)*(short *)((int)param_2 + 0xc6);
  param_2[0xe] = (int)*(short *)((int)param_2 + 0xca);
  param_2[0xf] = param_2[0x33] + 0xffff >> 0x10;
  param_2[0x10] = param_2[0x34] + 0xffff >> 0x10;
  if (*(short *)(param_2 + 0x11) == 0) {
    *(undefined2 *)(param_2 + 0x11) = 1000;
  }
  sVar4 = *(short *)(param_2 + 0xe);
  sVar6 = (short)(((uint)*(ushort *)(param_2 + 0x11) * 0xc) / 10);
  sVar5 = (short)((uint)(param_2[0x34] + 0xffff) >> 0x10);
  *(short *)((int)param_2 + 0x4a) = sVar6;
  *(short *)((int)param_2 + 0x46) = sVar5;
  *(short *)(param_2 + 0x12) = sVar4;
  if ((int)sVar6 < (int)sVar5 - (int)sVar4) {
    *(short *)((int)param_2 + 0x4a) = sVar5 - sVar4;
  }
  *(undefined2 *)(param_2 + 0x14) = *(undefined2 *)((int)param_2 + 0xbe);
  *(undefined2 *)((int)param_2 + 0x52) = *(undefined2 *)(param_2 + 0x30);
  return 0;
}

