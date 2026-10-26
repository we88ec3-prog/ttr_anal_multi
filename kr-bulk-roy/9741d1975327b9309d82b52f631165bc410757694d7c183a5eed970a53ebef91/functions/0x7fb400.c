
/* WARNING: Removing unreachable block (ram,0x007fbaa3) */

void FUN_007fb400(int param_1,int param_2)

{
  int iVar1;
  void *_Dst;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  float *pfVar10;
  float *pfVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 extraout_ST0;
  float10 extraout_ST1;
  undefined4 uStack_17c;
  int iStack_178;
  int *piStack_174;
  int iStack_170;
  int *piStack_16c;
  float *pfStack_168;
  undefined4 *puStack_164;
  int *piStack_160;
  int iVar17;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  int iStack_11c;
  float fStack_118;
  float fStack_114;
  float fStack_110;
  float fStack_10c;
  float *pfStack_108;
  float *pfStack_104;
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
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  double dStack_c4;
  double dStack_bc;
  double dStack_b4;
  double dStack_ac;
  float fStack_a4;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint local_1c;
  undefined4 uStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0092b7fe;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&fStack_13c;
  ExceptionList = &local_14;
  if (param_1 != 0) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x104))();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      uStack_18 = 0;
      FUN_00798de0();
      piStack_160 = (int *)0x7fb486;
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      uStack_18 = 0xffffffff;
    }
    piStack_160 = *(int **)(in_ECX + 0x10);
    puStack_164 = (undefined4 *)0x7fb4a7;
    (**(code **)(*piStack_160 + 0x164))();
    fStack_f8 = *DAT_00fb76ac;
    fStack_f4 = DAT_00fb76ac[1];
    fStack_f0 = DAT_00fb76ac[2];
    fStack_ec = DAT_00fb76ac[3];
    uStack_3c = 0;
    piStack_16c = *(int **)(in_ECX + 0x10);
    uStack_40 = 0;
    uStack_44 = 0;
    uStack_48 = 0;
    puStack_164 = &uStack_74;
    uStack_50 = 0;
    uStack_54 = 0;
    uStack_58 = 0;
    pfStack_168 = (float *)&DAT_00000100;
    uStack_5c = 0;
    uStack_64 = 0;
    uStack_68 = 0;
    uStack_6c = 0;
    uStack_70 = 0;
    uStack_38 = 0x3f800000;
    uStack_4c = 0x3f800000;
    uStack_60 = 0x3f800000;
    uStack_74 = 0x3f800000;
    iStack_170 = 0x7fb556;
    (**(code **)(*piStack_16c + 0xb0))();
    fVar4 = (float)(*(int *)(in_ECX + 0x70) - *(int *)(in_ECX + 0x6c) >> 2);
    fStack_10c = 0.0;
    fStack_a4 = fVar4;
    if (fVar4 != 0.0) {
      do {
        iVar6 = *(int *)(*(int *)(*(int *)(in_ECX + 0x6c) + (int)fStack_10c * 4) + 0x88);
        if (iVar6 != 0) {
          piStack_160 = *(int **)(in_ECX + 0x10);
          iVar17 = 0x18;
          puStack_164 = (undefined4 *)0x7fb59e;
          (**(code **)(*piStack_160 + 400))();
          if (*(uint *)(in_ECX + 0x4c) <= *(uint *)(in_ECX + 0x50)) {
            *(undefined4 *)(in_ECX + 0x50) = 0;
          }
          piStack_174 = *(int **)(in_ECX + 0x48);
          puStack_164 = (undefined4 *)
                        ((-(uint)(*(int *)(in_ECX + 0x50) != 0) & 0xfffff000) + 0x2000);
          pfStack_168 = (float *)&stack0xfffffeb8;
          piStack_16c = (int *)(*(int *)(in_ECX + 0x54) * 0x18);
          iStack_170 = *(int *)(in_ECX + 0x50) * 0x18;
          iStack_178 = 0x7fb5ea;
          (**(code **)(*piStack_174 + 0x2c))();
          iStack_178 = *(int *)(*(int *)(in_ECX + 0x6c) + (int)fStack_134 * 4);
          fStack_130 = *(float *)(iStack_178 + 0x90);
          fStack_138 = (float)(*(int *)(*(int *)(in_ECX + 0x68) + 0x168) *
                              *(int *)(*(int *)(in_ECX + 0x68) + 0x164));
          pfVar11 = *(float **)(iStack_178 + 0xe8);
          iStack_178 = iStack_178 + 0xa4;
          uStack_17c = 0x100;
          (**(code **)(**(int **)(in_ECX + 0x10) + 0xb0))(*(int **)(in_ECX + 0x10));
          pfVar5 = pfVar11 + iVar6 * 0x25;
          pfStack_104 = pfVar5;
          if (pfVar11 != pfVar5) {
            pfVar11 = pfVar11 + 0x23;
            do {
              uVar9 = 0;
              if (pfVar11[-0x23] != 0.0) {
                fVar2 = pfVar11[-0xf] / pfVar11[-0x10];
                pfVar5 = (float *)FUN_007f9f20(fVar2);
                fVar4 = *pfVar5;
                if (NAN(fVar4) || 1.0 < fVar4 == (fVar4 == 1.0)) {
                  if (0.0 < *pfVar5) {
                    piStack_160 = (int *)(longlong)ROUND(*pfVar5 * 255.0 + 0.5);
                  }
                  else {
                    piStack_160 = (int *)0x0;
                  }
                }
                else {
                  piStack_160 = (int *)0xff;
                }
                fVar4 = pfVar5[1];
                if (NAN(fVar4) || 1.0 < fVar4 == (fVar4 == 1.0)) {
                  if (0.0 < pfVar5[1]) {
                    uVar9 = (uint)(longlong)ROUND(pfVar5[1] * 255.0 + 0.5);
                  }
                }
                else {
                  uVar9 = 0xff;
                }
                if (1.0 < pfVar5[2] == (pfVar5[2] == 1.0)) {
                  if (0.0 < pfVar5[2]) {
                    uVar8 = (uint)(longlong)ROUND(pfVar5[2] * 255.0 + 0.5);
                  }
                  else {
                    uVar8 = 0;
                  }
                }
                else {
                  uVar8 = 0xff;
                }
                if (1.0 < pfVar5[3] == (pfVar5[3] == 1.0)) {
                  if (0.0 < pfVar5[3]) {
                    iVar6 = (int)(longlong)ROUND(pfVar5[3] * 255.0 + 0.5);
                  }
                  else {
                    iVar6 = 0;
                  }
                }
                else {
                  iVar6 = 0xff;
                }
                fStack_128 = -fStack_118;
                puStack_164 = (undefined4 *)0x6;
                fStack_124 = -fStack_114;
                fStack_f4 = (float)(((iVar6 << 8 | (uint)piStack_160) << 8 | uVar9) << 8 | uVar8);
                fStack_120 = -fStack_110;
                piStack_160 = (int *)(in_ECX + 0x128);
                fVar12 = (float10)fStack_10c;
                pfVar10 = (float *)(in_ECX + 0x88);
                fVar14 = (float10)0;
                dStack_ac = (double)(fVar12 * fVar14);
                fVar13 = (float10)fStack_128;
                dStack_b4 = (double)(fVar13 * fVar14);
                dStack_c4 = (double)((float10)fStack_124 * fVar14);
                dStack_bc = (double)((float10)fStack_120 * fVar14);
                do {
                  if (pfVar11[-1] == 0.0) {
                    fVar4 = *pfVar11;
                  }
                  else {
                    fVar4 = (1.0 - fVar2) * *pfVar11 + pfVar11[1] * fVar2;
                  }
                  piStack_16c = (int *)(pfVar11[-2] * fVar4);
                  fStack_f0 = (float)piStack_16c * pfVar10[-2];
                  fStack_ec = pfVar10[-1] * (float)piStack_16c;
                  fStack_e8 = (float)piStack_16c * *pfVar10;
                  fStack_e4 = fStack_f0 * fStack_13c;
                  fStack_e0 = fStack_ec * fStack_13c;
                  fStack_dc = fStack_13c * fStack_e8;
                  fVar14 = (float10)fStack_e4;
                  fVar15 = (float10)fStack_e0;
                  fVar16 = (float10)fStack_dc;
                  fStack_12c = (float)((((float10)dStack_ac - fVar14 * fVar13) -
                                       fVar15 * (float10)fStack_124) - fVar16 * (float10)fStack_120)
                  ;
                  fStack_138 = (float)(((float10)fStack_120 * fVar15 +
                                       fVar12 * fVar14 + (float10)dStack_b4) -
                                      (float10)fStack_124 * fVar16);
                  fStack_134 = (float)((fVar16 * fVar13 + fVar12 * fVar15 + (float10)dStack_c4) -
                                      (float10)fStack_120 * fVar14);
                  fStack_130 = (float)((fVar16 * fVar12 + (float10)dStack_bc +
                                       (float10)fStack_124 * fVar14) - fVar13 * fVar15);
                  fVar14 = (float10)fStack_118;
                  fVar13 = (float10)fStack_114;
                  fVar15 = (float10)fStack_110;
                  fStack_d4 = (float)((fVar12 * (float10)fStack_138 + fVar14 * (float10)fStack_12c +
                                      fVar13 * (float10)fStack_130) - fVar15 * (float10)fStack_134);
                  fStack_d0 = (float)((fVar15 * (float10)fStack_138 +
                                      (float10)fStack_12c * fVar13 + (float10)fStack_134 * fVar12) -
                                     (float10)fStack_130 * fVar14);
                  fStack_cc = (float)(((float10)fStack_130 * fVar12 + (float10)fStack_12c * fVar15 +
                                      (float10)fStack_134 * fVar14) - fVar13 * (float10)fStack_138);
                  fStack_100 = pfVar11[-0x22] + fStack_d4;
                  fVar3 = pfVar11[-0x21] + fStack_d0;
                  fVar4 = pfVar11[-0x20];
                  pfStack_108 = pfVar10;
                  fStack_fc = fVar3;
                  *pfStack_168 = fStack_100;
                  fVar4 = fVar4 + fStack_cc;
                  pfStack_168[1] = fVar3;
                  fStack_f8 = fVar4;
                  pfStack_168[2] = fVar4;
                  pfStack_168[3] = fStack_f4;
                  iVar6 = *(int *)(in_ECX + 0x68);
                  iVar7 = FUN_008fed10();
                  iVar1 = *(int *)(iVar6 + 0x168);
                  piStack_16c = (int *)((iVar7 % 0) % *(int *)(iVar6 + 0x164) + piStack_160[-6]);
                  pfStack_168[4] = (float)(int)piStack_16c * *(float *)(iVar6 + 0x15c);
                  pfStack_168[5] =
                       (float)(*piStack_160 + (iVar7 % 0) / iVar1) *
                       *(float *)(*(int *)(in_ECX + 0x68) + 0x160);
                  pfStack_168 = pfStack_168 + 6;
                  iVar17 = iVar17 + 1;
                  fVar13 = extraout_ST0;
                  fVar12 = extraout_ST1;
                  if (iVar17 == *(int *)(in_ECX + 0x54)) {
                    (**(code **)(**(int **)(in_ECX + 0x48) + 0x30))(*(int **)(in_ECX + 0x48));
                    (**(code **)(**(int **)(in_ECX + 0x10) + 0x144))
                              (*(int **)(in_ECX + 0x10),4,*(undefined4 *)(in_ECX + 0x50),
                               *(uint *)(in_ECX + 0x54) / 3);
                    *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x50) + *(int *)(in_ECX + 0x54);
                    if (*(uint *)(in_ECX + 0x4c) <= *(uint *)(in_ECX + 0x50)) {
                      *(undefined4 *)(in_ECX + 0x50) = 0;
                    }
                    (**(code **)(**(int **)(in_ECX + 0x48) + 0x2c))
                              (*(int **)(in_ECX + 0x48),*(int *)(in_ECX + 0x50) * 0x18,
                               *(int *)(in_ECX + 0x54) * 0x18,&uStack_17c,
                               (-(uint)(*(int *)(in_ECX + 0x50) != 0) & 0xfffff000) + 0x2000);
                    fVar12 = (float10)fStack_10c;
                    fVar13 = (float10)fStack_128;
                    iVar17 = 0;
                    pfVar10 = pfStack_108;
                  }
                  piStack_160 = piStack_160 + 1;
                  pfVar10 = pfVar10 + 6;
                  puStack_164 = (undefined4 *)((int)puStack_164 + -1);
                } while (puStack_164 != (undefined4 *)0x0);
                puStack_164 = (undefined4 *)0x0;
                pfVar5 = pfStack_104;
                pfStack_108 = pfVar10;
              }
              pfVar10 = pfVar11 + 2;
              pfVar11 = pfVar11 + 0x25;
            } while (pfVar10 != pfVar5);
          }
          (**(code **)(**(int **)(in_ECX + 0x48) + 0x30))(*(int **)(in_ECX + 0x48));
          if (iStack_11c != 0) {
            piStack_160 = (int *)0x7fbc43;
            (**(code **)(**(int **)(in_ECX + 0x10) + 0x144))();
          }
          *(int *)(in_ECX + 0x50) = *(int *)(in_ECX + 0x50) + *(int *)(in_ECX + 0x54);
          fVar4 = fStack_a4;
        }
        fStack_10c = (float)((int)fStack_10c + 1);
      } while ((uint)fStack_10c < (uint)fVar4);
    }
  }
  if (param_2 != 0) {
    _Dst = *(void **)(in_ECX + 0x6c);
    if (_Dst != *(void **)(in_ECX + 0x70)) {
      FID_conflict__memcpy(_Dst,*(void **)(in_ECX + 0x70),0);
      *(void **)(in_ECX + 0x70) = _Dst;
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&fStack_13c);
  return;
}

