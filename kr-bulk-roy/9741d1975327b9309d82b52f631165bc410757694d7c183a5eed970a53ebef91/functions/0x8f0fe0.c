
int FUN_008f0fe0(int param_1)

{
  short *psVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  int *in_EAX;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  short *psVar11;
  short *psVar12;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  int local_c;
  int local_8;
  
  puVar2 = *(uint **)(param_1 + 0x2a4);
  iVar10 = in_EAX[7];
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_18 = iVar10;
  if ((puVar2 == (uint *)0x0) || (*(int *)(param_1 + 0x288) == 0)) {
    local_8 = 0;
  }
  else {
    local_8 = (**(code **)(param_1 + 0x1fc))(param_1,0x63766172);
    if ((local_8 == 0) && (local_8 = FUN_008babe0(), local_8 == 0)) {
      iVar3 = in_EAX[8];
      iVar4 = *in_EAX;
      iVar6 = FUN_008b99c0();
      if (iVar6 == 0x10000) {
        local_1c = FUN_008bc7d0(iVar10,4,0,*puVar2,0,&local_8);
        if (((local_8 == 0) &&
            (local_20 = FUN_008bc7d0(iVar10,4,0,*puVar2,0,&local_8), local_8 == 0)) &&
           (local_24 = FUN_008bc7d0(iVar10,4,0,*puVar2,0,&local_8), local_8 == 0)) {
          uVar7 = FUN_008b9960();
          uVar8 = FUN_008b9960();
          local_c = (uVar8 & 0xffff) + (iVar3 - iVar4);
          iVar10 = local_18;
          for (uVar7 = uVar7 & 0xfff; local_18 = iVar10, uVar7 != 0; uVar7 = uVar7 - 1) {
            uVar8 = FUN_008b9960();
            uVar9 = FUN_008b9960();
            local_14 = uVar9 & 0xffff;
            if ((uVar9 & 0x8000) == 0) {
              if (((uVar9 & 0x4000) != 0) && (uVar9 = 0, (*puVar2 & 0x7fffffff) != 0)) {
                do {
                  FUN_008b9960();
                  uVar9 = uVar9 + 1;
                } while (uVar9 < *puVar2 * 2);
              }
            }
            else {
              uVar9 = 0;
              if (*puVar2 != 0) {
                do {
                  sVar5 = FUN_008b9960();
                  *(int *)(local_1c + uVar9 * 4) = sVar5 * 4;
                  uVar9 = uVar9 + 1;
                } while (uVar9 < *puVar2);
              }
              if ((local_14 & 0x4000) != 0) {
                uVar9 = 0;
                if (*puVar2 != 0) {
                  do {
                    sVar5 = FUN_008b9960();
                    *(int *)(local_20 + uVar9 * 4) = sVar5 * 4;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < *puVar2);
                }
                uVar9 = 0;
                if (*puVar2 != 0) {
                  do {
                    sVar5 = FUN_008b9960();
                    *(int *)(local_24 + uVar9 * 4) = sVar5 * 4;
                    uVar9 = uVar9 + 1;
                  } while (uVar9 < *puVar2);
                }
              }
              iVar10 = FUN_008f0ab0(puVar2,local_14,local_20,local_24);
              if ((iVar10 != 0) && ((local_14 & 0x2000) != 0)) {
                iVar3 = *in_EAX;
                iVar4 = in_EAX[8];
                in_EAX[8] = iVar3 + local_c;
                iVar6 = FUN_008f0470(&local_28);
                psVar11 = (short *)FUN_008f05c0();
                if ((iVar6 == 0) || (psVar11 == (short *)0x0)) {
LAB_008f12f5:
                  if (iVar6 != -1) {
                    FUN_008b9f80(local_18,iVar6);
                  }
                }
                else {
                  if (iVar6 != -1) {
                    if (local_28 != 0) {
                      local_14 = local_28;
                      psVar12 = psVar11;
                      do {
                        psVar1 = (short *)(*(int *)(param_1 + 0x288) +
                                          (uint)*(ushort *)((iVar6 - (int)psVar11) + (int)psVar12) *
                                          2);
                        *psVar1 = *psVar1 + (short)((longlong)(int)*psVar12 * (longlong)iVar10 +
                                                    (ulonglong)
                                                    ((int)((longlong)(int)*psVar12 *
                                                           (longlong)iVar10 >> 0x3f) + 0x8000) >>
                                                   0x10);
                        psVar12 = psVar12 + 1;
                        local_14 = local_14 + -1;
                      } while (local_14 != 0);
                      local_14 = 0;
                    }
                    goto LAB_008f12f5;
                  }
                  uVar9 = 0;
                  if (*(int *)(param_1 + 0x284) != 0) {
                    do {
                      psVar12 = (short *)(*(int *)(param_1 + 0x288) + uVar9 * 2);
                      *psVar12 = *psVar12 +
                                 (short)((longlong)(int)psVar11[uVar9] * (longlong)iVar10 +
                                         (ulonglong)
                                         ((int)((longlong)(int)psVar11[uVar9] * (longlong)iVar10 >>
                                               0x3f) + 0x8000) >> 0x10);
                      uVar9 = uVar9 + 1;
                    } while (uVar9 < *(uint *)(param_1 + 0x284));
                  }
                }
                FUN_008b9f80(local_18,psVar11);
                in_EAX[8] = *in_EAX + (iVar4 - iVar3);
              }
            }
            local_c = local_c + (uVar8 & 0xffff);
            iVar10 = local_18;
          }
        }
      }
      else {
        local_8 = 0;
      }
      FUN_008baca0();
    }
    else {
      local_8 = 0;
    }
  }
  FUN_008b9f80(iVar10,local_1c);
  FUN_008b9f80(iVar10,local_20);
  FUN_008b9f80(iVar10,local_24);
  return local_8;
}

