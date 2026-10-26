
void FUN_008c7420(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  size_t _Size;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  byte bVar7;
  int iVar8;
  uint uVar9;
  int unaff_EBX;
  undefined1 *puVar10;
  uint *puVar11;
  int local_54;
  uint *local_48;
  uint local_44;
  void *local_40;
  uint local_3c;
  int local_38 [2];
  int local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *(undefined4 *)(unaff_EBX + 0x1c);
  local_38[0] = 0;
  local_48 = (uint *)0x0;
  local_40 = (void *)0x0;
  local_54 = 0;
  local_44 = 0;
  local_38[0] = FUN_008bacd0();
  if (((((local_38[0] != 0) || (local_30 == 0x774f4646)) || (local_30 == 0x74746366)) ||
      ((local_2c != *(uint *)(unaff_EBX + 4) || ((short)local_28 == 0)))) ||
     ((local_2c <= (local_28 & 0xffff) * 0x14 + 0x2c ||
      ((local_24 <= (local_28 & 0xffff) * 0x10 + 0xc || ((local_24 & 3) != 0)))))) {
LAB_008c74c0:
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  if (local_1c == 0) {
    if ((local_18 != 0) || (local_14 != 0)) goto LAB_008c74c0;
  }
  else if ((local_18 != 0) && (local_14 == 0)) goto LAB_008c74c0;
  if ((local_10 == 0) && (local_c != 0)) goto LAB_008c74c0;
  puVar3 = (undefined1 *)FUN_008baee0(uVar1,local_24,local_38);
  if ((local_38[0] != 0) || (local_54 = FUN_008baee0(uVar1,0x28,local_38), local_38[0] != 0))
  goto LAB_008c7866;
  iVar8 = 0;
  for (uVar4 = local_28 & 0xffff; uVar4 != 0; uVar4 = uVar4 >> 1) {
    iVar8 = iVar8 + 1;
  }
  *puVar3 = (char)((uint)local_30 >> 0x18);
  bVar7 = (byte)(iVar8 + -1);
  iVar5 = 1 << (bVar7 & 0x1f);
  puVar3[1] = (char)((uint)local_30 >> 0x10);
  iVar6 = iVar5 * 0x10;
  iVar5 = (local_28 & 0xffff) * 0x10 + iVar5 * -0x10;
  puVar3[2] = (char)((uint)local_30 >> 8);
  puVar3[3] = (undefined1)local_30;
  puVar3[4] = (char)(local_28 >> 8);
  puVar3[5] = (undefined1)local_28;
  puVar3[6] = (char)((uint)iVar6 >> 8);
  puVar3[7] = (char)iVar6;
  puVar3[8] = (char)((uint)(iVar8 + -1) >> 8);
  puVar3[9] = bVar7;
  puVar3[10] = (char)((uint)iVar5 >> 8);
  puVar3[0xb] = (char)iVar5;
  puVar10 = puVar3 + 0xc;
  local_48 = (uint *)FUN_008bc7d0(uVar1,0x18,0,local_28 & 0xffff,0,local_38);
  if (((local_38[0] != 0) ||
      (local_40 = (void *)FUN_008bc7d0(uVar1,4,0,local_28 & 0xffff,0,local_38), local_38[0] != 0))
     || (local_38[0] = FUN_008babe0(), local_38[0] != 0)) goto LAB_008c7866;
  local_3c = 0;
  if ((short)local_28 != 0) {
    local_3c = 0;
    puVar11 = local_48;
    do {
      uVar4 = FUN_008b99c0();
      *puVar11 = uVar4;
      uVar4 = FUN_008b99c0();
      puVar11[1] = uVar4;
      uVar4 = FUN_008b99c0();
      puVar11[2] = uVar4;
      uVar4 = FUN_008b99c0();
      puVar11[3] = uVar4;
      uVar4 = FUN_008b99c0();
      puVar11[4] = uVar4;
      uVar4 = *puVar11;
      if (uVar4 <= local_44) {
        FUN_008baca0();
        goto LAB_008c785f;
      }
      *(uint **)((int)local_40 + local_3c * 4) = puVar11;
      local_3c = local_3c + 1;
      puVar11 = puVar11 + 6;
      local_44 = uVar4;
    } while ((int)local_3c < (int)(local_28 & 0xffff));
  }
  FUN_008baca0();
  _qsort(local_40,local_28 & 0xffff,4,FUN_008c73f0);
  uVar9 = local_28 & 0xffff;
  local_44 = uVar9 * 0x14 + 0x2c;
  uVar4 = uVar9 * 0x10 + 0xc;
  iVar8 = 0;
  if (uVar9 != 0) {
    do {
      uVar9 = *(uint *)(*(int *)((int)local_40 + iVar8 * 4) + 4);
      if (((uVar9 != local_44) ||
          (uVar2 = *(uint *)(*(int *)((int)local_40 + iVar8 * 4) + 8), local_2c < uVar9 + uVar2)) ||
         ((local_3c = *(uint *)(*(int *)((int)local_40 + iVar8 * 4) + 0xc),
          local_24 < local_3c + uVar4 || (local_3c < uVar2)))) goto LAB_008c785f;
      *(uint *)(*(int *)((int)local_40 + iVar8 * 4) + 0x14) = uVar4;
      local_44 = local_44 + (uVar2 + 3 & 0xfffffffc);
      uVar4 = uVar4 + (local_3c + 3 & 0xfffffffc);
      iVar8 = iVar8 + 1;
    } while (iVar8 < (int)(local_28 & 0xffff));
  }
  uVar9 = local_44;
  if (local_1c == 0) {
LAB_008c7742:
    if (local_10 != 0) {
      uVar9 = uVar9 + 3 & 0xfffffffc;
      if ((local_10 != uVar9) || (local_2c < local_c + local_10)) goto LAB_008c785f;
      uVar9 = uVar9 + local_c;
    }
    if ((uVar4 == local_24) && (uVar9 == local_2c)) {
      local_3c = 0;
      if ((short)local_28 != 0) {
        puVar11 = local_48 + 4;
        do {
          *puVar10 = *(undefined1 *)((int)puVar11 + -0xd);
          puVar10[1] = *(undefined1 *)((int)puVar11 + -0xe);
          puVar10[2] = (char)(puVar11[-4] >> 8);
          puVar10[3] = (char)puVar11[-4];
          puVar10[4] = *(undefined1 *)((int)puVar11 + 3);
          puVar10[5] = *(undefined1 *)((int)puVar11 + 2);
          puVar10[6] = (char)(*puVar11 >> 8);
          puVar10[7] = (char)*puVar11;
          puVar10[8] = *(undefined1 *)((int)puVar11 + 7);
          puVar10[9] = *(undefined1 *)((int)puVar11 + 6);
          puVar10[10] = (char)(puVar11[1] >> 8);
          puVar10[0xb] = (char)puVar11[1];
          puVar10[0xc] = *(undefined1 *)((int)puVar11 + -1);
          puVar10[0xd] = *(undefined1 *)((int)puVar11 + -2);
          puVar10[0xe] = (char)(puVar11[-1] >> 8);
          puVar10[0xf] = (char)puVar11[-1];
          puVar10 = puVar10 + 0x10;
          local_38[0] = FUN_008b97e0();
          if ((local_38[0] != 0) || (local_38[0] = FUN_008babe0(), local_38[0] != 0))
          goto LAB_008c7866;
          _Size = puVar11[-1];
          if (puVar11[-2] == _Size) {
            FID_conflict__memcpy(puVar3 + puVar11[1],*(void **)(unaff_EBX + 0x20),_Size);
          }
          else {
            local_44 = _Size;
            local_38[0] = FUN_008fbd60(uVar1,puVar3 + puVar11[1],&local_44,
                                       *(undefined4 *)(unaff_EBX + 0x20),puVar11[-2]);
            if (local_38[0] != 0) goto LAB_008c7866;
            if (local_44 != puVar11[-1]) goto LAB_008c785f;
          }
          FUN_008baca0();
          for (uVar4 = puVar11[-1] + puVar11[1]; (uVar4 & 3) != 0; uVar4 = uVar4 + 1) {
            puVar3[uVar4] = 0;
          }
          local_3c = local_3c + 1;
          puVar11 = puVar11 + 6;
        } while ((int)local_3c < (int)(local_28 & 0xffff));
      }
      FUN_008b9790(local_54,puVar3,local_24);
      *(undefined4 *)(local_54 + 0x1c) = *(undefined4 *)(unaff_EBX + 0x1c);
      *(code **)(local_54 + 0x18) = FUN_008c73c0;
      FUN_008ba2d0(*(undefined4 *)(param_1 + 0x68),*(uint *)(param_1 + 8) >> 10 & 1);
      *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffbff;
      *(int *)(param_1 + 0x68) = local_54;
      goto LAB_008c7866;
    }
  }
  else if ((local_1c == local_44) && (local_18 + local_1c <= local_2c)) {
    uVar9 = local_44 + local_18;
    goto LAB_008c7742;
  }
LAB_008c785f:
  local_38[0] = 8;
LAB_008c7866:
  FUN_008b9f80(uVar1,local_48);
  FUN_008b9f80(uVar1,local_40);
  if (local_38[0] != 0) {
    FUN_008b9f80(uVar1,puVar3);
    FUN_008b97c0(local_54);
    FUN_008b9f80(uVar1,local_54);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

