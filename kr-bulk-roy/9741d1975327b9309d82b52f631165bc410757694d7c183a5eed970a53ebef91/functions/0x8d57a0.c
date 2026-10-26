
void FUN_008d57a0(uint param_1)

{
  int iVar1;
  uint uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  uint *in_ECX;
  ushort uVar8;
  int iVar9;
  uint *puVar10;
  undefined1 local_b4 [4];
  int local_b0;
  int local_ac;
  uint local_a8;
  undefined1 local_a4 [4];
  uint local_a0;
  int local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  short local_8c;
  ushort local_8a;
  ushort local_88;
  short local_84;
  ushort local_82;
  uint local_80;
  int local_7c;
  uint *local_78;
  int local_74;
  int local_70;
  undefined4 local_6c;
  undefined1 local_60 [12];
  ushort local_54;
  ushort local_52;
  undefined1 local_50 [12];
  ushort local_44;
  ushort local_42;
  undefined1 local_40 [12];
  ushort local_34;
  ushort local_32;
  undefined1 local_30 [8];
  int local_28;
  int local_20;
  int local_1c;
  short local_18;
  ushort local_16;
  short local_14;
  short local_12;
  int local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_98 = in_ECX[0x19];
  uVar2 = in_ECX[0x1a];
  in_ECX[0x21] = 0;
  local_78 = in_ECX;
  local_74 = FUN_008b97e0(uVar2,0);
  if ((local_74 != 0) || (iVar4 = FUN_008bacd0(uVar2,&DAT_00be80c0,&local_84), iVar4 != 0))
  goto LAB_008d5e0e;
  local_74 = 2;
  if (local_84 == 0x5a4d) {
    local_74 = FUN_008b97e0(uVar2,local_82);
    if ((local_74 != 0) || (iVar4 = FUN_008bacd0(uVar2,&DAT_00be80d4,&local_8c), iVar4 != 0))
    goto LAB_008d5e0e;
    local_74 = 2;
    if (local_8c == 0x454e) {
      local_7c = 0;
      local_74 = FUN_008b97e0(uVar2,(uint)local_8a + (uint)local_82);
      if ((local_74 != 0) ||
         (local_74 = FUN_008babe0(uVar2,(uint)local_88 - (uint)local_8a), local_74 != 0))
      goto LAB_008d5e0e;
      local_80 = FUN_008b9990(uVar2);
      local_80 = local_80 & 0xffff;
      sVar3 = FUN_008b9990(uVar2);
      while (uVar5 = 0, sVar3 != 0) {
        uVar5 = FUN_008b9990(uVar2);
        uVar5 = uVar5 & 0xffff;
        if (sVar3 == -0x7ff8) {
          iVar4 = FUN_008b9850(uVar2);
          local_7c = iVar4 + 4 + (*(int *)(uVar2 + 0x20) - *(int *)(uVar2 + 0x24));
          break;
        }
        *(int *)(uVar2 + 0x20) = *(int *)(uVar2 + 0x20) + uVar5 * 0xc + 4;
        sVar3 = FUN_008b9990();
      }
      FUN_008baca0(uVar2);
      puVar10 = local_78;
      iVar4 = local_74;
      if ((((short)uVar5 == 0) || (local_7c == 0)) ||
         (*(uint *)(uVar2 + 4) <= uVar5 * 0x76 && uVar5 * 0x76 - *(uint *)(uVar2 + 4) != 0))
      goto LAB_008d5ace;
      *local_78 = uVar5;
      if ((int)uVar5 <= (int)param_1) goto LAB_008d5956;
      if ((int)param_1 < 0) goto LAB_008d5e0e;
      uVar5 = FUN_008baee0(local_98,0xac,&local_74);
      puVar10[0x21] = uVar5;
      if (local_74 != 0) goto LAB_008d5e0e;
      local_74 = FUN_008b97e0(uVar2,local_7c + param_1 * 0xc);
      if ((local_74 != 0) || (local_74 = FUN_008babe0(uVar2,0xc), uVar5 = local_80, local_74 != 0))
      goto LAB_008d5e04;
      uVar6 = FUN_008b9990(uVar2);
      *(uint *)local_78[0x21] = (uVar6 & 0xffff) << ((byte)uVar5 & 0x1f);
      uVar6 = FUN_008b9990(uVar2);
      *(uint *)(local_78[0x21] + 0xa4) = (uVar6 & 0xffff) << ((byte)uVar5 & 0x1f);
      *(int *)(uVar2 + 0x20) = *(int *)(uVar2 + 0x20) + 8;
      FUN_008baca0(uVar2);
      local_74 = FUN_008d56e0();
      puVar10 = local_78;
    }
    else {
      puVar10 = in_ECX;
      if (local_8c == 0x4550) {
        local_74 = FUN_008b97e0(uVar2,local_82);
        if ((local_74 == 0) &&
           (local_74 = FUN_008bacd0(uVar2,&DAT_00be80ec,&local_1c), local_74 == 0)) {
          iVar4 = 0;
          if ((local_1c == 0x4550) &&
             (((local_18 == 0x14c && (local_14 == 0xe0)) && (local_12 == 0x10b)))) {
            *in_ECX = 0;
            uVar8 = 0;
            if (local_16 != 0) {
              do {
                local_74 = 0;
                local_74 = FUN_008bacd0(uVar2,&DAT_00be8120,local_30);
                if (local_74 != 0) goto LAB_008d5e0e;
                if (local_10 == local_28) {
                  local_74 = FUN_008b97e0(uVar2,local_20);
                  if ((local_74 != 0) ||
                     (local_74 = FUN_008bacd0(uVar2,&DAT_00be8140,local_50), local_74 != 0))
                  goto LAB_008d5e0e;
                  local_7c = local_20;
                  local_80 = 0;
                  puVar10 = local_78;
                  if ((uint)local_42 + (uint)local_44 == 0) goto LAB_008d5de8;
                  uVar5 = 0;
                  local_74 = 0;
                  goto LAB_008d5b36;
                }
                uVar8 = uVar8 + 1;
                iVar4 = 0;
              } while (uVar8 < local_16);
            }
          }
          goto LAB_008d5ace;
        }
        goto LAB_008d5e0e;
      }
    }
    goto LAB_008d5de8;
  }
  goto LAB_008d5e04;
  while( true ) {
    iVar4 = 0;
    if (-1 < (int)local_a8) goto LAB_008d5ace;
    local_a8 = local_a8 & 0x7fffffff;
    iVar9 = local_a8 + local_20;
    local_9c = iVar9;
    local_74 = FUN_008b97e0(uVar2,iVar9);
    if ((local_74 != 0) || (local_74 = FUN_008bacd0(uVar2,&DAT_00be8140,local_60), local_74 != 0))
    goto LAB_008d5e0e;
    local_90 = 0;
    if ((uint)local_52 + (uint)local_54 != 0) {
      uVar5 = 0;
      local_90 = 0;
      local_74 = 0;
      do {
        local_74 = FUN_008b97e0(uVar2,iVar9 + 0x10 + uVar5 * 8);
        if ((local_74 != 0) ||
           (local_74 = FUN_008bacd0(uVar2,&DAT_00be8160,local_a4), local_74 != 0))
        goto LAB_008d5e0e;
        iVar4 = 0;
        if (-1 < (int)local_a0) goto LAB_008d5ace;
        local_a0 = local_a0 & 0x7fffffff;
        iVar1 = local_a0 + local_20;
        local_74 = FUN_008b97e0(uVar2,iVar1);
        if ((local_74 != 0) ||
           (local_74 = FUN_008bacd0(uVar2,&DAT_00be8140,local_40), local_74 != 0))
        goto LAB_008d5e0e;
        local_94 = 0;
        if ((uint)local_32 + (uint)local_34 != 0) {
          uVar5 = 0;
          local_94 = 0;
          local_74 = 0;
          do {
            local_74 = FUN_008b97e0(uVar2,iVar1 + 0x10 + uVar5 * 8);
            if ((local_74 != 0) ||
               (local_74 = FUN_008bacd0(uVar2,&DAT_00be8160,local_b4), local_74 != 0))
            goto LAB_008d5e0e;
            iVar4 = 0;
            if ((local_a0 & 0x80000000) != 0) goto LAB_008d5ace;
            if (local_ac == 8) {
              local_74 = FUN_008b97e0(uVar2,local_b0 + local_7c);
              if ((local_74 != 0) ||
                 (local_74 = FUN_008bacd0(uVar2,&DAT_00be8170,&local_70), puVar10 = local_78,
                 local_74 != 0)) goto LAB_008d5e0e;
              if (param_1 == *local_78) {
                piVar7 = (int *)FUN_008baee0(local_98,0xac,&local_74);
                puVar10[0x21] = (uint)piVar7;
                if (local_74 != 0) goto LAB_008d5e0e;
                *piVar7 = (local_70 - local_28) + local_20;
                *(undefined4 *)(puVar10[0x21] + 0xa4) = local_6c;
                local_74 = FUN_008d56e0();
                if (local_74 != 0) goto LAB_008d5e04;
              }
              *puVar10 = *puVar10 + 1;
            }
            local_94 = local_94 + 1;
            uVar5 = local_94 & 0xffff;
            iVar9 = local_9c;
          } while (uVar5 < (uint)local_32 + (uint)local_34);
        }
        local_90 = local_90 + 1;
        uVar5 = local_90 & 0xffff;
      } while (uVar5 < (uint)local_52 + (uint)local_54);
    }
    local_80 = local_80 + 1;
    uVar5 = local_80 & 0xffff;
    puVar10 = local_78;
    if ((uint)local_42 + (uint)local_44 <= uVar5) break;
LAB_008d5b36:
    local_74 = FUN_008b97e0(uVar2,local_7c + 0x10 + uVar5 * 8);
    if ((local_74 != 0) || (local_74 = FUN_008bacd0(uVar2,&DAT_00be8160,&local_ac), local_74 != 0))
    goto LAB_008d5e0e;
  }
LAB_008d5de8:
  iVar4 = local_74;
  if (*puVar10 == 0) {
LAB_008d5ace:
    local_74 = iVar4;
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if ((int)*puVar10 <= (int)param_1) {
LAB_008d5956:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (local_74 == 0) goto LAB_008d5e0e;
LAB_008d5e04:
  FUN_008d5680();
LAB_008d5e0e:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

