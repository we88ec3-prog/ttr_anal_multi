
float10 FUN_00796000(float param_1,float param_2,float param_3)

{
  float fVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar2 = (float10)param_2;
  fVar3 = (float10)param_3;
  fVar4 = (float10)param_1;
  if ((float10)0 == fVar4) {
    return fVar4;
  }
  if ((float10)1 == fVar4) {
    return fVar4;
  }
  fVar5 = (float10)(float)(fVar3 + fVar2);
  if (fVar5 == (float10)0) {
    return fVar4;
  }
  if ((float10)1 < fVar5) {
    fVar3 = (float10)(float)(fVar3 / fVar5);
    fVar2 = (float10)(float)(fVar2 / fVar5);
  }
  fVar5 = (float10)1;
  fVar1 = (float)(fVar5 / (((float10)2.0 - fVar2) - fVar3));
  if (fVar2 <= fVar4) {
    if (fVar5 - fVar3 <= fVar4) {
      return (float10)(float)(fVar5 - (float10)(float)(fVar5 - fVar4) *
                                      (float10)(float)(fVar5 - fVar4) * ((float10)fVar1 / fVar3));
    }
    return (float10)(float)(((float10)2.0 * fVar4 - fVar2) * (float10)fVar1);
  }
  return (float10)(float)(fVar4 * fVar4 * ((float10)fVar1 / fVar2));
}

