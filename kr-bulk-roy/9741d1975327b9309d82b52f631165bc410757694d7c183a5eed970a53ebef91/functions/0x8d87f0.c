
int FUN_008d87f0(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  undefined1 *puVar3;
  short sVar4;
  int in_EAX;
  byte *pbVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  uint uVar13;
  byte *pbVar14;
  byte *pbVar15;
  undefined4 *unaff_EDI;
  byte *local_c;
  int local_8;
  
  uVar7 = *(undefined4 *)(param_1 + 0x1c);
  *unaff_EDI = uVar7;
  unaff_EDI[1] = param_2;
  unaff_EDI[0x22] = 0;
  unaff_EDI[0x23] = unaff_EDI + 0x22;
  local_8 = FUN_008b97e0(param_1,param_2);
  if (local_8 != 0) {
    return local_8;
  }
  local_8 = FUN_008babe0(param_1);
  if (local_8 != 0) {
    return local_8;
  }
  unaff_EDI[0x25] = *(undefined4 *)(param_1 + 0x20);
  puVar3 = *(undefined1 **)(param_1 + 0x20);
  pbVar12 = puVar3 + in_EAX;
  pbVar15 = local_c;
  if (puVar3 + 0xf <= pbVar12) {
    unaff_EDI[2] = (uint)CONCAT11(*puVar3,puVar3[1]);
    unaff_EDI[3] = (uint)CONCAT11(puVar3[2],puVar3[3]);
    unaff_EDI[4] = (uint)CONCAT11(puVar3[4],puVar3[5]);
    unaff_EDI[5] = (int)(short)((ushort)(byte)puVar3[6] << 8) | (uint)(byte)puVar3[7];
    unaff_EDI[6] = (int)(short)((ushort)(byte)puVar3[8] << 8) | (uint)(byte)puVar3[9];
    unaff_EDI[7] = (int)(short)((ushort)(byte)puVar3[10] << 8) | (uint)(byte)puVar3[0xb];
    unaff_EDI[8] = (int)(short)((ushort)(byte)puVar3[0xc] << 8) | (uint)(byte)puVar3[0xd];
    bVar1 = puVar3[0xe];
    unaff_EDI[9] = (uint)bVar1;
    local_c = puVar3 + 0xf;
    if ((bVar1 & 4) == 0) {
      local_c = puVar3 + 0x11;
      pbVar15 = puVar3 + 0xf;
      if (pbVar12 < local_c) goto LAB_008d8b9a;
      unaff_EDI[10] = (int)(short)((ushort)(byte)puVar3[0xf] << 8) | (uint)(byte)puVar3[0x10];
    }
    iVar8 = 0;
    if (((char)bVar1 < '\0') &&
       (local_8 = FUN_008d80f0(&local_c,pbVar12), iVar8 = local_8, local_8 != 0)) goto LAB_008d8c60;
    local_8 = iVar8;
    pbVar5 = local_c + 3;
    pbVar15 = local_c;
    if (pbVar5 <= pbVar12) {
      uVar10 = (uint)CONCAT21(CONCAT11(*local_c,local_c[1]),local_c[2]);
      if (uVar10 != 0) {
        pbVar14 = pbVar5;
        local_c = pbVar5 + uVar10;
        if (pbVar12 < pbVar5 + uVar10) goto LAB_008d8b9a;
        do {
          pbVar5 = local_c;
          if (((local_c < pbVar14 + 4) || (uVar13 = (uint)CONCAT11(*pbVar14,pbVar14[1]), uVar13 < 4)
              ) || (uVar10 < uVar13)) break;
          sVar4 = CONCAT11(pbVar14[2],pbVar14[3]);
          if (sVar4 == 1) {
            puVar11 = unaff_EDI + 0x15;
LAB_008d8a28:
            local_8 = FUN_008d86b0(uVar7,puVar11);
            if (local_8 != 0) {
              return local_8;
            }
          }
          else if (sVar4 == 2) {
            if (pbVar14 + 0x24 <= pbVar14 + uVar13) {
              unaff_EDI[0xb] = (int)(short)((ushort)pbVar14[0xe] << 8) | (uint)pbVar14[0xf];
              unaff_EDI[0xc] = (int)(short)((ushort)pbVar14[0x10] << 8) | (uint)pbVar14[0x11];
              unaff_EDI[0xd] = (int)(short)((ushort)pbVar14[0x12] << 8) | (uint)pbVar14[0x13];
            }
          }
          else if (sVar4 == 3) {
            puVar11 = unaff_EDI + 0x16;
            goto LAB_008d8a28;
          }
          uVar10 = uVar10 - uVar13;
          pbVar14 = pbVar14 + uVar13;
          pbVar5 = local_c;
        } while (uVar10 != 0);
      }
      pbVar14 = pbVar5 + 1;
      pbVar15 = local_c;
      if (pbVar14 <= pbVar12) {
        uVar10 = (uint)*pbVar5;
        unaff_EDI[0x1a] = uVar10;
        if (pbVar14 + uVar10 * 2 <= pbVar12) {
          uVar6 = FUN_008bc7d0(uVar7,4,0,uVar10,0,&local_8);
          unaff_EDI[0x1b] = uVar6;
          if (local_8 != 0) goto LAB_008d8c60;
          uVar13 = 0;
          pbVar15 = pbVar14;
          if (uVar10 != 0) {
            do {
              pbVar14 = pbVar15 + 2;
              *(uint *)(unaff_EDI[0x1b] + uVar13 * 4) =
                   (int)(short)((ushort)*pbVar15 << 8) | (uint)pbVar15[1];
              uVar13 = uVar13 + 1;
              pbVar15 = pbVar14;
            } while (uVar13 < uVar10);
          }
          pbVar15 = local_c;
          if (pbVar14 + 8 <= pbVar12) {
            unaff_EDI[0x1c] = (uint)*pbVar14;
            unaff_EDI[0x1d] = (uint)pbVar14[1];
            unaff_EDI[0x11] = (uint)CONCAT11(pbVar14[2],pbVar14[3]);
            unaff_EDI[0xe] = (uint)CONCAT11(pbVar14[4],pbVar14[5]);
            pbVar5 = pbVar14 + 8;
            uVar10 = (uint)CONCAT11(pbVar14[6],pbVar14[7]);
            unaff_EDI[0x1e] = uVar10;
            unaff_EDI[0x1f] = pbVar5 + (param_2 - *(int *)(param_1 + 0x20));
            uVar7 = FUN_008bc7d0(uVar7,0x10,0,uVar10,0,&local_8);
            unaff_EDI[0x20] = uVar7;
            if (local_8 != 0) goto LAB_008d8c60;
            iVar8 = 4;
            if ((bVar1 & 2) != 0) {
              iVar8 = 5;
            }
            if ((bVar1 & 4) != 0) {
              iVar8 = iVar8 + 2;
            }
            if ((bVar1 & 8) != 0) {
              iVar8 = iVar8 + 1;
            }
            if ((bVar1 & 0x10) != 0) {
              iVar8 = iVar8 + 1;
            }
            if ((bVar1 & 0x20) != 0) {
              iVar8 = iVar8 + 1;
            }
            pbVar15 = local_c;
            if (pbVar5 + iVar8 * uVar10 <= pbVar12) {
              if (uVar10 != 0) {
                iVar8 = 0;
                param_2 = uVar10;
                do {
                  puVar9 = (uint *)(unaff_EDI[0x20] + iVar8);
                  if ((bVar1 & 2) == 0) {
                    uVar10 = (uint)*pbVar5;
                    pbVar15 = pbVar5 + 1;
                  }
                  else {
                    pbVar15 = pbVar5 + 2;
                    uVar10 = (uint)CONCAT11(*pbVar5,pbVar5[1]);
                  }
                  *puVar9 = uVar10;
                  if ((bVar1 & 4) == 0) {
                    uVar10 = unaff_EDI[10];
                  }
                  else {
                    bVar2 = *pbVar15;
                    pbVar12 = pbVar15 + 1;
                    pbVar15 = pbVar15 + 2;
                    uVar10 = (int)(short)((ushort)bVar2 << 8) | (uint)*pbVar12;
                  }
                  puVar9[1] = uVar10;
                  if ((bVar1 & 8) != 0) {
                    pbVar15 = pbVar15 + 1;
                  }
                  if ((bVar1 & 0x10) == 0) {
                    uVar10 = (uint)*pbVar15;
                    pbVar12 = pbVar15 + 1;
                  }
                  else {
                    pbVar12 = pbVar15 + 2;
                    uVar10 = (uint)CONCAT11(*pbVar15,pbVar15[1]);
                  }
                  puVar9[2] = uVar10;
                  if ((bVar1 & 0x20) == 0) {
                    pbVar5 = pbVar12 + 2;
                    uVar10 = (uint)*pbVar12;
                  }
                  else {
                    pbVar5 = pbVar12 + 3;
                    uVar10 = (uint)CONCAT11(*pbVar12,pbVar12[1]);
                  }
                  iVar8 = iVar8 + 0x10;
                  param_2 = param_2 - 1;
                  puVar9[3] = uVar10 << 8 | (uint)pbVar5[-1];
                } while (param_2 != 0);
              }
              goto LAB_008d8c60;
            }
          }
        }
      }
    }
  }
LAB_008d8b9a:
  local_c = pbVar15;
  local_8 = 8;
LAB_008d8c60:
  FUN_008baca0(param_1);
  uVar7 = FUN_008b9850(param_1);
  unaff_EDI[0x24] = uVar7;
  unaff_EDI[0x25] = 0;
  return local_8;
}

