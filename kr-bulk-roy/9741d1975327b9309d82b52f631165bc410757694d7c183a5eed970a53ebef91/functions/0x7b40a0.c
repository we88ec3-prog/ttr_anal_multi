
void FUN_007b40a0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int xRight;
  int yTop;
  int xLeft;
  uint uVar10;
  void *pvVar11;
  int *piVar12;
  void *pvVar13;
  float10 extraout_ST0;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 extraout_ST1;
  uint local_19c;
  uint local_190;
  float local_18c;
  uint local_174;
  uint uStack_170;
  tagRECT local_168;
  float local_158;
  float local_154;
  undefined4 local_150;
  undefined1 local_14c [64];
  undefined1 local_10c [64];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  float local_8c;
  float local_88;
  undefined4 local_84;
  float local_80;
  uint local_7c;
  float local_78;
  float local_74;
  undefined4 local_70;
  float local_6c;
  uint local_68;
  float local_64;
  float local_60;
  undefined4 local_5c;
  float local_58;
  uint local_54;
  float local_50;
  float local_4c;
  undefined4 local_48;
  float local_44;
  uint local_40;
  float local_3c;
  float local_38;
  undefined4 local_34;
  float local_30;
  uint local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  float local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00935226;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00fba830 == 0) {
    if (DAT_00fbab54 == DAT_00fbab58) goto LAB_007b4eab;
    pvVar11 = (void *)0x0;
    pvVar13 = DAT_00fbab54;
  }
  else {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(local_14);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar8 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    (**(code **)(*piVar8 + 0xb4))(piVar8,2,local_10c);
    (**(code **)(*piVar8 + 0xb4))(piVar8,3,local_14c);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x10))(DAT_00fb773c);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb7738 + 0x14))(DAT_00fb7738);
    local_94 = 0;
    local_98 = 0;
    local_9c = 0;
    local_a0 = 0;
    local_a8 = 0;
    local_ac = 0;
    local_b0 = 0;
    local_b4 = 0;
    local_bc = 0;
    local_c0 = 0;
    local_c4 = 0;
    local_c8 = 0;
    local_90 = 0x3f800000;
    local_a4 = 0x3f800000;
    local_b8 = 0x3f800000;
    local_cc = 0x3f800000;
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x8b,0xffffffff);
    (**(code **)(*piVar8 + 0xb0))(piVar8,2,local_10c);
    (**(code **)(*piVar8 + 0xb0))(piVar8,3,local_14c);
    (**(code **)(*piVar8 + 0xb0))(piVar8,0x100,&local_cc);
    (**(code **)(*piVar8 + 0x164))(piVar8,0x44);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x16,3);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0xf,1);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x19,5);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x18,0x6f);
    (**(code **)(*piVar8 + 0x10c))(piVar8,0,4,2);
    (**(code **)(*piVar8 + 0x10c))(piVar8,0,5,2);
    (**(code **)(*piVar8 + 0xe4))(piVar8,7,1);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x17,4);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x1b,1);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x13,5);
    (**(code **)(*piVar8 + 0xe4))(piVar8,0x14,6);
    (**(code **)(*piVar8 + 0x114))(piVar8,0,1,3);
    (**(code **)(*piVar8 + 0x114))(piVar8,0,2,3);
    (**(code **)(*piVar8 + 0x104))(piVar8,0,0);
    local_19c = 0;
    if ((int)DAT_00fbab58 - (int)DAT_00fbab54 >> 2 != 0) {
      do {
        iVar2 = *(int *)((int)DAT_00fbab54 + local_19c * 4);
        if ((DAT_00fb79e8 & 1) == 0) {
          DAT_00fb79e8 = DAT_00fb79e8 | 1;
          local_8 = 3;
          FUN_00798de0();
          _atexit((_func_4879 *)&LAB_00bcd2e0);
          local_8 = 0xffffffff;
        }
        FUN_0079b910(&DAT_00fb76a8,iVar2 + 0x10);
        iVar9 = FUN_008fed10();
        local_158 = (float)iVar9;
        iVar9 = FUN_008fed10();
        local_154 = (float)iVar9;
        iVar9 = FUN_008fed10();
        xRight = FUN_008fed10();
        yTop = FUN_008fed10();
        xLeft = FUN_008fed10();
        SetRect(&local_168,xLeft,yTop,xRight,iVar9);
        local_8c = (float)local_168.left;
        local_88 = (float)local_168.top;
        local_78 = (float)local_168.right;
        local_60 = (float)local_168.bottom;
        local_84 = local_150;
        local_80 = 1.0;
        local_70 = local_150;
        local_6c = 1.0;
        local_5c = local_150;
        local_58 = 1.0;
        local_48 = local_150;
        local_44 = 1.0;
        local_34 = local_150;
        local_30 = 1.0;
        local_7c = 0xa00a0a0a;
        local_68 = 0xa00a0a0a;
        local_54 = 0xa00a0a0a;
        local_40 = 0xa00a0a0a;
        local_2c = 0xa00a0a0a;
        local_20 = local_150;
        local_18 = 0xa00a0a0a;
        local_1c = 1.0;
        local_74 = local_88;
        local_64 = local_8c;
        local_50 = local_8c;
        local_4c = local_60;
        local_3c = local_78;
        local_38 = local_88;
        local_28 = local_78;
        local_24 = local_60;
        (**(code **)(*piVar8 + 0x14c))(piVar8,4,2,&local_8c,0x14);
        local_18c = 0.0;
        piVar12 = (int *)**(int **)(iVar2 + 4);
        if (piVar12 != *(int **)(iVar2 + 4)) {
          do {
            if (piVar12[4] != 0) {
              local_168.right = FUN_008fed10();
              local_7c = *(uint *)(&DAT_00fba690 + piVar12[5] * 8);
              local_68 = *(uint *)(&DAT_00fba694 + piVar12[5] * 8);
              fVar5 = local_18c * *(float *)(iVar2 + 0x20);
              local_18c = local_18c + (float)piVar12[6];
              fVar4 = (float10)1;
              local_8c = (float)(extraout_ST0 + fVar4);
              local_88 = (float)((float10)((float)local_168.top + fVar5) + fVar4);
              local_78 = (float)((float10)local_168.right - fVar4);
              local_60 = (float)((float10)(*(float *)(iVar2 + 0x20) * local_18c +
                                          (float)local_168.top) - fVar4);
              fVar4 = (float10)1;
              if (((float)piVar12[7] < (float)piVar12[8]) && (0.9 < *(float *)(iVar2 + 0x2c))) {
                uStack_170 = local_7c >> 0x10 & 0xff;
                fVar6 = (float)uStack_170;
                uStack_170 = local_7c >> 8 & 0xff;
                fVar5 = (float)uStack_170;
                uStack_170 = local_7c & 0xff;
                fVar14 = (float10)0.5;
                fVar15 = (float10)(float)((float10)(fVar6 * 0.003921569) * fVar14);
                if (fVar15 < fVar4) {
                  if (fVar15 < extraout_ST1 == (fVar15 == extraout_ST1)) {
                    local_174 = (uint)(longlong)ROUND(fVar15 * (float10)255.0 + fVar14);
                    uVar10 = local_174;
                  }
                  else {
                    uVar10 = 0;
                  }
                }
                else {
                  uVar10 = 0xff;
                }
                fVar16 = (float10)255.0;
                fVar15 = (float10)(float)((float10)(fVar5 * 0.003921569) * fVar14);
                if (fVar15 < fVar4) {
                  if (fVar15 < extraout_ST1 == (fVar15 == extraout_ST1)) {
                    local_174 = (uint)(longlong)ROUND(fVar15 * fVar16 + fVar14);
                    local_190 = local_174;
                  }
                  else {
                    local_190 = 0;
                  }
                }
                else {
                  local_190 = 0xff;
                }
                fVar15 = (float10)(float)((float10)((float)uStack_170 * 0.003921569) * fVar14);
                if (fVar15 < fVar4) {
                  if (fVar15 < extraout_ST1 == (fVar15 == extraout_ST1)) {
                    local_174 = (uint)(longlong)ROUND(fVar15 * fVar16 + fVar14);
                  }
                  else {
                    local_174 = 0;
                  }
                }
                else {
                  local_174 = 0xff;
                }
                local_7c = ((uVar10 | 0xffffff00) << 8 | local_190) << 8 | local_174;
                uStack_170 = local_68 >> 0x10 & 0xff;
                fVar6 = (float)uStack_170;
                uStack_170 = local_68 >> 8 & 0xff;
                fVar5 = (float)uStack_170;
                uStack_170 = local_68 & 0xff;
                fVar15 = (float10)(float)((float10)(fVar6 * 0.003921569) * fVar14);
                if (fVar15 < fVar4) {
                  if (fVar15 < extraout_ST1 == (fVar15 == extraout_ST1)) {
                    local_174 = (uint)(longlong)ROUND(fVar15 * fVar16 + fVar14);
                    uVar10 = local_174;
                  }
                  else {
                    uVar10 = 0;
                  }
                }
                else {
                  uVar10 = 0xff;
                }
                fVar15 = (float10)(float)((float10)(fVar5 * 0.003921569) * fVar14);
                if (fVar15 < fVar4) {
                  if (fVar15 < extraout_ST1 == (fVar15 == extraout_ST1)) {
                    local_174 = (uint)(longlong)ROUND(fVar15 * fVar16 + fVar14);
                    local_190 = local_174;
                  }
                  else {
                    local_190 = 0;
                  }
                }
                else {
                  local_190 = 0xff;
                }
                fVar15 = (float10)(float)((float10)((float)uStack_170 * 0.003921569) * fVar14);
                if (fVar15 < fVar4) {
                  if (fVar15 < extraout_ST1 == (fVar15 == extraout_ST1)) {
                    local_174 = (uint)(longlong)ROUND(fVar15 * fVar16 + fVar14);
                  }
                  else {
                    local_174 = 0;
                  }
                }
                else {
                  local_174 = 0xff;
                }
                local_68 = ((uVar10 | 0xffffff00) << 8 | local_190) << 8 | local_174;
              }
              local_84 = local_150;
              local_80 = (float)fVar4;
              local_70 = local_150;
              local_6c = (float)fVar4;
              local_5c = local_150;
              local_58 = (float)fVar4;
              local_48 = local_150;
              local_44 = (float)fVar4;
              local_30 = (float)fVar4;
              local_34 = local_150;
              local_1c = (float)fVar4;
              local_20 = local_150;
              local_74 = local_88;
              local_64 = local_8c;
              local_54 = local_7c;
              local_50 = local_8c;
              local_4c = local_60;
              local_40 = local_7c;
              local_3c = local_78;
              local_38 = local_88;
              local_2c = local_68;
              local_28 = local_78;
              local_24 = local_60;
              local_18 = local_68;
              (**(code **)(*piVar8 + 0x14c))(piVar8,4,2,&local_8c,0x14);
            }
            if (*(char *)((int)piVar12 + 0x25) == '\0') {
              piVar3 = (int *)piVar12[2];
              if (*(char *)((int)piVar3 + 0x25) == '\0') {
                cVar1 = *(char *)(*piVar3 + 0x25);
                piVar12 = piVar3;
                piVar3 = (int *)*piVar3;
                while (cVar1 == '\0') {
                  cVar1 = *(char *)(*piVar3 + 0x25);
                  piVar12 = piVar3;
                  piVar3 = (int *)*piVar3;
                }
              }
              else {
                cVar1 = *(char *)(piVar12[1] + 0x25);
                piVar7 = (int *)piVar12[1];
                piVar3 = piVar12;
                while ((piVar12 = piVar7, cVar1 == '\0' && (piVar3 == (int *)piVar12[2]))) {
                  cVar1 = *(char *)(piVar12[1] + 0x25);
                  piVar7 = (int *)piVar12[1];
                  piVar3 = piVar12;
                }
              }
            }
          } while (piVar12 != *(int **)(iVar2 + 4));
        }
        local_19c = local_19c + 1;
      } while (local_19c < (uint)((int)DAT_00fbab58 - (int)DAT_00fbab54 >> 2));
    }
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 4;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    (**(code **)(*DAT_00fb773c + 0x14))(DAT_00fb773c);
    if (DAT_00fbab54 == DAT_00fbab58) goto LAB_007b4eab;
    pvVar13 = (void *)0x0;
    pvVar11 = DAT_00fbab54;
  }
  FID_conflict__memcpy(DAT_00fbab54,DAT_00fbab58,0);
  DAT_00fbab58 = (void *)((int)pvVar11 + (int)pvVar13);
LAB_007b4eab:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

