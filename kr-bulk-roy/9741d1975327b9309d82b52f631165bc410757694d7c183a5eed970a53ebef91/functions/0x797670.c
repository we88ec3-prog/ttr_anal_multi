
float10 FUN_00797670(float param_1,int param_2,float param_3)

{
  uint uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  
  fVar4 = (float10)1;
  fVar2 = (float10)param_1;
  if (fVar4 < fVar2) {
    return fVar4;
  }
  if (fVar2 < (float10)-1.0) {
    return (float10)-1.0;
  }
  fVar3 = (float10)param_3;
  if ((float10)0 <= fVar3) {
    if (fVar4 < fVar3) {
      param_3 = (float)fVar4;
      fVar3 = (float10)param_3;
    }
  }
  else {
    param_3 = (float)(float10)0;
    fVar3 = (float10)param_3;
  }
  if (param_2 == 1) {
    uVar1 = 3;
    fVar4 = (float10)1;
    fVar5 = fVar2;
    while( true ) {
      if ((uVar1 & 1) != 0) {
        fVar4 = fVar4 * fVar5;
      }
      uVar1 = uVar1 >> 1;
      if (uVar1 == 0) break;
      fVar5 = fVar5 * fVar5;
    }
    fVar2 = (float10)(float)(((float10)(float)fVar4 - fVar2) * fVar3 + fVar2);
  }
  else {
    if (param_2 == 2) {
      uVar1 = 3;
      fVar4 = (float10)1;
      fVar6 = fVar2 - fVar4;
      fVar5 = fVar4;
      while( true ) {
        if ((uVar1 & 1) != 0) {
          fVar5 = fVar5 * fVar6;
        }
        uVar1 = uVar1 >> 1;
        if (uVar1 == 0) break;
        fVar6 = fVar6 * fVar6;
      }
      return (float10)(float)(((float10)(float)(fVar4 + fVar5) - fVar2) * fVar3 + fVar2);
    }
    if (param_2 == 3) {
      fVar4 = (float10)FUN_00797600((double)param_1);
      return (float10)(float)((float10)param_1 + (float10)param_3 * (fVar4 - (float10)param_1));
    }
  }
  return fVar2;
}

