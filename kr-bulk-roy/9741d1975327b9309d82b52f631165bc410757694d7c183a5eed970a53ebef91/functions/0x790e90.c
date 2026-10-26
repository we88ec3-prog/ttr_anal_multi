
void FUN_00790e90(float param_1)

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
    fVar3 = *unaff_ESI;
    *unaff_ESI = *unaff_ESI * fVar2 + unaff_ESI[2] * fVar1;
    unaff_ESI[2] = unaff_ESI[2] * fVar2 - fVar3 * fVar1;
    fVar3 = unaff_ESI[3];
    unaff_ESI[3] = unaff_ESI[3] * fVar2 + unaff_ESI[5] * fVar1;
    unaff_ESI[5] = unaff_ESI[5] * fVar2 - fVar3 * fVar1;
    fVar3 = unaff_ESI[6];
    unaff_ESI[6] = unaff_ESI[6] * fVar2 + unaff_ESI[8] * fVar1;
    unaff_ESI[8] = unaff_ESI[8] * fVar2 - fVar3 * fVar1;
    fVar3 = unaff_ESI[9];
    unaff_ESI[9] = unaff_ESI[0xb] * fVar1 + unaff_ESI[9] * fVar2;
    unaff_ESI[0xb] = unaff_ESI[0xb] * fVar2 - fVar3 * fVar1;
    return;
  }
  return;
}

