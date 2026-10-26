
void FUN_008f48c0(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  short *psVar3;
  longlong lVar4;
  int in_EAX;
  short *psVar5;
  short *psVar6;
  int iVar7;
  undefined4 uVar8;
  ushort uVar9;
  int iVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  
  puVar12 = *(ushort **)(in_EAX + 0x1c);
  puVar1 = puVar12 + *(int *)(in_EAX + 0x18) * 0x14;
  psVar3 = *(short **)(in_EAX + 0x40 + param_1 * 0x1c);
  psVar5 = psVar3 + *(int *)(in_EAX + param_1 * 0x1c + 0x38) * 0x18;
  uVar9 = (-(ushort)(param_1 != 0) & 0x40) + 0x40;
  if (psVar3 < psVar5) {
    for (; puVar12 < puVar1; puVar12 = puVar12 + 0x14) {
      uVar2 = *puVar12;
      if (((uVar9 & uVar2) == 0) && (((uVar2 & 0x100) == 0 || ((uVar2 & 0x200) != 0)))) {
        if (param_1 == 1) {
          uVar2 = puVar12[7];
          iVar11 = *(int *)(puVar12 + 4);
        }
        else {
          uVar2 = puVar12[6];
          iVar11 = *(int *)(puVar12 + 2);
        }
        iVar13 = (int)(short)uVar2;
        if (*psVar3 - iVar13 < 0) {
          if (iVar13 - psVar5[-0x18] < 0) {
            iVar10 = ((int)psVar5 - (int)psVar3) / 0x30;
            iVar11 = 0;
            if (iVar10 < 9) {
              psVar6 = psVar3;
              if (0 < iVar10) {
                do {
                  if (iVar13 <= *psVar6) break;
                  iVar11 = iVar11 + 1;
                  psVar6 = psVar6 + 0x18;
                } while (iVar11 < iVar10);
              }
              if (psVar3[iVar11 * 0x18] == iVar13) {
                iVar11 = *(int *)(psVar3 + iVar11 * 0x18 + 4);
                goto LAB_008f4a72;
              }
            }
            else if (0 < iVar10) {
              do {
                iVar7 = iVar10 + iVar11 >> 1;
                if (psVar3[iVar7 * 0x18] <= iVar13) {
                  if (iVar13 <= psVar3[iVar7 * 0x18]) {
                    iVar11 = *(int *)(psVar3 + iVar7 * 0x18 + 4);
                    goto LAB_008f4a72;
                  }
                  iVar11 = iVar7 + 1;
                  iVar7 = iVar10;
                }
                iVar10 = iVar7;
              } while (iVar11 < iVar7);
            }
            psVar6 = psVar3 + iVar11 * 0x18;
            if (*(int *)(psVar6 + -0x10) == 0) {
              uVar8 = FUN_008b7f40(*(int *)(psVar6 + 4) - *(int *)(psVar6 + -0x14),
                                   (int)*psVar6 - (int)psVar6[-0x18]);
              *(undefined4 *)(psVar6 + -0x10) = uVar8;
            }
            lVar4 = (longlong)(iVar13 - psVar6[-0x18]) * (longlong)*(int *)(psVar6 + -0x10);
            lVar4 = lVar4 + (ulonglong)((int)(lVar4 >> 0x3f) + 0x8000);
            iVar11 = *(int *)(psVar6 + -0x14) +
                     ((uint)lVar4 >> 0x10) + (int)((ulonglong)lVar4 >> 0x20) * 0x10000;
          }
          else {
            iVar11 = (*(int *)(psVar5 + -0x14) - *(int *)(psVar5 + -0x16)) + iVar11;
          }
        }
        else {
          iVar11 = (*(int *)(psVar3 + 4) - *(int *)(psVar3 + 2)) + iVar11;
        }
LAB_008f4a72:
        if (param_1 == 0) {
          *(int *)(puVar12 + 8) = iVar11;
        }
        else {
          *(int *)(puVar12 + 10) = iVar11;
        }
        *puVar12 = *puVar12 | uVar9;
      }
    }
  }
  return;
}

