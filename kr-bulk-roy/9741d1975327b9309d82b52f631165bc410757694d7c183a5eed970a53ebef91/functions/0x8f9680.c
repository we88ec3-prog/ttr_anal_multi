
void FUN_008f9680(int *param_1,uint param_2,uint param_3,int param_4,int param_5,uint *param_6,
                 uint *param_7,uint *param_8)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int *in_ECX;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int in_EDX;
  uint uVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int local_118 [15];
  int local_dc;
  int *local_d8;
  int local_d4;
  uint *local_d0;
  int *local_cc;
  uint local_c8;
  int local_c4;
  undefined4 local_c0;
  uint *local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  uint *local_a8;
  int *local_a4;
  int local_a0;
  uint local_9c;
  uint *local_98;
  uint local_94;
  uint *local_90;
  uint local_8c;
  uint local_88 [16];
  uint local_48 [17];
  
  local_48[0x10] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar11 = 0;
  local_b8 = param_8;
  local_a4 = param_1;
  local_b4 = param_2;
  local_d0 = param_7;
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  local_48[6] = 0;
  local_48[7] = 0;
  local_48[8] = 0;
  local_48[9] = 0;
  local_48[10] = 0;
  local_48[0xb] = 0;
  local_48[0xc] = 0;
  local_48[0xd] = 0;
  local_48[0xe] = 0;
  local_48[0xf] = 0;
  uVar7 = param_2;
  do {
    local_48[*param_1] = local_48[*param_1] + 1;
    param_1 = param_1 + 1;
    uVar7 = uVar7 - 1;
  } while (uVar7 != 0);
  if (local_48[0] == param_2) {
    *in_ECX = 0;
    *param_6 = 0;
    __security_check_cookie(local_48[0x10] ^ (uint)&stack0xfffffffc);
    return;
  }
  local_8c = *param_6;
  local_94 = 1;
  do {
    if (local_48[local_94] != 0) break;
    local_94 = local_94 + 1;
  } while (local_94 < 0x10);
  if (local_8c < local_94) {
    local_8c = local_94;
  }
  local_b0 = 0xf;
  do {
    if (local_48[local_b0] != 0) break;
    local_b0 = local_b0 - 1;
  } while (local_b0 != 0);
  if (local_b0 < local_8c) {
    local_8c = local_b0;
  }
  *param_6 = local_8c;
  iVar9 = 1 << ((byte)local_94 & 0x1f);
  for (uVar7 = local_94; uVar7 < local_b0; uVar7 = uVar7 + 1) {
    if ((int)(iVar9 - local_48[uVar7]) < 0) goto LAB_008f98af;
    iVar9 = (iVar9 - local_48[uVar7]) * 2;
  }
  local_9c = local_b0 * 4;
  local_d4 = iVar9 - local_48[local_b0];
  if (-1 < local_d4) {
    local_48[local_b0] = local_48[local_b0] + local_d4;
    iVar4 = 0;
    iVar9 = local_b0 - 1;
    local_88[1] = 0;
    if (iVar9 != 0) {
      iVar10 = 0;
      do {
        iVar4 = iVar4 + *(int *)((int)local_48 + iVar10 + 4);
        iVar9 = iVar9 + -1;
        *(int *)((int)local_88 + iVar10 + 8) = iVar4;
        iVar10 = iVar10 + 4;
      } while (iVar9 != 0);
    }
    uVar7 = 0;
    do {
      iVar9 = *local_a4;
      local_a4 = local_a4 + 1;
      local_98 = (uint *)local_a4;
      if (iVar9 != 0) {
        local_90 = local_88 + iVar9;
        uVar5 = *local_90;
        param_8[uVar5] = uVar7;
        *local_90 = uVar5 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < param_2);
    local_98 = param_8;
    local_b4 = local_88[local_b0];
    iVar9 = -local_8c;
    local_ac = 0;
    local_88[0] = 0;
    local_a0 = -1;
    local_118[0] = 0;
    local_90 = (uint *)0x0;
    local_a4 = (int *)0x0;
    if ((int)local_94 <= (int)local_b0) {
      local_a8 = local_48 + local_94;
      uVar7 = local_b0;
      uVar5 = local_8c;
      local_dc = in_EDX;
      local_cc = in_ECX;
      do {
        uVar2 = *local_a8;
        if (uVar2 != 0) {
          local_c8 = uVar2 + 1;
          local_9c = uVar2;
          do {
            local_c8 = local_c8 - 1;
            local_9c = local_9c - 1;
            if ((int)(iVar9 + uVar5) < (int)local_94) {
              local_c4 = iVar9 - uVar5;
              iVar4 = iVar9 + uVar5;
              do {
                iVar9 = iVar4;
                local_a0 = local_a0 + 1;
                local_c4 = local_c4 + uVar5;
                uVar7 = local_b0 - iVar9;
                if (local_8c < local_b0 - iVar9) {
                  uVar7 = local_8c;
                }
                uVar5 = local_94 - iVar9;
                uVar2 = 1 << ((byte)uVar5 & 0x1f);
                if ((local_c8 < uVar2) &&
                   (iVar4 = uVar2 + (-1 - local_9c), puVar6 = local_a8, uVar5 < uVar7)) {
                  while (uVar5 = uVar5 + 1, uVar5 < uVar7) {
                    local_90 = puVar6 + 1;
                    if ((uint)(iVar4 * 2) <= *local_90) break;
                    iVar4 = iVar4 * 2 - *local_90;
                    puVar6 = local_90;
                  }
                }
                local_a4 = (int *)(1 << ((byte)uVar5 & 0x1f));
                uVar7 = (int)local_a4 + *local_d0;
                if (0x5a0 < uVar7) goto LAB_008f98af;
                puVar6 = (uint *)(local_dc + *local_d0 * 8);
                local_d8 = local_118 + local_a0;
                local_118[local_a0] = (int)puVar6;
                *local_d0 = uVar7;
                local_90 = puVar6;
                if (local_a0 == 0) {
                  *local_cc = (int)puVar6;
                }
                else {
                  local_88[local_a0] = local_ac;
                  uVar7 = local_ac >> ((byte)local_c4 & 0x1f);
                  iVar4 = local_d8[-1];
                  local_c0._0_2_ = CONCAT11((undefined1)local_8c,(byte)uVar5);
                  uVar11 = ((int)puVar6 - iVar4 >> 3) - uVar7;
                  *(uint *)(iVar4 + uVar7 * 8) = local_c0;
                  *(uint *)(iVar4 + 4 + uVar7 * 8) = uVar11;
                }
                iVar4 = iVar9 + local_8c;
                uVar5 = local_8c;
              } while ((int)(iVar9 + local_8c) < (int)local_94);
            }
            cVar1 = (char)local_94;
            bVar8 = (byte)iVar9;
            if (local_98 < local_b8 + local_b4) {
              uVar11 = *local_98;
              if (uVar11 < param_3) {
                local_c0._0_1_ = (-(uVar11 < 0x100) & 0xa0U) + 0x60;
              }
              else {
                iVar4 = (uVar11 - param_3) * 4;
                local_c0._0_1_ = *(char *)(iVar4 + param_5) + 'P';
                uVar11 = *(uint *)(iVar4 + param_4);
              }
              local_98 = local_98 + 1;
            }
            else {
              local_c0._0_1_ = -0x40;
            }
            local_c0 = CONCAT31(CONCAT21(local_c0._2_2_,cVar1 - bVar8),(char)local_c0);
            iVar4 = 1 << (cVar1 - bVar8 & 0x1f);
            piVar3 = (int *)(local_ac >> (bVar8 & 0x1f));
            if (piVar3 < local_a4) {
              puVar6 = local_90 + (int)piVar3 * 2;
              do {
                *puVar6 = local_c0;
                puVar6[1] = uVar11;
                piVar3 = (int *)((int)piVar3 + iVar4);
                puVar6 = puVar6 + iVar4 * 2;
              } while (piVar3 < local_a4);
            }
            uVar5 = 1 << (cVar1 - 1U & 0x1f);
            uVar7 = local_ac & uVar5;
            while (uVar7 != 0) {
              local_ac = local_ac ^ uVar5;
              uVar5 = uVar5 >> 1;
              uVar7 = local_ac & uVar5;
            }
            local_ac = local_ac ^ uVar5;
            if (((1 << (bVar8 & 0x1f)) - 1U & local_ac) != local_88[local_a0]) {
              do {
                iVar9 = iVar9 - local_8c;
                local_a0 = local_a0 + -1;
              } while (((1 << ((byte)iVar9 & 0x1f)) - 1U & local_ac) != local_88[local_a0]);
            }
            uVar7 = local_b0;
            uVar5 = local_8c;
          } while (local_9c != 0);
        }
        local_a8 = local_a8 + 1;
        local_94 = local_94 + 1;
      } while ((int)local_94 <= (int)uVar7);
    }
    __security_check_cookie(local_48[0x10] ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_008f98af:
  __security_check_cookie(local_48[0x10] ^ (uint)&stack0xfffffffc);
  return;
}

