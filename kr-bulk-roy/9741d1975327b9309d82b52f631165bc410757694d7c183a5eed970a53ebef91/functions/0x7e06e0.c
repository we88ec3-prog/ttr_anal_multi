
void FUN_007e06e0(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *in_EAX;
  float *in_ECX;
  uint uVar8;
  uint uVar9;
  uint local_c;
  
  fVar7 = param_2;
  fVar3 = 1.0 - param_2;
  *in_ECX = *in_EAX * param_2 + fVar3 * *param_1;
  in_ECX[1] = in_EAX[1] * param_2 + param_1[1] * fVar3;
  fVar1 = param_1[2];
  fVar2 = in_EAX[2];
  fVar4 = (float)((uint)fVar2 >> 0x10 & 0xff) * 0.003921569 * param_2 +
          (float)((uint)fVar1 >> 0x10 & 0xff) * 0.003921569 * fVar3;
  fVar5 = (float)((uint)fVar2 >> 8 & 0xff) * 0.003921569 * param_2 +
          (float)((uint)fVar1 >> 8 & 0xff) * 0.003921569 * fVar3;
  fVar6 = (float)((uint)fVar2 & 0xff) * 0.003921569 * param_2 +
          (float)((uint)fVar1 & 0xff) * 0.003921569 * fVar3;
  fVar1 = (float)((uint)fVar2 >> 0x18) * 0.003921569 * param_2 +
          (float)((uint)fVar1 >> 0x18) * 0.003921569 * fVar3;
  if (fVar4 < 1.0) {
    if (0.0 < fVar4) {
      local_c = (uint)(longlong)ROUND(fVar4 * 255.0 + 0.5);
      param_2 = (float)local_c;
    }
    else {
      param_2 = 0.0;
    }
  }
  else {
    param_2 = 3.57331e-43;
  }
  if (fVar5 < 1.0) {
    if (fVar5 < 0.0 == (fVar5 == 0.0)) {
      local_c = (uint)(longlong)ROUND(fVar5 * 255.0 + 0.5);
      uVar9 = local_c;
    }
    else {
      uVar9 = 0;
    }
  }
  else {
    uVar9 = 0xff;
  }
  if (fVar6 < 1.0) {
    if (fVar6 < 0.0 == (fVar6 == 0.0)) {
      local_c = (uint)(longlong)ROUND(fVar6 * 255.0 + 0.5);
      uVar8 = local_c;
    }
    else {
      uVar8 = 0;
    }
  }
  else {
    uVar8 = 0xff;
  }
  if (fVar1 < 1.0) {
    if (0.0 < fVar1) {
      local_c = (uint)(longlong)ROUND(fVar1 * 255.0 + 0.5);
    }
    else {
      local_c = 0;
    }
  }
  else {
    local_c = 0xff;
  }
  in_ECX[2] = (float)(((local_c << 8 | (uint)param_2) << 8 | uVar9) << 8 | uVar8);
  if (0.99 <= fVar7) {
    in_ECX[3] = in_EAX[3];
    return;
  }
  in_ECX[3] = param_1[3];
  return;
}

