
void FUN_00780a00(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float *in_ECX;
  float *unaff_ESI;
  
  if ((((in_ECX[3] == 1.0) && (*in_ECX == 0.0)) && (in_ECX[1] == 0.0)) && (in_ECX[2] == 0.0)) {
    _memset(unaff_ESI,0,0x34);
    unaff_ESI[8] = 1.0;
    unaff_ESI[4] = 1.0;
    *unaff_ESI = 1.0;
    return;
  }
  fVar3 = in_ECX[3] * in_ECX[3] + in_ECX[2] * in_ECX[2] + *in_ECX * *in_ECX + in_ECX[1] * in_ECX[1];
  if (fVar3 == 0.0) {
    fVar3 = 1.0;
  }
  else {
    fVar3 = 2.0 / fVar3;
  }
  fVar8 = in_ECX[1] * fVar3;
  fVar9 = fVar3 * in_ECX[2];
  fVar11 = fVar3 * *in_ECX * in_ECX[3];
  fVar1 = in_ECX[3];
  fVar2 = in_ECX[3];
  fVar10 = *in_ECX * fVar3 * *in_ECX;
  fVar3 = *in_ECX;
  fVar4 = *in_ECX;
  fVar5 = in_ECX[1];
  fVar6 = in_ECX[1];
  fVar7 = in_ECX[2];
  *unaff_ESI = 1.0 - (fVar8 * fVar5 + fVar9 * fVar7);
  unaff_ESI[3] = fVar3 * fVar8 - fVar9 * fVar2;
  unaff_ESI[6] = fVar4 * fVar9 + fVar8 * fVar1;
  unaff_ESI[1] = fVar3 * fVar8 + fVar9 * fVar2;
  unaff_ESI[4] = 1.0 - (fVar10 + fVar9 * fVar7);
  unaff_ESI[7] = fVar6 * fVar9 - fVar11;
  unaff_ESI[2] = fVar4 * fVar9 - fVar8 * fVar1;
  unaff_ESI[5] = fVar6 * fVar9 + fVar11;
  unaff_ESI[8] = 1.0 - (fVar8 * fVar5 + fVar10);
  return;
}

