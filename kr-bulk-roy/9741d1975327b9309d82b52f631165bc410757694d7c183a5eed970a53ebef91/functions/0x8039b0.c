
void FUN_008039b0(undefined4 param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  int in_ECX;
  
  D3DXVec3TransformCoord((float *)(in_ECX + 0x2c),in_ECX + 4,param_2);
  D3DXVec3TransformCoord((float *)(in_ECX + 0x38),in_ECX + 0x10,param_2);
  *(float *)(in_ECX + 0x44) = *(float *)(in_ECX + 0x38) - *(float *)(in_ECX + 0x2c);
  *(float *)(in_ECX + 0x48) = *(float *)(in_ECX + 0x3c) - *(float *)(in_ECX + 0x30);
  *(float *)(in_ECX + 0x4c) = *(float *)(in_ECX + 0x40) - *(float *)(in_ECX + 0x34);
  fVar1 = *(float *)(in_ECX + 0x4c) * *(float *)(in_ECX + 0x4c) +
          *(float *)(in_ECX + 0x48) * *(float *)(in_ECX + 0x48) +
          *(float *)(in_ECX + 0x44) * *(float *)(in_ECX + 0x44);
  *(float *)(in_ECX + 0x50) = fVar1;
  if (fVar1 == 0.0) {
    *(undefined4 *)(in_ECX + 0x50) = 0x3f800000;
  }
  *(float *)(in_ECX + 0x54) = 1.0 / param_3;
  if (1.0 / param_3 == 0.0) {
    *(undefined4 *)(in_ECX + 0x54) = 0x3f800000;
    *(float *)(in_ECX + 0x58) = *(float *)(in_ECX + 0x20) * param_3 * param_3;
    return;
  }
  *(float *)(in_ECX + 0x58) = *(float *)(in_ECX + 0x20) * param_3 * param_3;
  return;
}

