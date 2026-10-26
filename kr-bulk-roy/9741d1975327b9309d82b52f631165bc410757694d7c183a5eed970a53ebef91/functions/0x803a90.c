
void FUN_00803a90(undefined4 param_1,int param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  int in_ECX;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  fVar1 = (*(float *)(in_ECX + 0x4c) * (*(float *)(param_2 + 0xc) - *(float *)(in_ECX + 0x34)) +
          *(float *)(in_ECX + 0x48) * (*(float *)(param_2 + 8) - *(float *)(in_ECX + 0x30)) +
          *(float *)(in_ECX + 0x44) * (*(float *)(param_2 + 4) - *(float *)(in_ECX + 0x2c))) /
          *(float *)(in_ECX + 0x50);
  if (0.0 <= fVar1) {
    if (fVar1 < 1.0) {
      local_14 = *(float *)(in_ECX + 0x44) * fVar1 + *(float *)(in_ECX + 0x2c);
      local_10 = *(float *)(in_ECX + 0x48) * fVar1 + *(float *)(in_ECX + 0x30);
      local_c = *(float *)(in_ECX + 0x34) + *(float *)(in_ECX + 0x4c) * fVar1;
    }
    else {
      local_14 = *(float *)(in_ECX + 0x38);
      local_10 = *(float *)(in_ECX + 0x3c);
      local_c = *(float *)(in_ECX + 0x40);
    }
  }
  else {
    local_14 = *(float *)(in_ECX + 0x2c);
    local_10 = *(float *)(in_ECX + 0x30);
    local_c = *(float *)(in_ECX + 0x34);
  }
  local_14 = local_14 - *(float *)(param_2 + 4);
  local_10 = local_10 - *(float *)(param_2 + 8);
  local_c = local_c - *(float *)(param_2 + 0xc);
  fVar1 = local_c * local_c + local_14 * local_14 + local_10 * local_10;
  if (*(float *)(in_ECX + 0x58) < fVar1) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_18 = 1.0;
  fVar1 = *(float *)(in_ECX + 0x28) * *(float *)(in_ECX + 0x54) * *(float *)(in_ECX + 0x54) * fVar1;
  if (fVar1 != 0.0) {
    local_18 = 1.0 / (fVar1 + 1.0);
  }
  D3DXVec3Normalize(&local_14,&local_14);
  fVar1 = *(float *)(in_ECX + 0x24);
  local_14 = param_4 * fVar1 * local_14;
  local_10 = local_10 * fVar1 * param_4;
  local_c = param_4 * fVar1 * local_c;
  *(float *)(param_2 + 0x10) = *(float *)(param_2 + 0x10) + local_18 * local_14;
  *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) + local_10 * local_18;
  *(float *)(param_2 + 0x18) = local_18 * local_c + *(float *)(param_2 + 0x18);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

