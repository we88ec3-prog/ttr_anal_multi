
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00802850(float param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,
                 undefined4 param_17)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  float *pfVar7;
  undefined4 *puVar8;
  uint uVar9;
  float10 fVar10;
  float local_d4;
  int *local_d0;
  int *local_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  uint local_ac;
  float local_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50 [12];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_d4;
  local_d4 = param_1;
  if (*(int *)(in_ECX + 4) != 0) {
    puVar5 = &param_2;
    puVar8 = (undefined4 *)(in_ECX + 0xa4);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 1;
    }
    param_16 = 0;
    param_15 = 0;
    param_14 = 0;
    param_13 = 0;
    param_11 = 0;
    param_10 = 0;
    param_9 = 0;
    param_8 = 0;
    param_6 = 0;
    param_5 = 0;
    param_4 = 0;
    param_3 = 0;
    param_17 = 0x3f800000;
    param_12 = 0x3f800000;
    param_7 = 0x3f800000;
    param_2 = 0x3f800000;
  }
  if (_DAT_00f8b024 <= *(float *)(in_ECX + 0x18)) {
    local_d4 = (*(float *)(in_ECX + 0x18) + 0.016666668) * 0.5;
    *(float *)(in_ECX + 0x18) = *(float *)(in_ECX + 0x18) - local_d4;
    local_cc = (int *)(local_d4 + *(float *)(in_ECX + 0x7c));
    *(int **)(in_ECX + 0x7c) = local_cc;
    if ((float)local_cc < *(float *)(in_ECX + 0x84)) {
      FUN_00802410(in_ECX,local_d4);
    }
    local_d0 = (int *)(*(float *)(in_ECX + 0x7c) / *(float *)(in_ECX + 0x84));
    fVar10 = (float10)FUN_00801230(local_d0);
    local_68 = (float)fVar10;
    fVar10 = (float10)FUN_00801230(local_d0);
    local_64 = (float)fVar10;
    fVar10 = (float10)FUN_00801230(local_d0);
    local_60 = (float)fVar10;
    local_b8 = local_d4 * local_68;
    local_b4 = local_64 * local_d4;
    local_b0 = local_60 * local_d4;
    local_cc = *(int **)(in_ECX + 0x90);
    local_5c = (float)local_cc * local_b8;
    local_58 = local_b4 * (float)local_cc;
    local_54 = (float)local_cc * local_b0;
    if (*(int *)(in_ECX + 4) != 0) {
      puVar5 = (undefined4 *)(in_ECX + 0xa4);
      puVar8 = local_50;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar8 = puVar8 + 1;
      }
      local_18 = 0;
      local_1c = 0;
      local_20 = 0;
      D3DXMatrixInverse(local_50,0,local_50);
      D3DXVec3TransformCoord(&local_68,&local_68,&local_5c);
      local_cc = *(int **)(in_ECX + 0xec);
      local_5c = (float)local_cc * local_5c;
      local_58 = local_58 * (float)local_cc;
      local_54 = (float)local_cc * local_54;
    }
    uVar6 = 0;
    *(undefined4 *)(in_ECX + 0x88) = 0;
    fVar1 = *(float *)(*(int *)(in_ECX + 0xe4) + 0x154);
    uVar9 = *(int *)(in_ECX + 0x98) - *(int *)(in_ECX + 0x94) >> 2;
    local_a8 = fVar1 * fVar1 * *(float *)(in_ECX + 0x90) * *(float *)(in_ECX + 0x90);
    local_ac = uVar9;
    if (uVar9 != 0) {
      do {
        (**(code **)(**(int **)(*(int *)(in_ECX + 0x94) + uVar6 * 4) + 8))
                  (local_d4,&param_2,*(undefined4 *)(in_ECX + 0x90));
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar9);
    }
    local_d0 = *(int **)(in_ECX + 0xe8);
    piVar4 = local_d0 + *(int *)(in_ECX + 0x8c) * 0x25;
    local_cc = piVar4;
    if (local_d0 != piVar4) {
      pfVar7 = (float *)(local_d0 + 0xe);
      fVar1 = local_d4;
      do {
        if (*local_d0 != 0) {
          fStack_c8 = pfVar7[6] / pfVar7[5];
          if (pfVar7[2] == 0.0) {
            fStack_c4 = pfVar7[3];
          }
          else {
            fStack_c4 = pfVar7[4] * fStack_c8 + (1.0 - fStack_c8) * pfVar7[3];
          }
          uVar6 = 0;
          local_b8 = pfVar7[-10] * fVar1;
          local_b4 = fVar1 * pfVar7[-9];
          local_b0 = pfVar7[-8] * fVar1;
          fStack_74 = fStack_c4 * local_b8;
          fStack_70 = local_b4 * fStack_c4;
          fStack_6c = fStack_c4 * local_b0;
          pfVar7[-0xd] = pfVar7[-0xd] + fStack_74;
          pfVar7[-0xc] = fStack_70 + pfVar7[-0xc];
          pfVar7[-0xb] = pfVar7[-0xb] + fStack_6c;
          pfVar7[6] = fVar1 + pfVar7[6];
          fStack_c0 = pfVar7[-9] * pfVar7[-9] + pfVar7[-10] * pfVar7[-10] + pfVar7[-8] * pfVar7[-8];
          if (local_ac != 0) {
            do {
              (**(code **)(**(int **)(*(int *)(in_ECX + 0x94) + uVar6 * 4) + 0xc))
                        (fVar1,local_d0,&param_2,*(undefined4 *)(in_ECX + 0x90));
              uVar6 = uVar6 + 1;
              piVar4 = local_cc;
              fVar1 = local_d4;
            } while (uVar6 < local_ac);
          }
          if (pfVar7[-1] == 0.0) {
            fStack_9c = *pfVar7;
          }
          else {
            fStack_9c = pfVar7[1] * fStack_c8 + (1.0 - fStack_c8) * *pfVar7;
          }
          if (pfVar7[-4] == 0.0) {
            fStack_c4 = pfVar7[-3];
          }
          else {
            fStack_c4 = pfVar7[-2] * fStack_c8 + (1.0 - fStack_c8) * pfVar7[-3];
          }
          if (pfVar7[-7] == 0.0) {
            fStack_c8 = pfVar7[-6];
          }
          else {
            fStack_c8 = (1.0 - fStack_c8) * pfVar7[-6] + pfVar7[-5] * fStack_c8;
          }
          fStack_a4 = fStack_c8 * fVar1;
          fStack_a0 = fVar1 * fStack_c4;
          fStack_9c = fVar1 * fStack_9c;
          fStack_98 = pfVar7[-10] + fStack_a4;
          fStack_94 = fStack_a0 + pfVar7[-9];
          fStack_90 = pfVar7[-8] + fStack_9c;
          local_68 = fStack_98 + local_5c;
          local_64 = fStack_94 + local_58;
          fVar2 = fStack_90 + local_54;
          fStack_bc = fVar2 * fVar2 + local_64 * local_64 + local_68 * local_68;
          local_60 = fVar2;
          if (((fStack_c0 < fStack_bc != (fStack_c0 == fStack_bc)) && (fStack_bc <= local_a8)) ||
             (fStack_bc < fStack_c0)) {
            pfVar7[-10] = local_68;
            pfVar7[-9] = local_64;
          }
          else {
            D3DXVec3Normalize(&local_68,&local_68);
            fStack_78 = *(float *)(*(int *)(in_ECX + 0xe4) + 0x154);
            fStack_80 = fStack_78 * local_68;
            fStack_7c = local_64 * fStack_78;
            fStack_78 = fStack_78 * local_60;
            fStack_c0 = *(float *)(in_ECX + 0x90);
            fStack_8c = fStack_c0 * fStack_80;
            pfVar7[-10] = fStack_8c;
            fStack_88 = fStack_7c * fStack_c0;
            pfVar7[-9] = fStack_88;
            fVar2 = fStack_c0 * fStack_78;
            piVar4 = local_cc;
            fVar1 = local_d4;
            fStack_84 = fVar2;
          }
          pfVar7[-8] = fVar2;
          if (pfVar7[6] <= pfVar7[5]) {
            *(int *)(in_ECX + 0x88) = *(int *)(in_ECX + 0x88) + 1;
          }
          else {
            *local_d0 = 0;
          }
        }
        local_d0 = local_d0 + 0x25;
        pfVar7 = pfVar7 + 0x25;
      } while (local_d0 != piVar4);
    }
    __security_check_cookie(local_c ^ (uint)&local_d4);
    return;
  }
  *(float *)(in_ECX + 0x18) = param_1 + *(float *)(in_ECX + 0x18);
  __security_check_cookie(local_c ^ (uint)&local_d4);
  return;
}

