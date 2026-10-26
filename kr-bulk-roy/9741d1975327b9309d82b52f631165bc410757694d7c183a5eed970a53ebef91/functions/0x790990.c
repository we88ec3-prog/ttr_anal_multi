
void FUN_00790990(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *in_EAX;
  float *unaff_EDI;
  
  fVar1 = *param_1 - *in_EAX;
  fVar2 = param_1[1] - in_EAX[1];
  fVar3 = param_1[2] - in_EAX[2];
  if (((fVar1 != 0.0) || (fVar2 != 0.0)) || (fVar3 != 0.0)) {
    FUN_00781020(0x3f800000);
    fVar4 = fVar3 * param_2[1] - fVar2 * param_2[2];
    fVar6 = fVar1 * param_2[2] - *param_2 * fVar3;
    fVar5 = *param_2 * fVar2 - fVar1 * param_2[1];
    FUN_00781020(0x3f800000);
    FUN_00781020(0x3f800000);
    *unaff_EDI = fVar4;
    unaff_EDI[1] = fVar6;
    unaff_EDI[2] = fVar5;
    unaff_EDI[3] = fVar2 * fVar5 - fVar3 * fVar6;
    unaff_EDI[4] = fVar4 * fVar3 - fVar1 * fVar5;
    unaff_EDI[5] = fVar6 * fVar1 - fVar2 * fVar4;
    unaff_EDI[6] = fVar1;
    unaff_EDI[7] = fVar2;
    unaff_EDI[8] = fVar3;
    if (param_3 != 0.0) {
      FUN_00791030(param_3);
    }
    fVar1 = param_1[1];
    fVar2 = param_1[2];
    unaff_EDI[9] = *param_1;
    unaff_EDI[10] = fVar1;
    unaff_EDI[0xb] = fVar2;
  }
  return;
}

