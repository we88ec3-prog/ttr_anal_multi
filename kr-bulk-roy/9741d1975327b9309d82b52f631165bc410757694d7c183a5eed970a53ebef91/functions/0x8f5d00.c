
byte * FUN_008f5d00(byte *param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  undefined1 uVar3;
  byte *pbVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  int iVar14;
  uint uVar15;
  byte *pbVar16;
  byte *pbVar17;
  int iVar18;
  int local_1c;
  byte *local_10;
  
  iVar8 = (int)param_1 + 0x2c + param_2 * 0x1c;
  pbVar4 = *(byte **)(iVar8 + 0x14);
  pbVar6 = pbVar4 + *(int *)(iVar8 + 0xc) * 0x30;
  local_10 = (byte *)0x0;
  local_1c = 0;
  if (param_2 == 1) {
    pbVar13 = pbVar4;
    if (pbVar4 < pbVar6) {
      do {
        if ((pbVar13[0xc] & 4) == 0) {
          iVar8 = *(int *)(pbVar13 + 0x14);
          pbVar16 = *(byte **)(pbVar13 + 0x18);
          pbVar9 = pbVar16;
          pbVar17 = pbVar13;
          if (((iVar8 != 0) ||
              ((pbVar16 != (byte *)0x0 &&
               (iVar8 = *(int *)(pbVar16 + 0x14), pbVar9 = pbVar13, pbVar17 = pbVar16, iVar8 != 0)))
              ) && (pbVar17 != (byte *)0x0)) {
            uVar5 = *(undefined4 *)(iVar8 + 8);
            pbVar17[0xc] = pbVar17[0xc] | 4;
            *(undefined4 *)(pbVar17 + 8) = uVar5;
            if ((pbVar9 != (byte *)0x0) && (*(int *)(pbVar9 + 0x14) == 0)) {
              FUN_008f5cc0(1);
              pbVar9[0xc] = pbVar9[0xc] | 4;
            }
            if (local_10 == (byte *)0x0) {
              local_10 = pbVar13;
            }
          }
        }
        pbVar13 = pbVar13 + 0x30;
      } while (pbVar13 < pbVar6);
      goto LAB_008f5da9;
    }
  }
  else {
LAB_008f5da9:
    if (pbVar4 < pbVar6) {
      pbVar13 = pbVar4 + 0xc;
      do {
        bVar2 = *pbVar13;
        if ((bVar2 & 4) == 0) {
          iVar8 = *(int *)(pbVar13 + 0xc);
          if (iVar8 == 0) {
            local_1c = local_1c + 1;
          }
          else if (*(int *)(iVar8 + 0x14) == 0) {
            if (local_10 == (byte *)0x0) {
              iVar11 = *(int *)(iVar8 + 4);
              iVar14 = *(int *)(pbVar13 + -8);
              iVar7 = FUN_008f5b50(bVar2,*(undefined1 *)(iVar8 + 0xc));
              if (iVar7 < 0x41) {
                iVar12 = 0x20;
                local_10 = (byte *)0x20;
              }
              else {
                iVar12 = 0x26;
                local_10 = (byte *)0x1a;
              }
              if (iVar7 < 0x60) {
                iVar14 = (iVar11 - iVar14 >> 1) + iVar14;
                uVar10 = iVar14 + 0x20U & 0xffffffc0;
                iVar14 = iVar14 - uVar10;
                iVar11 = iVar14 + iVar12;
                if (iVar11 < 0) {
                  iVar11 = -iVar11;
                }
                iVar14 = iVar14 - (int)local_10;
                if (iVar14 < 0) {
                  iVar14 = -iVar14;
                }
                if (iVar11 < iVar14) {
                  local_10 = (byte *)-iVar12;
                }
                iVar11 = (uVar10 + (int)local_10) - iVar7 / 2;
                *(int *)(pbVar13 + -4) = iVar11;
                *(int *)(iVar8 + 8) = iVar11 + iVar7;
              }
              else {
                *(uint *)(pbVar13 + -4) = iVar14 + 0x20U & 0xffffffc0;
              }
              *pbVar13 = *pbVar13 | 4;
              local_10 = pbVar13 + -0xc;
              FUN_008f5cc0(param_2);
            }
            else {
              iVar7 = *(int *)(iVar8 + 4) - *(int *)(pbVar13 + -8);
              iVar14 = (*(int *)(local_10 + 8) - *(int *)(local_10 + 4)) + *(int *)(pbVar13 + -8);
              uVar3 = *(undefined1 *)(iVar8 + 0xc);
              iVar12 = iVar7 >> 1;
              iVar18 = iVar12 + iVar14;
              iVar11 = FUN_008f5b50(bVar2,uVar3);
              if ((*(byte *)(iVar8 + 0xc) & 4) == 0) {
                if (iVar11 < 0x60) {
                  uVar10 = iVar18 + 0x20U & 0xffffffc0;
                  if (iVar11 < 0x41) {
                    iVar7 = 0x20;
                    iVar14 = 0x20;
                  }
                  else {
                    iVar7 = 0x26;
                    iVar14 = 0x1a;
                  }
                  iVar12 = (iVar7 - uVar10) + iVar18;
                  if (iVar12 < 0) {
                    iVar12 = -iVar12;
                  }
                  iVar18 = (iVar18 - iVar14) - uVar10;
                  if (iVar18 < 0) {
                    iVar18 = -iVar18;
                  }
                  if (iVar12 < iVar18) {
                    iVar14 = -iVar7;
                  }
                  *(uint *)(pbVar13 + -4) = (uVar10 + iVar14) - iVar11 / 2;
                  *(uint *)(iVar8 + 8) = iVar11 / 2 + uVar10 + iVar14;
                }
                else {
                  iVar18 = FUN_008f5b50(bVar2,uVar3);
                  uVar10 = iVar14 + 0x20U & 0xffffffc0;
                  iVar12 = (iVar18 >> 1) - (iVar12 + iVar14);
                  iVar11 = iVar12 + uVar10;
                  if (iVar11 < 0) {
                    iVar11 = -iVar11;
                  }
                  uVar15 = (iVar7 + 0x20 + iVar14 & 0xffffffc0U) - iVar18;
                  iVar12 = iVar12 + uVar15;
                  if (iVar12 < 0) {
                    iVar12 = -iVar12;
                  }
                  if (iVar12 <= iVar11) {
                    uVar10 = uVar15;
                  }
                  *(uint *)(pbVar13 + -4) = uVar10;
                  *(uint *)(iVar8 + 8) = uVar10 + iVar18;
                }
              }
              else {
                *(int *)(pbVar13 + -4) = *(int *)(iVar8 + 8) - iVar11;
              }
              *pbVar13 = *pbVar13 | 4;
              *(byte *)(iVar8 + 0xc) = *(byte *)(iVar8 + 0xc) | 4;
              if ((pbVar4 < pbVar13 + -0xc) && (*(int *)(pbVar13 + -4) < *(int *)(pbVar13 + -0x34)))
              {
                *(int *)(pbVar13 + -4) = *(int *)(pbVar13 + -0x34);
              }
            }
          }
          else {
            FUN_008f5cc0(param_2);
            *pbVar13 = *pbVar13 | 4;
          }
        }
        pbVar16 = pbVar13 + 0x24;
        pbVar13 = pbVar13 + 0x30;
      } while (pbVar16 < pbVar6);
    }
  }
  pbVar13 = (byte *)(((int)pbVar6 - (int)pbVar4) * 0x2aaaaaab);
  iVar8 = ((int)pbVar6 - (int)pbVar4) / 0x30;
  if (param_2 == 0) {
    if (iVar8 == 6) {
      param_1 = pbVar4 + 0x60;
      pbVar13 = pbVar4 + 0xc0;
      pbVar16 = pbVar4;
    }
    else {
      if (iVar8 != 0xc) goto LAB_008f6093;
      param_1 = pbVar4 + 0xf0;
      pbVar13 = pbVar4 + 0x1b0;
      pbVar16 = pbVar4 + 0x30;
    }
    iVar11 = (*(int *)(param_1 + 4) * 2 - *(int *)(pbVar13 + 4)) - *(int *)(pbVar16 + 4);
    if (iVar11 < 0) {
      iVar11 = -iVar11;
    }
    if (iVar11 < 8) {
      iVar11 = *(int *)(pbVar16 + 8) + *(int *)(param_1 + 8) * -2 + *(int *)(pbVar13 + 8);
      *(int *)(pbVar13 + 8) = *(int *)(pbVar13 + 8) - iVar11;
      if (*(int *)(pbVar13 + 0x18) != 0) {
        piVar1 = (int *)(*(int *)(pbVar13 + 0x18) + 8);
        *piVar1 = *piVar1 - iVar11;
      }
      if (iVar8 == 0xc) {
        *(int *)(pbVar4 + 0x188) = *(int *)(pbVar4 + 0x188) - iVar11;
        *(int *)(pbVar4 + 0x218) = *(int *)(pbVar4 + 0x218) - iVar11;
      }
      pbVar13[0xc] = pbVar13[0xc] | 4;
      pbVar13 = *(byte **)(pbVar13 + 0x18);
      if (pbVar13 != (byte *)0x0) {
        pbVar13[0xc] = pbVar13[0xc] | 4;
      }
    }
  }
LAB_008f6093:
  if (((local_1c != 0) || (local_10 == (byte *)0x0)) && (pbVar4 < pbVar6)) {
    pbVar16 = pbVar4 + 0x1c;
    do {
      if ((pbVar16[-0x10] & 4) == 0) {
        if (*(int *)pbVar16 == 0) {
LAB_008f60f5:
          if (local_10 == (byte *)0x0) {
            local_10 = pbVar16 + -0x1c;
            *(uint *)(pbVar16 + -0x14) = *(int *)(pbVar16 + -0x18) + 0x20U & 0xffffffc0;
          }
          else {
            for (pbVar13 = pbVar16 + -0x4c; (pbVar4 <= pbVar13 && ((pbVar13[0xc] & 4) == 0));
                pbVar13 = pbVar13 + -0x30) {
            }
            for (pbVar9 = pbVar16 + 0x14; (pbVar9 < pbVar6 && ((pbVar9[0xc] & 4) == 0));
                pbVar9 = pbVar9 + 0x30) {
            }
            if ((((pbVar13 < pbVar4) || (pbVar16 + -0x1c <= pbVar13)) || (pbVar6 <= pbVar9)) ||
               (pbVar9 <= pbVar16 + -0x1c)) {
              *(uint *)(pbVar16 + -0x14) =
                   ((*(int *)(pbVar16 + -0x18) - *(int *)(local_10 + 4)) + 0x10U & 0xffffffe0) +
                   *(int *)(local_10 + 8);
            }
            else if (*(int *)(pbVar9 + 4) == *(int *)(pbVar13 + 4)) {
              *(undefined4 *)(pbVar16 + -0x14) = *(undefined4 *)(pbVar13 + 8);
            }
            else {
              iVar8 = FUN_008b7dc0(*(int *)(pbVar16 + -0x18) - *(int *)(pbVar13 + 4),
                                   *(int *)(pbVar9 + 8) - *(int *)(pbVar13 + 8),
                                   *(int *)(pbVar9 + 4) - *(int *)(pbVar13 + 4));
              *(int *)(pbVar16 + -0x14) = iVar8 + *(int *)(pbVar13 + 8);
            }
          }
        }
        else {
          iVar8 = *(int *)(*(int *)pbVar16 + 4) - *(int *)(pbVar16 + -0x18);
          if (iVar8 < 0) {
            iVar8 = -iVar8;
          }
          if (0x4f < iVar8) goto LAB_008f60f5;
          FUN_008f5cf0();
        }
        pbVar16[-0x10] = pbVar16[-0x10] | 4;
        pbVar13 = pbVar16 + -0x1c;
        if ((pbVar4 < pbVar13) &&
           (pbVar13 = *(byte **)(pbVar16 + -0x44), *(int *)(pbVar16 + -0x14) < (int)pbVar13)) {
          *(byte **)(pbVar16 + -0x14) = pbVar13;
        }
        if (((pbVar16 + 0x14 < pbVar6) && ((pbVar16[0x20] & 4) != 0)) &&
           (pbVar13 = *(byte **)(pbVar16 + 0x1c), (int)pbVar13 < *(int *)(pbVar16 + -0x14))) {
          *(byte **)(pbVar16 + -0x14) = pbVar13;
        }
      }
      pbVar9 = pbVar16 + 0x14;
      pbVar16 = pbVar16 + 0x30;
    } while (pbVar9 < pbVar6);
  }
  return pbVar13;
}

