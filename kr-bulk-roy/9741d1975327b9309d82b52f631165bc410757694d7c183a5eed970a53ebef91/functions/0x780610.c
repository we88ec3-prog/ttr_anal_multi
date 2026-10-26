
void FUN_00780610(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  float *in_ECX;
  float *unaff_EDI;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float local_2c;
  float local_28;
  float local_24;
  
  fVar1 = *in_ECX;
  fVar2 = in_ECX[1];
  fVar3 = in_ECX[2];
  fVar4 = *in_EAX;
  fVar5 = in_EAX[1];
  fVar6 = in_EAX[2];
  FUN_00781020(0x3f800000);
  FUN_00781020(0x3f800000);
  local_2c = fVar2 * fVar6 - fVar3 * fVar5;
  local_28 = fVar4 * fVar3 - fVar1 * fVar6;
  local_24 = fVar5 * fVar1 - fVar2 * fVar4;
  FUN_004ad080(local_24 * local_24 + local_28 * local_28 + local_2c * local_2c);
  fVar7 = (float10)FUN_008fee20();
  fVar8 = (float10)3.1415927 - fVar7;
  fVar9 = (float10)fVar2;
  fVar10 = (float10)fVar3;
  fVar11 = fVar8;
  if ((float)((float10)fVar4 * (float10)fVar1 + fVar9 * (float10)fVar5 + fVar10 * (float10)fVar6) <
      0.0) {
    fVar11 = (float10)3.1415927 - fVar8;
    fVar7 = fVar8;
  }
  fVar8 = (float10)0.001;
  if (fVar8 < fVar7 != (fVar8 == fVar7)) {
    if (fVar11 < fVar8) {
      if (fVar8 <= fVar9 * fVar9 + fVar10 * fVar10) {
        local_2c = 0.0;
        local_24 = (float)-fVar9;
        local_28 = fVar3;
      }
      else {
        local_28 = 0.0;
        local_2c = 0.0;
        local_24 = 1.0;
      }
    }
    FUN_00781020(0x3f800000);
    fVar11 = (float10)FUN_008ff0a0();
    *unaff_EDI = (float)((float10)local_2c * fVar11);
    unaff_EDI[1] = (float)((float10)local_28 * fVar11);
    unaff_EDI[2] = (float)(fVar11 * (float10)local_24);
    fVar11 = (float10)FUN_008fef70();
    unaff_EDI[3] = (float)fVar11;
    return;
  }
  *unaff_EDI = 0.0;
  unaff_EDI[1] = 0.0;
  unaff_EDI[2] = 0.0;
  unaff_EDI[3] = 1.0;
  return;
}

