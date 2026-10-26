
void FUN_0083e0c0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *in_ECX;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  float *pfVar11;
  float *pfVar12;
  float *pfVar13;
  undefined4 *puVar14;
  undefined4 local_100 [4];
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  float local_d4 [4];
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  int local_90;
  undefined4 local_8c;
  float *local_88;
  int local_84;
  int *local_80;
  int *local_7c;
  float local_78;
  float local_74;
  float local_70;
  int local_6c;
  undefined8 local_68;
  float local_60;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_90 = param_1;
  local_80 = in_ECX;
  if (DAT_00fba930 != *(int *)(param_1 + 0x448)) {
    (**(code **)(**(int **)(param_1 + 0xec) + 0x15c))
              (*(int **)(param_1 + 0xec),*(int *)(param_1 + 0x448));
    DAT_00fba930 = *(int *)(param_1 + 0x448);
  }
  (**(code **)(**(int **)(param_1 + 0xec) + 0x1a0))
            (*(int **)(param_1 + 0xec),*(undefined4 *)(param_1 + 0x44c));
  local_6c = in_ECX[0x1c];
  if ((local_6c != 0) && (in_ECX[0x1b] != 0)) {
    local_7c = (int *)0x0;
    local_8c = 0;
    local_88 = (float *)FUN_00838eb0(in_ECX[0x17] * local_6c * 4,&local_7c,&local_8c);
    if (local_88 != (float *)0x0) {
      iVar5 = 2;
      if (in_ECX[0xf] != 0) {
        iVar5 = FUN_00844b70();
      }
      local_68 = CONCAT44(*(undefined4 *)(param_1 + 0xac),*(undefined4 *)(param_1 + 0xa0));
      local_60 = *(float *)(param_1 + 0xb8);
      if (iVar5 == 2) {
        FUN_00840490(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xac),local_60);
      }
      pfVar11 = (float *)(param_1 + 0x98);
      pfVar13 = local_d4;
      for (iVar5 = 0xd; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar13 = *pfVar11;
        pfVar11 = pfVar11 + 1;
        pfVar13 = pfVar13 + 1;
      }
      local_78 = -local_d4[2];
      local_74 = -local_c0;
      local_70 = -local_b4;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0x3f800000;
      local_68 = 0x3f80000000000000;
      local_60 = 0.0;
      FUN_00780610();
      iVar5 = local_6c;
      if (local_6c != 0) {
        local_6c = 0;
        local_84 = iVar5;
        do {
          puVar10 = (undefined4 *)(local_80[0x1b] + local_6c);
          if (puVar10 != (undefined4 *)0x0) {
            local_68._0_4_ = (uint)(longlong)ROUND((float)puVar10[0xb] * 255.0);
            uVar8 = (uint)local_68 & 0xff;
            local_68._0_4_ = (uint)(longlong)ROUND((float)puVar10[0xe] * 255.0);
            uVar6 = (uint)local_68 << 8;
            local_68._0_4_ = (uint)(longlong)ROUND((float)puVar10[0xc] * 255.0);
            uVar9 = (uint)local_68 & 0xff;
            local_68 = (longlong)ROUND((float)puVar10[0xd] * 255.0);
            local_60 = (float)(((uVar8 | uVar6) << 8 | uVar9) << 8 | (uint)local_68 & 0xff);
            puVar7 = puVar10;
            puVar14 = local_100;
            for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
              *puVar14 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar14 = puVar14 + 1;
            }
            puVar7 = (undefined4 *)FUN_0077e880(local_100 + 3);
            if (local_100 + 3 != puVar7) {
              local_e8 = puVar7[3];
              local_100[3] = *puVar7;
              local_f0 = puVar7[1];
              local_ec = puVar7[2];
            }
            fVar1 = (float)(int)local_60;
            if ((int)local_60 < 0) {
              fVar1 = fVar1 + 4.2949673e+09;
            }
            pfVar11 = (float *)&DAT_00f7aee0;
            local_60 = fVar1;
            do {
              FUN_007cd220();
              pfVar13 = local_88 + 6;
              pfVar12 = pfVar11 + 6;
              local_78 = *pfVar11 * local_bc + local_d4[3] * pfVar11[-1] + local_d4[0] * pfVar11[-2]
                         + local_b0;
              local_74 = *pfVar11 * local_b8 + local_c4 * pfVar11[-1] + local_d4[1] * pfVar11[-2] +
                         local_ac;
              fVar1 = pfVar11[-2];
              fVar2 = pfVar11[-1];
              fVar3 = *pfVar11;
              *local_88 = local_78;
              local_88[1] = local_74;
              local_70 = fVar3 * local_b4 + local_c0 * fVar2 + local_d4[2] * fVar1 + local_a8;
              local_88[2] = local_70;
              local_88[3] = local_60;
              local_88[4] = pfVar11[2] * (float)puVar10[0x12] + (float)puVar10[0x10];
              local_88[5] = pfVar11[3] * (float)puVar10[0x13] + (float)puVar10[0x11];
              pfVar11 = pfVar12;
              local_88 = pfVar13;
            } while ((int)pfVar12 < 0xf7af40);
          }
          local_6c = local_6c + 0x50;
          local_84 = local_84 + -1;
        } while (local_84 != 0);
        local_84 = 0;
        param_1 = local_90;
      }
      iVar5 = *(int *)(*(int *)(param_1 + 0x354) + *(int *)(param_1 + 0x364) * 4);
      if ((*(int *)(iVar5 + 0x14) != 0) && (piVar4 = *(int **)(iVar5 + 8), piVar4 != (int *)0x0)) {
        (**(code **)(*piVar4 + 0x30))(piVar4);
        *(undefined4 *)(iVar5 + 0x14) = 0;
      }
      piVar4 = local_7c;
      (**(code **)(**(int **)(param_1 + 0xec) + 400))
                (*(int **)(param_1 + 0xec),0,local_7c,local_8c,local_80[0x17]);
      local_18 = 0;
      local_1c = 0;
      local_20 = 0;
      local_24 = 0;
      local_2c = 0;
      local_30 = 0;
      local_34 = 0;
      local_38 = 0;
      local_40 = 0;
      local_44 = 0;
      local_48 = 0;
      local_4c = 0;
      local_14 = 0x3f800000;
      local_28 = 0x3f800000;
      local_3c = 0x3f800000;
      local_50 = 0x3f800000;
      (**(code **)(**(int **)(param_1 + 0xec) + 0xb0))(*(int **)(param_1 + 0xec),0x100,&local_50);
      iVar5 = local_80[0x18] + *local_80 * 0x14;
      (**(code **)(**(int **)(param_1 + 0xec) + 0x148))
                (*(int **)(param_1 + 0xec),local_80[0x13],*(undefined4 *)(iVar5 + 0xc),0,
                 *(undefined4 *)(iVar5 + 0x10),*(int *)(iVar5 + 4) * 3,*(undefined4 *)(iVar5 + 8));
      (**(code **)(*piVar4 + 8))(piVar4);
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar5 = *(int *)(*(int *)(param_1 + 0x354) + *(int *)(param_1 + 0x364) * 4);
    if ((*(int *)(iVar5 + 0x14) != 0) && (piVar4 = *(int **)(iVar5 + 8), piVar4 != (int *)0x0)) {
      (**(code **)(*piVar4 + 0x30))(piVar4);
      *(undefined4 *)(iVar5 + 0x14) = 0;
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

