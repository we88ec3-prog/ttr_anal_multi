
void FUN_008f8d20(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int *piVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  int local_f8;
  int local_f4;
  int local_f0;
  int *local_ec;
  int *local_e8;
  int local_e4;
  int local_e0;
  byte *local_dc;
  int local_d8;
  int *local_d4;
  int local_d0 [25];
  int local_6c [25];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_d4 = (int *)(&DAT_00beb1d8 + *(int *)(*in_ECX + 0xc) * 8);
  iVar6 = *local_d4;
  local_e8 = in_ECX;
  local_f4 = param_1;
  while (iVar6 != 0x206) {
    pbVar8 = &DAT_00beafd0 + iVar6;
    if ((*(byte *)(local_d4 + 1) & 1) == 0) {
      local_ec = in_ECX + 0x116;
      local_d8 = 0;
      local_e4 = 0;
    }
    else {
      local_ec = in_ECX + 0xb;
      local_d8 = 0;
      local_e4 = 0;
    }
    while (iVar6 = local_e4, *pbVar8 != 0) {
      uVar3 = (uint)*pbVar8;
      pbVar8 = pbVar8 + 1;
      if (0x7f < uVar3) {
        if (uVar3 < 0xe0) {
          iVar6 = 1;
          uVar3 = uVar3 & 0x1f;
        }
        else if (uVar3 < 0xf0) {
          iVar6 = 2;
          uVar3 = uVar3 & 0xf;
        }
        else {
          iVar6 = 3;
          uVar3 = uVar3 & 7;
        }
        do {
          uVar3 = uVar3 << 6 | (int)(char)*pbVar8 & 0x3fU;
          pbVar8 = pbVar8 + 1;
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      local_dc = pbVar8;
      FUN_008f7580(in_ECX,uVar3,&local_f8,&local_f0);
      iVar6 = local_f4;
      if (local_f8 != 0) {
        iVar4 = FUN_008bb2e0(local_f4,local_f8,1);
        iVar6 = *(int *)(iVar6 + 0x54);
        iVar2 = *(int *)(iVar6 + 0x70);
        in_ECX = local_e8;
        if ((iVar4 == 0) && (0 < (short)((uint)*(undefined4 *)(iVar6 + 0x6c) >> 0x10))) {
          local_f0 = (int)(short)*(undefined4 *)(iVar6 + 0x6c);
          iVar9 = -1;
          iVar4 = 0;
          local_e0 = 0;
          if (0 < local_f0) {
            iVar5 = 0;
            local_e0 = 0;
            do {
              iVar10 = (int)*(short *)(*(int *)(iVar6 + 0x78) + local_e0 * 2);
              if (iVar5 < iVar10) {
                uVar1 = *(ushort *)(local_d4 + 1);
                if ((uVar1 & 1) == 0) {
                  if ((uVar1 & 2) == 0) {
                    if (iVar5 <= iVar10) {
                      piVar7 = (int *)(iVar2 + 4 + iVar5 * 8);
                      do {
                        if ((iVar9 < 0) || (*piVar7 < iVar4)) {
                          iVar4 = *piVar7;
                          iVar9 = iVar5;
                        }
                        iVar5 = iVar5 + 1;
                        piVar7 = piVar7 + 2;
                      } while (iVar5 <= iVar10);
                    }
                  }
                  else if (iVar5 <= iVar10) {
                    piVar7 = (int *)(iVar2 + 4 + iVar5 * 8);
                    do {
                      if ((iVar9 < 0) || (iVar4 < *piVar7)) {
                        iVar4 = *piVar7;
                        iVar9 = iVar5;
                      }
                      iVar5 = iVar5 + 1;
                      piVar7 = piVar7 + 2;
                    } while (iVar5 <= iVar10);
                  }
                }
                else if ((uVar1 & 2) == 0) {
                  for (; iVar5 <= iVar10; iVar5 = iVar5 + 1) {
                    if ((iVar9 < 0) || (*(int *)(iVar2 + iVar5 * 8) < iVar4)) {
                      iVar4 = *(int *)(iVar2 + iVar5 * 8);
                      iVar9 = iVar5;
                    }
                  }
                }
                else {
                  for (; iVar5 <= iVar10; iVar5 = iVar5 + 1) {
                    if ((iVar9 < 0) || (iVar4 < *(int *)(iVar2 + iVar5 * 8))) {
                      iVar4 = *(int *)(iVar2 + iVar5 * 8);
                      iVar9 = iVar5;
                    }
                  }
                }
              }
              local_e0 = local_e0 + 1;
              iVar5 = iVar10 + 1;
            } while (local_e0 < local_f0);
          }
          pbVar8 = local_dc;
          if ((*(byte *)(local_d4 + 1) & 4) == 0) {
            local_6c[local_e4] = iVar4;
            local_e4 = local_e4 + 1;
          }
          else {
            local_d0[local_d8] = iVar4;
            local_d8 = local_d8 + 1;
          }
        }
      }
    }
    if ((local_e4 != 0) || (local_d8 != 0)) {
      FUN_008f3d30();
      iVar4 = local_d8;
      FUN_008f3d30();
      iVar2 = local_ec[0x36];
      local_ec[0x36] = iVar2 + 1;
      piVar7 = local_ec + iVar2 * 7 + 0x37;
      if (iVar6 == 0) {
        iVar6 = local_d0[iVar4 / 2];
        piVar7[3] = iVar6;
        *piVar7 = iVar6;
      }
      else if (iVar4 == 0) {
        iVar6 = local_6c[iVar6 / 2];
        piVar7[3] = iVar6;
        *piVar7 = iVar6;
      }
      else {
        *piVar7 = local_d0[iVar4 / 2];
        piVar7[3] = local_6c[iVar6 / 2];
      }
      iVar6 = *piVar7;
      if ((piVar7[3] != iVar6) && ((ushort)(piVar7[3] < iVar6) != (*(ushort *)(local_d4 + 1) & 2)))
      {
        iVar6 = (piVar7[3] + iVar6) / 2;
        piVar7[3] = iVar6;
        *piVar7 = iVar6;
      }
      piVar7[6] = 0;
      if ((*(byte *)(local_d4 + 1) & 2) != 0) {
        piVar7[6] = 2;
      }
    }
    piVar7 = local_d4 + 2;
    local_d4 = local_d4 + 2;
    iVar6 = *piVar7;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

