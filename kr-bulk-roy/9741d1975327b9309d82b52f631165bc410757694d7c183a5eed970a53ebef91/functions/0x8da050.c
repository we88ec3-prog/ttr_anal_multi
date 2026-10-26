
void FUN_008da050(byte *param_1,byte *param_2)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  undefined4 uVar4;
  uint uVar5;
  int in_ECX;
  byte *pbVar6;
  byte *pbVar7;
  uint *puVar8;
  byte *extraout_EDX;
  uint uVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint local_44;
  byte *local_40;
  byte *local_3c;
  byte *local_38;
  int local_34;
  uint local_30;
  byte *local_2c;
  uint local_28 [2];
  undefined1 local_20 [16];
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_34 = 0;
  pbVar6 = param_1 + 1;
  pbVar12 = local_2c;
  if ((param_2 < pbVar6) || (bVar2 = *param_1, pbVar12 = pbVar6, (char)bVar2 < '\0'))
  goto LAB_008da481;
  local_3c = (byte *)0x0;
  local_40 = (byte *)0x0;
  if ((bVar2 & 4) == 0) {
    local_2c = pbVar6;
    if ((bVar2 & 2) != 0) {
      local_2c = param_1 + 2;
      if (param_2 < local_2c) goto LAB_008da481;
      local_3c = (byte *)(uint)*pbVar6;
    }
    if ((bVar2 & 1) != 0) {
      param_1 = local_2c + 1;
      pbVar12 = local_2c;
      if (param_2 < param_1) goto LAB_008da481;
      bVar3 = *local_2c;
      goto LAB_008da0f2;
    }
  }
  else {
    param_1 = param_1 + 2;
    if (param_2 < param_1) goto LAB_008da481;
    local_3c = (byte *)(*pbVar6 & 0xf);
    bVar3 = *pbVar6 >> 4;
LAB_008da0f2:
    local_40 = (byte *)(uint)bVar3;
    local_2c = param_1;
  }
  pbVar12 = local_2c;
  pbVar6 = local_3c + (int)local_40;
  if (*(byte **)(in_ECX + 4) < pbVar6) {
    uVar4 = FUN_008bc7d0(**(undefined4 **)(in_ECX + 0x1c),4,*(byte **)(in_ECX + 4),
                         (uint)(pbVar6 + 7) & 0xfffffff8,*(undefined4 *)(in_ECX + 8),&local_34);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    if (local_34 != 0) goto LAB_008da4a1;
    *(uint *)(in_ECX + 4) = (uint)(pbVar6 + 7) & 0xfffffff8;
  }
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 8) + (int)local_3c * 4;
  uVar5 = 0;
  local_30 = 0;
  local_38 = (byte *)0x0;
  pbVar11 = local_2c;
  if (pbVar6 != (byte *)0x0) {
    pbVar7 = pbVar12 + 1;
    local_2c = pbVar12 + 2;
    do {
      pbVar11 = pbVar12;
      if (((uint)local_38 & 7) == 0) {
        if (param_2 < pbVar7) goto LAB_008da481;
        local_30 = (uint)*pbVar12;
        pbVar11 = pbVar12 + 1;
        local_2c = local_2c + 1;
        pbVar7 = pbVar7 + 1;
      }
      pbVar12 = pbVar11;
      if ((local_30 & 1) == 0) {
        if (param_2 < pbVar7) goto LAB_008da481;
        local_2c = local_2c + 1;
        uVar5 = uVar5 + *pbVar11;
        pbVar12 = pbVar11 + 1;
        pbVar7 = pbVar7 + 1;
      }
      else {
        if (param_2 < local_2c) goto LAB_008da481;
        local_2c = local_2c + 2;
        pbVar12 = pbVar11 + 2;
        pbVar7 = pbVar7 + 2;
        uVar5 = (int)(short)((ushort)*pbVar11 << 8) | (uint)pbVar11[1];
      }
      local_30 = local_30 >> 1;
      *(uint *)(*(int *)(in_ECX + 8) + (int)local_38 * 4) = uVar5;
      local_38 = local_38 + 1;
      pbVar11 = pbVar12;
    } while (local_38 < pbVar6);
  }
  local_2c = pbVar11;
  pbVar6 = pbVar12;
  if (((bVar2 & 8) == 0) || (local_34 = FUN_008d9da0(), pbVar6 = local_2c, local_34 == 0)) {
    FUN_008d8d80();
    local_28[1] = 0;
    local_c = 0;
    pbVar11 = pbVar6 + 1;
    local_28[0] = 0;
    local_10 = 0;
    local_2c = (byte *)0x0;
    pbVar12 = local_2c;
    if (pbVar11 <= extraout_EDX) {
      do {
        local_2c = (byte *)0x0;
        bVar2 = *pbVar6 >> 4;
        pbVar6 = (byte *)(*pbVar6 & 0xf);
        pbVar12 = local_2c;
        switch(bVar2) {
        case 0:
          local_30 = 0;
          break;
        case 1:
        case 4:
        case 5:
          local_30 = 1;
          local_2c = pbVar6;
          break;
        case 2:
          if (local_3c <= pbVar6) goto LAB_008da481;
          local_28[0] = *(uint *)(*(int *)(in_ECX + 8) + (int)pbVar6 * 4);
          local_28[1] = local_c;
          local_10 = local_28[0];
          local_30 = 0;
          break;
        case 3:
          if (local_40 <= pbVar6) goto LAB_008da481;
          local_28[1] = *(uint *)(*(int *)(in_ECX + 0xc) + (int)pbVar6 * 4);
          local_28[0] = local_10;
          local_c = local_28[1];
          local_30 = 0;
          break;
        case 6:
          local_2c = (byte *)0xb8e;
          local_30 = 3;
          break;
        case 7:
          local_2c = (byte *)0xe2b;
          local_30 = 3;
          break;
        default:
          local_30 = 4;
          local_2c = pbVar6;
        }
        puVar8 = local_28;
        local_44 = 0;
        pbVar6 = pbVar11;
        if (local_30 != 0) {
          pbVar7 = pbVar11 + 1;
          pbVar10 = pbVar11 + 2;
          do {
            uVar5 = (uint)local_2c & 3;
            pbVar12 = local_2c;
            if (uVar5 == 0) {
              if (param_2 < pbVar7) goto LAB_008da481;
              bVar3 = *pbVar11;
              pbVar11 = pbVar11 + 1;
              pbVar10 = pbVar10 + 1;
              pbVar7 = pbVar7 + 1;
              if (local_3c <= (byte *)(uint)bVar3) goto LAB_008da481;
              uVar9 = *(uint *)(*(int *)(in_ECX + 8) + (int)(uint)bVar3 * 4);
            }
            else if (uVar5 == 1) {
              if (param_2 < pbVar10) goto LAB_008da481;
              bVar3 = *pbVar11;
              pbVar6 = pbVar11 + 1;
              pbVar11 = pbVar11 + 2;
              pbVar10 = pbVar10 + 2;
              pbVar7 = pbVar7 + 2;
              uVar9 = (int)(short)((ushort)bVar3 << 8) | (uint)*pbVar6;
            }
            else {
              uVar9 = local_10;
              if (uVar5 == 2) {
                if (param_2 < pbVar7) goto LAB_008da481;
                bVar3 = *pbVar11;
                pbVar11 = pbVar11 + 1;
                pbVar10 = pbVar10 + 1;
                pbVar7 = pbVar7 + 1;
                uVar9 = (int)(char)bVar3 + local_10;
              }
            }
            *puVar8 = uVar9;
            uVar5 = (uint)local_2c >> 2 & 3;
            if (uVar5 == 0) {
              if (param_2 < pbVar7) goto LAB_008da481;
              bVar3 = *pbVar11;
              pbVar11 = pbVar11 + 1;
              pbVar10 = pbVar10 + 1;
              pbVar7 = pbVar7 + 1;
              if (local_40 <= (byte *)(uint)bVar3) goto LAB_008da481;
              uVar9 = *(uint *)(*(int *)(in_ECX + 0xc) + (int)(uint)bVar3 * 4);
            }
            else if (uVar5 == 1) {
              if (param_2 < pbVar10) goto LAB_008da481;
              bVar3 = *pbVar11;
              pbVar6 = pbVar11 + 1;
              pbVar11 = pbVar11 + 2;
              pbVar10 = pbVar10 + 2;
              pbVar7 = pbVar7 + 2;
              uVar9 = (int)(short)((ushort)bVar3 << 8) | (uint)*pbVar6;
            }
            else {
              uVar9 = local_c;
              if (uVar5 == 2) {
                if (param_2 < pbVar7) goto LAB_008da481;
                bVar3 = *pbVar11;
                pbVar11 = pbVar11 + 1;
                pbVar10 = pbVar10 + 1;
                pbVar7 = pbVar7 + 1;
                uVar9 = (int)(char)bVar3 + local_c;
              }
            }
            puVar8[1] = uVar9;
            if ((local_44 == 0) && (local_30 == 4)) {
              if (param_2 < pbVar7) goto LAB_008da481;
              local_2c = (byte *)(uint)*pbVar11;
              pbVar11 = pbVar11 + 1;
              pbVar10 = pbVar10 + 1;
              pbVar7 = pbVar7 + 1;
              local_30 = 3;
            }
            else {
              local_2c = (byte *)((uint)local_2c >> 4);
            }
            local_10 = *puVar8;
            puVar1 = puVar8 + 1;
            local_44 = local_44 + 1;
            puVar8 = puVar8 + 2;
            local_c = *puVar1;
            pbVar6 = pbVar11;
          } while (local_44 < local_30);
        }
        switch(bVar2) {
        case 0:
          FUN_008d8ee0();
          goto LAB_008da4a1;
        case 1:
        case 2:
        case 3:
          local_34 = FUN_008d8d90();
          break;
        case 4:
        case 5:
          local_34 = FUN_008d8e80(local_28);
          break;
        default:
          local_34 = FUN_008d8df0(local_28,local_20);
        }
        if (local_34 != 0) goto LAB_008da4a1;
        pbVar11 = pbVar6 + 1;
        local_2c = (byte *)0x0;
        if (param_2 < pbVar11) {
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      } while( true );
    }
LAB_008da481:
    local_2c = pbVar12;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
LAB_008da4a1:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

