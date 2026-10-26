
void FUN_00780b80(float *param_1)

{
  float fVar1;
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar2;
  float local_c;
  
  if (1.0 <= unaff_ESI[3]) {
    local_c = 0.0;
  }
  else if (unaff_ESI[3] <= -1.0) {
    local_c = 6.2831855;
  }
  else {
    fVar2 = (float10)FUN_008ff1d0();
    local_c = (float)fVar2 + (float)fVar2;
  }
  *param_1 = local_c;
  if (local_c < 0.001) {
    *unaff_EDI = 0.0;
    unaff_EDI[1] = 0.0;
    unaff_EDI[2] = 1.0;
    return;
  }
  fVar2 = (float10)FUN_008ff0a0();
  fVar1 = 1.0 / (float)fVar2;
  *unaff_EDI = fVar1 * *unaff_ESI;
  unaff_EDI[1] = unaff_ESI[1] * fVar1;
  unaff_EDI[2] = fVar1 * unaff_ESI[2];
  return;
}

