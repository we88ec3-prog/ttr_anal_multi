
void FUN_007e16e0(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  float *pfVar8;
  undefined1 auStack_234 [8];
  uint local_22c;
  longlong local_228;
  float *local_21c;
  float *local_218;
  uint local_214;
  uint local_210;
  float local_20c;
  float local_208;
  float local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  float local_1e8;
  float local_1e4;
  float local_1e0;
  uint local_1dc;
  float local_1d8;
  float fStack_1d4;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  float fStack_1b8;
  float fStack_1b4;
  float fStack_1b0;
  float fStack_1ac;
  float fStack_1a8;
  float fStack_1a4;
  float fStack_1a0;
  float fStack_19c;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  float fStack_174;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  float fStack_148;
  float fStack_144;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_104;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f4;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b4;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  int iStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_234;
  local_21c = *(float **)(*(int *)(param_1 + 0xc + *(int *)(param_1 + 4) * 4) + 8);
  pfVar8 = *(float **)(*(int *)(param_1 + 0xc + *(int *)(param_1 + 8) * 4) + 8);
  iVar5 = 0;
  if (pfVar8 == (float *)0x0) {
    pfVar8 = *(float **)(*(int *)(param_1 + 0xc) + 8);
  }
  if (local_21c == (float *)0x0) {
    local_21c = *(float **)(*(int *)(param_1 + 0xc) + 8);
  }
  local_218 = pfVar8;
  if (((pfVar8 != (float *)0x0) && (local_21c != (float *)0x0)) &&
     (local_1dc = (int)pfVar8[10] - (int)pfVar8[9] >> 2,
     local_1dc == (int)local_21c[10] - (int)local_21c[9] >> 2)) {
    local_1d8 = 1.0 - *(float *)(param_1 + 0x30);
    local_20c = local_1d8 * *local_21c;
    local_208 = local_21c[1] * local_1d8;
    local_204 = local_21c[2] * local_1d8;
    local_200 = local_1d8 * local_21c[3];
    local_1e0 = *(float *)(param_1 + 0x30);
    local_1ec = local_1e0 * *pfVar8;
    local_1e8 = pfVar8[1] * local_1e0;
    local_1e4 = pfVar8[2] * local_1e0;
    local_1e0 = local_1e0 * pfVar8[3];
    local_1fc = local_1ec + local_20c;
    local_1f8 = local_1e8 + local_208;
    local_1f4 = local_1e4 + local_204;
    local_1f0 = local_1e0 + local_200;
    if (local_1fc < 1.0) {
      if (0.0 < local_1fc) {
        local_228 = (longlong)ROUND(local_1fc * 255.0 + 0.5);
        local_210 = (uint)local_228;
      }
      else {
        local_210 = 0;
      }
    }
    else {
      local_210 = 0xff;
    }
    if (local_1f8 < 1.0) {
      if (local_1f8 < 0.0 == (local_1f8 == 0.0)) {
        local_228 = (longlong)ROUND(local_1f8 * 255.0 + 0.5);
        local_214 = (uint)local_228;
      }
      else {
        local_214 = 0;
      }
    }
    else {
      local_214 = 0xff;
    }
    if (local_1f4 < 1.0) {
      if (local_1f4 < 0.0 == (local_1f4 == 0.0)) {
        local_228 = (longlong)ROUND(local_1f4 * 255.0 + 0.5);
        local_22c = (uint)local_228;
      }
      else {
        local_22c = 0;
      }
    }
    else {
      local_22c = 0xff;
    }
    if (local_1f0 < 1.0) {
      if (0.0 < local_1f0) {
        local_228 = (longlong)ROUND(local_1f0 * 255.0 + 0.5);
        iVar5 = (uint)local_228;
      }
    }
    else {
      iVar5 = 0xff;
    }
    uVar2 = FUN_00434740();
    piVar3 = (int *)FUN_0079a5f0(uVar2);
    (**(code **)(*piVar3 + 0xe4))
              (piVar3,0x8b,((iVar5 << 8 | local_210) << 8 | local_214) << 8 | local_22c);
    local_22c = 0;
    if (local_1dc != 0) {
      do {
        piVar3 = *(int **)((int)pfVar8[9] + local_22c * 4);
        iVar5 = *(int *)((int)local_21c[9] + local_22c * 4);
        if ((piVar3 != (int *)0x0) && (iVar5 != 0)) {
          fStack_f4 = *(float *)(iVar5 + 0x24);
          fStack_f0 = *(float *)(iVar5 + 0x28);
          piVar6 = piVar3;
          piVar7 = &iStack_90;
          for (iVar4 = 0x20; iVar4 != 0; iVar4 = iVar4 + -1) {
            *piVar7 = *piVar6;
            piVar6 = piVar6 + 1;
            piVar7 = piVar7 + 1;
          }
          fStack_ec = *(float *)(iVar5 + 0x2c);
          fStack_e8 = *(float *)(iVar5 + 0x30);
          fStack_130 = local_1d8 * fStack_f4;
          fStack_12c = fStack_f0 * local_1d8;
          fStack_128 = fStack_ec * local_1d8;
          fStack_124 = fStack_e8 * local_1d8;
          fStack_150 = (float)piVar3[9];
          fStack_14c = (float)piVar3[10];
          fStack_148 = (float)piVar3[0xb];
          fStack_144 = (float)piVar3[0xc];
          fStack_1c8 = *(float *)(param_1 + 0x30);
          fStack_1d4 = fStack_1c8 * fStack_150;
          fStack_1d0 = fStack_14c * fStack_1c8;
          fStack_1cc = fStack_148 * fStack_1c8;
          fStack_1c8 = fStack_1c8 * fStack_144;
          fStack_1c4 = fStack_1d4 + fStack_130;
          fStack_1c0 = fStack_1d0 + fStack_12c;
          fStack_1bc = fStack_1cc + fStack_128;
          fStack_1b8 = fStack_1c8 + fStack_124;
          fStack_1b4 = *(float *)(iVar5 + 4);
          fStack_1b0 = *(float *)(iVar5 + 8);
          fStack_1ac = *(float *)(iVar5 + 0xc);
          fStack_1a8 = *(float *)(iVar5 + 0x10);
          fStack_160 = fStack_1b4 * local_1d8;
          fStack_15c = fStack_1b0 * local_1d8;
          fStack_158 = fStack_1ac * local_1d8;
          fStack_154 = fStack_1a8 * local_1d8;
          fStack_198 = (float)piVar3[1];
          fStack_194 = (float)piVar3[2];
          fStack_190 = (float)piVar3[3];
          fStack_18c = (float)piVar3[4];
          fStack_170 = *(float *)(param_1 + 0x30);
          fStack_17c = fStack_170 * fStack_198;
          fStack_178 = fStack_194 * fStack_170;
          fStack_174 = fStack_190 * fStack_170;
          fStack_170 = fStack_170 * fStack_18c;
          fStack_140 = fStack_17c + fStack_160;
          fStack_13c = fStack_178 + fStack_15c;
          fStack_138 = fStack_174 + fStack_158;
          fStack_134 = fStack_170 + fStack_154;
          fStack_120 = *(float *)(iVar5 + 0x14);
          fStack_11c = *(float *)(iVar5 + 0x18);
          fStack_118 = *(float *)(iVar5 + 0x1c);
          fStack_114 = *(float *)(iVar5 + 0x20);
          fStack_c8 = fStack_120 * local_1d8;
          fStack_c4 = fStack_11c * local_1d8;
          fStack_c0 = fStack_118 * local_1d8;
          fStack_bc = fStack_114 * local_1d8;
          fStack_104 = (float)piVar3[5];
          fStack_100 = (float)piVar3[6];
          fStack_fc = (float)piVar3[7];
          fStack_f8 = (float)piVar3[8];
          fStack_d8 = *(float *)(param_1 + 0x30);
          fStack_e4 = fStack_d8 * fStack_104;
          fStack_e0 = fStack_100 * fStack_d8;
          fStack_dc = fStack_fc * fStack_d8;
          fStack_d8 = fStack_d8 * fStack_f8;
          fStack_ac = fStack_e4 + fStack_c8;
          fStack_a8 = fStack_e0 + fStack_c4;
          fStack_a4 = fStack_dc + fStack_c0;
          fStack_a0 = fStack_d8 + fStack_bc;
          if (*piVar3 == 3) {
            fStack_188 = *(float *)(iVar5 + 0x40);
            fStack_184 = *(float *)(iVar5 + 0x44);
            fStack_180 = *(float *)(iVar5 + 0x48);
            fStack_b8 = fStack_188 * local_1d8;
            fStack_b4 = fStack_184 * local_1d8;
            fStack_b0 = local_1d8 * fStack_180;
            fStack_9c = (float)piVar3[0x10];
            fStack_98 = (float)piVar3[0x11];
            fStack_94 = (float)piVar3[0x12];
            fVar1 = *(float *)(param_1 + 0x30);
            fStack_16c = fVar1 * fStack_9c;
            fStack_168 = fStack_98 * fVar1;
            fStack_164 = fVar1 * fStack_94;
            fStack_d4 = fStack_16c + fStack_b8;
            fStack_d0 = fStack_168 + fStack_b4;
            fStack_cc = fStack_164 + fStack_b0;
            fStack_50 = fStack_d4;
            fStack_4c = fStack_d0;
            fStack_48 = fStack_cc;
          }
          else {
            fStack_1a4 = *(float *)(iVar5 + 0x34);
            fStack_1a0 = *(float *)(iVar5 + 0x38);
            fStack_19c = *(float *)(iVar5 + 0x3c);
            local_20c = fStack_1a4 * local_1d8;
            local_208 = fStack_1a0 * local_1d8;
            local_204 = fStack_19c * local_1d8;
            fStack_110 = (float)piVar3[0xd];
            fStack_10c = (float)piVar3[0xe];
            fStack_108 = (float)piVar3[0xf];
            fVar1 = *(float *)(param_1 + 0x30);
            local_1fc = fVar1 * fStack_110;
            local_1f8 = fStack_10c * fVar1;
            local_1f4 = fVar1 * fStack_108;
            local_1ec = local_1fc + local_20c;
            local_1e8 = local_1f8 + local_208;
            local_1e4 = local_1f4 + local_204;
            fStack_44 = (float)piVar3[0x13] * *(float *)(param_1 + 0x30) +
                        *(float *)(iVar5 + 0x4c) * local_1d8;
            fStack_3c = (float)piVar3[0x15] * *(float *)(param_1 + 0x30) +
                        *(float *)(iVar5 + 0x54) * local_1d8;
            fStack_38 = (float)piVar3[0x16] * *(float *)(param_1 + 0x30) +
                        *(float *)(iVar5 + 0x58) * local_1d8;
            fStack_34 = (float)piVar3[0x17] * *(float *)(param_1 + 0x30) +
                        *(float *)(iVar5 + 0x5c) * local_1d8;
            fStack_40 = (float)piVar3[0x14] * *(float *)(param_1 + 0x30) +
                        *(float *)(iVar5 + 0x50) * local_1d8;
            fStack_30 = (float)piVar3[0x18] * *(float *)(param_1 + 0x30) +
                        *(float *)(iVar5 + 0x60) * local_1d8;
            fStack_2c = (float)piVar3[0x19] * *(float *)(param_1 + 0x30) +
                        local_1d8 * *(float *)(iVar5 + 100);
            fStack_5c = local_1ec;
            fStack_58 = local_1e8;
            fStack_54 = local_1e4;
          }
          local_228 = CONCAT44(local_228._4_4_,fVar1);
          fStack_8c = fStack_140;
          fStack_88 = fStack_13c;
          fStack_84 = fStack_138;
          fStack_80 = fStack_134;
          fStack_7c = fStack_ac;
          fStack_78 = fStack_a8;
          fStack_74 = fStack_a4;
          fStack_70 = fStack_a0;
          fStack_6c = fStack_1c4;
          fStack_68 = fStack_1c0;
          fStack_64 = fStack_1bc;
          fStack_60 = fStack_1b8;
          uVar2 = FUN_00434740();
          FUN_0079b4a0(uVar2);
          pfVar8 = local_218;
        }
        local_22c = local_22c + 1;
      } while (local_22c < local_1dc);
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_234);
  return;
}

