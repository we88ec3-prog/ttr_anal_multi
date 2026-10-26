
void FUN_00803070(int param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  float *pfVar6;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  uint local_30;
  float local_2c;
  int local_28;
  float *local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093206c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  local_8 = 0xffffffff;
  local_30 = *(int *)(param_1 + 0xc) - *(int *)(param_1 + 8) >> 2;
  local_1c = 0;
  if (local_30 == 0) {
    *(undefined4 *)(param_1 + 4) = 1;
    ExceptionList = local_10;
    return;
  }
  do {
    uVar5 = local_1c;
    puVar4 = *(undefined4 **)(*(int *)(param_1 + 8) + local_1c * 4);
    local_14 = *(int *)*puVar4;
    if (*(int *)(param_1 + 4) != 0) {
      local_18 = FUN_007f3a70();
      if (*(int *)(*(int *)(param_1 + 8) + uVar5 * 4) != 0) {
        iVar3 = *(int *)(*(int *)(param_1 + 8) + uVar5 * 4);
        if (iVar3 != 0) {
          if (*(int *)(iVar3 + 4) != 0) {
            FUN_00891d3d(*(int *)(iVar3 + 4));
            *(undefined4 *)(iVar3 + 4) = 0;
          }
          if (*(int *)(iVar3 + 8) != 0) {
            FUN_00891d3d(*(int *)(iVar3 + 8));
            *(undefined4 *)(iVar3 + 8) = 0;
          }
          FUN_0089120c(iVar3);
        }
        *(undefined4 *)(*(int *)(param_1 + 8) + uVar5 * 4) = 0;
      }
      *(int *)(*(int *)(param_1 + 8) + uVar5 * 4) = local_18;
      puVar4 = *(undefined4 **)(*(int *)(param_1 + 8) + uVar5 * 4);
    }
    local_3c = 0.0;
    local_38 = 0.0;
    local_20 = *(uint *)(local_14 + 0x14) >> 4 & 1;
    local_34 = 0.0;
    local_28 = *(int *)(local_14 + 0xc);
    local_2c = *(float *)(local_14 + 0x10);
    if (local_2c != 0.0) {
      local_14 = 0;
      local_18 = (int)local_2c;
      do {
        pfVar6 = (float *)(puVar4[1] + local_14);
        _memset(&local_88,0,0x34);
        local_68 = 1.0;
        local_78 = 1.0;
        local_88 = 1.0;
        FUN_00780a00();
        FUN_00791100();
        local_64 = param_2;
        local_60 = param_3;
        local_5c = param_4;
        local_48 = pfVar6[2] * local_70 + pfVar6[1] * local_7c + *pfVar6 * local_88 + param_2;
        local_44 = pfVar6[2] * local_6c + pfVar6[1] * local_78 + *pfVar6 * local_84 + param_3;
        fVar1 = *pfVar6;
        fVar2 = pfVar6[1];
        *pfVar6 = local_48;
        pfVar6[1] = local_44;
        local_40 = pfVar6[2] * local_68 + fVar2 * local_74 + fVar1 * local_80 + param_4;
        pfVar6[2] = local_40;
        local_3c = *pfVar6 + local_3c;
        local_38 = pfVar6[1] + local_38;
        local_34 = pfVar6[2] + local_34;
        if (local_20 != 0) {
          local_24 = pfVar6 + 3;
          pfVar6 = (float *)FUN_0077e800();
          *local_24 = *pfVar6;
          local_24[1] = pfVar6[1];
          local_24[2] = pfVar6[2];
        }
        local_14 = local_14 + local_28;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
      local_18 = 0;
      uVar5 = local_1c;
    }
    puVar4[3] = local_3c;
    puVar4[4] = local_38;
    fVar1 = (float)(int)local_2c;
    puVar4[5] = local_34;
    if ((int)local_2c < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
    local_1c = uVar5 + 1;
    local_2c = 1.0 / fVar1;
    puVar4[3] = local_2c * (float)puVar4[3];
    puVar4[4] = (float)puVar4[4] * local_2c;
    puVar4[5] = local_2c * (float)puVar4[5];
  } while (local_1c < local_30);
  *(undefined4 *)(param_1 + 4) = 1;
  ExceptionList = local_10;
  return;
}

