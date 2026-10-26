
undefined4 FUN_007cce40(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float local_88 [13];
  float local_54 [4];
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  float local_14 [4];
  
  local_1c = *(float *)(param_2 + 0x20);
  local_20 = *(float *)(param_2 + 0x1c);
  local_18 = *(float *)(param_2 + 0x24);
  if (local_1c * local_20 * local_18 == 0.0) {
    return 0;
  }
  FUN_007cd220();
  pfVar5 = local_54;
  pfVar6 = local_88;
  for (iVar4 = 0xd; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  _memset(local_54,0,0x34);
  local_34 = 1.0;
  local_44 = 1.0;
  local_54[0] = 1.0;
  FUN_00790b40();
  *param_1 = local_30 + local_3c * 0.0 + local_54[0] * 0.0 + local_54[3] * 0.0;
  param_1[1] = local_38 * 0.0 + local_44 * 0.0 + local_54[1] * 0.0 + local_2c;
  param_1[2] = local_54[2] * 0.0 + local_40 * 0.0 + local_34 * 0.0 + local_28;
  fVar1 = *(float *)(param_2 + 0xc);
  fVar2 = *(float *)(param_2 + 0x10);
  fVar3 = *(float *)(param_2 + 0x14);
  if (param_1 + 3 != local_14) {
    param_1[6] = *(float *)(param_2 + 0x18);
    param_1[3] = -fVar1;
    param_1[4] = -fVar2;
    param_1[5] = -fVar3;
  }
  param_1[7] = 1.0 / local_20;
  param_1[8] = 1.0 / local_1c;
  param_1[9] = 1.0 / local_18;
  return 1;
}

