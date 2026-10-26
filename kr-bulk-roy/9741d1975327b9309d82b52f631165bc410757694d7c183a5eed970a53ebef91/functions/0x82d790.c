
undefined4
FUN_0082d790(float *param_1,float *param_2,float param_3,float param_4,float param_5,float param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  float10 fVar12;
  undefined1 local_74 [24];
  undefined4 *local_5c;
  int *local_50;
  int local_4c;
  undefined4 local_44;
  undefined4 local_40;
  float local_3c;
  int *local_38;
  float local_34;
  int *local_30;
  float local_2c;
  float local_28;
  float local_24;
  int *local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pfVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009070d0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  fVar2 = (float)FUN_008fed10(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_34 = fVar2;
  local_30 = (int *)FUN_008fed10();
  fVar3 = (float)FUN_008fed10();
  local_3c = fVar3;
  local_38 = (int *)FUN_008fed10();
  if ((int)fVar2 < 0) {
    ExceptionList = local_10;
    return 0;
  }
  if ((int)local_30 < 0) {
    ExceptionList = local_10;
    return 0;
  }
  if ((uint)param_1[2] < (uint)fVar3) {
    ExceptionList = local_10;
    return 0;
  }
  if ((int *)param_1[3] < local_38) {
    ExceptionList = local_10;
    return 0;
  }
  if ((int)fVar3 < 0) {
    ExceptionList = local_10;
    return 0;
  }
  if ((int)local_38 < 0) {
    ExceptionList = local_10;
    return 0;
  }
  if ((uint)param_1[2] < (uint)fVar2) {
    ExceptionList = local_10;
    return 0;
  }
  if ((int *)param_1[3] < local_30) {
    ExceptionList = local_10;
    return 0;
  }
  iVar4 = FUN_0082ed20(param_1);
  if (iVar4 != 0) {
    *param_2 = param_5 - param_3;
    param_2[1] = param_6 - param_4;
    ExceptionList = local_10;
    return 3;
  }
  FUN_0049d640();
  local_8 = 0;
  FUN_0049d640();
  local_8._0_1_ = 1;
  iVar4 = *(int *)((int)param_1[8] + 8 + ((int)param_1[2] * (int)local_30 + (int)fVar2) * 0x18);
  iVar5 = *(int *)((int)param_1[8] + 8 + ((int)param_1[2] * (int)local_38 + (int)local_3c) * 0x18);
  local_18 = iVar4;
  fVar12 = (float10)FUN_0082d750();
  local_14 = (int *)(float)fVar12;
  if (64.0 <= (float)local_14) {
LAB_0082d93d:
    if (iVar4 == iVar5) {
      if (iVar4 != -1) {
        local_3c = param_5 - param_3;
        *param_2 = local_3c;
        local_38 = (int *)(param_6 - param_4);
        param_2[1] = (float)local_38;
        D3DXVec2Normalize(param_2,param_2);
        goto LAB_0082db30;
      }
      if (32.0 <= (float)local_14) goto LAB_0082da07;
      FUN_0082ef70();
      piVar6 = local_30;
      local_8._0_1_ = 3;
      iVar4 = FUN_0082e360(param_1,local_74,fVar2,local_30,local_3c,local_38,(int)fVar2 + -0x20,
                           local_30 + -8,(int)fVar2 + 0x20,local_30 + 8);
      if (iVar4 != 0) goto LAB_0082daca;
      iVar5 = *(int *)((int)param_1[8] + 0xc + ((int)param_1[2] * (int)piVar6 + (int)fVar2) * 0x18);
      if (iVar5 != -1) {
        local_8._0_1_ = 1;
        FUN_007b74a0();
        iVar4 = local_18;
        goto LAB_0082da07;
      }
    }
    else {
LAB_0082da07:
      param_1 = (float *)iVar5;
      fVar3 = pfVar1[8];
      iVar5 = (int)pfVar1[2] * (int)local_38 + (int)local_3c;
      if ((*(int *)((int)fVar3 + 0x10 + iVar5 * 0x18) == 0) ||
         (iVar9 = (int)pfVar1[2] * (int)local_30 + (int)fVar2,
         *(int *)((int)fVar3 + 0x10 + iVar9 * 0x18) == 0)) goto LAB_0082df93;
      if (iVar4 == -1) {
        iVar4 = (int)pfVar1[4] + *(int *)((int)fVar3 + iVar9 * 0x18 + 0xc) * 0x38;
        local_44 = *(undefined4 *)(iVar4 + 0x24);
        local_40 = *(undefined4 *)(iVar4 + 0x28);
        fVar12 = (float10)FUN_0082d750();
        if ((float10)64.0 <= fVar12) goto LAB_0082df93;
        FUN_0082ef70();
        local_8._0_1_ = 4;
        iVar4 = (int)fVar2 + -0x40;
        piVar6 = local_30 + -0x10;
        iVar5 = (int)fVar2 + 0x40;
        piVar8 = local_30 + 0x10;
      }
      else {
        iVar9 = (int)param_1;
        if (((param_1 != (float *)0xffffffff) ||
            (iVar9 = *(int *)((int)fVar3 + iVar5 * 0x18 + 0xc), iVar4 != iVar9)) ||
           (iVar9 = (int)param_1, 32.0 <= (float)local_14)) {
          param_1 = (float *)iVar9;
          local_14 = (int *)CONCAT22((short)param_1,(short)iVar4);
          FUN_0082ef00(&local_14);
          if ((local_24 != pfVar1[10]) && (iVar5 = *(int *)((int)local_24 + 0x10), iVar5 != 0)) {
            *(int *)(iVar5 + 8) = DAT_00fba91c;
            DAT_00fba91c = DAT_00fba91c + 1;
            iVar4 = (int)pfVar1[4] + (uint)*(ushort *)(iVar5 + 4) * 0x38;
            local_2c = (float)*(int *)(iVar4 + 0x24) * (1.0 / *pfVar1);
            local_28 = (float)*(int *)(iVar4 + 0x28) * (1.0 / pfVar1[1]);
            local_3c = (float)(int)local_34 * (1.0 / *pfVar1);
            local_38 = (int *)((1.0 / pfVar1[1]) * (float)(int)local_30);
            local_34 = local_2c - local_3c;
            *param_2 = local_34;
            local_30 = (int *)(local_28 - (float)local_38);
            param_2[1] = (float)local_30;
            FUN_0056fb00();
            FUN_0056fb00();
            ExceptionList = local_10;
            return 2;
          }
          puVar7 = (undefined4 *)FUN_00891268(0x10);
          puVar10 = (undefined4 *)0x0;
          if (puVar7 != (undefined4 *)0x0) {
            puVar7[2] = 0;
            *puVar7 = 0;
            puVar7[1] = 0;
            puVar7[3] = 0;
            puVar10 = puVar7;
          }
          *puVar10 = 0;
          puVar10[1] = iVar4;
          puVar10[2] = 0x3f800000;
          param_2 = (float *)puVar10;
          fVar12 = (float10)FUN_0082d750();
          puVar10[3] = (float)fVar12;
          FUN_0074a200();
          FUN_0082d6a0();
          local_24 = -NAN;
          local_14 = (int *)0x0;
          fVar2 = 0.0;
          do {
            if (((local_4c == 0) || (local_24 != -NAN)) || (0x1ff < (int)fVar2)) goto LAB_0082dede;
            local_28 = (float)((int)fVar2 + 1);
            param_2 = (float *)0x0;
            FUN_0082d6e0(&local_50,&param_2);
            FUN_0074a200();
            *(undefined4 *)((int)pfVar1[4] + 0x34 + *(int *)((int)param_2 + 4) * 0x38) = 1;
            iVar4 = *(int *)((int)pfVar1[4] + 4 + *(int *)((int)param_2 + 4) * 0x38);
            local_20 = (int *)((int)pfVar1[4] + 4 + *(int *)((int)param_2 + 4) * 0x38);
            local_1c = 0;
            fVar2 = local_28;
            if (local_20[1] - iVar4 >> 2 != 0) {
              do {
                uVar11 = local_1c;
                iVar4 = *(int *)(iVar4 + local_1c * 4);
                if (*(int *)((int)pfVar1[4] + 0x34 + iVar4 * 0x38) == 0) {
                  iVar5 = (int)pfVar1[4] + iVar4 * 0x38;
                  local_44 = *(undefined4 *)(iVar5 + 0x24);
                  local_40 = *(undefined4 *)(iVar5 + 0x28);
                  if (*(int *)(iVar5 + 0x30) == 0) {
                    piVar8 = (int *)FUN_00891268(0x10);
                    piVar6 = (int *)0x0;
                    if (piVar8 != (int *)0x0) {
                      *piVar8 = 0;
                      piVar8[2] = 0;
                      piVar8[1] = 0;
                      piVar8[3] = 0;
                      piVar6 = piVar8;
                    }
                    piVar6[2] = (int)(*(float *)((int)param_2 + 8) + 2.0);
                    piVar6[1] = *(int *)(*local_20 + uVar11 * 4);
                    *piVar6 = (int)param_2;
                    *(undefined4 *)((int)pfVar1[4] + 0x30 + piVar6[1] * 0x38) = 1;
                    local_30 = piVar6;
                    fVar12 = (float10)FUN_0082d750();
                    piVar6[3] = (int)(float)fVar12;
                    FUN_0074a200();
                    uVar11 = local_1c;
                    if ((float *)piVar6[1] == param_1) {
                      local_24 = 1.4013e-45;
                      fVar2 = local_28;
                      local_14 = piVar6;
                      break;
                    }
                  }
                  else {
                    for (piVar6 = (int *)*local_50; piVar6 != local_50; piVar6 = (int *)*piVar6) {
                      if (*(int *)(piVar6[2] + 4) == iVar4) {
                        fVar12 = (float10)FUN_0082d750();
                        if (fVar12 + (float10)*(float *)((int)param_2 + 8) + (float10)2.0 <
                            (float10)*(float *)(piVar6[2] + 0xc) +
                            (float10)*(float *)(piVar6[2] + 8)) {
                          *(float *)(piVar6[2] + 8) =
                               (float)((float10)2.0 + (float10)*(float *)((int)param_2 + 8));
                          *(float **)piVar6[2] = param_2;
                        }
                        break;
                      }
                    }
                  }
                }
                iVar4 = *local_20;
                local_1c = uVar11 + 1;
                fVar2 = local_28;
              } while (local_1c < (uint)(local_20[1] - iVar4 >> 2));
            }
          } while( true );
        }
        FUN_0082ef70();
        local_8._0_1_ = 5;
        iVar4 = (int)fVar2 + -0x20;
        piVar6 = local_30 + -8;
        iVar5 = (int)fVar2 + 0x20;
        piVar8 = local_30 + 8;
      }
      iVar4 = FUN_0082e360(pfVar1,local_74,fVar2,local_30,local_3c,local_38,iVar4,piVar6,iVar5,
                           piVar8);
      if (iVar4 != 0) goto LAB_0082daca;
    }
    FUN_007b74a0();
LAB_0082df93:
    FUN_0056fb00();
    FUN_0056fb00();
    ExceptionList = local_10;
    return 0;
  }
  FUN_0082ef70();
  local_8._0_1_ = 2;
  iVar4 = FUN_0082e360(param_1,local_74,fVar2,local_30,local_3c,local_38,(int)fVar2 + -0x40,
                       local_30 + -0x10,(int)fVar2 + 0x40,local_30 + 0x10);
  if (iVar4 == 0) {
    local_8._0_1_ = 1;
    FUN_007b74a0();
    iVar4 = local_18;
    goto LAB_0082d93d;
  }
LAB_0082daca:
  piVar6 = (int *)FUN_0082efd0();
  local_2c = (float)*piVar6 * (1.0 / *pfVar1);
  local_28 = (float)piVar6[1] * (1.0 / pfVar1[1]);
  local_3c = (float)(int)local_34 * (1.0 / *pfVar1);
  local_38 = (int *)((1.0 / pfVar1[1]) * (float)(int)local_30);
  local_34 = local_2c - local_3c;
  *param_2 = local_34;
  local_30 = (int *)(local_28 - (float)local_38);
  param_2[1] = (float)local_30;
  FUN_007b74a0();
LAB_0082db30:
  FUN_0056fb00();
  FUN_0056fb00();
  ExceptionList = local_10;
  return 3;
LAB_0082dede:
  param_2 = (float *)0xffffffff;
  piVar6 = local_14;
  while (piVar8 = piVar6, piVar8 != (int *)0x0) {
    piVar6 = (int *)*piVar8;
    if ((piVar6 != (int *)0x0) && (*piVar6 == 0)) {
      param_2 = (float *)piVar8[1];
    }
  }
  for (piVar6 = (int *)*local_50; piVar6 != local_50; piVar6 = (int *)*piVar6) {
    FUN_0089120c(piVar6[2]);
  }
  for (puVar10 = (undefined4 *)*local_5c; puVar10 != local_5c; puVar10 = (undefined4 *)*puVar10) {
    FUN_0089120c(puVar10[2]);
  }
  if ((local_14 != (int *)0x0) && (param_2 != (float *)0xffffffff)) {
    puVar10 = (undefined4 *)FUN_00891268(0xc);
    if (puVar10 != (undefined4 *)0x0) {
      *(undefined2 *)(puVar10 + 1) = param_2._0_2_;
      param_2 = (float *)CONCAT22((short)param_1,(undefined2)local_18);
      DAT_00fba91c = DAT_00fba91c + 1;
      *puVar10 = param_2;
      puVar10[2] = DAT_00fba91c;
    }
    FUN_0082e0c0(pfVar1);
  }
  goto LAB_0082df93;
}

