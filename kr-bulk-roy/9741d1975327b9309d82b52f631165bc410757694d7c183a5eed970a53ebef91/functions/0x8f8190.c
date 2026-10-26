
void FUN_008f8190(int *param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int local_144;
  int local_140;
  uint local_13c;
  int local_138;
  byte *local_134;
  int local_12c;
  int local_128;
  int local_124;
  undefined4 local_120;
  int local_11c;
  int local_118;
  uint local_114;
  int *local_110;
  int local_10c;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int *local_f8;
  int local_f4;
  int local_f0;
  undefined1 local_e9;
  int local_e8;
  int local_e4;
  int local_e0;
  int local_dc;
  int local_d8;
  char local_d1;
  int local_d0 [25];
  int local_6c [25];
  uint local_8;
  uint uVar3;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_f8 = (int *)(&DAT_00beb1d8 + *(int *)(*param_1 + 0xc) * 8);
  iVar6 = *local_f8;
  local_138 = in_ECX;
  local_110 = param_1;
  pbVar1 = local_134;
joined_r0x008f81cb:
  if (iVar6 == 0x206) {
    local_134 = pbVar1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_134 = &DAT_00beafd0 + iVar6;
  local_11c = 0;
  local_118 = 0;
  bVar2 = *local_134;
  if (bVar2 != 0) {
LAB_008f8200:
    uVar3 = (uint)bVar2;
    local_134 = local_134 + 1;
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
        uVar3 = uVar3 << 6 | (int)(char)*local_134 & 0x3fU;
        local_134 = local_134 + 1;
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    FUN_008f7580(local_110,uVar3,&local_140,&local_144);
    iVar6 = local_138;
    if (local_140 != 0) {
      iVar4 = FUN_008bb2e0(local_138,local_140,1);
      iVar6 = *(int *)(iVar6 + 0x54);
      local_128 = *(int *)(iVar6 + 0x74);
      local_12c = *(int *)(iVar6 + 0x70);
      local_124 = *(int *)(iVar6 + 0x78);
      local_120 = *(undefined4 *)(iVar6 + 0x7c);
      if ((iVar4 != 0) || ((short)((uint)*(undefined4 *)(iVar6 + 0x6c) >> 0x10) < 1))
      goto LAB_008f888f;
      iVar4 = 0;
      local_114 = (uint)(short)*(undefined4 *)(iVar6 + 0x6c);
      local_d8 = 0;
      local_f0 = 0;
      local_e4 = 0;
      local_e0 = 0;
      iVar6 = -1;
      if (0 < (int)local_114) {
        do {
          local_10c = iVar6;
          iVar5 = (int)*(short *)(local_124 + local_e0 * 2);
          iVar6 = local_10c;
          if (iVar4 < iVar5) {
            if ((*(byte *)(local_f8 + 1) & 1) == 0) {
              if (iVar4 <= iVar5) {
                piVar9 = (int *)(local_12c + 4 + iVar4 * 8);
                iVar7 = iVar4;
                do {
                  if ((iVar6 < 0) || (*piVar9 < local_d8)) {
                    local_d8 = *piVar9;
                    iVar6 = iVar7;
                  }
                  iVar7 = iVar7 + 1;
                  piVar9 = piVar9 + 2;
                } while (iVar7 <= iVar5);
                goto LAB_008f8384;
              }
            }
            else if (iVar4 <= iVar5) {
              piVar9 = (int *)(local_12c + 4 + iVar4 * 8);
              iVar7 = iVar4;
              do {
                if ((iVar6 < 0) || (local_d8 < *piVar9)) {
                  local_d8 = *piVar9;
                  iVar6 = iVar7;
                }
                iVar7 = iVar7 + 1;
                piVar9 = piVar9 + 2;
              } while (iVar7 <= iVar5);
LAB_008f8384:
              if (iVar6 != local_10c) {
                local_f0 = iVar4;
                local_e4 = iVar5;
              }
            }
          }
          iVar4 = iVar5 + 1;
          local_e0 = local_e0 + 1;
        } while (local_e0 < (int)local_114);
        if (iVar6 < 0) goto LAB_008f8878;
        local_dc = *(int *)(local_12c + iVar6 * 8);
        local_e8 = iVar6;
        local_104 = iVar6;
        local_f4 = iVar6;
        if ((*(byte *)(local_128 + iVar6) & 3) != 1) {
          local_f4 = -1;
          local_104 = local_f4;
        }
        do {
          iVar4 = local_e4;
          if (local_f0 < local_e8) {
            iVar4 = local_e8 + -1;
          }
          iVar5 = *(int *)(local_12c + 4 + iVar4 * 8);
          iVar7 = iVar5 - local_d8;
          if (iVar7 < 0) {
            iVar7 = local_d8 - iVar5;
          }
          local_e0 = iVar6;
          if (5 < iVar7) {
            iVar5 = *(int *)(local_12c + iVar4 * 8);
            iVar8 = iVar5 - local_dc;
            if (iVar8 < 0) {
              iVar8 = local_dc - iVar5;
            }
            if (iVar8 <= iVar7 * 0x14) break;
          }
          if (((*(byte *)(iVar4 + local_128) & 3) == 1) && (local_f4 = iVar4, local_104 < 0)) {
            local_104 = iVar4;
          }
          local_e8 = iVar4;
        } while (iVar4 != iVar6);
        do {
          local_fc = local_f0;
          if (local_e0 < local_e4) {
            local_fc = local_e0 + 1;
          }
          iVar4 = *(int *)(local_12c + 4 + local_fc * 8);
          iVar5 = iVar4 - local_d8;
          if (iVar5 < 0) {
            iVar5 = local_d8 - iVar4;
          }
          if (5 < iVar5) {
            iVar4 = *(int *)(local_12c + local_fc * 8);
            iVar7 = iVar4 - local_dc;
            if (iVar7 < 0) {
              iVar7 = local_dc - iVar4;
            }
            if (iVar7 <= iVar5 * 0x14) break;
          }
          if (((*(byte *)(local_fc + local_128) & 3) == 1) && (local_104 = local_fc, local_f4 < 0))
          {
            local_f4 = local_fc;
          }
          local_e0 = local_fc;
        } while (local_fc != iVar6);
        if ((*(byte *)(local_f8 + 1) & 4) != 0) {
          local_114 = (uint)local_110[10] / 0x19;
          iVar4 = *(int *)(local_12c + local_e0 * 8);
          iVar5 = *(int *)(local_12c + local_e8 * 8);
          iVar7 = iVar4 - iVar5;
          if (iVar7 < 0) {
            iVar7 = iVar5 - iVar4;
          }
          if ((iVar7 < (int)local_114) && ((local_e0 - local_e8) + 2 <= local_e4 - local_f0)) {
            local_13c = (uint)local_110[10] >> 2;
            iVar4 = iVar6;
            do {
              iVar5 = local_e4;
              if (local_f0 < iVar4) {
                iVar5 = iVar4 + -1;
              }
              if (*(int *)(local_12c + iVar5 * 8) != local_dc) {
                if (iVar5 != iVar6) {
                  local_e9 = *(int *)(local_12c + iVar5 * 8) < local_dc;
                  local_dc = local_e0;
                  local_d1 = '\0';
                  iVar6 = local_e0;
                  goto LAB_008f85f2;
                }
                break;
              }
              iVar4 = iVar5;
            } while (iVar5 != iVar6);
            goto LAB_008f888f;
          }
        }
        goto LAB_008f87f4;
      }
      goto LAB_008f8878;
    }
    goto LAB_008f888f;
  }
  goto LAB_008f8986;
LAB_008f85f2:
  do {
    if (local_d1 == '\0') {
      local_100 = iVar6;
      if ((*(byte *)(iVar6 + local_128) & 3) != 1) {
        local_100 = -1;
      }
      local_d1 = '\x01';
      local_108 = local_100;
      local_dc = iVar6;
    }
    iVar4 = local_f0;
    if (iVar6 < local_e4) {
      iVar4 = iVar6 + 1;
    }
    iVar6 = *(int *)(local_12c + 4 + local_dc * 8);
    iVar5 = local_d8 - iVar6;
    if (iVar5 < 0) {
      iVar5 = iVar6 - local_d8;
    }
    if ((int)local_13c < iVar5) {
      local_d1 = '\0';
    }
    else {
      iVar5 = *(int *)(local_12c + 4 + iVar4 * 8);
      local_10c = iVar5 - iVar6;
      if (local_10c < 0) {
        local_10c = iVar6 - iVar5;
      }
      if (5 < local_10c) {
        iVar6 = *(int *)(local_12c + iVar4 * 8);
        iVar5 = *(int *)(local_12c + local_dc * 8);
        iVar7 = iVar6 - iVar5;
        if (iVar7 < 0) {
          iVar7 = iVar5 - iVar6;
        }
        if (iVar7 <= local_10c * 0x14) {
          local_d1 = '\0';
          goto LAB_008f8717;
        }
      }
      if (((*(byte *)(iVar4 + local_128) & 3) == 1) && (local_108 = iVar4, local_100 < 0)) {
        local_100 = iVar4;
      }
      iVar6 = *(int *)(local_12c + iVar4 * 8);
      iVar5 = *(int *)(local_12c + local_dc * 8);
      iVar7 = iVar6 - iVar5;
      if (iVar7 < 0) {
        iVar7 = iVar5 - iVar6;
      }
      if ((iVar5 < iVar6 == (bool)local_e9) && ((int)local_114 <= iVar7)) {
        local_d8 = *(int *)(local_12c + 4 + local_dc * 8);
        iVar6 = *(int *)(local_12c + local_dc * 8);
        goto LAB_008f8735;
      }
    }
LAB_008f8717:
    iVar6 = iVar4;
  } while (iVar4 != local_e8);
  goto LAB_008f87f4;
  while( true ) {
    if (((*(byte *)(iVar5 + local_128) & 3) == 1) && (local_100 < 0)) {
      local_100 = iVar5;
    }
    local_e0 = iVar5;
    iVar4 = iVar5;
    local_108 = iVar5;
    if (iVar5 == local_e8) break;
LAB_008f8735:
    iVar5 = local_f0;
    if (iVar4 < local_e4) {
      iVar5 = iVar4 + 1;
    }
    iVar4 = *(int *)(local_12c + 4 + iVar5 * 8);
    iVar7 = iVar4 - local_d8;
    if (iVar7 < 0) {
      iVar7 = local_d8 - iVar4;
    }
    if (5 < iVar7) {
      iVar4 = *(int *)(local_12c + local_fc * 8);
      iVar7 = iVar4 - iVar6;
      if (iVar7 < 0) {
        iVar7 = iVar6 - iVar4;
      }
      if (iVar7 <= local_10c * 0x14) {
        local_e0 = local_e4;
        if (local_f0 < iVar5) {
          local_e0 = iVar5 + -1;
        }
        break;
      }
    }
  }
  local_e8 = local_dc;
  local_f4 = local_100;
  local_104 = local_108;
LAB_008f87f4:
  local_d8 = local_d8 + local_144;
  if ((local_f4 < 0) || (local_104 < 0)) {
LAB_008f8836:
    if (((*(byte *)(local_128 + local_e8) & 3) != 1) || ((*(byte *)(local_128 + local_e0) & 3) != 1)
       ) {
      local_d0[local_118] = local_d8;
      local_118 = local_118 + 1;
      goto LAB_008f888f;
    }
  }
  else {
    iVar6 = *(int *)(local_12c + local_104 * 8);
    iVar4 = *(int *)(local_12c + local_f4 * 8);
    uVar3 = iVar6 - iVar4;
    if ((int)uVar3 < 0) {
      uVar3 = iVar4 - iVar6;
    }
    if (uVar3 <= (uint)local_110[10] >> 3) goto LAB_008f8836;
  }
LAB_008f8878:
  local_6c[local_11c] = local_d8;
  local_11c = local_11c + 1;
LAB_008f888f:
  iVar4 = local_118;
  iVar6 = local_11c;
  bVar2 = *local_134;
  if (bVar2 == 0) goto code_r0x008f889f;
  goto LAB_008f8200;
code_r0x008f889f:
  if ((local_11c != 0) || (pbVar1 = local_134, local_118 != 0)) {
    FUN_008f3d30();
    FUN_008f3d30();
    piVar9 = local_110 + local_110[0x14c] * 7 + 0x14d;
    local_110[0x14c] = local_110[0x14c] + 1;
    if (iVar6 == 0) {
      iVar6 = local_d0[iVar4 / 2];
      piVar9[3] = iVar6;
      *piVar9 = iVar6;
    }
    else {
      iVar6 = iVar6 / 2;
      if (iVar4 == 0) {
        iVar6 = local_6c[iVar6];
        piVar9[3] = iVar6;
        *piVar9 = iVar6;
      }
      else {
        *piVar9 = local_6c[iVar6];
        piVar9[3] = local_d0[iVar4 / 2];
      }
    }
    iVar6 = *piVar9;
    if ((piVar9[3] != iVar6) && ((ushort)(iVar6 < piVar9[3]) != (*(ushort *)(local_f8 + 1) & 1))) {
      iVar6 = (piVar9[3] + iVar6) / 2;
      piVar9[3] = iVar6;
      *piVar9 = iVar6;
    }
    piVar9[6] = 0;
    if ((*(byte *)(local_f8 + 1) & 1) != 0) {
      piVar9[6] = 2;
    }
    pbVar1 = local_134;
    if ((*(byte *)(local_f8 + 1) & 2) != 0) {
      piVar9[6] = piVar9[6] | 4;
    }
  }
LAB_008f8986:
  local_134 = pbVar1;
  local_f8 = local_f8 + 2;
  iVar6 = *local_f8;
  pbVar1 = local_134;
  goto joined_r0x008f81cb;
}

