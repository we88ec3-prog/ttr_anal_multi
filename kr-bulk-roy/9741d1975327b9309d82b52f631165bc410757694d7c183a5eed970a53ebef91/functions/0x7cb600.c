
void FUN_007cb600(float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_14;
  float local_10;
  float local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  fVar1 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[2];
  local_14 = (fVar1 + param_1[3] * 1024.0) - fVar1;
  local_10 = (fVar2 + param_1[4] * 1024.0) - fVar2;
  local_c = (fVar3 + param_1[5] * 1024.0) - fVar3;
  D3DXVec3Normalize(&local_14,&local_14);
  fVar4 = (param_4 - fVar3) * local_10 - (param_3 - fVar2) * local_c;
  fVar3 = (param_2 - fVar1) * local_c - local_14 * (param_4 - fVar3);
  fVar1 = local_14 * (param_3 - fVar2) - (param_2 - fVar1) * local_10;
  if (fVar1 * fVar1 + fVar4 * fVar4 + fVar3 * fVar3 < param_5 * param_5) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

