
void FUN_00790f60(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *unaff_ESI;
  float10 fVar4;
  
  if (param_1 != 0.0) {
    fVar4 = (float10)FUN_008ff0a0();
    fVar1 = (float)fVar4;
    fVar4 = (float10)FUN_008fef70();
    fVar2 = (float)fVar4;
    fVar3 = unaff_ESI[1];
    unaff_ESI[1] = *unaff_ESI * fVar1 + unaff_ESI[1] * fVar2;
    *unaff_ESI = *unaff_ESI * fVar2 - fVar3 * fVar1;
    fVar3 = unaff_ESI[4];
    unaff_ESI[4] = unaff_ESI[4] * fVar2 + unaff_ESI[3] * fVar1;
    unaff_ESI[3] = unaff_ESI[3] * fVar2 - fVar3 * fVar1;
    fVar3 = unaff_ESI[7];
    unaff_ESI[7] = unaff_ESI[6] * fVar1 + unaff_ESI[7] * fVar2;
    unaff_ESI[6] = unaff_ESI[6] * fVar2 - fVar3 * fVar1;
    fVar3 = unaff_ESI[10];
    unaff_ESI[10] = unaff_ESI[10] * fVar2 + unaff_ESI[9] * fVar1;
    unaff_ESI[9] = unaff_ESI[9] * fVar2 - fVar3 * fVar1;
    return;
  }
  return;
}

