
/* WARNING: Type propagation algorithm not settling */

void FUN_00796260(uint param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  float *pfVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  float10 fVar12;
  float local_b8 [4];
  float local_a8 [12];
  int local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c [4];
  undefined1 local_c [4];
  float local_8;
  
  piVar3 = param_2;
  local_8 = (float)(**(code **)(*param_2 + 0x18))();
  local_20 = 0.0;
  local_1c[0] = 0.0;
  local_1c[1] = 0.0;
  local_1c[2] = 1.0;
  local_34 = 1.0;
  local_a8[3] = 1.0;
  local_44 = 1.0;
  local_54 = 1.0;
  local_64 = 1.0;
  local_a8[0xb] = 1.0;
  local_a8[7] = 1.0;
  local_40 = 0.0;
  local_3c = 0.0;
  local_38 = 0.0;
  local_a8[0] = 0.0;
  local_a8[1] = 0.0;
  local_a8[2] = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_48 = 0.0;
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = 0.0;
  local_70 = 0.0;
  local_6c = 0.0;
  local_68 = 0.0;
  local_a8[8] = 0.0;
  local_a8[9] = 0.0;
  local_a8[10] = 0.0;
  local_a8[4] = 0.0;
  local_a8[5] = 0.0;
  local_a8[6] = 0.0;
  if ((0 < (int)param_1) || ((param_2[3] == 3 && (param_2[4] == 3)))) {
    iVar9 = param_2[6];
    if ((uint)((param_2[7] - iVar9) / 0x60) <= param_1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid vector<T> subscript");
    }
    fVar1 = *(float *)(param_1 * 0x60 + 0x50 + iVar9);
    iVar9 = param_1 * 0x60 + iVar9;
    if (fVar1 < 6.2831755 == (fVar1 == 6.2831755)) {
      iVar11 = 0;
      do {
        local_1c[0] = *(float *)(iVar9 + 0x54);
        local_1c[1] = *(float *)(iVar9 + 0x58);
        local_1c[2] = *(float *)(iVar9 + 0x5c);
        *(undefined4 *)((int)local_a8 + iVar11) = *(undefined4 *)((int)local_1c + iVar11);
        iVar11 = iVar11 + 4;
      } while (iVar11 < 0xc);
      local_a8[3] = 0.0;
      pfVar4 = (float *)FUN_00780500();
      if (&local_60 != pfVar4) {
        local_54 = pfVar4[3];
        local_60 = *pfVar4;
        local_5c = pfVar4[1];
        local_58 = pfVar4[2];
      }
    }
    else {
      uVar10 = (uint)local_8;
      if (param_1 != 0) {
        uVar10 = param_1;
      }
      pfVar4 = (float *)(**(code **)(*param_2 + 0x1c))(&local_30,uVar10 - 1);
      if (&local_20 != pfVar4) {
        local_1c[2] = pfVar4[3];
        local_20 = *pfVar4;
        local_1c[0] = pfVar4[1];
        local_1c[1] = pfVar4[2];
      }
      pfVar4 = (float *)(**(code **)(*param_2 + 0x1c))(&local_30,param_1);
      if (local_1c[2] * pfVar4[3] + local_1c[1] * pfVar4[2] + local_1c[0] * pfVar4[1] +
          local_20 * *pfVar4 < 0.0) {
        local_30 = -local_20;
        local_2c = -local_1c[0];
        local_28 = -local_1c[1];
        local_1c[2] = -local_1c[2];
        local_20 = local_30;
        local_1c[0] = local_2c;
        local_1c[1] = local_28;
      }
      uVar5 = (**(code **)(*param_2 + 0x1c))(local_b8,param_1);
      local_30 = -local_20;
      local_2c = -local_1c[0];
      local_28 = -local_1c[1];
      local_24 = local_1c[2];
      FUN_0077e880(uVar5);
      FUN_00780500();
      local_54 = local_24;
      local_60 = local_30;
      local_5c = local_2c;
      local_58 = local_28;
    }
  }
  if (((int)param_1 < (int)((int)local_8 - 1U)) || ((param_2[3] == 3 && (param_2[4] == 3)))) {
    if (param_1 == (int)local_8 - 1U) {
      uVar10 = 0;
    }
    else {
      uVar10 = param_1 + 1;
    }
    if ((uint)((param_2[7] - param_2[6]) / 0x60) <= uVar10) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid vector<T> subscript");
    }
    iVar9 = uVar10 * 0x60 + param_2[6];
    if (*(float *)(iVar9 + 0x50) < 6.2831755 == (*(float *)(iVar9 + 0x50) == 6.2831755)) {
      iVar11 = 0;
      do {
        local_1c[0] = *(float *)(iVar9 + 0x54);
        local_1c[1] = *(float *)(iVar9 + 0x58);
        local_1c[2] = *(float *)(iVar9 + 0x5c);
        *(undefined4 *)((int)local_a8 + iVar11) = *(undefined4 *)((int)local_1c + iVar11);
        iVar11 = iVar11 + 4;
      } while (iVar11 < 0xc);
      local_a8[3] = 0.0;
      pfVar4 = (float *)FUN_00780500();
      if (&local_50 != pfVar4) {
        local_44 = pfVar4[3];
        local_50 = *pfVar4;
        local_4c = pfVar4[1];
        local_48 = pfVar4[2];
      }
    }
    else {
      pfVar4 = (float *)(**(code **)(*param_2 + 0x1c))(local_b8,uVar10);
      if (&local_40 != pfVar4) {
        local_34 = pfVar4[3];
        local_40 = *pfVar4;
        local_3c = pfVar4[1];
        local_38 = pfVar4[2];
      }
      pfVar4 = (float *)(**(code **)(*param_2 + 0x1c))(local_b8,param_1);
      if (local_34 * pfVar4[3] + local_38 * pfVar4[2] + local_3c * pfVar4[1] + local_40 * *pfVar4 <
          0.0) {
        local_40 = -local_40;
        local_3c = -local_3c;
        local_38 = -local_38;
        local_34 = -local_34;
        local_30 = local_40;
        local_2c = local_3c;
        local_28 = local_38;
      }
      pfVar4 = (float *)(**(code **)(*param_2 + 0x1c))(local_b8,param_1);
      local_30 = -*pfVar4;
      local_2c = -pfVar4[1];
      local_28 = -pfVar4[2];
      local_24 = pfVar4[3];
      FUN_0077e880(&local_40);
      FUN_00780500();
      local_44 = local_24;
      local_50 = local_30;
      local_4c = local_2c;
      local_48 = local_28;
    }
  }
  if ((param_1 == 0) && ((param_2[3] != 3 || (param_2[4] != 3)))) {
    local_54 = local_44;
    local_60 = local_50;
    local_5c = local_4c;
    local_58 = local_48;
  }
  local_1c[3] = (float)((int)local_8 - 1);
  if (((float)param_1 == local_1c[3]) && ((param_2[3] != 3 || (param_2[4] != 3)))) {
    local_44 = local_54;
    local_50 = local_60;
    local_4c = local_5c;
    local_48 = local_58;
  }
  iVar9 = param_2[6];
  piVar6 = param_2 + 7;
  param_2 = (int *)0x3f800000;
  local_34 = 1.0;
  if (param_1 < (uint)((*piVar6 - iVar9) / 0x60)) {
    local_78 = param_1 * 0x60;
    iVar11 = iVar9 + local_78;
    local_74 = 1.0 - *(float *)(iVar9 + 0x20 + local_78);
    if (((0 < (int)param_1) && ((int)param_1 < (int)local_1c[3])) ||
       ((piVar3[3] == 3 && (piVar3[4] == 3)))) {
      if (param_1 == 0) {
        iVar9 = (**(code **)(*piVar3 + 4))(local_1c + 1);
        iVar9 = *(int *)(iVar9 + 4);
        piVar6 = (int *)(**(code **)(*piVar3 + 4))(local_c);
        iVar11 = *piVar6;
        iVar7 = (**(code **)(*piVar3 + 0x20))(local_1c[3]);
        iVar8 = (**(code **)(*piVar3 + 0x20))(0);
        local_8 = (float)(iVar8 + ((iVar9 - iVar11) - iVar7));
        iVar9 = (**(code **)(*piVar3 + 0x20))(1);
        iVar11 = (**(code **)(*piVar3 + 0x20))(0);
        param_2 = (int *)((local_8 + (float)(iVar9 - iVar11)) * 0.5);
        local_34 = local_8 / (float)param_2;
        iVar9 = (**(code **)(*piVar3 + 0x20))(1);
        iVar11 = (**(code **)(*piVar3 + 0x20))(0);
        local_8 = (float)(iVar9 - iVar11);
        fVar1 = (float)(int)local_8;
      }
      else if ((float)param_1 == local_1c[3]) {
        iVar9 = (**(code **)(*piVar3 + 4))(local_1c + 1);
        iVar9 = *(int *)(iVar9 + 4);
        piVar6 = (int *)(**(code **)(*piVar3 + 4))(&local_38);
        iVar11 = *piVar6;
        iVar7 = (**(code **)(*piVar3 + 0x20))(local_1c[3]);
        iVar8 = (**(code **)(*piVar3 + 0x20))(0);
        local_34 = (float)(iVar8 + ((iVar9 - iVar11) - iVar7));
        iVar11 = (int)local_8 - 2;
        local_8 = (float)iVar11;
        iVar9 = (**(code **)(*piVar3 + 0x20))(local_1c[3]);
        iVar11 = (**(code **)(*piVar3 + 0x20))(iVar11);
        param_2 = (int *)((local_34 + (float)(iVar9 - iVar11)) * 0.5);
        local_34 = local_34 / (float)param_2;
        iVar9 = (**(code **)(*piVar3 + 0x20))(local_1c[3]);
        iVar11 = (**(code **)(*piVar3 + 0x20))(local_8);
        local_8 = (float)(iVar9 - iVar11);
        fVar1 = (float)(int)local_8;
      }
      else {
        iVar9 = (**(code **)(*piVar3 + 0x20))(param_1 - 1);
        iVar11 = (**(code **)(*piVar3 + 0x20))(param_1 + 1);
        param_2 = (int *)((float)(iVar11 - iVar9) * 0.5);
        iVar9 = (**(code **)(*piVar3 + 0x20))(param_1 - 1);
        iVar11 = (**(code **)(*piVar3 + 0x20))(param_1);
        local_8 = (float)(iVar11 - iVar9);
        local_34 = (float)(int)local_8 / (float)param_2;
        iVar9 = (**(code **)(*piVar3 + 0x20))(param_1);
        iVar11 = (**(code **)(*piVar3 + 0x20))(param_1 + 1);
        local_8 = (float)(iVar11 - iVar9);
        fVar1 = (float)(int)local_8;
      }
      if ((uint)((piVar3[7] - piVar3[6]) / 0x60) <= param_1) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db7d("invalid vector<T> subscript");
      }
      iVar11 = piVar3[6] + local_78;
      fVar12 = (float10)FUN_004ff540(*(undefined4 *)(iVar11 + 0x20));
      fVar2 = (float)fVar12;
      local_34 = (local_34 + fVar2) - local_34 * fVar2;
      param_2 = (int *)((fVar1 / (float)param_2 + fVar2) - (fVar1 / (float)param_2) * fVar2);
    }
    local_8 = (1.0 - *(float *)(iVar11 + 0x1c)) * 0.5;
    fVar1 = 1.0 - *(float *)(iVar11 + 0x24);
    fVar2 = local_74 * local_8;
    local_8 = (2.0 - local_74) * local_8;
    local_74 = 1.0 - fVar2 * (2.0 - fVar1) * local_34;
    local_1c[3] = -local_8 * fVar1 * local_34;
    local_1c[2] = fVar2 * fVar1 * (float)param_2 - 1.0;
    local_70 = (local_74 * local_60 + local_1c[3] * local_50) * 0.5;
    local_6c = (local_4c * local_1c[3] + local_5c * local_74) * 0.5;
    local_68 = (local_48 * local_1c[3] + local_58 * local_74) * 0.5;
    local_64 = (local_74 * local_54 + local_44 * local_1c[3]) * 0.5;
    pfVar4 = (float *)FUN_00780580();
    if (local_a8 + 8 != pfVar4) {
      local_a8[0xb] = pfVar4[3];
      local_a8[8] = *pfVar4;
      local_a8[9] = pfVar4[1];
      local_a8[10] = pfVar4[2];
    }
    pfVar4 = (float *)FUN_00780580();
    if (local_a8 + 4 != pfVar4) {
      local_a8[7] = pfVar4[3];
      local_a8[4] = *pfVar4;
      local_a8[5] = pfVar4[1];
      local_a8[6] = pfVar4[2];
    }
    pfVar4 = (float *)(**(code **)(*piVar3 + 0x1c))(local_b8,param_1);
    local_64 = ((local_a8[0xb] * pfVar4[3] - local_a8[8] * *pfVar4) - local_a8[9] * pfVar4[1]) -
               local_a8[10] * pfVar4[2];
    local_70 = (local_a8[9] * pfVar4[2] + *pfVar4 * local_a8[0xb] + pfVar4[3] * local_a8[8]) -
               local_a8[10] * pfVar4[1];
    local_6c = (*pfVar4 * local_a8[10] + local_a8[9] * pfVar4[3] + local_a8[0xb] * pfVar4[1]) -
               pfVar4[2] * local_a8[8];
    local_68 = (pfVar4[2] * local_a8[0xb] + pfVar4[3] * local_a8[10] + pfVar4[1] * local_a8[8]) -
               *pfVar4 * local_a8[9];
    if (param_1 < (uint)((piVar3[7] - piVar3[6]) / 0x60)) {
      pfVar4 = (float *)(local_78 + 0x40 + piVar3[6]);
      if (pfVar4 != local_b8) {
        pfVar4[3] = local_64;
        *pfVar4 = local_70;
        pfVar4[1] = local_6c;
        pfVar4[2] = local_68;
      }
      pfVar4 = (float *)(**(code **)(*piVar3 + 0x1c))(local_b8,param_1);
      local_64 = ((local_a8[7] * pfVar4[3] - local_a8[4] * *pfVar4) - local_a8[5] * pfVar4[1]) -
                 local_a8[6] * pfVar4[2];
      local_70 = (local_a8[5] * pfVar4[2] + local_a8[7] * *pfVar4 + local_a8[4] * pfVar4[3]) -
                 local_a8[6] * pfVar4[1];
      local_6c = (local_a8[6] * *pfVar4 + local_a8[5] * pfVar4[3] + local_a8[7] * pfVar4[1]) -
                 pfVar4[2] * local_a8[4];
      local_68 = (pfVar4[3] * local_a8[6] + pfVar4[2] * local_a8[7] + pfVar4[1] * local_a8[4]) -
                 *pfVar4 * local_a8[5];
      if (param_1 < (uint)((piVar3[7] - piVar3[6]) / 0x60)) {
        pfVar4 = (float *)(local_78 + 0x30 + piVar3[6]);
        if (pfVar4 != local_b8) {
          pfVar4[3] = local_64;
          *pfVar4 = local_70;
          pfVar4[1] = local_6c;
          pfVar4[2] = local_68;
        }
        return;
      }
                    /* WARNING: Subroutine does not return */
      FUN_0087db7d("invalid vector<T> subscript");
    }
                    /* WARNING: Subroutine does not return */
    FUN_0087db7d("invalid vector<T> subscript");
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid vector<T> subscript");
}

