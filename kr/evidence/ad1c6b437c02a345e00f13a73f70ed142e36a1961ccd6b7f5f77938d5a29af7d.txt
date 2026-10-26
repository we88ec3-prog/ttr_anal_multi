
void FUN_004cad60(float param_1,float param_2,int param_3)

{
  float fVar1;
  int *in_ECX;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  fVar1 = (float)in_ECX[0x36];
  local_18 = 0.0;
  local_14 = 0.0;
  local_c = fVar1 * fVar1 + (float)in_ECX[0x37] * (float)in_ECX[0x37];
  if (0.01 < local_c) {
    local_10 = param_2 * fVar1;
    local_20 = param_1 * local_10;
    local_1c = param_1 * param_2 * (float)in_ECX[0x37];
    local_18 = local_20 + 0.0;
    local_14 = local_1c + 0.0;
    in_ECX[0x36] = (int)((float)in_ECX[0x36] - local_18);
    in_ECX[0x37] = (int)((float)in_ECX[0x37] - local_14);
    fVar1 = (float)in_ECX[0x36];
    local_c = fVar1 * fVar1 + (float)in_ECX[0x37] * (float)in_ECX[0x37];
  }
  if (local_c < 0.04) {
    local_18 = fVar1 + local_18;
    fVar1 = (float)in_ECX[0x37];
    in_ECX[0x37] = 0;
    local_14 = fVar1 + local_14;
    in_ECX[0x36] = 0;
  }
  if (param_3 == 0) {
    (**(code **)(*in_ECX + 0x54))(&local_18);
    return;
  }
  local_20 = (float)in_ECX[0x28] + local_18;
  local_1c = (float)in_ECX[0x29] + local_14;
  (**(code **)(*in_ECX + 0x44))(&local_20,1);
  return;
}

