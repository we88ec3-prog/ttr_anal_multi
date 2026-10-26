
void FUN_0073b2f0(float *param_1,int *param_2,float *param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int *in_ECX;
  float10 extraout_ST0;
  float10 fVar1;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  undefined4 local_5c;
  float *pfStack_58;
  undefined4 uStack_54;
  undefined1 auStack_44 [4];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  int local_30;
  int local_2c;
  int local_28;
  float local_24 [2];
  int local_1c [3];
  int local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_44;
  local_3c = param_1[1];
  local_24[0] = 1.0;
  local_24[1] = 1.0;
  fVar1 = (float10)0;
  local_38 = (float)fVar1;
  local_34 = (float)fVar1;
  local_40 = *param_1;
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = in_ECX[3];
  local_10 = in_ECX[4];
  if (param_2 == (int *)0x0) {
    param_2 = local_1c;
  }
  if (param_3 == (float *)0x0) {
    param_3 = local_24;
  }
  local_30 = param_2[2] - *param_2;
  local_28 = param_2[3] - param_2[1];
  if ((float10)*param_3 < fVar1) {
    uStack_54 = 0x73b386;
    local_2c = FUN_008fed10();
    local_40 = (float)(extraout_ST0 - (float10)local_2c);
    fVar1 = extraout_ST1;
  }
  if ((float10)param_3[1] < fVar1) {
    uStack_54 = 0x73b3ac;
    local_2c = FUN_008fed10();
    local_3c = (float)(extraout_ST0_00 - (float10)local_2c);
  }
  if (param_4 == 1) {
    local_38 = (float)local_30 * 0.5;
    local_34 = (float)local_28 * 0.5;
  }
  else if (param_4 == 2) {
    local_38 = (float)local_30 * 0.5;
    local_34 = (float)local_28 * 0.5;
    local_40 = local_38 + local_40;
    local_3c = local_34 + local_3c;
  }
  uStack_54 = param_6;
  pfStack_58 = &local_40;
  local_5c = param_5;
  (**(code **)(*in_ECX + 0x2c))(param_2,param_3,&local_38);
  __security_check_cookie((uint)local_24[0] ^ (uint)&local_5c);
  return;
}

