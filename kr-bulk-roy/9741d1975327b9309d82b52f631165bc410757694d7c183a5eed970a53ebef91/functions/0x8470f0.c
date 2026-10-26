
void FUN_008470f0(int param_1,int *param_2)

{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  size_t _Size;
  int iVar9;
  void *pvVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  undefined4 *puVar16;
  float *pfVar17;
  undefined4 *puVar18;
  int *piVar19;
  undefined1 local_1a8 [44];
  undefined4 local_17c [13];
  undefined4 local_148 [13];
  undefined4 local_114 [13];
  int *local_e0;
  int *local_dc;
  undefined4 local_d8;
  uint local_d0;
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
  float local_80;
  int local_7c;
  float local_78;
  float local_74;
  float local_70;
  int local_6c;
  float local_68;
  int local_64;
  float local_60;
  int local_5c;
  int local_58;
  float local_54;
  uint local_50;
  int *local_4c;
  int local_48;
  int local_44;
  size_t local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  int local_2c;
  int local_28;
  void *local_24;
  float *local_20;
  uint local_1c;
  int local_18;
  float *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090908b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_28 = *(int *)(param_1 + 0x78);
  if ((local_28 != 0) && (*(int *)(param_1 + 0xac) != 0)) {
    if (*(int *)(local_28 + 0x40) == 0) {
      local_2c = 0;
    }
    else {
      local_2c = FUN_00857160(*(int *)(local_28 + 0x40));
    }
    local_40 = ((*(int *)(*(int *)(param_1 + 0x78) + 0x4c) -
                *(int *)(*(int *)(param_1 + 0x78) + 0x48)) / 0x18) * local_2c;
    local_58 = 0;
    local_44 = 0;
    local_48 = 0;
    local_30 = 0;
    local_50 = 0;
    local_60 = 0.0;
    local_68 = 0.0;
    local_54 = 0.0;
    local_6c = 0;
    local_5c = 0;
    iVar9 = FUN_00857520(0);
    if (iVar9 != 0) {
      local_58 = *(int *)(iVar9 + 0xc);
    }
    iVar9 = FUN_00857520(3);
    if (iVar9 == 0) {
      local_64 = 0;
    }
    else {
      local_44 = *(int *)(iVar9 + 0xc);
      local_64 = 1;
      iVar9 = FUN_00857520(6);
      if (iVar9 != 0) {
        local_48 = *(int *)(iVar9 + 0xc);
      }
      local_50 = (uint)(iVar9 != 0);
      iVar9 = FUN_00857520(7);
      if (iVar9 != 0) {
        local_30 = *(int *)(iVar9 + 0xc);
      }
    }
    piVar15 = (int *)(local_28 + 0x40);
    local_28 = *(int *)(local_28 + 0x44);
    if ((local_28 != 0) && (*piVar15 != 0)) {
      local_e0 = (int *)0x0;
      local_dc = (int *)0x0;
      local_d8 = 0;
      local_8 = 0;
      local_20 = *(float **)(*piVar15 + 4);
      local_14 = (float *)*local_20;
      local_24 = (void *)0x0;
      if (local_14 != local_20) {
        do {
          pfVar11 = local_14;
          fVar3 = local_14[3];
          local_80 = fVar3;
          local_7c = FUN_00857b00(fVar3,local_14[5]);
          pvVar10 = local_24;
          switch(pfVar11[4]) {
          case 0.0:
          case 5.60519e-45:
          case 7.00649e-45:
          case 8.40779e-45:
            local_78 = 5.60519e-45;
            break;
          case 1.4013e-45:
          case 9.80909e-45:
            local_78 = 1.12104e-44;
            break;
          case 2.8026e-45:
            local_78 = 1.68156e-44;
            break;
          case 4.2039e-45:
            local_78 = 2.24208e-44;
            break;
          default:
            local_78 = 0.0;
          }
          local_70 = pfVar11[7];
          local_74 = (float)local_24;
          if (fVar3 != 0.0) {
            if ((local_44 == 0) || (fVar3 != 4.2039e-45)) {
              if ((local_48 == 0) || (fVar3 != 8.40779e-45)) {
                if ((local_30 == 0) || (fVar3 != 9.80909e-45)) {
                  FUN_007b1810();
                }
                else {
                  local_54 = (float)local_24;
                }
              }
              else {
                local_68 = (float)local_24;
                local_5c = local_7c;
              }
            }
            else {
              local_60 = (float)local_24;
              local_6c = local_7c;
            }
          }
          local_24 = (void *)((int)pvVar10 + (int)local_78);
          FUN_0085e240();
        } while (local_14 != local_20);
      }
      _Size = local_40;
      FUN_00845670();
      pvVar10 = (void *)FUN_008456c0();
      local_24 = pvVar10;
      _memset(pvVar10,0,_Size);
      local_28 = *(int *)(*(int *)(param_1 + 0x78) + 0x48);
      local_20 = (float *)FUN_00846220();
      local_18 = 0;
      local_1c = 0;
      if (((local_20 != (float *)0x0) && (iVar9 = FUN_008462f0(&local_18,&local_1c), iVar9 != 0)) &&
         (local_14 = (float *)0x0, 0 < (int)local_20)) {
        piVar15 = (int *)(local_18 + 0x1c);
        do {
          if ((0.0 < *(float *)(local_1c + (int)local_14 * 4)) && (iVar9 = 0, 0 < *piVar15)) {
            local_18 = 0;
            do {
              local_4c = *(int **)(local_1c + (int)local_14 * 4);
              pfVar11 = (float *)(piVar15[2] + local_18);
              iVar14 = *(int *)(piVar15[1] + iVar9 * 4);
              local_3c = (float)local_4c * *pfVar11;
              local_38 = pfVar11[1] * (float)local_4c;
              local_34 = (float)local_4c * pfVar11[2];
              iVar13 = iVar14;
              do {
                iVar12 = iVar13 * local_2c;
                *(float *)(iVar12 + (int)local_24) = local_3c + *(float *)(iVar12 + (int)local_24);
                *(float *)((int)local_24 + iVar12 + 4) =
                     *(float *)(iVar12 + 4 + (int)local_24) + local_38;
                *(float *)((int)local_24 + iVar12 + 8) =
                     local_34 + *(float *)((int)local_24 + iVar12 + 8);
                iVar13 = *(int *)(local_28 + 0x10 + iVar13 * 0x18);
              } while (iVar13 != iVar14);
              local_18 = local_18 + 0xc;
              iVar9 = iVar9 + 1;
              pvVar10 = local_24;
            } while (iVar9 < *piVar15);
          }
          local_14 = (float *)((int)local_14 + 1);
          piVar15 = piVar15 + 0x16;
        } while ((int)local_14 < (int)local_20);
      }
      local_d0 = (*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c)) / 100;
      local_1c = 0;
      if (local_d0 != 0) {
        local_18 = 0;
        do {
          if ((uint)((*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x7c)) / 100) <= local_1c) {
LAB_008478de:
                    /* WARNING: Subroutine does not return */
            FUN_0087db7d("invalid vector<T> subscript");
          }
          uVar4 = *(uint *)(local_18 + 0x50 + *(int *)(param_1 + 0x7c));
          iVar9 = **(int **)(param_1 + 0xac);
          if ((uint)((*(int **)(param_1 + 0xac))[1] - iVar9 >> 2) <= uVar4) goto LAB_008478de;
          (**(code **)(**(int **)(iVar9 + uVar4 * 4) + 0x24))(local_1a8);
          FUN_007cd220();
          puVar16 = local_114;
          puVar18 = local_17c;
          for (iVar9 = 0xd; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar18 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar18 = puVar18 + 1;
          }
          iVar9 = *(int *)(param_1 + 0x7c);
          if ((uint)((*(int *)(param_1 + 0x80) - iVar9) / 100) <= local_1c) goto LAB_008478de;
          puVar16 = (undefined4 *)(local_18 + 0x1c + iVar9);
          puVar18 = local_148;
          for (iVar14 = 0xd; iVar14 != 0; iVar14 = iVar14 + -1) {
            *puVar18 = *puVar16;
            puVar16 = puVar16 + 1;
            puVar18 = puVar18 + 1;
          }
          FUN_007e7dd0(local_148);
          pfVar11 = *(float **)(local_18 + 0x54 + iVar9);
          local_4c = *(int **)(local_18 + 0x58 + iVar9);
          fVar3 = local_94;
          fVar5 = local_a0;
          fVar6 = local_98;
          fVar7 = local_a4;
          fVar8 = local_9c;
          local_20 = pfVar11;
          if (pfVar11 != (float *)local_4c) {
            do {
              iVar9 = (int)*pfVar11;
              local_14 = (float *)pfVar11[1];
              pfVar17 = (float *)(local_58 + iVar9 * 0xc);
              local_3c = (fVar8 * pfVar17[2] +
                          local_a8 * pfVar17[1] + local_b4 * *(float *)(local_58 + iVar9 * 0xc) +
                         local_90) * (float)local_14;
              local_38 = (fVar6 * pfVar17[2] + fVar7 * pfVar17[1] + local_b0 * *pfVar17 + local_8c)
                         * (float)local_14;
              local_34 = (fVar3 * pfVar17[2] + fVar5 * pfVar17[1] + local_ac * *pfVar17 + local_88)
                         * (float)local_14;
              local_20 = pfVar11;
              do {
                piVar15 = (int *)(local_28 + iVar9 * 0x18);
                pfVar17 = (float *)(iVar9 * local_2c + (int)local_24);
                *pfVar17 = local_3c + *pfVar17;
                pfVar17[1] = local_38 + pfVar17[1];
                pfVar17[2] = local_34 + pfVar17[2];
                if (*piVar15 != piVar15[1]) {
                  if (local_64 != 0) {
                    local_14 = (float *)pfVar11[1];
                    iVar9 = *(int *)(*piVar15 + local_6c * 4);
                    pfVar2 = (float *)(local_44 + iVar9 * 0xc);
                    local_c0 = (fVar8 * pfVar2[2] +
                               *pfVar2 * local_b4 +
                               local_a8 * *(float *)(local_44 + 4 + iVar9 * 0xc)) * (float)local_14;
                    local_bc = (fVar6 * pfVar2[2] + local_b0 * *pfVar2 + fVar7 * pfVar2[1]) *
                               (float)local_14;
                    local_b8 = (fVar3 * pfVar2[2] + local_ac * *pfVar2 + fVar5 * pfVar2[1]) *
                               (float)local_14;
                    *(float *)((int)pfVar17 + (int)local_60) =
                         local_c0 + *(float *)((int)pfVar17 + (int)local_60);
                    *(float *)((int)pfVar17 + (int)local_60 + 4) =
                         local_bc + *(float *)((int)pfVar17 + (int)local_60 + 4);
                    pfVar2 = (float *)((int)pfVar17 + (int)local_60 + 8);
                    *pfVar2 = local_b8 + *pfVar2;
                    if (local_50 != 0) {
                      local_c4 = pfVar11[1];
                      iVar9 = *(int *)(*piVar15 + local_5c * 4);
                      pfVar2 = (float *)(local_48 + iVar9 * 0xc);
                      local_cc = (fVar8 * pfVar2[2] +
                                 *pfVar2 * local_b4 +
                                 local_a8 * *(float *)(local_48 + 4 + iVar9 * 0xc)) * local_c4;
                      local_c8 = (fVar6 * pfVar2[2] + fVar7 * pfVar2[1] + *pfVar2 * local_b0) *
                                 local_c4;
                      local_c4 = (fVar3 * pfVar2[2] + fVar5 * pfVar2[1] + *pfVar2 * local_ac) *
                                 local_c4;
                      *(float *)((int)pfVar17 + (int)local_68) =
                           *(float *)((int)pfVar17 + (int)local_68) + local_cc;
                      *(float *)((int)pfVar17 + (int)local_68 + 4) =
                           local_c8 + *(float *)((int)pfVar17 + (int)local_68 + 4);
                      pfVar2 = (float *)((int)pfVar17 + (int)local_68 + 8);
                      *pfVar2 = local_c4 + *pfVar2;
                      iVar9 = *(int *)(*piVar15 + local_5c * 4);
                      local_14 = (float *)pfVar11[1];
                      pfVar2 = (float *)(local_30 + iVar9 * 0xc);
                      local_78 = (fVar8 * pfVar2[2] +
                                 local_a8 * pfVar2[1] +
                                 *(float *)(local_30 + iVar9 * 0xc) * local_b4) * (float)local_14;
                      local_74 = (fVar6 * pfVar2[2] + fVar7 * pfVar2[1] + *pfVar2 * local_b0) *
                                 (float)local_14;
                      local_70 = (fVar3 * pfVar2[2] + fVar5 * pfVar2[1] + *pfVar2 * local_ac) *
                                 (float)local_14;
                      *(float *)((int)pfVar17 + (int)local_54) =
                           local_78 + *(float *)((int)pfVar17 + (int)local_54);
                      *(float *)((int)pfVar17 + (int)local_54 + 4) =
                           local_74 + *(float *)((int)pfVar17 + (int)local_54 + 4);
                      pfVar2 = (float *)((int)pfVar17 + (int)local_54 + 8);
                      *pfVar2 = local_70 + *pfVar2;
                    }
                  }
                  if (local_e0 != local_dc) {
                    piVar19 = local_e0 + 2;
                    do {
                      FUN_00845720(piVar19[1] + (int)pfVar17,
                                   *(int *)(*piVar15 + piVar19[-1] * 4) * *piVar19 + piVar19[2],
                                   *piVar19);
                      piVar1 = piVar19 + 3;
                      pfVar11 = local_20;
                      piVar19 = piVar19 + 5;
                      fVar5 = local_a0;
                      fVar3 = local_94;
                      fVar7 = local_a4;
                      fVar6 = local_98;
                      fVar8 = local_9c;
                    } while (piVar1 != local_dc);
                  }
                  iVar9 = piVar15[4];
                }
              } while ((float)iVar9 != *pfVar11);
              pfVar11 = pfVar11 + 2;
              local_20 = pfVar11;
            } while (pfVar11 != (float *)local_4c);
          }
          local_18 = local_18 + 100;
          local_1c = local_1c + 1;
          pvVar10 = local_24;
        } while (local_1c < local_d0);
      }
      (**(code **)(*param_2 + 0xe8))(param_1 + 0xb0,local_40,pvVar10);
      if (local_e0 != (int *)0x0) {
        FUN_0089120c(local_e0);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

