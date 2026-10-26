
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0086b490(int param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float *pfVar8;
  float *pfVar9;
  float10 fVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 fVar12;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  int local_194;
  uint local_18c;
  int local_188;
  float local_170 [4];
  float local_160;
  float local_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  float local_110;
  float local_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80;
  undefined4 local_7c;
  float local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  fVar4 = _DAT_00fba93c;
  local_18c = 0;
  if (*(int *)(param_3 + 4) != 0) {
    fVar11 = (float10)0;
    local_188 = 0;
    do {
      fVar12 = (float10)0;
      fVar10 = (float10)-1.0;
      pfVar9 = (float *)(*(int *)(param_3 + 8) + local_188);
      fVar3 = *(float *)(*(int *)(param_3 + 8) + 0x4c + local_188) + fVar4;
      pfVar9[0x13] = fVar3;
      if (pfVar9[0x14] < fVar3) {
        if (local_18c < *(uint *)(param_3 + 4)) {
          iVar5 = *(uint *)(param_3 + 4) - 1;
          *(int *)(param_3 + 4) = iVar5;
          puVar6 = (undefined4 *)(iVar5 * 0x54 + *(int *)(param_3 + 8));
          puVar7 = (undefined4 *)(*(int *)(param_3 + 8) + local_188);
          if (puVar7 != puVar6) {
            *puVar7 = *puVar6;
            puVar7[1] = puVar6[1];
            puVar7[2] = puVar6[2];
            if (puVar7 + 3 != puVar6 + 3) {
              puVar7[6] = puVar6[6];
              puVar7[3] = puVar6[3];
              puVar7[4] = puVar6[4];
              puVar7[5] = puVar6[5];
            }
            puVar7[7] = puVar6[7];
            puVar7[8] = puVar6[8];
            puVar7[9] = puVar6[9];
            puVar7[10] = puVar6[10];
          }
          puVar7[0xb] = puVar6[0xb];
          puVar7[0xc] = puVar6[0xc];
          puVar7[0xd] = puVar6[0xd];
          puVar7[0xe] = puVar6[0xe];
          puVar7[0xf] = puVar6[0xf];
          puVar7[0x10] = puVar6[0x10];
          puVar7[0x11] = puVar6[0x11];
          puVar7[0x12] = puVar6[0x12];
          puVar7[0x13] = puVar6[0x13];
          puVar7[0x14] = puVar6[0x14];
        }
      }
      else {
        fVar1 = pfVar9[0x14];
        local_148 = 1.4013e-45;
        local_170[0] = (float)fVar11;
        local_170[1] = (float)fVar11;
        local_170[2] = (float)fVar11;
        local_170[3] = (float)fVar11;
        local_160 = (float)fVar11;
        local_15c = (float)fVar11;
        local_158 = 1.0;
        local_154 = 1.0;
        local_150 = 1.0;
        local_14c = 1.0;
        iVar5 = FUN_008fed10();
        local_84 = *(float *)(*(int *)(param_1 + 0x26c) + iVar5 * 0xc);
        iVar5 = *(int *)(param_1 + 0x26c) + iVar5 * 0xc;
        local_80 = *(undefined4 *)(iVar5 + 4);
        local_7c = *(undefined4 *)(iVar5 + 8);
        local_90 = (float)((float10)pfVar9[0x12] * extraout_ST1);
        local_88 = (float)((float10)pfVar9[0x12] * fVar12);
        local_b4 = local_84 * local_90;
        local_b0 = local_90 * local_84;
        local_ac = local_84 * local_88;
        local_a8 = (float)((float10)local_b4 * fVar10);
        local_a4 = (float)((float10)local_b0 * fVar10);
        local_a0 = (float)((float10)local_ac * fVar10);
        fVar11 = extraout_ST1;
        local_8c = local_90;
        iVar5 = FUN_008fed10();
        local_100 = pfVar9[0xe];
        local_54 = *(float *)(*(int *)(param_1 + 0x230) + iVar5 * 0xc);
        iVar5 = *(int *)(param_1 + 0x230) + iVar5 * 0xc;
        local_108 = local_100 * pfVar9[0xb];
        local_50 = *(undefined4 *)(iVar5 + 4);
        local_4c = *(undefined4 *)(iVar5 + 8);
        local_104 = pfVar9[0xc] * local_100;
        local_100 = local_100 * pfVar9[0xd];
        local_c0 = local_54 * local_108;
        local_bc = local_104 * local_54;
        local_b8 = local_54 * local_100;
        local_f0 = (float)((float10)local_c0 * fVar12);
        local_ec = (float)((float10)local_bc * fVar12);
        local_e8 = (float)((float10)local_b8 * fVar12);
        local_120 = local_f0 + local_a8;
        local_11c = local_ec + local_a4;
        local_118 = local_e8 + local_a0;
        *pfVar9 = local_120 + *pfVar9;
        pfVar9[1] = local_11c + pfVar9[1];
        pfVar9[2] = local_118 + pfVar9[2];
        fVar10 = extraout_ST1_00;
        iVar5 = FUN_008fed10();
        local_48 = *(float *)(*(int *)(param_1 + 0x26c) + iVar5 * 0xc);
        iVar5 = *(int *)(param_1 + 0x26c) + iVar5 * 0xc;
        local_44 = *(undefined4 *)(iVar5 + 4);
        local_40 = *(undefined4 *)(iVar5 + 8);
        local_cc = (float)((float10)pfVar9[0x12] * extraout_ST1_01);
        local_c4 = (float)((float10)pfVar9[0x12] * fVar10);
        local_9c = local_48 * local_cc;
        local_98 = local_cc * local_48;
        local_94 = local_48 * local_c4;
        local_e4 = (float)((float10)local_9c * fVar11);
        local_e0 = (float)((float10)local_98 * fVar11);
        local_dc = (float)((float10)local_94 * fVar11);
        pfVar9[0xb] = pfVar9[0xb] + local_e4;
        pfVar9[0xc] = local_e0 + pfVar9[0xc];
        pfVar9[0xd] = local_dc + pfVar9[0xd];
        local_c8 = local_cc;
        iVar5 = FUN_008fed10();
        local_d8 = *(undefined4 *)(*(int *)(param_1 + 0x2e4) + iVar5 * 0xc);
        iVar5 = *(int *)(param_1 + 0x2e4) + iVar5 * 0xc;
        local_d4 = *(undefined4 *)(iVar5 + 4);
        local_d0 = *(undefined4 *)(iVar5 + 8);
        iVar5 = FUN_008fed10();
        puVar6 = (undefined4 *)(*(int *)(param_1 + 0x324) + iVar5 * 0xc);
        local_138 = *puVar6;
        local_5c = puVar6[1];
        local_144 = local_d8;
        local_58 = puVar6[2];
        local_140 = local_d4;
        local_13c = local_d0;
        local_60 = local_138;
        iVar5 = FUN_008fed10();
        local_78 = *(float *)(*(int *)(param_1 + 500) + iVar5 * 0xc);
        iVar5 = *(int *)(param_1 + 500) + iVar5 * 0xc;
        local_74 = *(undefined4 *)(iVar5 + 4);
        local_114 = pfVar9[0xf] * local_78;
        local_70 = *(undefined4 *)(iVar5 + 8);
        pfVar9[7] = local_114;
        pfVar9[8] = local_114;
        pfVar9[9] = local_114;
        local_110 = local_114;
        local_10c = local_114;
        iVar5 = FUN_008fed10();
        local_6c = *(undefined4 *)(*(int *)(param_1 + 0x2a8) + iVar5 * 0xc);
        iVar5 = *(int *)(param_1 + 0x2a8) + iVar5 * 0xc;
        local_68 = *(undefined4 *)(iVar5 + 4);
        local_64 = *(undefined4 *)(iVar5 + 8);
        pfVar8 = pfVar9 + 3;
        fVar11 = (float10)FUN_008ff0a0();
        *pfVar8 = (float)((float10)0.0 * fVar11);
        pfVar9[5] = (float)((float10)0.0 * fVar11);
        pfVar9[4] = (float)fVar11;
        fVar11 = (float10)FUN_008fef70();
        pfVar9[6] = (float)fVar11;
        local_128 = *(float *)(param_1 + 0x348);
        local_124 = *(float *)(param_1 + 0x34c);
        fVar11 = (float10)0;
        local_130 = *(float *)(param_1 + 0x340);
        local_12c = *(float *)(param_1 + 0x344);
        iVar5 = *(int *)(param_1 + 0x354);
        iVar2 = *(int *)(param_1 + 0x350);
        local_194 = 0;
        if (fVar11 != (float10)(fVar3 / fVar1)) {
          local_194 = FUN_008fed10();
          fVar11 = extraout_ST0;
        }
        fVar3 = (float)iVar2;
        local_130 = local_130 + (float)(local_194 % iVar2) / fVar3;
        fVar1 = (float)iVar5;
        local_12c = local_12c + (float)(local_194 / iVar5) / fVar1;
        local_128 = local_128 * (1.0 / fVar3);
        local_124 = (1.0 / fVar1) * local_124;
        if (local_170 != pfVar9) {
          local_170[0] = *pfVar9;
          local_170[1] = pfVar9[1];
          local_170[2] = pfVar9[2];
          if (local_170 + 3 != pfVar8) {
            local_158 = pfVar9[6];
            local_170[3] = *pfVar8;
            local_160 = pfVar9[4];
            local_15c = pfVar9[5];
          }
          local_154 = pfVar9[7];
          local_150 = pfVar9[8];
          local_14c = pfVar9[9];
          local_148 = pfVar9[10];
        }
        if (*(int *)(param_1 + 0x364) == 1) {
          FUN_007cd220();
          fVar1 = local_170[1];
          fVar3 = local_170[0];
          local_fc = local_170[0] * local_3c + local_170[1] * local_30 + local_170[2] * local_24 +
                     local_18;
          local_170[0] = local_fc;
          local_f8 = local_170[2] * local_20 + local_170[1] * local_2c + local_38 * fVar3 + local_14
          ;
          local_170[1] = local_f8;
          local_f4 = local_170[2] * local_1c + local_34 * fVar3 + local_28 * fVar1 + local_10;
          fVar11 = (float10)0;
          local_170[2] = local_f4;
        }
        local_134 = (float)fVar11;
        if (*(int *)(param_1 + 0x360) != 0) {
          pfVar9 = *(float **)(param_2 + 0x88);
          if (local_170 < pfVar9) {
            pfVar8 = *(float **)(param_2 + 0x84);
            if (local_170 < pfVar8) goto LAB_0086bd63;
            if (pfVar9 == *(float **)(param_2 + 0x8c)) {
              FUN_0084b590();
              fVar11 = (float10)0;
            }
            pfVar8 = (float *)((((int)local_170 - (int)pfVar8) / 0x50) * 0x50 +
                              *(int *)(param_2 + 0x84));
            pfVar9 = *(float **)(param_2 + 0x88);
            if (pfVar9 != (float *)0x0) goto LAB_0086bd88;
          }
          else {
LAB_0086bd63:
            if (pfVar9 == *(float **)(param_2 + 0x8c)) {
              FUN_0084b590();
              fVar11 = (float10)0;
            }
            pfVar9 = *(float **)(param_2 + 0x88);
            if (pfVar9 != (float *)0x0) {
              pfVar8 = local_170;
LAB_0086bd88:
              for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
                *pfVar9 = *pfVar8;
                pfVar8 = pfVar8 + 1;
                pfVar9 = pfVar9 + 1;
              }
            }
          }
          *(int *)(param_2 + 0x88) = *(int *)(param_2 + 0x88) + 0x50;
        }
        local_18c = local_18c + 1;
        local_188 = local_188 + 0x54;
      }
    } while (local_18c < *(uint *)(param_3 + 4));
  }
  return;
}

