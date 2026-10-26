
void FUN_00780c60(float *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  
  fVar1 = *unaff_EDI;
  fVar2 = *param_1;
  fVar3 = unaff_EDI[1];
  fVar5 = param_1[1];
  fVar4 = param_1[1];
  fVar6 = param_1[2];
  *unaff_ESI = *param_1;
  fVar7 = param_1[3];
  unaff_ESI[1] = fVar5;
  fVar5 = unaff_EDI[2];
  unaff_ESI[2] = fVar6;
  fVar6 = param_1[2];
  unaff_ESI[3] = fVar7;
  fVar10 = (float10)unaff_EDI[3] * (float10)param_1[3] +
           (float10)fVar5 * (float10)fVar6 +
           (float10)fVar3 * (float10)fVar4 + (float10)fVar1 * (float10)fVar2;
  fVar9 = (float10)1;
  fVar8 = (float10)1e-06;
  if (fVar10 + fVar9 <= fVar8) {
    *unaff_ESI = -*unaff_EDI;
    unaff_ESI[1] = -unaff_EDI[1];
    unaff_ESI[2] = -unaff_EDI[2];
    unaff_ESI[3] = -unaff_EDI[3];
    fVar9 = (float10)FUN_008ff0a0();
    fVar8 = (float10)FUN_008ff0a0();
    fVar9 = (float10)(double)fVar9;
    *unaff_ESI = (float)((float10)*unaff_ESI * fVar8 + (float10)*unaff_EDI * fVar9);
    unaff_ESI[1] = (float)((float10)unaff_ESI[1] * fVar8 + (float10)unaff_EDI[1] * fVar9);
    unaff_ESI[2] = (float)(fVar9 * (float10)unaff_EDI[2] + (float10)unaff_ESI[2] * fVar8);
    return;
  }
  fVar10 = fVar9 - fVar10;
  if (fVar10 < fVar8 == (fVar10 == fVar8)) {
    FUN_008ff1d0();
    fVar9 = (float10)FUN_008ff0a0();
    fVar8 = (float10)FUN_008ff0a0();
    fVar10 = (float10)FUN_008ff0a0();
    fVar10 = fVar10 / (float10)(double)fVar9;
    fVar9 = (float10)(double)(fVar8 / (float10)(double)fVar9);
  }
  else {
    fVar10 = (float10)param_2;
    fVar9 = fVar9 - fVar10;
  }
  *unaff_ESI = (float)((float10)*param_1 * fVar10 + (float10)*unaff_EDI * fVar9);
  unaff_ESI[1] = (float)((float10)unaff_EDI[1] * fVar9 + (float10)param_1[1] * fVar10);
  unaff_ESI[2] = (float)((float10)unaff_EDI[2] * fVar9 + (float10)param_1[2] * fVar10);
  unaff_ESI[3] = (float)(fVar10 * (float10)param_1[3] + (float10)unaff_EDI[3] * fVar9);
  return;
}

