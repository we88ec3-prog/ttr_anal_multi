
void FUN_00830230(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  int *piVar9;
  uint uVar10;
  int local_4c;
  int local_44;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_18;
  char local_14 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0x9c) != 0) && (*(int *)(in_ECX + 0xa0) != 0)) {
    piVar1 = *(int **)(*(int *)(in_ECX + 0x9c) + 0x18);
    iVar2 = *piVar1;
    iVar3 = piVar1[1];
    if (*(int *)(in_ECX + 300) != 0) {
      FUN_00891d3d(*(int *)(in_ECX + 300));
      *(undefined4 *)(in_ECX + 300) = 0;
    }
    lVar4 = (ulonglong)(uint)(iVar3 * iVar2) * 4;
    uVar5 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar4 >> 0x20) != 0) | (uint)lVar4);
    *(int *)(in_ECX + 0x134) = iVar3;
    *(undefined4 *)(in_ECX + 300) = uVar5;
    *(int *)(in_ECX + 0x130) = iVar2;
    local_2c = 0;
    if (0 < iVar3 + -2) {
      local_38 = iVar2 * 4;
      do {
        local_30 = 0;
        if (0 < iVar2 + -2) {
          local_3c = local_38;
          do {
            local_18 = 0;
            local_34 = local_2c;
            if (local_2c < local_2c + 3) {
              do {
                if (local_30 < local_30 + 3) {
                  piVar1 = *(int **)(in_ECX + 0x9c);
                  piVar9 = *(int **)(in_ECX + 0xa0);
                  iVar8 = local_30;
                  do {
                    if (((piVar1[5] == 0) ||
                        (iVar6 = ((local_34 - piVar1[1]) * piVar1[2] - *piVar1) + iVar8,
                        piVar1[3] * piVar1[2] <= iVar6)) || (iVar6 < 0)) {
                      local_20 = 0;
                    }
                    else {
                      local_20 = *(int *)(piVar1[5] + iVar6 * 4);
                    }
                    if (((piVar9[5] == 0) ||
                        (iVar6 = ((local_34 - piVar9[1]) * piVar9[2] - *piVar9) + iVar8,
                        piVar9[3] * piVar9[2] <= iVar6)) || (iVar6 < 0)) {
                      iVar6 = 0;
                    }
                    else {
                      iVar6 = *(int *)(piVar9[5] + iVar6 * 4);
                    }
                    local_14[local_18] = (iVar6 == 0 && local_20 == 0) * '<';
                    local_18 = local_18 + 1;
                    iVar8 = iVar8 + 1;
                  } while (iVar8 < local_30 + 3);
                }
                local_34 = local_34 + 1;
              } while (local_34 < local_2c + 3);
            }
            if ((*(int *)(in_ECX + 0x1c) == 0) && (*(int *)(in_ECX + 0x20) == 0)) {
LAB_008305a1:
              iVar8 = 0x14;
            }
            else {
              local_44 = 0;
              local_24 = local_2c;
              if (local_30 < 0) {
                local_28 = 0;
              }
              else {
                local_28 = local_30;
                if (*(int *)(in_ECX + 4) <= local_30) {
                  local_28 = *(int *)(in_ECX + 4) + -1;
                }
              }
              if (local_2c < 0) {
                local_24 = 0;
              }
              else if (*(int *)(in_ECX + 8) <= local_2c) {
                local_24 = *(int *)(in_ECX + 8) + -1;
              }
              if ((-1 < local_28) && (local_44 = local_28, *(int *)(in_ECX + 4) <= local_28)) {
                local_44 = *(int *)(in_ECX + 4) + -1;
              }
              if (local_24 < 0) {
                iVar8 = 0;
              }
              else {
                iVar8 = local_24;
                if (*(int *)(in_ECX + 8) <= local_24) {
                  iVar8 = *(int *)(in_ECX + 8) + -1;
                }
              }
              piVar1 = *(int **)(in_ECX + 0x1c);
              iVar6 = local_44 / *piVar1;
              iVar7 = iVar8 / piVar1[1];
              piVar9 = (int *)((piVar1[2] * iVar7 + iVar6) * 0x10 + piVar1[6]);
              if (*piVar9 == 0) {
                uVar10 = piVar9[3] * (iVar8 - piVar1[1] * iVar7) + (local_44 - *piVar1 * iVar6);
                if ((int)uVar10 < piVar9[1]) {
                  iVar8 = FUN_008fed10();
                  uVar10 = uVar10 & 0x80000007;
                  if ((int)uVar10 < 0) {
                    uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
                  }
                  local_20 = (int)(char)(*(byte *)(piVar9[2] - iVar8) &
                                        '\x01' << ((byte)uVar10 & 0x1f));
                }
                else {
                  local_20 = 0;
                }
              }
              else {
                local_20 = piVar9[1];
              }
              local_4c = local_28;
              if (local_28 < 0) {
                local_4c = 0;
              }
              else if (*(int *)(in_ECX + 4) <= local_28) {
                local_4c = *(int *)(in_ECX + 4) + -1;
              }
              if (local_24 < 0) {
                local_24 = 0;
              }
              else if (*(int *)(in_ECX + 8) <= local_24) {
                local_24 = *(int *)(in_ECX + 8) + -1;
              }
              piVar1 = *(int **)(in_ECX + 0x20);
              iVar8 = local_4c / *piVar1;
              iVar6 = local_24 / piVar1[1];
              piVar9 = (int *)((piVar1[2] * iVar6 + iVar8) * 0x10 + piVar1[6]);
              if (*piVar9 == 0) {
                uVar10 = piVar9[3] * (local_24 - piVar1[1] * iVar6) + (local_4c - *piVar1 * iVar8);
                if ((int)uVar10 < piVar9[1]) {
                  iVar8 = FUN_008fed10();
                  uVar10 = uVar10 & 0x80000007;
                  if ((int)uVar10 < 0) {
                    uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
                  }
                  iVar8 = (int)(char)(*(byte *)(piVar9[2] - iVar8) & '\x01' << ((byte)uVar10 & 0x1f)
                                     );
                }
                else {
                  iVar8 = 0;
                }
              }
              else {
                iVar8 = piVar9[1];
              }
              if (iVar8 != 0 || local_20 != 0) goto LAB_008305a1;
              iVar8 = 0x96;
            }
            iVar6 = FUN_008300d0();
            uVar10 = iVar8 + iVar6;
            if (0xff < (int)uVar10) {
              uVar10 = 0xff;
            }
            uVar10 = uVar10 & 0xff;
            *(uint *)(local_3c + 4 + *(int *)(in_ECX + 300)) =
                 ((uVar10 | 0xffff8000) << 8 | uVar10) << 8 | uVar10;
            local_3c = local_3c + 4;
            local_30 = local_30 + 1;
          } while (local_30 < iVar2 + -2);
        }
        local_38 = local_38 + iVar2 * 4;
        local_2c = local_2c + 1;
      } while (local_2c < iVar3 + -2);
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

