
void FUN_008037f0(undefined4 param_1,int param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  int in_ECX;
  float local_28;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_14 = *(float *)(in_ECX + 0x20) - *(float *)(param_2 + 4);
  local_10 = *(float *)(in_ECX + 0x24) - *(float *)(param_2 + 8);
  local_c = *(float *)(in_ECX + 0x28) - *(float *)(param_2 + 0xc);
  fVar1 = local_c * local_c + local_14 * local_14 + local_10 * local_10;
  if (*(float *)(in_ECX + 0x30) < fVar1) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_28 = 1.0;
  fVar1 = *(float *)(in_ECX + 0x1c) * *(float *)(in_ECX + 0x2c) * *(float *)(in_ECX + 0x2c) * fVar1;
  if (fVar1 != 0.0) {
    local_28 = 1.0 / (fVar1 + 1.0);
  }
  D3DXVec3Normalize(&local_14,&local_14);
  fVar1 = *(float *)(in_ECX + 0x18);
  local_14 = param_4 * fVar1 * local_14;
  local_10 = local_10 * fVar1 * param_4;
  local_c = param_4 * fVar1 * local_c;
  *(float *)(param_2 + 0x10) = *(float *)(param_2 + 0x10) + local_28 * local_14;
  *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) + local_10 * local_28;
  *(float *)(param_2 + 0x18) = *(float *)(param_2 + 0x18) + local_28 * local_c;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

