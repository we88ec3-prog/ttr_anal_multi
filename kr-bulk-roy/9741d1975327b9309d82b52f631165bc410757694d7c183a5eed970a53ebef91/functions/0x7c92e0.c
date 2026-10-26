
void FUN_007c92e0(float *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *in_ECX;
  undefined1 local_5c [4];
  undefined1 local_58 [4];
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  undefined4 local_20;
  undefined4 local_1c;
  float local_18;
  undefined4 local_14;
  undefined4 local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_38 = 0xc7000000;
  local_34 = 0xc7000000;
  local_30 = param_2;
  local_2c = 0x47000000;
  local_28 = 0xc7000000;
  local_20 = 0xc7000000;
  local_44 = 32768.0;
  local_40 = 32768.0;
  local_24 = param_2;
  local_3c = param_2;
  local_1c = 0x47000000;
  local_14 = 0x47000000;
  local_18 = param_2;
  local_10 = 0x47000000;
  local_c = param_2;
  pfVar1 = in_ECX + 3;
  iVar4 = FUN_007c81e0(pfVar1,&local_2c,&local_48,local_58,local_5c,0);
  if (iVar4 == 0) {
    iVar4 = FUN_007c81e0(pfVar1,&local_2c,&local_48,local_58,local_5c,0);
    if (iVar4 == 0) {
      fVar3 = 0.0;
      *param_1 = 0.0;
      param_1[1] = 0.0;
    }
    else {
      local_54 = local_48 * *pfVar1;
      local_50 = in_ECX[4] * local_48;
      local_4c = local_48 * in_ECX[5];
      local_44 = *in_ECX + local_54;
      local_40 = in_ECX[1] + local_50;
      fVar3 = in_ECX[2] + local_4c;
      *param_1 = local_44;
      param_1[1] = local_40;
      local_3c = fVar3;
    }
  }
  else {
    local_44 = local_48 * *pfVar1;
    local_40 = in_ECX[4] * local_48;
    fVar2 = in_ECX[5];
    local_54 = *in_ECX + local_44;
    local_50 = in_ECX[1] + local_40;
    fVar3 = in_ECX[2] + local_48 * fVar2;
    *param_1 = local_54;
    param_1[1] = local_50;
    local_4c = fVar3;
    local_3c = local_48 * fVar2;
  }
  param_1[2] = fVar3;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

