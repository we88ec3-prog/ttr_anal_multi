
void FUN_007bd8d0(float param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  int unaff_EDI;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  undefined4 uVar17;
  float local_128;
  uint local_fc;
  uint local_f8;
  float local_c4;
  float local_c0;
  float local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  uint local_98;
  undefined4 local_94 [4];
  undefined4 local_84;
  undefined4 local_74;
  float local_60;
  float local_5c;
  float local_58;
  undefined4 local_54;
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
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 1;
  local_9c = 1;
  *(float *)(unaff_EDI + 0x1c) =
       param_1 * *(float *)(unaff_EDI + 0x24) + *(float *)(unaff_EDI + 0x1c);
  local_c4 = 0.0;
  local_c0 = 0.0;
  local_bc = 0.0;
  local_b8 = 0;
  local_b4 = 0;
  local_b0 = 0;
  local_ac = 0x3f800000;
  local_a8 = 0x3f800000;
  local_a4 = 0x3f800000;
  local_a0 = 0x3f800000;
  uVar1 = *(undefined4 *)(unaff_EDI + 0x18);
  uVar2 = *(undefined4 *)(unaff_EDI + 0x18);
  uVar3 = *(undefined4 *)(unaff_EDI + 0x18);
  local_18 = uVar1;
  local_14 = uVar2;
  local_10 = uVar3;
  _memset(local_94,0,0x34);
  local_74 = 0x3f800000;
  local_84 = 0x3f800000;
  local_94[0] = 0x3f800000;
  FUN_00790dc0(*(undefined4 *)(unaff_EDI + 0x34));
  FUN_00790e90(*(undefined4 *)(unaff_EDI + 0x38));
  FUN_00790f60(*(undefined4 *)(unaff_EDI + 0x3c));
  FUN_00780890();
  local_1c = 0x3f800000;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  uVar4 = *(undefined4 *)(unaff_EDI + 0x28);
  uVar5 = *(undefined4 *)(unaff_EDI + 0x2c);
  uVar6 = *(undefined4 *)(unaff_EDI + 0x30);
  local_44 = *(undefined4 *)(unaff_EDI + 0x40);
  local_40 = *(undefined4 *)(unaff_EDI + 0x40);
  local_3c = *(undefined4 *)(unaff_EDI + 0x40);
  local_38 = 1;
  local_34 = uVar4;
  local_30 = uVar5;
  local_2c = uVar6;
  _memset(local_94,0,0x34);
  local_74 = 0x3f800000;
  local_84 = 0x3f800000;
  local_94[0] = 0x3f800000;
  FUN_00790dc0(*(undefined4 *)(unaff_EDI + 0x50));
  FUN_00790e90(*(undefined4 *)(unaff_EDI + 0x54));
  FUN_00790f60(*(undefined4 *)(unaff_EDI + 0x58));
  FUN_00780890();
  local_48 = 0x3f800000;
  local_f8 = 1;
  local_fc = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  fVar7 = *(float *)(unaff_EDI + 0x44);
  fVar8 = *(float *)(unaff_EDI + 0x48);
  fVar9 = *(float *)(unaff_EDI + 0x4c);
  local_98 = *(int *)(unaff_EDI + 8) - *(int *)(unaff_EDI + 4) >> 2;
  local_60 = fVar7;
  local_5c = fVar8;
  local_58 = fVar9;
  if (local_98 != 0) {
    do {
      iVar11 = *(int *)(*(int *)(unaff_EDI + 4) + local_fc * 4);
      iVar12 = *(int *)(iVar11 + 4);
      local_128 = (*(float *)(unaff_EDI + 0x1c) - *(float *)(iVar12 + 0x40)) *
                  *(float *)(iVar12 + 100);
      uVar14 = (**(code **)(**(int **)(iVar11 + 8) + 0x1c))(local_128);
      iVar16 = *(int *)(iVar11 + 8);
      local_f8 = local_f8 & uVar14;
      if (iVar16 != 0) {
        fVar10 = *(float *)(iVar16 + 0x70);
        if (*(char *)(iVar12 + 0x60) == '\0') {
          if (*(float *)(unaff_EDI + 0x1c) <= *(float *)(iVar12 + 0x40)) {
            uVar17 = *(undefined4 *)(iVar16 + 0x78);
          }
          else {
            *(undefined4 *)(unaff_EDI + 0x5c) = uVar4;
            *(undefined4 *)(unaff_EDI + 0x60) = uVar5;
            *(undefined4 *)(unaff_EDI + 100) = uVar6;
            local_c4 = *(float *)(unaff_EDI + 0x5c);
            local_c0 = *(float *)(unaff_EDI + 0x60);
            local_bc = *(float *)(unaff_EDI + 100);
            if ((((fVar7 != local_c4) || (fVar8 != local_c0)) || (fVar9 != local_bc)) &&
               (*(int *)(unaff_EDI + 0x68) == 0)) {
              local_ac = 0x3f800000;
              local_b8 = 0;
              local_b4 = 0;
              local_b0 = 0;
              local_a8 = uVar1;
              local_a4 = uVar2;
              local_a0 = uVar3;
              FUN_0077e910(local_94,*(undefined4 *)(*(int *)(iVar11 + 8) + 0x78),&local_c4);
              FUN_0077ea00();
              *(int *)(unaff_EDI + 0x68) = *(int *)(unaff_EDI + 0x68) + 1;
              goto LAB_007bddbf;
            }
            uVar17 = *(undefined4 *)(*(int *)(iVar11 + 8) + 0x78);
          }
          FUN_0077e910(local_94,uVar17,&local_60);
          FUN_0077ea00();
        }
        else {
          puVar15 = (undefined4 *)FUN_0077e910(local_94,*(undefined4 *)(iVar16 + 0x78),&local_34);
          puVar13 = *(undefined4 **)(*(int *)(iVar11 + 8) + 0x74);
          if (puVar13 != puVar15) {
            *puVar13 = *puVar15;
            puVar13[1] = puVar15[1];
            puVar13[2] = puVar15[2];
            if (puVar13 + 3 != puVar15 + 3) {
              puVar13[6] = puVar15[6];
              puVar13[3] = puVar15[3];
              puVar13[4] = puVar15[4];
              puVar13[5] = puVar15[5];
            }
            puVar13[7] = puVar15[7];
            puVar13[8] = puVar15[8];
            puVar13[9] = puVar15[9];
            puVar13[10] = puVar15[10];
          }
        }
LAB_007bddbf:
        if (*(char *)(iVar12 + 0x61) == '\0') {
          if (fVar10 < local_128 != (fVar10 == local_128)) {
            iVar16 = FUN_008fed10();
            local_128 = (float)(extraout_ST1 - extraout_ST0_00 * (float10)iVar16);
          }
          fVar10 = param_1 * *(float *)(unaff_EDI + 0x24) * *(float *)(iVar12 + 100);
        }
        else {
          iVar16 = FUN_008fed10();
          if ((int)(uint)*(byte *)(iVar12 + 0x61) <= iVar16) {
            iVar16 = *(byte *)(iVar12 + 0x61) - 1;
          }
          local_128 = (float)(extraout_ST0 - (float10)iVar16 * (float10)fVar10);
          if (iVar16 < 0) {
            local_128 = -1.0;
          }
          fVar10 = param_1 * *(float *)(unaff_EDI + 0x24) * *(float *)(iVar12 + 100);
        }
        (**(code **)(**(int **)(iVar11 + 8) + 0x14))(fVar10,local_128);
        (**(code **)(**(int **)(iVar11 + 8) + 0x28))();
      }
      local_fc = local_fc + 1;
    } while (local_fc < local_98);
  }
  if (((*(float *)(unaff_EDI + 0x20) < *(float *)(unaff_EDI + 0x1c) !=
        (*(float *)(unaff_EDI + 0x20) == *(float *)(unaff_EDI + 0x1c))) && (local_f8 != 0)) &&
     (*(int *)(unaff_EDI + 0x14) == 0)) {
    *(undefined4 *)(unaff_EDI + 0x6c) = 1;
    *(float *)(unaff_EDI + 0x5c) = fVar7;
    *(float *)(unaff_EDI + 0x60) = fVar8;
    *(float *)(unaff_EDI + 100) = fVar9;
    *(undefined4 *)(unaff_EDI + 0x68) = 0;
  }
  return;
}

