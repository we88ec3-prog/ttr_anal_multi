
void FUN_0072ba00(int param_1,int param_2,uint param_3,ushort *param_4)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint *in_ECX;
  undefined4 *puVar8;
  int iVar9;
  int *in_EDX;
  uint uVar10;
  byte bVar11;
  int iVar12;
  ushort *puVar13;
  uint local_84;
  uint local_80;
  ushort *local_78;
  ushort *local_74;
  ushort *local_70;
  uint local_6c;
  int local_68;
  int local_60;
  uint local_5c;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  ushort auStack_48 [16];
  ushort local_28 [16];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_28[0] = 0;
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  local_28[4] = 0;
  local_28[5] = 0;
  local_28[6] = 0;
  local_28[7] = 0;
  local_28[8] = 0;
  local_28[9] = 0;
  local_28[10] = 0;
  local_28[0xb] = 0;
  local_28[0xc] = 0;
  local_28[0xd] = 0;
  local_28[0xe] = 0;
  local_28[0xf] = 0;
  uVar3 = 0;
  if (param_3 != 0) {
    do {
      local_28[*(ushort *)(param_2 + uVar3 * 2)] = local_28[*(ushort *)(param_2 + uVar3 * 2)] + 1;
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_3);
  }
  uVar3 = 0xf;
  do {
    if (local_28[uVar3] != 0) break;
    uVar3 = uVar3 - 1;
  } while (uVar3 != 0);
  local_54 = *in_ECX;
  if (uVar3 < *in_ECX) {
    local_54 = uVar3;
  }
  if (uVar3 == 0) {
    *(undefined4 *)*in_EDX = 0x140;
    *in_EDX = *in_EDX + 4;
    *(undefined4 *)*in_EDX = 0x140;
    *in_EDX = *in_EDX + 4;
    *in_ECX = 1;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_50 = 1;
  do {
    if (local_28[local_50] != 0) break;
    if (local_28[local_50 + 1] != 0) {
      local_50 = local_50 + 1;
      break;
    }
    if (local_28[local_50 + 2] != 0) {
      local_50 = local_50 + 2;
      break;
    }
    if (local_28[local_50 + 3] != 0) {
      local_50 = local_50 + 3;
      break;
    }
    if (local_28[local_50 + 4] != 0) {
      local_50 = local_50 + 4;
      break;
    }
    local_50 = local_50 + 5;
  } while (local_50 < 0x10);
  if (local_54 < local_50) {
    local_54 = local_50;
  }
  iVar12 = 1;
  uVar4 = 1;
  do {
    iVar12 = iVar12 * 2 - (uint)local_28[uVar4];
    if (iVar12 < 0) goto LAB_0072bbbf;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x10);
  if ((0 < iVar12) && ((param_1 == 0 || (uVar3 != 1)))) {
LAB_0072bbbf:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  auStack_48[1] = 0;
  uVar4 = 2;
  do {
    uVar5 = uVar4 + 2;
    *(short *)((int)auStack_48 + uVar4 + 2) =
         *(short *)((int)auStack_48 + uVar4) + *(short *)((int)local_28 + uVar4);
    uVar4 = uVar5;
  } while (uVar5 < 0x1e);
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      if (*(short *)(param_2 + uVar4 * 2) != 0) {
        param_4[auStack_48[*(ushort *)(param_2 + uVar4 * 2)]] = (ushort)uVar4;
        auStack_48[*(ushort *)(param_2 + uVar4 * 2)] =
             auStack_48[*(ushort *)(param_2 + uVar4 * 2)] + 1;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
  }
  if (param_1 == 0) {
    local_74 = param_4;
    local_78 = param_4;
    local_68 = 0x13;
  }
  else if (param_1 == 1) {
    local_78 = (ushort *)&DAT_00c089be;
    local_74 = (ushort *)&DAT_00c089fe;
    local_68 = 0x100;
  }
  else {
    local_78 = (ushort *)&DAT_00c08c40;
    local_74 = (ushort *)&DAT_00c08c80;
    local_68 = -1;
  }
  local_60 = *in_EDX;
  local_5c = 0xffffffff;
  bVar7 = (byte)local_54;
  local_84 = 1 << (bVar7 & 0x1f);
  local_80 = 0;
  uVar5 = 0;
  uVar4 = local_84 - 1;
  if ((param_1 == 1) && (0x5af < local_84)) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_70 = param_4;
  local_6c = local_84;
LAB_0072bc56:
  do {
    bVar11 = (byte)uVar5;
    bVar1 = (char)local_50 - bVar11;
    uVar2 = *local_70;
    if ((int)(uint)uVar2 < local_68) {
      local_4c._0_2_ = (ushort)bVar1 << 8;
LAB_0072bc91:
      local_4c = CONCAT22(uVar2,(ushort)local_4c);
    }
    else {
      if ((int)(uint)uVar2 <= local_68) {
        local_4c = CONCAT31((uint3)bVar1,0x60);
        uVar2 = 0;
        goto LAB_0072bc91;
      }
      local_4c = CONCAT22(local_78[*local_70],CONCAT11(bVar1,(char)local_74[*local_70]));
    }
    iVar12 = 1 << ((char)local_50 - bVar11 & 0x1f);
    puVar8 = (undefined4 *)(local_60 + ((local_80 >> (bVar11 & 0x1f)) + local_84) * 4);
    uVar6 = local_84;
    do {
      puVar8 = puVar8 + -iVar12;
      uVar6 = uVar6 - iVar12;
      *puVar8 = local_4c;
    } while (uVar6 != 0);
    for (uVar6 = 1 << ((char)local_50 - 1U & 0x1f); (local_80 & uVar6) != 0; uVar6 = uVar6 >> 1) {
    }
    if (uVar6 == 0) {
      local_80 = 0;
    }
    else {
      local_80 = (uVar6 - 1 & local_80) + uVar6;
    }
    local_70 = local_70 + 1;
    puVar13 = local_28 + local_50;
    *puVar13 = *puVar13 - 1;
    if (*puVar13 == 0) {
      if (local_50 == uVar3) {
        local_4c._0_2_ = CONCAT11((char)local_50 - bVar11,0x40);
        local_4c = (uint)(ushort)local_4c;
        goto joined_r0x0072be03;
      }
      local_50 = (uint)*(ushort *)(param_2 + (uint)*local_70 * 2);
    }
  } while ((local_50 <= local_54) || (uVar6 = uVar4 & local_80, uVar6 == local_5c));
  if (uVar5 == 0) {
    uVar5 = local_54;
  }
  local_60 = local_60 + local_84 * 4;
  iVar9 = local_50 - uVar5;
  uVar10 = uVar5 + iVar9;
  iVar12 = 1 << ((byte)iVar9 & 0x1f);
  if (uVar10 < uVar3) {
    puVar13 = local_28 + uVar10;
    do {
      uVar2 = *puVar13;
      if ((int)(iVar12 - (uint)uVar2) < 1) break;
      uVar10 = uVar10 + 1;
      iVar9 = iVar9 + 1;
      puVar13 = puVar13 + 1;
      iVar12 = (iVar12 - (uint)uVar2) * 2;
    } while (uVar10 < uVar3);
  }
  local_84 = 1 << ((byte)iVar9 & 0x1f);
  local_6c = local_6c + local_84;
  if ((param_1 != 1) || (local_6c < 0x5b0)) {
    *(byte *)(*in_EDX + uVar6 * 4) = (byte)iVar9;
    *(byte *)(*in_EDX + 1 + uVar6 * 4) = bVar7;
    *(short *)(*in_EDX + 2 + uVar6 * 4) = (short)(local_60 - *in_EDX >> 2);
    local_5c = uVar6;
    goto LAB_0072bc56;
  }
LAB_0072be7f:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
joined_r0x0072be03:
  if (local_80 == 0) goto LAB_0072be63;
  if ((uVar5 != 0) && ((uVar4 & local_80) != local_5c)) {
    local_60 = *in_EDX;
    uVar5 = 0;
    local_50 = local_54;
    local_4c._0_2_ = CONCAT11(bVar7,(undefined1)local_4c);
    local_4c = (uint)(ushort)local_4c;
  }
  *(uint *)(local_60 + (local_80 >> ((byte)uVar5 & 0x1f)) * 4) = local_4c;
  for (uVar3 = 1 << ((char)local_50 - 1U & 0x1f); (local_80 & uVar3) != 0; uVar3 = uVar3 >> 1) {
  }
  if (uVar3 == 0) goto LAB_0072be63;
  local_80 = (local_80 & uVar3 - 1) + uVar3;
  goto joined_r0x0072be03;
LAB_0072be63:
  *in_EDX = *in_EDX + local_6c * 4;
  *in_ECX = local_54;
  goto LAB_0072be7f;
}

