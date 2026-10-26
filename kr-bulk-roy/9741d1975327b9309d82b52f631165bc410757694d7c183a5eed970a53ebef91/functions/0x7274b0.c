
int FUN_007274b0(int *param_1,int param_2)

{
  undefined2 uVar1;
  uint *puVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  uint _Size;
  byte *pbVar10;
  byte *pbVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  undefined1 *local_1c;
  uint local_14;
  undefined4 local_10;
  byte *local_c;
  uint local_8;
  
  if ((((param_1 == (int *)0x0) || (puVar2 = (uint *)param_1[7], puVar2 == (uint *)0x0)) ||
      (param_1[3] == 0)) || ((*param_1 == 0 && (param_1[1] != 0)))) {
    return -2;
  }
  if (*puVar2 == 0xb) {
    *puVar2 = 0xc;
  }
  local_1c = (undefined1 *)param_1[3];
  pbVar10 = (byte *)*param_1;
  local_24 = param_1[4];
  uVar6 = param_1[1];
  uVar13 = puVar2[0xe];
  uVar4 = *puVar2;
  uVar15 = puVar2[0xf];
  local_2c = 0;
  local_c = pbVar10;
  local_14 = local_24;
  local_8 = uVar6;
  do {
    pbVar11 = pbVar10;
    switch(uVar4) {
    case 0:
      if (puVar2[2] == 0) {
        *puVar2 = 0xc;
      }
      else {
        for (; pbVar10 = local_c, uVar15 < 0x10; uVar15 = uVar15 + 8) {
          if (local_8 == 0) goto LAB_007287a1;
          local_8 = local_8 - 1;
          local_c = pbVar11 + 1;
          uVar13 = uVar13 + ((uint)*pbVar11 << ((byte)uVar15 & 0x1f));
          pbVar11 = local_c;
        }
        local_c = pbVar10;
        if (((puVar2[2] & 2) == 0) || (uVar13 != 0x8b1f)) {
          puVar2[4] = 0;
          if (puVar2[8] != 0) {
            *(undefined4 *)(puVar2[8] + 0x30) = 0xffffffff;
          }
          if (((puVar2[2] & 1) == 0) || (((uVar13 & 0xff) * 0x100 + (uVar13 >> 8)) % 0x1f != 0)) {
            param_1[6] = (int)"incorrect header check";
          }
          else if (((byte)uVar13 & 0xf) == 8) {
            uVar4 = (uVar13 >> 4 & 0xf) + 8;
            uVar15 = uVar15 - 4;
            if (uVar4 <= puVar2[9]) {
              puVar2[5] = 1 << (sbyte)uVar4;
              uVar4 = FUN_0072b070(0);
              puVar2[6] = uVar4;
              param_1[0xc] = uVar4;
              *puVar2 = ~(uVar13 >> 0xc) & 2 | 9;
              uVar13 = 0;
              uVar15 = 0;
              break;
            }
            param_1[6] = (int)"invalid window size";
            uVar13 = uVar13 >> 4;
          }
          else {
            param_1[6] = (int)"unknown compression method";
          }
          goto LAB_00728741;
        }
        uVar4 = FUN_0072b6e0(0,0);
        puVar2[6] = uVar4;
        uVar4 = FUN_0072b700(2);
        uVar13 = 0;
        puVar2[6] = uVar4;
        uVar15 = 0;
        *puVar2 = 1;
      }
      break;
    case 1:
      for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
        pbVar11 = pbVar10;
        if (local_8 == 0) goto LAB_007287a1;
        bVar9 = *pbVar10;
        local_8 = local_8 - 1;
        pbVar10 = pbVar10 + 1;
        uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
        local_c = pbVar10;
      }
      puVar2[4] = uVar13;
      if ((char)uVar13 == '\b') {
        if ((uVar13 & 0xe000) == 0) {
          if ((uint *)puVar2[8] != (uint *)0x0) {
            *(uint *)puVar2[8] = uVar13 >> 8 & 1;
          }
          if ((puVar2[4] & 0x200) != 0) {
            uVar4 = FUN_0072b700(2);
            puVar2[6] = uVar4;
            pbVar10 = local_c;
          }
          uVar13 = 0;
          uVar15 = 0;
          *puVar2 = 2;
          do {
            pbVar11 = pbVar10;
            if (local_8 == 0) goto LAB_007287a1;
            bVar9 = *pbVar10;
            local_8 = local_8 - 1;
            bVar8 = (byte)uVar15;
            pbVar10 = pbVar10 + 1;
            uVar15 = uVar15 + 8;
            uVar13 = uVar13 + ((uint)bVar9 << (bVar8 & 0x1f));
            local_c = pbVar10;
joined_r0x0072770c:
          } while (uVar15 < 0x20);
          if (puVar2[8] != 0) {
            *(uint *)(puVar2[8] + 4) = uVar13;
          }
          if ((puVar2[4] & 0x200) != 0) {
            uVar4 = FUN_0072b700(4);
            puVar2[6] = uVar4;
            pbVar10 = local_c;
          }
          uVar13 = 0;
          uVar15 = 0;
          *puVar2 = 3;
          do {
            pbVar11 = pbVar10;
            if (local_8 == 0) goto LAB_007287a1;
            bVar9 = *pbVar10;
            local_8 = local_8 - 1;
            bVar8 = (byte)uVar15;
            pbVar10 = pbVar10 + 1;
            uVar15 = uVar15 + 8;
            uVar13 = uVar13 + ((uint)bVar9 << (bVar8 & 0x1f));
            local_c = pbVar10;
joined_r0x00727783:
          } while (uVar15 < 0x10);
          if (puVar2[8] != 0) {
            *(uint *)(puVar2[8] + 8) = uVar13 & 0xff;
            *(uint *)(puVar2[8] + 0xc) = uVar13 >> 8;
          }
          if ((puVar2[4] & 0x200) != 0) {
            uVar4 = FUN_0072b700(2);
            puVar2[6] = uVar4;
            pbVar10 = local_c;
          }
          uVar13 = 0;
          uVar15 = 0;
          *puVar2 = 4;
          goto switchD_00727528_caseD_4;
        }
        param_1[6] = (int)"unknown header flags set";
      }
      else {
        param_1[6] = (int)"unknown compression method";
      }
      goto LAB_00728741;
    case 2:
      goto joined_r0x0072770c;
    case 3:
      goto joined_r0x00727783;
    case 4:
switchD_00727528_caseD_4:
      if ((puVar2[4] & 0x400) == 0) {
        if (puVar2[8] != 0) {
          *(undefined4 *)(puVar2[8] + 0x10) = 0;
        }
      }
      else {
        for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
          pbVar11 = pbVar10;
          if (local_8 == 0) goto LAB_007287a1;
          bVar9 = *pbVar10;
          local_8 = local_8 - 1;
          pbVar10 = pbVar10 + 1;
          uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
          local_c = pbVar10;
        }
        puVar2[0x10] = uVar13;
        if (puVar2[8] != 0) {
          *(uint *)(puVar2[8] + 0x14) = uVar13;
        }
        if ((puVar2[4] & 0x200) != 0) {
          uVar4 = FUN_0072b700(2);
          puVar2[6] = uVar4;
          pbVar10 = local_c;
        }
        uVar13 = 0;
        uVar15 = 0;
      }
      *puVar2 = 5;
    case 5:
      if ((puVar2[4] & 0x400) == 0) {
LAB_0072791b:
        puVar2[0x10] = 0;
        *puVar2 = 6;
switchD_00727528_caseD_6:
        if ((puVar2[4] & 0x800) == 0) {
          if (puVar2[8] != 0) {
            *(undefined4 *)(puVar2[8] + 0x1c) = 0;
          }
LAB_007279d0:
          puVar2[0x10] = 0;
          *puVar2 = 7;
switchD_00727528_caseD_7:
          if ((puVar2[4] & 0x1000) == 0) {
            if (puVar2[8] != 0) {
              *(undefined4 *)(puVar2[8] + 0x24) = 0;
            }
LAB_00727a85:
            *puVar2 = 8;
switchD_00727528_caseD_8:
            if ((puVar2[4] & 0x200) != 0) {
              for (; uVar15 < 0x10; uVar15 = uVar15 + 8) {
                pbVar11 = pbVar10;
                if (local_8 == 0) goto LAB_007287a1;
                bVar9 = *pbVar10;
                local_8 = local_8 - 1;
                pbVar10 = pbVar10 + 1;
                uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
                local_c = pbVar10;
              }
              if (uVar13 != (ushort)puVar2[6]) {
                param_1[6] = (int)"header crc mismatch";
                goto LAB_00728741;
              }
              uVar13 = 0;
              uVar15 = 0;
            }
            if (puVar2[8] != 0) {
              *(uint *)(puVar2[8] + 0x2c) = (int)puVar2[4] >> 9 & 1;
              *(undefined4 *)(puVar2[8] + 0x30) = 1;
            }
            uVar4 = FUN_0072b6e0(0,0);
            puVar2[6] = uVar4;
            param_1[0xc] = uVar4;
            *puVar2 = 0xb;
            pbVar10 = local_c;
            break;
          }
          pbVar11 = pbVar10;
          if (local_8 != 0) {
            uVar4 = 0;
            do {
              bVar9 = pbVar10[uVar4];
              uVar4 = uVar4 + 1;
              uVar12 = puVar2[8];
              if (((uVar12 != 0) && (*(int *)(uVar12 + 0x24) != 0)) &&
                 (puVar2[0x10] < *(uint *)(uVar12 + 0x28))) {
                *(byte *)(*(int *)(uVar12 + 0x24) + puVar2[0x10]) = bVar9;
                puVar2[0x10] = puVar2[0x10] + 1;
                pbVar10 = local_c;
              }
            } while ((bVar9 != 0) && (uVar4 < local_8));
            if ((puVar2[4] & 0x200) != 0) {
              if (pbVar10 == (byte *)0x0) {
                uVar12 = 0;
                local_c = pbVar10;
              }
              else {
                uVar12 = FUN_0072b700(uVar4);
              }
              puVar2[6] = uVar12;
              pbVar10 = local_c;
            }
            local_8 = local_8 - uVar4;
            pbVar10 = pbVar10 + uVar4;
            pbVar11 = pbVar10;
            local_c = pbVar10;
            if (bVar9 == 0) goto LAB_00727a85;
          }
        }
        else {
          pbVar11 = pbVar10;
          if (local_8 != 0) {
            uVar4 = 0;
            do {
              bVar9 = pbVar10[uVar4];
              uVar4 = uVar4 + 1;
              uVar12 = puVar2[8];
              if (((uVar12 != 0) && (*(int *)(uVar12 + 0x1c) != 0)) &&
                 (puVar2[0x10] < *(uint *)(uVar12 + 0x20))) {
                *(byte *)(*(int *)(uVar12 + 0x1c) + puVar2[0x10]) = bVar9;
                puVar2[0x10] = puVar2[0x10] + 1;
                pbVar10 = local_c;
              }
            } while ((bVar9 != 0) && (uVar4 < local_8));
            if ((puVar2[4] & 0x200) != 0) {
              if (pbVar10 == (byte *)0x0) {
                uVar12 = 0;
                local_c = pbVar10;
              }
              else {
                uVar12 = FUN_0072b700(uVar4);
              }
              puVar2[6] = uVar12;
              pbVar10 = local_c;
            }
            local_8 = local_8 - uVar4;
            pbVar10 = pbVar10 + uVar4;
            pbVar11 = pbVar10;
            local_c = pbVar10;
            if (bVar9 == 0) goto LAB_007279d0;
          }
        }
      }
      else {
        uVar4 = puVar2[0x10];
        if (local_8 < puVar2[0x10]) {
          uVar4 = local_8;
        }
        if (uVar4 != 0) {
          if ((puVar2[8] != 0) && (iVar5 = *(int *)(puVar2[8] + 0x10), iVar5 != 0)) {
            iVar14 = *(int *)(puVar2[8] + 0x14) - puVar2[0x10];
            uVar12 = *(uint *)(puVar2[8] + 0x18);
            _Size = uVar4;
            if (uVar12 < iVar14 + uVar4) {
              _Size = uVar12 - iVar14;
            }
            FID_conflict__memcpy((void *)(iVar5 + iVar14),local_c,_Size);
            pbVar10 = local_c;
          }
          if ((puVar2[4] & 0x200) != 0) {
            uVar12 = FUN_0072b6e0(puVar2[6],uVar4);
            puVar2[6] = uVar12;
            pbVar10 = local_c;
          }
          local_8 = local_8 - uVar4;
          pbVar10 = pbVar10 + uVar4;
          puVar2[0x10] = puVar2[0x10] - uVar4;
          local_c = pbVar10;
        }
        pbVar11 = pbVar10;
        if (puVar2[0x10] == 0) goto LAB_0072791b;
      }
LAB_007287a1:
      param_1[3] = (int)local_1c;
      *param_1 = (int)pbVar11;
      param_1[4] = local_14;
      param_1[1] = local_8;
      puVar2[0xe] = uVar13;
      puVar2[0xf] = uVar15;
      if (((puVar2[10] == 0) && ((0x17 < (int)*puVar2 || (local_24 == param_1[4])))) ||
         (iVar5 = FUN_007273b0(param_1), iVar5 == 0)) {
        iVar5 = uVar6 - param_1[1];
        iVar14 = local_24 - param_1[4];
        param_1[2] = param_1[2] + iVar5;
        param_1[5] = param_1[5] + iVar14;
        puVar2[7] = puVar2[7] + iVar14;
        if ((puVar2[2] != 0) && (iVar14 != 0)) {
          if (puVar2[4] == 0) {
            uVar6 = FUN_0072b070(iVar14);
          }
          else if (param_1[3] == iVar14) {
            uVar6 = 0;
          }
          else {
            uVar6 = FUN_0072b700(iVar14);
          }
          puVar2[6] = uVar6;
          param_1[0xc] = uVar6;
        }
        param_1[0xb] = (-(uint)(puVar2[1] != 0) & 0x40) + ((*puVar2 != 0xb) - 1 & 0x80) +
                       puVar2[0xf];
        if (((iVar5 != 0) || (iVar14 != 0)) && (param_2 != 4)) {
          return local_2c;
        }
        if (local_2c != 0) {
          return local_2c;
        }
        return -5;
      }
      *puVar2 = 0x1c;
switchD_00727528_caseD_1c:
      return -4;
    case 6:
      goto switchD_00727528_caseD_6;
    case 7:
      goto switchD_00727528_caseD_7;
    case 8:
      goto switchD_00727528_caseD_8;
    case 9:
      for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
        pbVar11 = pbVar10;
        if (local_8 == 0) goto LAB_007287a1;
        bVar9 = *pbVar10;
        local_8 = local_8 - 1;
        pbVar10 = pbVar10 + 1;
        uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
        local_c = pbVar10;
      }
      uVar4 = (uVar13 >> 8 & 0xff00) + ((uVar13 & 0xff00) + uVar13 * 0x10000) * 0x100 +
              (uVar13 >> 0x18);
      puVar2[6] = uVar4;
      param_1[0xc] = uVar4;
      uVar13 = 0;
      uVar15 = 0;
      *puVar2 = 10;
    case 10:
      if (puVar2[3] == 0) {
        param_1[3] = (int)local_1c;
        *param_1 = (int)pbVar10;
        param_1[4] = local_14;
        param_1[1] = local_8;
        puVar2[0xf] = uVar15;
        puVar2[0xe] = uVar13;
        return 2;
      }
      uVar4 = FUN_0072b070(0);
      puVar2[6] = uVar4;
      param_1[0xc] = uVar4;
      *puVar2 = 0xb;
      pbVar10 = local_c;
switchD_00727528_caseD_b:
      if (puVar2[1] == 0) {
        for (; uVar15 < 3; uVar15 = uVar15 + 8) {
          pbVar11 = pbVar10;
          if (local_8 == 0) goto LAB_007287a1;
          bVar9 = *pbVar10;
          local_8 = local_8 - 1;
          pbVar10 = pbVar10 + 1;
          uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
          local_c = pbVar10;
        }
        puVar2[1] = uVar13 & 1;
        switch(uVar13 >> 1 & 3) {
        case 0:
          uVar13 = uVar13 >> 3;
          *puVar2 = 0xd;
          uVar15 = uVar15 - 3;
          break;
        case 1:
          uVar13 = uVar13 >> 3;
          puVar2[0x13] = (uint)&DAT_00c0ada8;
          puVar2[0x15] = 9;
          puVar2[0x14] = (uint)&DAT_00c0b5a8;
          puVar2[0x16] = 5;
          *puVar2 = 0x12;
          uVar15 = uVar15 - 3;
          break;
        case 2:
          uVar13 = uVar13 >> 3;
          *puVar2 = 0xf;
          uVar15 = uVar15 - 3;
          break;
        case 3:
          param_1[6] = (int)"invalid block type";
          *puVar2 = 0x1b;
        default:
          uVar13 = uVar13 >> 3;
          uVar15 = uVar15 - 3;
        }
      }
      else {
        uVar13 = uVar13 >> (sbyte)(uVar15 & 7);
        uVar15 = uVar15 - (uVar15 & 7);
        *puVar2 = 0x18;
      }
      break;
    case 0xb:
    case 0xc:
      goto switchD_00727528_caseD_b;
    case 0xd:
      uVar13 = uVar13 >> (sbyte)(uVar15 & 7);
      for (uVar15 = uVar15 - (uVar15 & 7); uVar15 < 0x20; uVar15 = uVar15 + 8) {
        pbVar11 = pbVar10;
        if (local_8 == 0) goto LAB_007287a1;
        bVar9 = *pbVar10;
        local_8 = local_8 - 1;
        pbVar10 = pbVar10 + 1;
        uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
        local_c = pbVar10;
      }
      uVar4 = uVar13 & 0xffff;
      if (uVar4 == ~uVar13 >> 0x10) {
        uVar13 = 0;
        puVar2[0x10] = uVar4;
        uVar15 = 0;
        *puVar2 = 0xe;
        goto switchD_00727528_caseD_e;
      }
      param_1[6] = (int)"invalid stored block lengths";
      goto LAB_00728741;
    case 0xe:
switchD_00727528_caseD_e:
      local_10 = puVar2[0x10];
      if (local_10 == 0) {
LAB_0072831b:
        *puVar2 = 0xb;
      }
      else {
        if (local_8 < local_10) {
          local_10 = local_8;
        }
        if (local_14 < local_10) {
          local_10 = local_14;
        }
        pbVar11 = pbVar10;
        if (local_10 == 0) goto LAB_007287a1;
        FID_conflict__memcpy(local_1c,local_c,local_10);
        local_8 = local_8 - local_10;
        local_14 = local_14 - local_10;
        local_1c = local_1c + local_10;
        puVar2[0x10] = puVar2[0x10] - local_10;
        pbVar10 = local_c + local_10;
        local_c = local_c + local_10;
      }
      break;
    case 0xf:
      for (; uVar15 < 0xe; uVar15 = uVar15 + 8) {
        pbVar11 = pbVar10;
        if (local_8 == 0) goto LAB_007287a1;
        bVar9 = *pbVar10;
        local_8 = local_8 - 1;
        pbVar10 = pbVar10 + 1;
        uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
        local_c = pbVar10;
      }
      puVar2[0x18] = (uVar13 & 0x1f) + 0x101;
      uVar12 = uVar13 >> 10;
      uVar4 = (uVar13 >> 5 & 0x1f) + 1;
      uVar13 = uVar13 >> 0xe;
      uVar15 = uVar15 - 0xe;
      puVar2[0x19] = uVar4;
      puVar2[0x17] = (uVar12 & 0xf) + 4;
      if ((puVar2[0x18] < 0x11f) && (uVar4 < 0x1f)) {
        puVar2[0x1a] = 0;
        *puVar2 = 0x10;
        goto switchD_00727528_caseD_10;
      }
      param_1[6] = (int)"too many length or distance symbols";
      goto LAB_00728741;
    case 0x10:
switchD_00727528_caseD_10:
      if (puVar2[0x1a] < puVar2[0x17]) {
        do {
          for (; uVar15 < 3; uVar15 = uVar15 + 8) {
            pbVar11 = pbVar10;
            if (local_8 == 0) goto LAB_007287a1;
            bVar9 = *pbVar10;
            local_8 = local_8 - 1;
            pbVar10 = pbVar10 + 1;
            uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
            local_c = pbVar10;
          }
          *(ushort *)((int)puVar2 + (uint)*(ushort *)(&DAT_00c0b628 + puVar2[0x1a] * 2) * 2 + 0x70)
               = (ushort)uVar13 & 7;
          puVar2[0x1a] = puVar2[0x1a] + 1;
          uVar13 = uVar13 >> 3;
          uVar15 = uVar15 - 3;
        } while (puVar2[0x1a] < puVar2[0x17]);
      }
      uVar4 = puVar2[0x1a];
      while (uVar4 < 0x13) {
        *(undefined2 *)
         ((int)puVar2 + (uint)*(ushort *)(&DAT_00c0b628 + puVar2[0x1a] * 2) * 2 + 0x70) = 0;
        puVar2[0x1a] = puVar2[0x1a] + 1;
        uVar4 = puVar2[0x1a];
      }
      puVar2[0x1b] = (uint)(puVar2 + 0x14c);
      puVar2[0x13] = (uint)(puVar2 + 0x14c);
      puVar2[0x15] = 7;
      local_2c = FUN_0072ba00(0,puVar2 + 0x1c,0x13,puVar2 + 0xbc);
      pbVar10 = local_c;
      if (local_2c == 0) {
        puVar2[0x1a] = 0;
        *puVar2 = 0x11;
        goto switchD_00727528_caseD_11;
      }
      param_1[6] = (int)"invalid code lengths set";
LAB_00728741:
      *puVar2 = 0x1b;
      break;
    case 0x11:
switchD_00727528_caseD_11:
      if (puVar2[0x1a] < puVar2[0x19] + puVar2[0x18]) {
        do {
          uVar4 = *(uint *)(puVar2[0x13] + ((1 << ((byte)puVar2[0x15] & 0x1f)) - 1U & uVar13) * 4);
          if (uVar15 < (uVar4 >> 8 & 0xff)) {
            do {
              pbVar11 = pbVar10;
              if (local_8 == 0) goto LAB_007287a1;
              bVar9 = *pbVar10;
              local_8 = local_8 - 1;
              bVar8 = (byte)uVar15;
              pbVar10 = pbVar10 + 1;
              uVar15 = uVar15 + 8;
              uVar13 = uVar13 + ((uint)bVar9 << (bVar8 & 0x1f));
              uVar4 = *(uint *)(puVar2[0x13] +
                               ((1 << ((byte)puVar2[0x15] & 0x1f)) - 1U & uVar13) * 4);
              local_c = pbVar10;
            } while (uVar15 < (uVar4 >> 8 & 0xff));
          }
          local_10._2_2_ = (short)(uVar4 >> 0x10);
          bVar9 = (byte)(uVar4 >> 8);
          if (uVar4 >> 0x10 < 0x10) {
            if (uVar15 < (uVar4 >> 8 & 0xff)) {
              do {
                pbVar11 = pbVar10;
                if (local_8 == 0) goto LAB_007287a1;
                bVar8 = *pbVar10;
                local_8 = local_8 - 1;
                bVar7 = (byte)uVar15;
                pbVar10 = pbVar10 + 1;
                uVar15 = uVar15 + 8;
                uVar13 = uVar13 + ((uint)bVar8 << (bVar7 & 0x1f));
                local_c = pbVar10;
              } while (uVar15 < (uVar4 >> 8 & 0xff));
            }
            uVar13 = uVar13 >> (bVar9 & 0x1f);
            uVar15 = uVar15 - (uVar4 >> 8 & 0xff);
            *(short *)((int)puVar2 + puVar2[0x1a] * 2 + 0x70) = local_10._2_2_;
            puVar2[0x1a] = puVar2[0x1a] + 1;
          }
          else {
            if (local_10._2_2_ == 0x10) {
              uVar4 = uVar4 >> 8 & 0xff;
              if (uVar15 < uVar4 + 2) {
                do {
                  pbVar11 = pbVar10;
                  if (local_8 == 0) goto LAB_007287a1;
                  bVar8 = *pbVar10;
                  local_8 = local_8 - 1;
                  bVar7 = (byte)uVar15;
                  pbVar10 = pbVar10 + 1;
                  uVar15 = uVar15 + 8;
                  uVar13 = uVar13 + ((uint)bVar8 << (bVar7 & 0x1f));
                  local_c = pbVar10;
                } while (uVar15 < uVar4 + 2);
              }
              uVar13 = uVar13 >> (bVar9 & 0x1f);
              uVar15 = uVar15 - uVar4;
              if (puVar2[0x1a] == 0) {
                param_1[6] = (int)"invalid bit length repeat";
                goto LAB_00728741;
              }
              uVar1 = *(undefined2 *)((int)puVar2 + puVar2[0x1a] * 2 + 0x6e);
              iVar5 = (uVar13 & 3) + 3;
              uVar13 = uVar13 >> 2;
              uVar15 = uVar15 - 2;
            }
            else {
              uVar4 = uVar4 >> 8 & 0xff;
              if (local_10._2_2_ == 0x11) {
                if (uVar15 < uVar4 + 3) {
                  do {
                    pbVar11 = pbVar10;
                    if (local_8 == 0) goto LAB_007287a1;
                    bVar8 = *pbVar10;
                    local_8 = local_8 - 1;
                    bVar7 = (byte)uVar15;
                    pbVar10 = pbVar10 + 1;
                    uVar15 = uVar15 + 8;
                    uVar13 = uVar13 + ((uint)bVar8 << (bVar7 & 0x1f));
                    local_c = pbVar10;
                  } while (uVar15 < uVar4 + 3);
                }
                uVar13 = uVar13 >> (bVar9 & 0x1f);
                iVar14 = -3;
                iVar5 = (uVar13 & 7) + 3;
                uVar13 = uVar13 >> 3;
              }
              else {
                if (uVar15 < uVar4 + 7) {
                  do {
                    pbVar11 = pbVar10;
                    if (local_8 == 0) goto LAB_007287a1;
                    bVar8 = *pbVar10;
                    local_8 = local_8 - 1;
                    bVar7 = (byte)uVar15;
                    pbVar10 = pbVar10 + 1;
                    uVar15 = uVar15 + 8;
                    uVar13 = uVar13 + ((uint)bVar8 << (bVar7 & 0x1f));
                    local_c = pbVar10;
                  } while (uVar15 < uVar4 + 7);
                }
                uVar13 = uVar13 >> (bVar9 & 0x1f);
                iVar14 = -7;
                iVar5 = (uVar13 & 0x7f) + 0xb;
                uVar13 = uVar13 >> 7;
              }
              uVar15 = uVar15 + (iVar14 - uVar4);
              uVar1 = 0;
            }
            pbVar10 = local_c;
            if (puVar2[0x19] + puVar2[0x18] < puVar2[0x1a] + iVar5) {
              param_1[6] = (int)"invalid bit length repeat";
              goto LAB_00728741;
            }
            for (; iVar5 != 0; iVar5 = iVar5 + -1) {
              *(undefined2 *)((int)puVar2 + puVar2[0x1a] * 2 + 0x70) = uVar1;
              puVar2[0x1a] = puVar2[0x1a] + 1;
            }
          }
        } while (puVar2[0x1a] < puVar2[0x19] + puVar2[0x18]);
      }
      if (*puVar2 != 0x1b) {
        puVar2[0x1b] = (uint)(puVar2 + 0x14c);
        puVar2[0x13] = (uint)(puVar2 + 0x14c);
        puVar2[0x15] = 9;
        local_2c = FUN_0072ba00(1,puVar2 + 0x1c,puVar2[0x18],puVar2 + 0xbc);
        pbVar10 = local_c;
        if (local_2c == 0) {
          puVar2[0x14] = puVar2[0x1b];
          puVar2[0x16] = 6;
          local_2c = FUN_0072ba00(2,(int)puVar2 + puVar2[0x18] * 2 + 0x70,puVar2[0x19],puVar2 + 0xbc
                                 );
          if (local_2c == 0) {
            *puVar2 = 0x12;
            goto switchD_00727528_caseD_12;
          }
          param_1[6] = (int)"invalid distances set";
        }
        else {
          param_1[6] = (int)"invalid literal/lengths set";
        }
        goto LAB_00728741;
      }
      break;
    case 0x12:
switchD_00727528_caseD_12:
      if ((local_8 < 6) || (local_14 < 0x102)) {
        uVar4 = *(uint *)(puVar2[0x13] + ((1 << ((byte)puVar2[0x15] & 0x1f)) - 1U & uVar13) * 4);
        if (uVar15 < (uVar4 >> 8 & 0xff)) {
          do {
            pbVar11 = pbVar10;
            if (local_8 == 0) goto LAB_007287a1;
            bVar9 = *pbVar10;
            local_8 = local_8 - 1;
            bVar8 = (byte)uVar15;
            pbVar10 = pbVar10 + 1;
            uVar15 = uVar15 + 8;
            uVar13 = uVar13 + ((uint)bVar9 << (bVar8 & 0x1f));
            uVar4 = *(uint *)(puVar2[0x13] + ((1 << ((byte)puVar2[0x15] & 0x1f)) - 1U & uVar13) * 4)
            ;
            local_c = pbVar10;
          } while (uVar15 < (uVar4 >> 8 & 0xff));
        }
        cVar3 = (char)uVar4;
        local_10 = uVar4;
        if ((cVar3 != '\0') && ((uVar4 & 0xf0) == 0)) {
          bVar9 = (byte)(uVar4 >> 8);
          local_10 = *(uint *)(puVar2[0x13] +
                              ((((1 << (cVar3 + bVar9 & 0x1f)) - 1U & uVar13) >> (bVar9 & 0x1f)) +
                              (uVar4 >> 0x10)) * 4);
          if (uVar15 < (local_10 >> 8 & 0xff) + (uVar4 >> 8 & 0xff)) {
            do {
              pbVar11 = pbVar10;
              if (local_8 == 0) goto LAB_007287a1;
              bVar8 = *pbVar10;
              local_8 = local_8 - 1;
              pbVar10 = pbVar10 + 1;
              uVar13 = uVar13 + ((uint)bVar8 << ((byte)uVar15 & 0x1f));
              uVar15 = uVar15 + 8;
              local_10 = *(uint *)(puVar2[0x13] +
                                  ((((1 << (cVar3 + bVar9 & 0x1f)) - 1U & uVar13) >> (bVar9 & 0x1f))
                                  + (uVar4 >> 0x10)) * 4);
              local_c = pbVar10;
            } while (uVar15 < (local_10 >> 8 & 0xff) + (uVar4 >> 8 & 0xff));
          }
          uVar13 = uVar13 >> (bVar9 & 0x1f);
          uVar15 = uVar15 - bVar9;
        }
        uVar13 = uVar13 >> ((byte)(local_10 >> 8) & 0x1f);
        uVar15 = uVar15 - (local_10 >> 8 & 0xff);
        puVar2[0x10] = local_10 >> 0x10;
        if ((char)local_10 == '\0') {
          *puVar2 = 0x17;
          break;
        }
        if ((local_10 & 0x20) == 0) {
          if ((local_10 & 0x40) == 0) {
            puVar2[0x12] = local_10 & 0xf;
            *puVar2 = 0x13;
            goto switchD_00727528_caseD_13;
          }
          param_1[6] = (int)"invalid literal/length code";
          goto LAB_00728741;
        }
        goto LAB_0072831b;
      }
      param_1[3] = (int)local_1c;
      *param_1 = (int)local_c;
      param_1[4] = local_14;
      param_1[1] = local_8;
      puVar2[0xe] = uVar13;
      puVar2[0xf] = uVar15;
      FUN_0072b2d0(param_1,local_24);
      local_14 = param_1[4];
      local_1c = (undefined1 *)param_1[3];
      uVar13 = puVar2[0xe];
      uVar15 = puVar2[0xf];
      local_8 = param_1[1];
      pbVar10 = (byte *)*param_1;
      local_c = (byte *)*param_1;
      break;
    case 0x13:
switchD_00727528_caseD_13:
      if (puVar2[0x12] != 0) {
        if (uVar15 < puVar2[0x12]) {
          do {
            pbVar11 = pbVar10;
            if (local_8 == 0) goto LAB_007287a1;
            bVar9 = *pbVar10;
            local_8 = local_8 - 1;
            bVar8 = (byte)uVar15;
            pbVar10 = pbVar10 + 1;
            uVar15 = uVar15 + 8;
            uVar13 = uVar13 + ((uint)bVar9 << (bVar8 & 0x1f));
            local_c = pbVar10;
          } while (uVar15 < puVar2[0x12]);
        }
        bVar9 = (byte)puVar2[0x12];
        puVar2[0x10] = puVar2[0x10] + ((1 << (bVar9 & 0x1f)) - 1U & uVar13);
        uVar13 = uVar13 >> (bVar9 & 0x1f);
        uVar15 = uVar15 - puVar2[0x12];
      }
      *puVar2 = 0x14;
    case 0x14:
      uVar4 = *(uint *)(puVar2[0x14] + ((1 << ((byte)puVar2[0x16] & 0x1f)) - 1U & uVar13) * 4);
      if (uVar15 < (uVar4 >> 8 & 0xff)) {
        do {
          pbVar11 = pbVar10;
          if (local_8 == 0) goto LAB_007287a1;
          bVar9 = *pbVar10;
          local_8 = local_8 - 1;
          bVar8 = (byte)uVar15;
          pbVar10 = pbVar10 + 1;
          uVar15 = uVar15 + 8;
          uVar13 = uVar13 + ((uint)bVar9 << (bVar8 & 0x1f));
          uVar4 = *(uint *)(puVar2[0x14] + ((1 << ((byte)puVar2[0x16] & 0x1f)) - 1U & uVar13) * 4);
          local_c = pbVar10;
        } while (uVar15 < (uVar4 >> 8 & 0xff));
      }
      local_10 = uVar4;
      if ((uVar4 & 0xf0) == 0) {
        bVar9 = (byte)(uVar4 >> 8);
        local_10 = *(uint *)(puVar2[0x14] +
                            ((((1 << ((char)uVar4 + bVar9 & 0x1f)) - 1U & uVar13) >> (bVar9 & 0x1f))
                            + (uVar4 >> 0x10)) * 4);
        if (uVar15 < (local_10 >> 8 & 0xff) + (uVar4 >> 8 & 0xff)) {
          do {
            pbVar11 = pbVar10;
            if (local_8 == 0) goto LAB_007287a1;
            bVar8 = *pbVar10;
            local_8 = local_8 - 1;
            pbVar10 = pbVar10 + 1;
            uVar13 = uVar13 + ((uint)bVar8 << ((byte)uVar15 & 0x1f));
            uVar15 = uVar15 + 8;
            local_10 = *(uint *)(puVar2[0x14] +
                                ((((1 << ((char)uVar4 + bVar9 & 0x1f)) - 1U & uVar13) >>
                                 (bVar9 & 0x1f)) + (uVar4 >> 0x10)) * 4);
            local_c = pbVar10;
          } while (uVar15 < (local_10 >> 8 & 0xff) + (uVar4 >> 8 & 0xff));
        }
        uVar13 = uVar13 >> (bVar9 & 0x1f);
        uVar15 = uVar15 - bVar9;
      }
      uVar13 = uVar13 >> ((byte)(local_10 >> 8) & 0x1f);
      uVar15 = uVar15 - (local_10 >> 8 & 0xff);
      if ((local_10 & 0x40) != 0) {
        param_1[6] = (int)"invalid distance code";
        goto LAB_00728741;
      }
      puVar2[0x11] = local_10 >> 0x10;
      puVar2[0x12] = local_10 & 0xf;
      *puVar2 = 0x15;
switchD_00727528_caseD_15:
      if (puVar2[0x12] != 0) {
        if (uVar15 < puVar2[0x12]) {
          do {
            pbVar11 = pbVar10;
            if (local_8 == 0) goto LAB_007287a1;
            bVar9 = *pbVar10;
            local_8 = local_8 - 1;
            bVar8 = (byte)uVar15;
            pbVar10 = pbVar10 + 1;
            uVar15 = uVar15 + 8;
            uVar13 = uVar13 + ((uint)bVar9 << (bVar8 & 0x1f));
            local_c = pbVar10;
          } while (uVar15 < puVar2[0x12]);
        }
        bVar9 = (byte)puVar2[0x12];
        puVar2[0x11] = puVar2[0x11] + ((1 << (bVar9 & 0x1f)) - 1U & uVar13);
        uVar13 = uVar13 >> (bVar9 & 0x1f);
        uVar15 = uVar15 - puVar2[0x12];
      }
      if ((puVar2[0xb] - local_14) + local_24 < puVar2[0x11]) {
        param_1[6] = (int)"invalid distance too far back";
        goto LAB_00728741;
      }
      *puVar2 = 0x16;
switchD_00727528_caseD_16:
      pbVar11 = pbVar10;
      if (local_14 != 0) {
        local_10 = puVar2[0x11];
        if (local_24 - local_14 < local_10) {
          local_10 = local_10 - (local_24 - local_14);
          if (puVar2[0xc] < local_10) {
            local_10 = local_10 - puVar2[0xc];
            local_30 = (puVar2[0xd] + puVar2[10]) - local_10;
          }
          else {
            local_30 = (puVar2[0xd] - local_10) + puVar2[0xc];
          }
          local_28 = puVar2[0x10];
          if (local_28 < local_10) goto LAB_007285a5;
        }
        else {
          local_30 = (int)local_1c - local_10;
          local_28 = puVar2[0x10];
LAB_007285a5:
          local_10 = local_28;
        }
        if (local_14 < local_10) {
          local_10 = local_14;
        }
        local_14 = local_14 - local_10;
        puVar2[0x10] = local_28 - local_10;
        local_30 = local_30 - (int)local_1c;
        do {
          *local_1c = local_1c[local_30];
          local_1c = local_1c + 1;
          local_10 = local_10 - 1;
        } while (local_10 != 0);
        if (puVar2[0x10] == 0) {
          *puVar2 = 0x12;
        }
        break;
      }
      goto LAB_007287a1;
    case 0x15:
      goto switchD_00727528_caseD_15;
    case 0x16:
      goto switchD_00727528_caseD_16;
    case 0x17:
      if (local_14 == 0) goto LAB_007287a1;
      *local_1c = (char)puVar2[0x10];
      local_1c = local_1c + 1;
      local_14 = local_14 - 1;
      *puVar2 = 0x12;
      break;
    case 0x18:
      if (puVar2[2] != 0) {
        for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
          pbVar11 = pbVar10;
          if (local_8 == 0) goto LAB_007287a1;
          bVar9 = *pbVar10;
          local_8 = local_8 - 1;
          pbVar10 = pbVar10 + 1;
          uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
          local_c = pbVar10;
        }
        iVar5 = local_24 - local_14;
        param_1[5] = param_1[5] + iVar5;
        puVar2[7] = puVar2[7] + iVar5;
        if (iVar5 != 0) {
          if (puVar2[4] == 0) {
            uVar4 = FUN_0072b070(iVar5);
          }
          else {
            uVar4 = FUN_0072b6e0(puVar2[6],iVar5);
          }
          puVar2[6] = uVar4;
          param_1[0xc] = uVar4;
          pbVar10 = local_c;
        }
        uVar4 = uVar13;
        if (puVar2[4] == 0) {
          uVar4 = ((uVar13 & 0xff00) + uVar13 * 0x10000) * 0x100 + (uVar13 >> 8 & 0xff00) +
                  (uVar13 >> 0x18);
        }
        local_24 = local_14;
        if (uVar4 != puVar2[6]) {
          param_1[6] = (int)"incorrect data check";
          goto LAB_00728741;
        }
        uVar13 = 0;
        uVar15 = 0;
      }
      *puVar2 = 0x19;
    case 0x19:
      if ((puVar2[2] != 0) && (puVar2[4] != 0)) {
        for (; uVar15 < 0x20; uVar15 = uVar15 + 8) {
          pbVar11 = pbVar10;
          if (local_8 == 0) goto LAB_007287a1;
          bVar9 = *pbVar10;
          local_8 = local_8 - 1;
          pbVar10 = pbVar10 + 1;
          uVar13 = uVar13 + ((uint)bVar9 << ((byte)uVar15 & 0x1f));
          local_c = pbVar10;
        }
        if (uVar13 != puVar2[7]) {
          param_1[6] = (int)"incorrect length check";
          goto LAB_00728741;
        }
        uVar13 = 0;
        uVar15 = 0;
      }
      *puVar2 = 0x1a;
switchD_00727528_caseD_1a:
      local_2c = 1;
      pbVar11 = pbVar10;
      goto LAB_007287a1;
    case 0x1a:
      goto switchD_00727528_caseD_1a;
    case 0x1b:
      local_2c = -3;
      goto LAB_007287a1;
    case 0x1c:
      goto switchD_00727528_caseD_1c;
    default:
      return -2;
    }
    uVar4 = *puVar2;
  } while( true );
}

