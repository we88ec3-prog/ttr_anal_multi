
void FUN_00791030(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *unaff_ESI;
  float10 fVar6;
  
  if (param_1 != 0.0) {
    unaff_ESI[0xc] = (float)((uint)unaff_ESI[0xc] & 0xfffffffd);
    fVar6 = (float10)FUN_008ff0a0();
    fVar1 = (float)fVar6;
    fVar6 = (float10)FUN_008fef70();
    fVar2 = (float)fVar6;
    fVar3 = fVar1 * unaff_ESI[3] + fVar2 * *unaff_ESI;
    *unaff_ESI = fVar3;
    fVar5 = fVar1 * unaff_ESI[4] + unaff_ESI[1] * fVar2;
    unaff_ESI[1] = fVar5;
    fVar4 = fVar1 * unaff_ESI[5] + unaff_ESI[2] * fVar2;
    unaff_ESI[2] = fVar4;
    unaff_ESI[3] = unaff_ESI[3] * fVar2 - fVar1 * fVar3;
    unaff_ESI[4] = fVar2 * unaff_ESI[4] - fVar1 * fVar5;
    unaff_ESI[5] = unaff_ESI[5] * fVar2 - fVar4 * fVar1;
    return;
  }
  return;
}

