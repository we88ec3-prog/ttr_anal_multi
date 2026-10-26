
int FUN_008f67f0(void)

{
  short *psVar1;
  int *piVar2;
  short sVar3;
  short sVar4;
  longlong lVar5;
  bool bVar6;
  int in_EAX;
  int iVar7;
  int iVar8;
  int iVar9;
  short *psVar10;
  undefined4 *in_ECX;
  undefined1 *puVar11;
  byte *pbVar12;
  int iVar13;
  undefined1 *puVar14;
  undefined1 *puVar15;
  short *psVar16;
  int iVar17;
  short *local_3c;
  undefined4 local_38;
  int local_34;
  short *local_30;
  int local_2c;
  short *local_28;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_c;
  
  psVar10 = (short *)in_ECX[in_EAX * 7 + 0xd];
  piVar2 = in_ECX + in_EAX * 7 + 0xb;
  local_38 = *in_ECX;
  iVar7 = in_EAX * 0x42c + 0x2c + in_ECX[0x1b];
  local_30 = psVar10 + *piVar2 * 0x18;
  piVar2[3] = 0;
  if (in_EAX == 0) {
    iVar17 = in_ECX[1];
  }
  else {
    iVar17 = in_ECX[3];
  }
  local_2c = *(int *)(iVar7 + 0xcc);
  lVar5 = (longlong)local_2c * (longlong)iVar17 +
          (ulonglong)((int)((longlong)local_2c * (longlong)iVar17 >> 0x3f) + 0x8000);
  if ((int)(((uint)lVar5 >> 0x10) + (int)((ulonglong)lVar5 >> 0x20) * 0x10000) < 0x11) {
    local_c = *(int *)(iVar7 + 0xcc);
  }
  else {
    local_c = FUN_008b7f40(0x10,iVar17);
  }
  if (psVar10 < local_30) {
    psVar10 = psVar10 + 1;
    do {
      local_28 = (short *)0x0;
      local_20 = 0xffff;
      if (piVar2[3] < 1) {
LAB_008f694f:
        iVar7 = FUN_008f4160(piVar2,(int)*psVar10,(int)*(char *)((int)psVar10 + -1),local_38,
                             &local_3c);
        psVar16 = local_3c;
        if (iVar7 != 0) {
          return iVar7;
        }
        _memset(local_3c,0,0x30);
        psVar1 = psVar10 + -1;
        *(short **)(psVar16 + 0x14) = psVar1;
        *(short **)(psVar16 + 0x16) = psVar1;
        *psVar16 = *psVar10;
        local_34 = (int)*psVar10;
        lVar5 = (longlong)local_34 * (longlong)iVar17 +
                (ulonglong)((int)((longlong)local_34 * (longlong)iVar17 >> 0x3f) + 0x8000);
        local_2c = ((uint)lVar5 >> 0x10) + (int)((ulonglong)lVar5 >> 0x20) * 0x10000;
        *(int *)(psVar16 + 4) = local_2c;
        *(int *)(psVar16 + 2) = local_2c;
        *(short **)(psVar10 + 7) = psVar1;
        *(undefined1 *)((int)psVar16 + 0xd) = *(undefined1 *)((int)psVar10 + -1);
      }
      else {
        local_24 = piVar2[3];
        psVar16 = (short *)piVar2[5];
        do {
          if (*(char *)((int)psVar16 + 0xd) == *(char *)((int)psVar10 + -1)) {
            iVar7 = (int)*psVar10 - (int)*psVar16;
            if (iVar7 < 0) {
              iVar7 = -iVar7;
            }
            if ((iVar7 < local_c) && (iVar7 < local_20)) {
              if (*(int *)(psVar10 + 9) != 0) {
                iVar8 = 0;
                iVar13 = *(int *)(psVar16 + 0x14);
                do {
                  if (*(int *)(iVar13 + 0x14) != 0) {
                    sVar3 = *(short *)(*(int *)(iVar13 + 0x14) + 2);
                    iVar9 = (int)*(short *)(*(int *)(psVar10 + 9) + 2);
                    if (sVar3 < *(short *)(*(int *)(psVar10 + 9) + 2)) {
                      iVar8 = iVar9 - sVar3;
                    }
                    else {
                      iVar8 = sVar3 - iVar9;
                      local_34 = iVar9;
                    }
                    if (local_c <= iVar8) goto LAB_008f6939;
                  }
                  iVar13 = *(int *)(iVar13 + 0x10);
                } while (iVar13 != *(int *)(psVar16 + 0x14));
                if (local_c <= iVar8) goto LAB_008f6939;
              }
              local_28 = psVar16;
              local_20 = iVar7;
            }
          }
LAB_008f6939:
          psVar16 = psVar16 + 0x18;
          local_24 = local_24 + -1;
        } while (local_24 != 0);
        local_24 = 0;
        if (local_28 == (short *)0x0) goto LAB_008f694f;
        *(undefined4 *)(psVar10 + 7) = *(undefined4 *)(local_28 + 0x14);
        *(short **)(*(int *)(local_28 + 0x16) + 0x10) = psVar10 + -1;
        *(short **)(local_28 + 0x16) = psVar10 + -1;
      }
      psVar16 = psVar10 + 0x17;
      psVar10 = psVar10 + 0x18;
    } while (psVar16 < local_30);
  }
  puVar15 = (undefined1 *)piVar2[5];
  puVar14 = puVar15 + piVar2[3] * 0x30;
  puVar11 = puVar15;
  if (puVar15 < puVar14) {
    do {
      iVar7 = *(int *)(puVar11 + 0x28);
      if (iVar7 != 0) {
        do {
          *(undefined1 **)(iVar7 + 0xc) = puVar11;
          iVar7 = *(int *)(iVar7 + 0x10);
        } while (iVar7 != *(int *)(puVar11 + 0x28));
      }
      puVar11 = puVar11 + 0x30;
    } while (puVar11 < puVar14);
    if (puVar15 < puVar14) {
      puVar15 = puVar15 + 0xc;
      do {
        pbVar12 = *(byte **)(puVar15 + 0x1c);
        local_18 = 0;
        local_14 = 0;
        do {
          if ((*pbVar12 & 1) == 0) {
            local_14 = local_14 + 1;
          }
          else {
            local_18 = local_18 + 1;
          }
          iVar7 = *(int *)(pbVar12 + 0x18);
          if ((iVar7 == 0) || (bVar6 = true, *(undefined1 **)(iVar7 + 0xc) == puVar15 + -0xc)) {
            bVar6 = false;
          }
          if ((*(int *)(pbVar12 + 0x14) != 0) || (bVar6)) {
            psVar10 = *(short **)(puVar15 + 0xc);
            iVar17 = *(int *)(pbVar12 + 0x14);
            if (bVar6) {
              psVar10 = *(short **)(puVar15 + 0x10);
              iVar17 = iVar7;
            }
            if (psVar10 == (short *)0x0) {
LAB_008f6abe:
              psVar10 = *(short **)(iVar17 + 0xc);
            }
            else {
              iVar7 = (int)*(short *)(puVar15 + -0xc) - (int)*psVar10;
              if (iVar7 < 0) {
                iVar7 = -iVar7;
              }
              sVar3 = *(short *)(pbVar12 + 2);
              sVar4 = *(short *)(iVar17 + 2);
              if (sVar4 < sVar3) {
                iVar13 = (int)sVar3 - (int)sVar4;
              }
              else {
                iVar13 = (int)sVar4 - (int)sVar3;
              }
              if (iVar13 < iVar7) goto LAB_008f6abe;
            }
            if (bVar6) {
              *(short **)(puVar15 + 0x10) = psVar10;
              *(byte *)(psVar10 + 6) = *(byte *)(psVar10 + 6) | 2;
            }
            else {
              *(short **)(puVar15 + 0xc) = psVar10;
            }
          }
          pbVar12 = *(byte **)(pbVar12 + 0x10);
        } while (pbVar12 != *(byte **)(puVar15 + 0x1c));
        *puVar15 = 0;
        if ((0 < local_18) && (local_14 <= local_18)) {
          *puVar15 = 1;
        }
        if ((*(int *)(puVar15 + 0x10) != 0) && (*(int *)(puVar15 + 0xc) != 0)) {
          *(undefined4 *)(puVar15 + 0x10) = 0;
        }
        puVar11 = puVar15 + 0x24;
        puVar15 = puVar15 + 0x30;
      } while (puVar11 < puVar14);
    }
  }
  return 0;
}

