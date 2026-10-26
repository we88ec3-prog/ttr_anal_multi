
int FUN_008f55a0(void)

{
  char *pcVar1;
  int *piVar2;
  longlong lVar3;
  bool bVar4;
  undefined2 *puVar5;
  int in_EAX;
  int iVar6;
  short *psVar7;
  undefined4 *in_ECX;
  int iVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  int iVar11;
  undefined1 *puVar12;
  char *pcVar13;
  byte *pbVar14;
  char *pcVar15;
  undefined2 *local_28;
  undefined4 local_24;
  int local_20;
  char *local_1c;
  int local_14;
  int local_10;
  int local_c;
  
  piVar2 = in_ECX + in_EAX * 7 + 0xb;
  local_24 = *in_ECX;
  iVar6 = in_ECX[0x1b];
  pcVar13 = (char *)piVar2[2];
  pcVar15 = pcVar13 + *piVar2 * 0x30;
  piVar2[3] = 0;
  local_1c = pcVar15;
  if (in_EAX == 0) {
    local_c = in_ECX[1];
    local_10 = FUN_008b7f40(0x40,in_ECX[3]);
  }
  else {
    local_c = in_ECX[3];
    local_10 = 0;
  }
  local_20 = *(int *)(in_EAX * 0x42c + iVar6 + 0xf8);
  lVar3 = (longlong)local_20 * (longlong)local_c +
          (ulonglong)((int)((longlong)local_20 * (longlong)local_c >> 0x3f) + 0x8000);
  iVar6 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
  if (0x10 < iVar6) {
    iVar6 = 0x10;
  }
  local_20 = FUN_008b7f40(iVar6,local_c);
  if (pcVar13 < pcVar15) {
    pcVar13 = pcVar13 + 1;
    do {
      if ((local_10 <= *(short *)(pcVar13 + 7)) &&
         ((*(int *)(pcVar13 + 0x17) == 0 || (local_10 * 3 <= *(short *)(pcVar13 + 7) * 2)))) {
        iVar6 = 0;
        if (0 < piVar2[3]) {
          psVar7 = (short *)piVar2[5];
          do {
            iVar8 = (int)*(short *)(pcVar13 + 1) - (int)*psVar7;
            if (iVar8 < 0) {
              iVar8 = -iVar8;
            }
            if ((iVar8 < local_20) && (*(char *)((int)psVar7 + 0xd) == *pcVar13)) {
              *(undefined4 *)(pcVar13 + 0xf) = *(undefined4 *)(psVar7 + 0x14);
              *(char **)(*(int *)(psVar7 + 0x16) + 0x10) = pcVar13 + -1;
              *(char **)(psVar7 + 0x16) = pcVar13 + -1;
              pcVar15 = local_1c;
              goto LAB_008f5751;
            }
            iVar6 = iVar6 + 1;
            psVar7 = psVar7 + 0x18;
          } while (iVar6 < piVar2[3]);
        }
        iVar6 = FUN_008f4160(piVar2,(int)*(short *)(pcVar13 + 1),(int)*pcVar13,local_24,&local_28);
        puVar5 = local_28;
        if (iVar6 != 0) {
          return iVar6;
        }
        _memset(local_28,0,0x30);
        *(char **)(puVar5 + 0x14) = pcVar13 + -1;
        *(char **)(puVar5 + 0x16) = pcVar13 + -1;
        *(char *)((int)puVar5 + 0xd) = *pcVar13;
        *puVar5 = *(undefined2 *)(pcVar13 + 1);
        lVar3 = (longlong)(int)*(short *)(pcVar13 + 1) * (longlong)local_c +
                (ulonglong)
                ((int)((longlong)(int)*(short *)(pcVar13 + 1) * (longlong)local_c >> 0x3f) + 0x8000)
        ;
        iVar6 = ((uint)lVar3 >> 0x10) + (int)((ulonglong)lVar3 >> 0x20) * 0x10000;
        *(int *)(puVar5 + 2) = iVar6;
        *(int *)(puVar5 + 4) = iVar6;
        *(char **)(pcVar13 + 0xf) = pcVar13 + -1;
        pcVar15 = local_1c;
      }
LAB_008f5751:
      pcVar1 = pcVar13 + 0x2f;
      pcVar13 = pcVar13 + 0x30;
    } while (pcVar1 < pcVar15);
  }
  puVar9 = (undefined1 *)piVar2[5];
  puVar12 = puVar9 + piVar2[3] * 0x30;
  puVar10 = puVar9;
  if (puVar9 < puVar12) {
    do {
      iVar6 = *(int *)(puVar10 + 0x28);
      if (iVar6 != 0) {
        do {
          *(undefined1 **)(iVar6 + 0xc) = puVar10;
          iVar6 = *(int *)(iVar6 + 0x10);
        } while (iVar6 != *(int *)(puVar10 + 0x28));
      }
      puVar10 = puVar10 + 0x30;
    } while (puVar10 < puVar12);
    if (puVar9 < puVar12) {
      puVar9 = puVar9 + 0xc;
      do {
        pbVar14 = *(byte **)(puVar9 + 0x1c);
        local_10 = 0;
        local_14 = 0;
        do {
          if ((*pbVar14 & 1) == 0) {
            local_14 = local_14 + 1;
          }
          else {
            local_10 = local_10 + 1;
          }
          iVar6 = *(int *)(pbVar14 + 0x18);
          if (((iVar6 == 0) || (*(undefined1 **)(iVar6 + 0xc) == (undefined1 *)0x0)) ||
             (*(undefined1 **)(iVar6 + 0xc) == puVar9 + -0xc)) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          iVar8 = *(int *)(pbVar14 + 0x14);
          if (((iVar8 != 0) && (*(int *)(iVar8 + 0xc) != 0)) || (bVar4)) {
            psVar7 = *(short **)(puVar9 + 0xc);
            if (bVar4) {
              psVar7 = *(short **)(puVar9 + 0x10);
              iVar8 = iVar6;
            }
            if (psVar7 == (short *)0x0) {
LAB_008f582a:
              psVar7 = *(short **)(iVar8 + 0xc);
            }
            else {
              iVar6 = (int)*(short *)(puVar9 + -0xc) - (int)*psVar7;
              if (iVar6 < 0) {
                iVar6 = -iVar6;
              }
              iVar11 = (int)*(short *)(pbVar14 + 2) - (int)*(short *)(iVar8 + 2);
              if (iVar11 < 0) {
                iVar11 = -iVar11;
              }
              if (iVar11 < iVar6) goto LAB_008f582a;
            }
            if (bVar4) {
              *(short **)(puVar9 + 0x10) = psVar7;
              *(byte *)(psVar7 + 6) = *(byte *)(psVar7 + 6) | 2;
            }
            else {
              *(short **)(puVar9 + 0xc) = psVar7;
            }
          }
          pbVar14 = *(byte **)(pbVar14 + 0x10);
        } while (pbVar14 != *(byte **)(puVar9 + 0x1c));
        *puVar9 = 0;
        if ((0 < local_10) && (local_14 <= local_10)) {
          *puVar9 = 1;
        }
        if ((*(int *)(puVar9 + 0x10) != 0) && (*(int *)(puVar9 + 0xc) != 0)) {
          *(undefined4 *)(puVar9 + 0x10) = 0;
        }
        puVar10 = puVar9 + 0x24;
        puVar9 = puVar9 + 0x30;
      } while (puVar10 < puVar12);
    }
  }
  return 0;
}

