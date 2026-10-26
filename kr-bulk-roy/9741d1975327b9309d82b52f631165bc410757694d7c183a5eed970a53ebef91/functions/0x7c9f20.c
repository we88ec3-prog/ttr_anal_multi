
void FUN_007c9f20(float *param_1,float *param_2)

{
  int iVar1;
  float *in_ECX;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float10 fVar5;
  float local_2fc;
  float local_2f8;
  float local_2f4;
  float local_2f0;
  float local_2ec;
  float local_2e8;
  undefined8 local_2e4;
  float local_2d8;
  float local_2d4;
  float local_2d0;
  float local_2cc;
  float local_2c8;
  float *local_2c4;
  float local_2c0;
  float local_2bc;
  float local_2b8;
  undefined8 local_2b4;
  float local_2ac;
  float *local_2a4;
  float local_2a0;
  float local_29c;
  float local_298;
  undefined8 local_294;
  float local_28c;
  float local_280;
  float local_27c;
  float local_278;
  float local_274;
  undefined4 local_270;
  float local_26c;
  float local_268;
  float local_264;
  undefined4 local_260;
  float local_25c;
  float local_258;
  float local_254;
  undefined4 local_250;
  float local_24c;
  float local_248;
  float local_244;
  undefined4 local_240;
  float local_23c;
  float local_238;
  float local_234;
  undefined4 local_230;
  float local_22c;
  float local_228;
  float local_224;
  undefined4 local_220;
  float local_21c;
  float local_218;
  float local_214;
  undefined4 local_210;
  float local_20c;
  float local_208;
  float local_204;
  undefined4 local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  undefined4 local_1f0;
  float local_1ec;
  float local_1e8;
  float local_1e4;
  undefined4 local_1e0;
  float local_1dc;
  float local_1d8;
  float local_1d4;
  undefined4 local_1d0;
  float local_1cc;
  float local_1c8;
  float local_1c4;
  undefined4 local_1c0;
  float local_1bc;
  float local_1b8;
  float local_1b4;
  undefined4 local_1b0;
  float local_1ac;
  float local_1a8;
  float local_1a4;
  undefined4 local_1a0;
  float local_19c;
  float local_198;
  float local_194;
  undefined4 local_190;
  float local_18c;
  float local_188;
  float local_184;
  undefined4 local_180;
  float local_17c;
  float local_178;
  float local_174;
  undefined4 local_170;
  float local_16c;
  float local_168;
  float local_164;
  undefined4 local_160;
  float local_15c;
  float local_158;
  float local_154;
  undefined4 local_150;
  float local_14c;
  float local_148;
  float local_144;
  undefined4 local_140;
  float local_13c;
  float local_138;
  float local_134;
  undefined4 local_130;
  float local_12c;
  float local_128;
  float local_124;
  undefined4 local_120;
  float local_11c;
  float local_118;
  float local_114;
  undefined4 local_110;
  float local_10c;
  float local_108;
  float local_104;
  undefined4 local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  undefined4 local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  undefined4 local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  undefined4 local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  undefined4 local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  undefined4 local_a0;
  float local_9c;
  float local_98;
  float local_94;
  undefined4 local_90;
  float local_8c;
  float local_88;
  float local_84;
  undefined4 local_80;
  float local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  float local_6c;
  float local_68;
  float local_64;
  undefined4 local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  float local_38 [7];
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_208 = param_2[1];
  local_26c = *param_2;
  local_27c = *in_ECX;
  local_2a4 = param_2;
  local_264 = param_2[2];
  local_278 = in_ECX[1];
  local_274 = in_ECX[2];
  local_270 = 0xffffffff;
  local_260 = 0xffffffff;
  local_250 = 0xffffffff;
  local_240 = 0xffffffff;
  local_230 = 0xffffffff;
  local_220 = 0xffffffff;
  local_210 = 0xffffffff;
  local_200 = 0xffffffff;
  local_1f0 = 0xffffffff;
  local_1e0 = 0xffffffff;
  local_1d0 = 0xffffffff;
  local_1c0 = 0xffffffff;
  local_1b0 = 0xffffffff;
  local_1a0 = 0xffffffff;
  local_190 = 0xffffffff;
  local_180 = 0xffffffff;
  local_170 = 0xffffffff;
  local_160 = 0xffffffff;
  local_150 = 0xffffffff;
  local_140 = 0xffffffff;
  local_130 = 0xffffffff;
  local_120 = 0xffffffff;
  local_110 = 0xffffffff;
  local_100 = 0xffffffff;
  local_f0 = 0xffffffff;
  local_e0 = 0xffffffff;
  local_d0 = 0xffffffff;
  local_c0 = 0xffffffff;
  local_b0 = 0xffffffff;
  local_a0 = 0xffffffff;
  local_90 = 0xffffffff;
  local_80 = 0xffffffff;
  local_70 = 0xffffffff;
  local_60 = 0xffffffff;
  local_50 = 0xffffffff;
  local_40 = 0xffffffff;
  local_2a0 = param_1[3] - *param_1;
  local_29c = param_1[4] - param_1[1];
  local_298 = param_1[5] - param_1[2];
  local_38[6] = param_1[6] - param_1[3];
  local_1c = param_1[7] - param_1[4];
  local_28c = param_1[8] - param_1[5];
  local_14 = *param_1 - param_1[6];
  local_10 = param_1[1] - param_1[7];
  local_2b4 = (double)CONCAT44(local_10,local_14);
  local_2ac = param_1[2] - param_1[8];
  local_280 = local_298 * local_298 + local_2a0 * local_2a0 + local_29c * local_29c;
  local_2c4 = in_ECX;
  local_268 = local_278;
  local_25c = local_27c;
  local_258 = local_278;
  local_254 = local_264;
  local_24c = local_27c;
  local_248 = local_278;
  local_244 = local_274;
  local_23c = local_26c;
  local_238 = local_278;
  local_234 = local_274;
  local_22c = local_26c;
  local_228 = local_278;
  local_224 = local_264;
  local_21c = local_27c;
  local_218 = local_278;
  local_214 = local_274;
  local_20c = local_27c;
  local_204 = local_274;
  local_1fc = local_26c;
  local_1f8 = local_208;
  local_1f4 = local_274;
  local_1ec = local_27c;
  local_1e8 = local_278;
  local_1e4 = local_274;
  local_1dc = local_26c;
  local_1d8 = local_208;
  local_1d4 = local_274;
  local_1cc = local_26c;
  local_1c8 = local_278;
  local_1c4 = local_274;
  local_1bc = local_26c;
  local_1b8 = local_278;
  local_1b4 = local_274;
  local_1ac = local_26c;
  local_1a8 = local_208;
  local_1a4 = local_264;
  local_19c = local_26c;
  local_198 = local_278;
  local_194 = local_264;
  local_18c = local_26c;
  local_188 = local_278;
  local_184 = local_274;
  local_17c = local_26c;
  local_178 = local_208;
  local_174 = local_274;
  local_16c = local_26c;
  local_168 = local_208;
  local_164 = local_264;
  local_15c = local_26c;
  local_158 = local_208;
  local_154 = local_274;
  local_14c = local_27c;
  local_148 = local_208;
  local_144 = local_264;
  local_13c = local_26c;
  local_138 = local_208;
  local_134 = local_264;
  local_12c = local_26c;
  local_128 = local_208;
  local_124 = local_274;
  local_11c = local_27c;
  local_118 = local_208;
  local_114 = local_274;
  local_10c = local_27c;
  local_108 = local_208;
  local_104 = local_264;
  local_fc = local_27c;
  local_f8 = local_208;
  local_f4 = local_274;
  local_ec = local_27c;
  local_e8 = local_278;
  local_e4 = local_264;
  local_dc = local_27c;
  local_d8 = local_208;
  local_d4 = local_264;
  local_cc = local_27c;
  local_c8 = local_208;
  local_c4 = local_274;
  local_bc = local_27c;
  local_b8 = local_278;
  local_b4 = local_274;
  local_ac = local_27c;
  local_a8 = local_278;
  local_a4 = local_264;
  local_9c = local_27c;
  local_98 = local_278;
  local_94 = local_264;
  local_8c = local_26c;
  local_88 = local_208;
  local_84 = local_264;
  local_7c = local_27c;
  local_78 = local_208;
  local_74 = local_264;
  local_6c = local_27c;
  local_68 = local_278;
  local_64 = local_264;
  local_5c = local_26c;
  local_58 = local_278;
  local_54 = local_264;
  local_4c = local_26c;
  local_48 = local_208;
  local_44 = local_264;
  local_38[3] = local_2a0;
  local_38[4] = local_29c;
  local_38[5] = local_298;
  local_18 = local_28c;
  local_c = local_2ac;
  local_294._0_4_ = local_38[6];
  local_294._4_4_ = local_1c;
  fVar5 = (float10)FUN_004ad080(local_280);
  local_38[0] = (float)fVar5;
  local_280 = local_28c * local_28c +
              (float)local_294 * (float)local_294 + local_294._4_4_ * local_294._4_4_;
  fVar5 = (float10)FUN_004ad080(local_280);
  local_38[1] = (float)fVar5;
  local_280 = local_2ac * local_2ac +
              (float)local_2b4 * (float)local_2b4 + local_2b4._4_4_ * local_2b4._4_4_;
  fVar5 = (float10)FUN_004ad080(local_280);
  local_38[2] = (float)fVar5;
  FUN_00781020(0x3f800000);
  FUN_00781020(0x3f800000);
  FUN_00781020(0x3f800000);
  pfVar4 = local_2a4;
  if ((((in_ECX[2] <= param_1[2]) || (in_ECX[2] <= param_1[5])) || (in_ECX[2] <= param_1[8])) &&
     (((param_1[2] <= local_2a4[2] || (param_1[5] <= local_2a4[2])) || (param_1[8] <= local_2a4[2]))
     )) {
    iVar3 = 0;
    pfVar2 = param_1;
    do {
      if (((*in_ECX < *pfVar2) && (in_ECX[1] < pfVar2[1])) &&
         ((*pfVar2 < *local_2a4 && (pfVar2[1] < local_2a4[1])))) goto LAB_007ca876;
      iVar3 = iVar3 + 1;
      pfVar2 = pfVar2 + 3;
    } while (iVar3 < 3);
    D3DXPlaneFromPoints(&local_2d8,param_1,param_1 + 3,param_1 + 6);
    local_2c0 = *in_ECX + *pfVar4;
    local_2bc = pfVar4[1] + in_ECX[1];
    local_2a0 = local_2c0 * 0.5;
    local_29c = local_2bc * 0.5;
    local_298 = in_ECX[2];
    local_28c = pfVar4[2] - in_ECX[2];
    local_2e4 = (double)(pfVar4[1] - in_ECX[1]);
    local_2b4 = (double)(*pfVar4 - *in_ECX);
    local_294 = (double)local_28c;
    local_280 = local_2d0 * local_298 + local_2a0 * local_2d8 + local_29c * local_2d4 + local_2cc;
    fVar5 = (float10)FUN_004ff540(local_280);
    local_2c8 = (float)fVar5;
    local_280 = (float)((float10)local_294 * (float10)local_294 +
                       (float10)local_2e4 * (float10)local_2e4 +
                       (float10)local_2b4 * (float10)local_2b4);
    fVar5 = (float10)FUN_004ad080(local_280);
    local_280 = (float)(fVar5 * (float10)0.5);
    if (local_2c8 < local_280 != (local_2c8 == local_280)) {
      local_294._0_4_ = local_2d8;
      local_294._4_4_ = local_2d4;
      local_28c = local_2d0;
      FUN_00781020(0x3f800000);
      local_2c0 = local_2a0;
      local_2bc = local_29c;
      local_2b8 = local_298;
      iVar3 = FUN_007c81e0(&local_294,param_1 + 3,&local_280,(int)&local_2e4 + 4,&local_2c8,0);
      if (iVar3 != 0) {
        local_2b4 = (double)CONCAT44(local_294._4_4_ * local_280,local_280 * (float)local_294);
        local_2ac = local_280 * local_28c;
        local_294._0_4_ = local_280 * (float)local_294 + local_2a0;
        local_294._4_4_ = local_294._4_4_ * local_280 + local_29c;
        local_28c = local_2ac + local_298;
        if (((((*local_2c4 < (float)local_294 != (*local_2c4 == (float)local_294)) &&
              (local_2c4[1] < local_294._4_4_ != (local_2c4[1] == local_294._4_4_))) &&
             (local_2c4[2] < local_28c != (local_2c4[2] == local_28c))) &&
            (((float)local_294 <= *local_2a4 && (local_294._4_4_ <= local_2a4[1])))) &&
           (local_28c <= local_2a4[2])) {
LAB_007ca876:
          __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
          return;
        }
      }
    }
    local_2c4 = (float *)((int)local_38 + (0xc - (int)param_1));
    local_2a4 = (float *)0x0;
    do {
      iVar3 = 0;
      local_2ac = (float)((int)local_2c4 + (int)param_1);
      pfVar4 = &local_278;
      do {
        local_2a0 = pfVar4[-1];
        local_29c = *pfVar4;
        local_298 = pfVar4[1];
        local_2fc = pfVar4[3];
        local_2f8 = pfVar4[4];
        local_2f4 = pfVar4[5];
        local_2f0 = pfVar4[7];
        local_2ec = pfVar4[8];
        local_2e8 = pfVar4[9];
        local_2c0 = local_2f0;
        local_2bc = local_2ec;
        local_2b8 = local_2e8;
        local_28c = local_2f4;
        local_294._0_4_ = local_2fc;
        local_294._4_4_ = local_2f8;
        iVar1 = FUN_007c81e0(local_2ac,&local_2fc,&local_280,(int)&local_2e4 + 4,&local_2c8,0);
        if (((iVar1 != 0) && (local_280 <= local_38[(int)local_2a4])) &&
           (!NAN(local_280) && 0.0 < local_280 != (local_280 == 0.0))) goto LAB_007ca876;
        iVar3 = iVar3 + 1;
        pfVar4 = pfVar4 + 0xc;
      } while (iVar3 < 0xc);
      local_2a4 = (float *)((int)local_2a4 + 1);
      param_1 = param_1 + 3;
    } while ((int)local_2a4 < 3);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

