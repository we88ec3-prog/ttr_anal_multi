
int FUN_008f5160(void)

{
  uint uVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  bool bVar5;
  int in_EAX;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  undefined4 *in_ECX;
  int iVar10;
  short *psVar11;
  byte *pbVar12;
  byte *pbVar13;
  undefined4 *puVar14;
  byte *pbVar15;
  undefined4 local_64 [8];
  undefined4 local_44;
  byte *local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  int local_20;
  undefined4 *local_1c;
  byte *local_10;
  int local_c;
  char local_5;
  
  local_30 = *in_ECX;
  piVar2 = in_ECX + in_EAX * 7 + 0xb;
  local_1c = (undefined4 *)in_ECX[10];
  pbVar13 = (byte *)0x0;
  local_2c = local_1c + in_ECX[9];
  local_10 = (byte *)0x0;
  _memset(local_64,0,0x30);
  iVar6 = piVar2[6];
  local_44 = 32000;
  local_64[0]._0_1_ = 0;
  if (iVar6 < 0) {
    iVar6 = -iVar6;
  }
  *piVar2 = 0;
  uVar7 = in_ECX[7];
  uVar1 = uVar7 + in_ECX[6] * 0x28;
  if (in_EAX == 0) {
    for (; uVar7 < uVar1; uVar7 = uVar7 + 0x28) {
      *(int *)(uVar7 + 0x18) = (int)*(short *)(uVar7 + 0xc);
      *(int *)(uVar7 + 0x1c) = (int)*(short *)(uVar7 + 0xe);
    }
  }
  else {
    for (; uVar7 < uVar1; uVar7 = uVar7 + 0x28) {
      *(int *)(uVar7 + 0x18) = (int)*(short *)(uVar7 + 0xe);
      *(int *)(uVar7 + 0x1c) = (int)*(short *)(uVar7 + 0xc);
    }
  }
  local_20 = iVar6;
  if (local_1c < local_2c) {
    do {
      pbVar15 = (byte *)*local_1c;
      bVar5 = false;
      local_c = 32000;
      iVar10 = -32000;
      if (pbVar15 != *(byte **)(pbVar15 + 0x24)) {
        bVar3 = (*(byte **)(pbVar15 + 0x24))[3];
        iVar8 = (int)(char)bVar3;
        if ((char)bVar3 < '\0') {
          iVar8 = -iVar8;
        }
        pbVar12 = pbVar15;
        if (iVar8 == iVar6) {
          iVar8 = (int)(char)pbVar15[3];
          if ((char)pbVar15[3] < '\0') {
            iVar8 = -iVar8;
          }
          if (iVar8 == iVar6) {
            do {
              pbVar12 = *(byte **)(pbVar12 + 0x24);
              iVar8 = (int)(char)pbVar12[3];
              if ((char)pbVar12[3] < '\0') {
                iVar8 = -iVar8;
              }
              if (iVar8 != iVar6) {
                pbVar12 = *(byte **)(pbVar12 + 0x20);
                break;
              }
            } while (pbVar12 != pbVar15);
          }
        }
        local_5 = '\0';
        pbVar15 = pbVar12;
        local_34 = pbVar12;
        do {
          if (bVar5) {
            iVar8 = *(int *)(pbVar12 + 0x18);
            if (iVar8 < local_c) {
              local_c = iVar8;
            }
            if (iVar10 < iVar8) {
              iVar10 = iVar8;
            }
            if (((char)pbVar12[3] != local_20) || (pbVar12 == pbVar15)) {
              *(byte **)(pbVar13 + 0x2c) = pbVar12;
              *(short *)(pbVar13 + 2) = (short)(iVar10 + local_c >> 1);
              if (((**(byte **)(pbVar13 + 0x28) | *pbVar12) & 3) != 0) {
                *pbVar13 = *pbVar13 | 1;
              }
              iVar10 = *(int *)(pbVar12 + 0x1c);
              iVar8 = *(int *)(*(int *)(pbVar13 + 0x28) + 0x1c);
              local_c = iVar10;
              if (iVar8 < iVar10) {
                local_c = iVar8;
              }
              if (iVar10 < iVar8) {
                iVar10 = iVar8;
              }
              *(undefined2 *)(pbVar13 + 4) = (undefined2)local_c;
              *(short *)(pbVar13 + 6) = (short)iVar10;
              *(short *)(pbVar13 + 8) = (short)iVar10 - *(short *)(pbVar13 + 4);
              bVar5 = false;
              local_10 = (byte *)0x0;
              pbVar13 = (byte *)0x0;
              goto LAB_008f530c;
            }
          }
          else {
LAB_008f530c:
            if (pbVar12 == pbVar15) {
              if (local_5 != '\0') break;
              local_5 = '\x01';
            }
          }
          if (!bVar5) {
            bVar3 = pbVar12[3];
            iVar9 = (int)(char)bVar3;
            iVar8 = iVar9;
            if ((char)bVar3 < '\0') {
              iVar8 = -iVar9;
            }
            if (iVar8 == iVar6) {
              iVar10 = FUN_008f40d0(local_30,&local_10);
              if (iVar10 != 0) {
                return iVar10;
              }
              puVar14 = local_64;
              pbVar13 = local_10;
              for (iVar10 = 0xc; iVar10 != 0; iVar10 = iVar10 + -1) {
                *(undefined4 *)pbVar13 = *puVar14;
                puVar14 = puVar14 + 1;
                pbVar13 = pbVar13 + 4;
              }
              local_10[1] = bVar3;
              iVar10 = *(int *)(pbVar12 + 0x18);
              *(byte **)(local_10 + 0x28) = pbVar12;
              *(byte **)(local_10 + 0x2c) = pbVar12;
              bVar5 = true;
              pbVar13 = local_10;
              pbVar15 = local_34;
              local_20 = iVar9;
              local_c = iVar10;
            }
          }
          pbVar12 = *(byte **)(pbVar12 + 0x20);
        } while( true );
      }
      local_1c = local_1c + 1;
    } while (local_1c < local_2c);
  }
  uVar1 = piVar2[2];
  uVar7 = *piVar2 * 0x30 + uVar1;
  if (uVar1 < uVar7) {
    psVar11 = (short *)(uVar1 + 8);
    iVar6 = ((uVar7 - uVar1) - 1) / 0x30 + 1;
    do {
      iVar10 = *(int *)(psVar11 + 0x10);
      iVar8 = *(int *)(psVar11 + 0x12);
      iVar9 = *(int *)(iVar10 + 0x1c);
      iVar4 = *(int *)(iVar8 + 0x1c);
      if (iVar10 != iVar8) {
        iVar10 = *(int *)(*(int *)(iVar10 + 0x24) + 0x1c);
        if (iVar9 < iVar4) {
          if (iVar10 < iVar9) {
            *psVar11 = *psVar11 + (short)(iVar9 - iVar10 >> 1);
          }
          iVar10 = *(int *)(*(int *)(iVar8 + 0x20) + 0x1c);
          if (iVar4 < iVar10) {
            *psVar11 = *psVar11 + (short)(iVar10 - iVar4 >> 1);
          }
        }
        else {
          if (iVar9 < iVar10) {
            *psVar11 = *psVar11 + (short)(iVar10 - iVar9 >> 1);
          }
          iVar10 = *(int *)(*(int *)(iVar8 + 0x20) + 0x1c);
          if (iVar10 < iVar4) {
            *psVar11 = *psVar11 + (short)(iVar4 - iVar10 >> 1);
          }
        }
      }
      psVar11 = psVar11 + 0x18;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  return 0;
}

