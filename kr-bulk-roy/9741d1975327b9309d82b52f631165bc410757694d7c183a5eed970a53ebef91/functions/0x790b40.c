
void FUN_00790b40(void)

{
  float fVar1;
  float fVar2;
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar3;
  float local_c;
  float local_8;
  
  local_c = 0.0;
  local_8 = 0.0;
  fVar2 = *unaff_ESI * unaff_ESI[4] * unaff_ESI[8];
  fVar1 = fVar2 + 0.0;
  if (fVar2 < 0.0) {
    local_c = fVar1;
    fVar1 = local_8;
  }
  local_8 = fVar1;
  fVar1 = unaff_ESI[7] * unaff_ESI[3] * unaff_ESI[2];
  if (0.0 <= fVar1) {
    local_8 = fVar1 + local_8;
  }
  else {
    local_c = fVar1 + local_c;
  }
  fVar1 = unaff_ESI[6] * unaff_ESI[1] * unaff_ESI[5];
  if (0.0 <= fVar1) {
    local_8 = fVar1 + local_8;
  }
  else {
    local_c = fVar1 + local_c;
  }
  fVar1 = -unaff_ESI[6] * unaff_ESI[4] * unaff_ESI[2];
  if (0.0 <= fVar1) {
    local_8 = fVar1 + local_8;
  }
  else {
    local_c = fVar1 + local_c;
  }
  fVar1 = -unaff_ESI[3] * unaff_ESI[1] * unaff_ESI[8];
  if (0.0 <= fVar1) {
    local_8 = fVar1 + local_8;
  }
  else {
    local_c = fVar1 + local_c;
  }
  fVar1 = -*unaff_ESI * unaff_ESI[7] * unaff_ESI[5];
  if (0.0 <= fVar1) {
    local_8 = fVar1 + local_8;
  }
  else {
    local_c = fVar1 + local_c;
  }
  fVar1 = local_c + local_8;
  if ((fVar1 != 0.0) &&
     (fVar3 = (float10)FUN_004ff540(fVar1 / (local_8 - local_c)), (float10)1e-15 <= fVar3)) {
    fVar1 = 1.0 / fVar1;
    *unaff_EDI = fVar1 * (unaff_ESI[8] * unaff_ESI[4] - unaff_ESI[5] * unaff_ESI[7]);
    unaff_EDI[1] = -((unaff_ESI[8] * unaff_ESI[1] - unaff_ESI[2] * unaff_ESI[7]) * fVar1);
    unaff_EDI[2] = (unaff_ESI[5] * unaff_ESI[1] - unaff_ESI[2] * unaff_ESI[4]) * fVar1;
    unaff_EDI[3] = -((unaff_ESI[8] * unaff_ESI[3] - unaff_ESI[6] * unaff_ESI[5]) * fVar1);
    unaff_EDI[4] = (*unaff_ESI * unaff_ESI[8] - unaff_ESI[6] * unaff_ESI[2]) * fVar1;
    unaff_EDI[5] = -((unaff_ESI[5] * *unaff_ESI - unaff_ESI[2] * unaff_ESI[3]) * fVar1);
    unaff_EDI[6] = (unaff_ESI[7] * unaff_ESI[3] - unaff_ESI[6] * unaff_ESI[4]) * fVar1;
    unaff_EDI[7] = -((*unaff_ESI * unaff_ESI[7] - unaff_ESI[6] * unaff_ESI[1]) * fVar1);
    unaff_EDI[8] = (*unaff_ESI * unaff_ESI[4] - unaff_ESI[3] * unaff_ESI[1]) * fVar1;
    unaff_EDI[9] = -(unaff_ESI[0xb] * unaff_EDI[6] +
                    *unaff_EDI * unaff_ESI[9] + unaff_ESI[10] * unaff_EDI[3]);
    unaff_EDI[10] =
         -(unaff_ESI[0xb] * unaff_EDI[7] +
          unaff_ESI[10] * unaff_EDI[4] + unaff_EDI[1] * unaff_ESI[9]);
    unaff_EDI[0xb] =
         -(unaff_ESI[0xb] * unaff_EDI[8] +
          unaff_EDI[2] * unaff_ESI[9] + unaff_ESI[10] * unaff_EDI[5]);
    return;
  }
  OutputDebugStringA("gbMatrix::Invert: singular matrix\n");
  _memset(unaff_EDI,0,0x34);
  return;
}

