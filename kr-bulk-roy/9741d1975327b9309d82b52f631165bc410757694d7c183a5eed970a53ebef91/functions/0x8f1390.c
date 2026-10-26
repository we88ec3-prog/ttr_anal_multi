
int FUN_008f1390(uint param_1,int *param_2,uint param_3)

{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  short sVar5;
  int in_EAX;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  short *psVar10;
  int iVar11;
  ushort *puVar12;
  int iVar13;
  ushort *puVar14;
  int iVar15;
  uint local_50;
  uint local_48;
  uint local_40;
  ushort *local_3c;
  int local_38;
  int local_34;
  ushort *local_30;
  uint local_2c;
  int local_28;
  void *local_24;
  short *local_20;
  int local_1c;
  int local_18;
  int local_14;
  ushort *local_10;
  int local_c;
  int local_8;
  
  puVar2 = *(uint **)(in_EAX + 0x2a4);
  piVar3 = *(int **)(in_EAX + 0x68);
  iVar15 = piVar3[7];
  local_40 = 0;
  local_3c = (ushort *)0x0;
  local_10 = (ushort *)0x0;
  if ((*(char *)(in_EAX + 0x2a0) == '\0') || (puVar2 == (uint *)0x0)) {
    return 6;
  }
  local_28 = iVar15;
  local_14 = FUN_008bc7d0(iVar15,8,0,param_3,0,&local_8);
  if (local_8 == 0) {
    *param_2 = local_14;
    if ((puVar2[8] <= param_1) || (piVar1 = (int *)(puVar2[9] + param_1 * 4), *piVar1 == piVar1[1]))
    {
      return 0;
    }
    local_8 = FUN_008b97e0(piVar3,*(undefined4 *)(puVar2[9] + param_1 * 4));
    if ((local_8 == 0) &&
       (local_8 = FUN_008babe0(piVar3,*(int *)(puVar2[9] + 4 + param_1 * 4) -
                                      *(int *)(puVar2[9] + param_1 * 4)), local_8 == 0)) {
      iVar4 = piVar3[8];
      iVar11 = *piVar3;
      local_24 = (void *)FUN_008bc7d0(iVar15,4,0,*puVar2,0,&local_8);
      if ((local_8 == 0) &&
         ((local_34 = FUN_008bc7d0(iVar15,4,0,*puVar2,0,&local_8), local_8 == 0 &&
          (local_38 = FUN_008bc7d0(iVar15,4,0,*puVar2,0,&local_8), local_8 == 0)))) {
        uVar6 = FUN_008b9960(piVar3);
        uVar7 = FUN_008b9960(piVar3);
        local_c = (uVar7 & 0xffff) + (iVar4 - iVar11);
        if ((uVar6 & 0x8000) != 0) {
          iVar15 = *piVar3;
          iVar4 = piVar3[8];
          piVar3[8] = iVar15 + local_c;
          local_3c = (ushort *)FUN_008f0470(&local_40);
          local_c = piVar3[8] - *piVar3;
          piVar3[8] = *piVar3 + (iVar4 - iVar15);
        }
        local_50 = 0;
        if ((uVar6 & 0xfff) != 0) {
          do {
            uVar7 = FUN_008b9960(piVar3);
            uVar8 = FUN_008b9960(piVar3);
            local_20 = (short *)(uVar8 & 0xffff);
            if ((uVar8 & 0x8000) == 0) {
              if (puVar2[6] <= (uVar8 & 0xfff)) {
                local_8 = 8;
                break;
              }
              FID_conflict__memcpy
                        (local_24,(void *)(puVar2[7] + (uVar8 & 0xfff) * *puVar2 * 4),*puVar2 * 4);
            }
            else {
              uVar8 = 0;
              if (*puVar2 != 0) {
                do {
                  sVar5 = FUN_008b9960(piVar3);
                  *(int *)((int)local_24 + uVar8 * 4) = sVar5 * 4;
                  uVar8 = uVar8 + 1;
                } while (uVar8 < *puVar2);
              }
            }
            if (((uint)local_20 & 0x4000) != 0) {
              uVar8 = 0;
              if (*puVar2 != 0) {
                do {
                  sVar5 = FUN_008b9960(piVar3);
                  *(int *)(local_34 + uVar8 * 4) = sVar5 * 4;
                  uVar8 = uVar8 + 1;
                } while (uVar8 < *puVar2);
              }
              uVar8 = 0;
              if (*puVar2 != 0) {
                do {
                  sVar5 = FUN_008b9960(piVar3);
                  *(int *)(local_38 + uVar8 * 4) = sVar5 * 4;
                  uVar8 = uVar8 + 1;
                } while (uVar8 < *puVar2);
              }
            }
            local_18 = FUN_008f0ab0(puVar2,local_20,local_34,local_38);
            if (local_18 != 0) {
              iVar15 = *piVar3;
              iVar4 = piVar3[8];
              if (((uint)local_20 & 0x2000) == 0) {
                local_2c = local_40;
                local_30 = local_3c;
              }
              else {
                piVar3[8] = iVar15 + local_c;
                local_10 = (ushort *)FUN_008f0470(&local_2c);
                local_30 = local_10;
              }
              uVar8 = local_2c;
              uVar9 = param_3;
              if (local_2c != 0) {
                uVar9 = local_2c;
              }
              local_1c = FUN_008f05c0(piVar3,uVar9);
              uVar9 = param_3;
              if (uVar8 != 0) {
                uVar9 = uVar8;
              }
              psVar10 = (short *)FUN_008f05c0(piVar3,uVar9);
              local_20 = psVar10;
              if (((local_30 != (ushort *)0x0) && (psVar10 != (short *)0x0)) && (local_1c != 0)) {
                if (local_30 == (ushort *)0xffffffff) {
                  uVar8 = 0;
                  if (param_3 != 0) {
                    local_30 = (ushort *)(local_1c - (int)psVar10);
                    do {
                      iVar11 = FUN_008b7f10((int)*(short *)((int)local_30 + (int)psVar10),local_18);
                      piVar1 = (int *)(local_14 + uVar8 * 8);
                      *piVar1 = *piVar1 + iVar11;
                      iVar11 = FUN_008b7f10((int)*psVar10,local_18);
                      piVar1 = (int *)(local_14 + 4 + uVar8 * 8);
                      *piVar1 = *piVar1 + iVar11;
                      uVar8 = uVar8 + 1;
                      psVar10 = psVar10 + 1;
                    } while (uVar8 < param_3);
                  }
                }
                else if (uVar8 != 0) {
                  puVar12 = (ushort *)(local_1c - (int)psVar10);
                  iVar11 = (int)psVar10 - (int)local_10;
                  local_48 = local_2c;
                  puVar14 = local_10;
                  local_30 = puVar12;
                  do {
                    if (*puVar14 < param_3) {
                      psVar10 = (short *)(iVar11 + (int)puVar14);
                      iVar13 = FUN_008b7f10((int)*(short *)((int)psVar10 + (int)puVar12),local_18);
                      *(int *)(local_14 + (uint)*puVar14 * 8) =
                           iVar13 + *(int *)(local_14 + (uint)*puVar14 * 8);
                      iVar13 = FUN_008b7f10((int)*psVar10,local_18);
                      *(int *)(local_14 + 4 + (uint)*puVar14 * 8) =
                           iVar13 + *(int *)(local_14 + 4 + (uint)*puVar14 * 8);
                      puVar12 = local_30;
                    }
                    puVar14 = puVar14 + 1;
                    local_48 = local_48 - 1;
                  } while (local_48 != 0);
                }
              }
              iVar11 = local_28;
              if (local_10 != (ushort *)0xffffffff) {
                FUN_008b9f80(local_28,local_10);
                local_10 = (ushort *)0x0;
              }
              FUN_008b9f80(iVar11,local_1c);
              FUN_008b9f80(iVar11,local_20);
              piVar3[8] = *piVar3 + (iVar4 - iVar15);
            }
            local_c = local_c + (uVar7 & 0xffff);
            local_50 = local_50 + 1;
          } while (local_50 < (uVar6 & 0xfff));
        }
        iVar15 = local_28;
        FUN_008b9f80(local_28,local_24);
        FUN_008b9f80(iVar15,local_34);
        FUN_008b9f80(iVar15,local_38);
      }
      FUN_008baca0(piVar3);
      if (local_8 == 0) {
        return 0;
      }
    }
    FUN_008b9f80(iVar15,local_14);
    *param_2 = 0;
  }
  return local_8;
}

