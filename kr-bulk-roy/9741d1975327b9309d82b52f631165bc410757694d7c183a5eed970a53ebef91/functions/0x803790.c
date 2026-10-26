
void FUN_00803790(undefined4 param_1,undefined4 param_2,float param_3)

{
  int in_ECX;
  
  D3DXVec3TransformCoord(in_ECX + 0x20,in_ECX + 4,param_2);
  if (0.0 < param_3) {
    *(float *)(in_ECX + 0x2c) = 1.0 / param_3;
    *(float *)(in_ECX + 0x30) = *(float *)(in_ECX + 0x14) * param_3 * param_3;
    return;
  }
  *(undefined4 *)(in_ECX + 0x2c) = 0x3f800000;
  *(float *)(in_ECX + 0x30) = *(float *)(in_ECX + 0x14) * param_3 * param_3;
  return;
}

