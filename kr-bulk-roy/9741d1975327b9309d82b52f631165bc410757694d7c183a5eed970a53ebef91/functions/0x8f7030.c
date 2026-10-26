
byte * FUN_008f7030(int param_1,int param_2)

{
  int *piVar1;
  short sVar2;
  byte *pbVar3;
  undefined4 uVar4;
  bool bVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  int iVar11;
  byte *pbVar12;
  undefined4 local_24;
  int local_1c;
  byte *local_18;
  int local_10;
  
  iVar11 = param_1 + 0x2c + param_2 * 0x1c;
  pbVar3 = *(byte **)(iVar11 + 0x14);
  pbVar9 = pbVar3 + *(int *)(iVar11 + 0xc) * 0x30;
  local_18 = (byte *)0x0;
  local_24 = 0;
  local_10 = 0;
  bVar5 = false;
  local_1c = 0;
  pbVar7 = pbVar3;
  if (pbVar3 < pbVar9) {
    do {
      if ((pbVar7[0xc] & 4) == 0) {
        iVar11 = *(int *)(pbVar7 + 0x14);
        pbVar12 = *(byte **)(pbVar7 + 0x18);
        pbVar6 = pbVar12;
        pbVar8 = pbVar7;
        if (((iVar11 != 0) ||
            ((pbVar12 != (byte *)0x0 &&
             (iVar11 = *(int *)(pbVar12 + 0x14), pbVar6 = pbVar7, pbVar8 = pbVar12, iVar11 != 0))))
           && (pbVar8 != (byte *)0x0)) {
          uVar4 = *(undefined4 *)(iVar11 + 8);
          pbVar8[0xc] = pbVar8[0xc] | 4;
          *(undefined4 *)(pbVar8 + 8) = uVar4;
          if ((pbVar6 != (byte *)0x0) && (*(int *)(pbVar6 + 0x14) == 0)) {
            FUN_008f6e80();
            pbVar6[0xc] = pbVar6[0xc] | 4;
          }
          if (local_18 == (byte *)0x0) {
            local_18 = pbVar7;
          }
        }
      }
      pbVar7 = pbVar7 + 0x30;
    } while (pbVar7 < pbVar9);
    if (pbVar3 < pbVar9) {
      pbVar7 = pbVar3 + 0xc;
      do {
        if ((*pbVar7 & 4) == 0) {
          pbVar12 = *(byte **)(pbVar7 + 0xc);
          if (pbVar12 == (byte *)0x0) {
            local_10 = local_10 + 1;
          }
          else if ((bVar5) &&
                  ((*(int *)(pbVar7 + -4) < local_1c + 0x40 ||
                   (*(int *)(pbVar12 + 8) < local_1c + 0x40)))) {
            local_10 = local_10 + 1;
          }
          else if (*(int *)(pbVar12 + 0x14) == 0) {
            if (pbVar12 < pbVar7 + -0xc) {
              FUN_008f6e80();
              *pbVar7 = *pbVar7 | 4;
              local_1c = *(int *)(pbVar7 + -4);
            }
            else {
              if ((param_2 == 1) || (local_18 != (byte *)0x0)) {
                FUN_008f6ea0(pbVar7 + -0xc,pbVar12,local_24);
              }
              else {
                local_24 = FUN_008f6ea0(pbVar7 + -0xc,pbVar12,0);
              }
              local_18 = pbVar7 + -0xc;
              *pbVar7 = *pbVar7 | 4;
              local_1c = *(int *)(pbVar12 + 8);
              pbVar12[0xc] = pbVar12[0xc] | 4;
            }
            bVar5 = true;
          }
          else {
            FUN_008f6e80();
            *pbVar7 = *pbVar7 | 4;
          }
        }
        pbVar12 = pbVar7 + 0x24;
        pbVar7 = pbVar7 + 0x30;
      } while (pbVar12 < pbVar9);
    }
  }
  iVar10 = (int)pbVar9 - (int)pbVar3;
  pbVar7 = (byte *)(iVar10 * 0x2aaaaaab);
  iVar11 = iVar10 / 0x30;
  if (param_2 == 0) {
    if (iVar11 == 6) {
      pbVar12 = pbVar3 + 0x60;
      pbVar6 = pbVar3 + 0xc0;
      pbVar8 = pbVar3;
    }
    else {
      if (iVar11 != 0xc) goto LAB_008f727b;
      pbVar12 = pbVar3 + 0xf0;
      pbVar6 = pbVar3 + 0x1b0;
      pbVar8 = pbVar3 + 0x30;
    }
    pbVar7 = (byte *)((*(int *)(pbVar12 + 4) * 2 - *(int *)(pbVar6 + 4)) - *(int *)(pbVar8 + 4));
    if ((int)pbVar7 < 0) {
      pbVar7 = (byte *)-(int)pbVar7;
    }
    if ((((*(byte **)(pbVar8 + 0x18) == pbVar8 + 0x30) &&
         (*(byte **)(pbVar12 + 0x18) == pbVar12 + 0x30)) &&
        (*(byte **)(pbVar6 + 0x18) == pbVar6 + 0x30)) && ((int)pbVar7 < 8)) {
      pbVar7 = (byte *)(*(int *)(pbVar8 + 8) + *(int *)(pbVar12 + 8) * -2 + *(int *)(pbVar6 + 8));
      *(int *)(pbVar6 + 8) = *(int *)(pbVar6 + 8) - (int)pbVar7;
      if (*(int *)(pbVar6 + 0x18) != 0) {
        piVar1 = (int *)(*(int *)(pbVar6 + 0x18) + 8);
        *piVar1 = *piVar1 - (int)pbVar7;
      }
      if (iVar11 == 0xc) {
        *(int *)(pbVar3 + 0x188) = *(int *)(pbVar3 + 0x188) - (int)pbVar7;
        *(int *)(pbVar3 + 0x218) = *(int *)(pbVar3 + 0x218) - (int)pbVar7;
      }
      pbVar6[0xc] = pbVar6[0xc] | 4;
      if (*(int *)(pbVar6 + 0x18) != 0) {
        pbVar12 = (byte *)(*(int *)(pbVar6 + 0x18) + 0xc);
        *pbVar12 = *pbVar12 | 4;
      }
    }
  }
LAB_008f727b:
  if (local_10 != 0) {
    if (pbVar3 < pbVar9) {
      pbVar7 = (byte *)((iVar10 - 1U) * -0x55555555);
      pbVar12 = pbVar3 + 0xc;
      iVar11 = (iVar10 - 1U) / 0x30 + 1;
      do {
        if (((*pbVar12 & 4) == 0) && (*(int *)(pbVar12 + 0x10) != 0)) {
          pbVar7 = (byte *)FUN_008f5cf0();
          *pbVar12 = *pbVar12 | 4;
          local_10 = local_10 + -1;
        }
        pbVar12 = pbVar12 + 0x30;
        iVar11 = iVar11 + -1;
      } while (iVar11 != 0);
    }
    if ((local_10 != 0) && (pbVar3 < pbVar9)) {
      pbVar12 = pbVar3 + -0x30;
      do {
        pbVar7 = pbVar12;
        if ((pbVar12[0x3c] & 4) == 0) {
          for (; (pbVar3 <= pbVar7 && ((pbVar7[0xc] & 4) == 0)); pbVar7 = pbVar7 + -0x30) {
          }
          for (pbVar6 = pbVar12 + 0x60; (pbVar6 < pbVar9 && ((pbVar6[0xc] & 4) == 0));
              pbVar6 = pbVar6 + 0x30) {
          }
          if (pbVar7 < pbVar3) {
            if (pbVar6 < pbVar9) {
              FUN_008f5cf0();
            }
          }
          else if (pbVar6 < pbVar9) {
            sVar2 = *(short *)pbVar7;
            if (*(short *)pbVar6 == sVar2) {
              *(undefined4 *)(pbVar12 + 0x38) = *(undefined4 *)(pbVar7 + 8);
            }
            else {
              iVar11 = FUN_008b7dc0((int)*(short *)(pbVar12 + 0x30) - (int)sVar2,
                                    *(int *)(pbVar6 + 8) - *(int *)(pbVar7 + 8),
                                    (int)*(short *)pbVar6 - (int)sVar2);
              *(int *)(pbVar12 + 0x38) = iVar11 + *(int *)(pbVar7 + 8);
            }
          }
          else {
            FUN_008f5cf0();
          }
        }
        pbVar7 = pbVar12 + 0x60;
        pbVar12 = pbVar12 + 0x30;
      } while (pbVar7 < pbVar9);
    }
  }
  return pbVar7;
}

