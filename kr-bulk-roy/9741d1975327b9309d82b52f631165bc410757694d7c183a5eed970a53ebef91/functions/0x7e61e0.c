
void FUN_007e61e0(int *param_1,int param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  float *pfVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int *unaff_ESI;
  int iVar19;
  float10 fVar20;
  float10 fVar21;
  float local_b0;
  float local_ac;
  float local_a8;
  bool local_a1;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_7c;
  int local_78;
  int local_74;
  int local_6c;
  int local_68;
  int local_64;
  int local_58;
  
  iVar19 = 0;
  iVar1 = param_6 + 1;
  local_a1 = false;
  local_68 = 0;
  if (0 < param_6) {
    iVar4 = iVar1 * 7;
    iVar18 = iVar1 * 0x1c;
    local_98 = 0;
    local_78 = 0;
    local_9c = iVar4;
    local_94 = iVar18;
    do {
      local_8c = 0;
      if (0 < param_5) {
        sVar8 = ((short)local_68 + 1) * (short)iVar1;
        sVar9 = (short)iVar1 * (short)local_68;
        local_88 = iVar19 * 0xc;
        local_84 = local_78;
        local_64 = local_98;
        local_58 = local_94;
        iVar17 = iVar19 * 6;
        local_6c = local_9c;
        do {
          local_a1 = local_a1 == false;
          sVar10 = (short)local_8c;
          if (local_a1) {
            *(short *)(iVar17 + *param_1) = sVar10 + sVar9;
            local_90._0_2_ = sVar10 + 1 + sVar9;
            *(short *)(iVar17 + 2 + *param_1) = (short)local_90;
            *(short *)(iVar17 + 4 + *param_1) = sVar10 + 1 + sVar8;
          }
          else {
            *(short *)(iVar17 + *param_1) = sVar10 + sVar9;
            local_90._0_2_ = sVar10 + 1 + sVar9;
            *(short *)(iVar17 + 2 + *param_1) = (short)local_90;
            *(short *)(iVar17 + 4 + *param_1) = sVar10 + sVar8;
          }
          local_7c._0_2_ = sVar10 + sVar9;
          iVar14 = *param_1 + iVar17;
          pfVar11 = (float *)(param_2 + (uint)*(ushort *)(iVar14 + 4) * 0xc);
          pfVar2 = (float *)(param_2 + (uint)*(ushort *)(*param_1 + iVar17) * 0xc);
          pfVar3 = (float *)(param_2 + (uint)*(ushort *)(iVar14 + 2) * 0xc);
          fVar6 = (pfVar11[2] - pfVar2[2]) * (pfVar3[1] - pfVar2[1]) -
                  (pfVar11[1] - pfVar2[1]) * (pfVar3[2] - pfVar2[2]);
          fVar7 = (*pfVar11 - *pfVar2) * (pfVar3[2] - pfVar2[2]) -
                  (*pfVar3 - *pfVar2) * (pfVar11[2] - pfVar2[2]);
          fVar5 = (*pfVar3 - *pfVar2) * (pfVar11[1] - pfVar2[1]) -
                  (*pfVar11 - *pfVar2) * (pfVar3[1] - pfVar2[1]);
          fVar20 = (float10)FUN_004ad080(fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7);
          if ((float10)0 == fVar20) {
            local_b0 = 1.0;
            fVar20 = (float10)0;
            fVar21 = fVar20;
          }
          else {
            fVar20 = (float10)1 / fVar20;
            local_b0 = (float)((float10)fVar6 * fVar20);
            fVar21 = (float10)fVar7 * fVar20;
            fVar20 = fVar20 * (float10)fVar5;
          }
          local_ac = (float)fVar21;
          pfVar11 = (float *)(*param_3 + local_88);
          *pfVar11 = local_b0;
          pfVar11[1] = local_ac;
          pfVar11[2] = (float)fVar20;
          *(int *)(*unaff_ESI + 4 + (*(int *)(*unaff_ESI + local_84) + local_64) * 4) = iVar19;
          *(int *)(*unaff_ESI + local_84) = *(int *)(*unaff_ESI + local_84) + 1;
          *(int *)(*unaff_ESI + 0x20 + (*(int *)(*unaff_ESI + 0x1c + local_84) + local_64) * 4) =
               iVar19;
          piVar12 = (int *)(*unaff_ESI + 0x1c + local_84);
          *piVar12 = *piVar12 + 1;
          *(int *)(*unaff_ESI + 4 + (*(int *)(*unaff_ESI + local_58) + local_6c) * 4) = iVar19;
          *(int *)(*unaff_ESI + local_58) = *(int *)(*unaff_ESI + local_58) + 1;
          iVar14 = iVar19 + 1;
          sVar15 = sVar10 + 1 + sVar8;
          if (local_a1) {
            *(short *)(iVar17 + 6 + *param_1) = sVar15;
            *(short *)(iVar17 + 8 + *param_1) = sVar10 + sVar8;
            *(short *)(iVar17 + 10 + *param_1) = (short)local_7c;
          }
          else {
            *(short *)(iVar17 + 6 + *param_1) = sVar15;
            *(short *)(iVar17 + 8 + *param_1) = sVar10 + sVar8;
            *(short *)(iVar17 + 10 + *param_1) = (short)local_90;
          }
          iVar16 = iVar17 + 6 + *param_1;
          pfVar11 = (float *)(param_2 + (uint)*(ushort *)(iVar16 + 4) * 0xc);
          pfVar2 = (float *)(param_2 + (uint)*(ushort *)(iVar17 + 6 + *param_1) * 0xc);
          pfVar3 = (float *)(param_2 + (uint)*(ushort *)(iVar16 + 2) * 0xc);
          fVar6 = (pfVar11[2] - pfVar2[2]) * (pfVar3[1] - pfVar2[1]) -
                  (pfVar11[1] - pfVar2[1]) * (pfVar3[2] - pfVar2[2]);
          fVar7 = (*pfVar11 - *pfVar2) * (pfVar3[2] - pfVar2[2]) -
                  (*pfVar3 - *pfVar2) * (pfVar11[2] - pfVar2[2]);
          fVar5 = (*pfVar3 - *pfVar2) * (pfVar11[1] - pfVar2[1]) -
                  (*pfVar11 - *pfVar2) * (pfVar3[1] - pfVar2[1]);
          fVar20 = (float10)FUN_004ad080(fVar5 * fVar5 + fVar6 * fVar6 + fVar7 * fVar7);
          if ((float10)0 == fVar20) {
            local_b0 = 1.0;
            local_ac = 0.0;
            local_a8 = 0.0;
          }
          else {
            fVar20 = (float10)1 / fVar20;
            local_b0 = (float)((float10)fVar6 * fVar20);
            local_ac = (float)((float10)fVar7 * fVar20);
            local_a8 = (float)(fVar20 * (float10)fVar5);
          }
          pfVar11 = (float *)(*param_3 + local_88 + 0xc);
          *pfVar11 = local_b0;
          pfVar11[1] = local_ac;
          pfVar11[2] = local_a8;
          local_8c = local_8c + 1;
          *(int *)(*unaff_ESI + 0x20 + (*(int *)(*unaff_ESI + 0x1c + local_58) + local_6c) * 4) =
               iVar14;
          piVar12 = (int *)(*unaff_ESI + 0x1c + local_58);
          *piVar12 = *piVar12 + 1;
          local_88 = local_88 + 0x18;
          *(int *)(*unaff_ESI + 4 + (*(int *)(*unaff_ESI + local_58) + local_6c) * 4) = iVar14;
          *(int *)(*unaff_ESI + local_58) = *(int *)(*unaff_ESI + local_58) + 1;
          iVar16 = *(int *)(*unaff_ESI + 0x1c + local_84) + local_64;
          local_6c = local_6c + 7;
          local_64 = local_64 + 7;
          *(int *)(*unaff_ESI + 0x20 + iVar16 * 4) = iVar14;
          piVar12 = (int *)(*unaff_ESI + 0x1c + local_84);
          *piVar12 = *piVar12 + 1;
          local_84 = local_84 + 0x1c;
          local_58 = local_58 + 0x1c;
          iVar19 = iVar19 + 2;
          iVar17 = iVar17 + 0xc;
        } while (local_8c < param_5);
      }
      local_a1 = !local_a1;
      local_68 = local_68 + 1;
      local_78 = local_78 + iVar18;
      local_94 = local_94 + iVar18;
      local_98 = local_98 + iVar4;
      local_9c = local_9c + iVar4;
    } while (local_68 < param_6);
  }
  if (0 < iVar1) {
    local_94 = 0;
    local_98 = 0;
    local_7c = iVar1;
    do {
      if (0 < param_5 + 1) {
        local_74 = local_98;
        local_9c = local_94;
        local_90 = param_5 + 1;
        do {
          local_b0 = 0.0;
          piVar12 = (int *)(*unaff_ESI + local_9c);
          local_ac = 0.0;
          iVar19 = 0;
          local_a8 = 0.0;
          iVar18 = *piVar12;
          if (3 < iVar18) {
            iVar4 = *param_3;
            iVar17 = (iVar18 - 4U >> 2) + 1;
            iVar19 = iVar17 * 4;
            piVar13 = piVar12 + 2;
            do {
              iVar14 = iVar4 + piVar13[-1] * 0xc;
              iVar17 = iVar17 + -1;
              pfVar11 = (float *)(iVar4 + *piVar13 * 0xc);
              pfVar2 = (float *)(iVar4 + piVar13[1] * 0xc);
              pfVar3 = (float *)(iVar4 + piVar13[2] * 0xc);
              local_b0 = local_b0 + *(float *)(iVar4 + piVar13[-1] * 0xc) + *pfVar11 + *pfVar2 +
                         *pfVar3;
              local_ac = pfVar3[1] + pfVar2[1] + pfVar11[1] + *(float *)(iVar14 + 4) + local_ac;
              local_a8 = pfVar3[2] + pfVar2[2] + pfVar11[2] + *(float *)(iVar14 + 8) + local_a8;
              piVar13 = piVar13 + 4;
            } while (iVar17 != 0);
          }
          if (iVar19 < iVar18) {
            piVar12 = piVar12 + iVar19 + 1;
            iVar18 = iVar18 - iVar19;
            do {
              local_b0 = local_b0 + *(float *)(*param_3 + *piVar12 * 0xc);
              iVar19 = *param_3 + *piVar12 * 0xc;
              piVar12 = piVar12 + 1;
              iVar18 = iVar18 + -1;
              local_ac = *(float *)(iVar19 + 4) + local_ac;
              local_a8 = *(float *)(iVar19 + 8) + local_a8;
            } while (iVar18 != 0);
          }
          fVar20 = (float10)FUN_004ad080(local_a8 * local_a8 +
                                         local_ac * local_ac + local_b0 * local_b0);
          if ((float10)0 == fVar20) {
            local_b0 = 1.0;
            local_ac = 0.0;
            local_a8 = 0.0;
          }
          else {
            fVar20 = (float10)1 / fVar20;
            local_b0 = (float)((float10)local_b0 * fVar20);
            local_ac = (float)((float10)local_ac * fVar20);
            local_a8 = (float)(fVar20 * (float10)local_a8);
          }
          iVar19 = *param_4;
          local_9c = local_9c + 0x1c;
          *(float *)(iVar19 + local_74) = local_b0;
          *(float *)(iVar19 + 4 + local_74) = local_ac;
          *(float *)(iVar19 + 8 + local_74) = local_a8;
          local_74 = local_74 + 0xc;
          local_90 = local_90 + -1;
        } while (local_90 != 0);
      }
      local_98 = local_98 + iVar1 * 0xc;
      local_94 = local_94 + iVar1 * 0x1c;
      local_7c = local_7c + -1;
    } while (local_7c != 0);
  }
  return;
}

