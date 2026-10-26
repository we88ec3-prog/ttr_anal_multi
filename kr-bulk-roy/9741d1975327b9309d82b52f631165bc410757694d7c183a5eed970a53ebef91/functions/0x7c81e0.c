
undefined4
FUN_007c81e0(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            undefined4 *param_6)

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
  float *in_EAX;
  float *in_ECX;
  float *unaff_EDI;
  float local_10;
  float local_c;
  float local_8;
  
  fVar1 = *param_2 - *in_ECX;
  fVar2 = param_2[1] - in_ECX[1];
  fVar3 = param_2[2] - in_ECX[2];
  fVar4 = *in_EAX - *in_ECX;
  fVar5 = in_EAX[1] - in_ECX[1];
  fVar6 = in_EAX[2] - in_ECX[2];
  fVar7 = fVar3 * param_1[1] - fVar2 * param_1[2];
  fVar9 = fVar1 * param_1[2] - *param_1 * fVar3;
  fVar8 = *param_1 * fVar2 - fVar1 * param_1[1];
  param_2 = (float *)(fVar8 * fVar6 + fVar7 * fVar4 + fVar5 * fVar9);
  if ((float)param_2 <= 0.0) {
    local_10 = *in_ECX - *unaff_EDI;
    local_c = in_ECX[1] - unaff_EDI[1];
    local_8 = in_ECX[2] - unaff_EDI[2];
    param_2 = (float *)-(float)param_2;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 0;
    }
  }
  else {
    local_10 = *unaff_EDI - *in_ECX;
    local_c = unaff_EDI[1] - in_ECX[1];
    local_8 = unaff_EDI[2] - in_ECX[2];
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = 1;
    }
  }
  if (0.0001 <= (float)param_2) {
    fVar7 = local_c * fVar9 + local_10 * fVar7 + local_8 * fVar8;
    *param_4 = fVar7;
    if (0.0 <= fVar7) {
      if ((float)param_2 < fVar7) {
        return 0;
      }
      fVar7 = local_c * fVar6 - local_8 * fVar5;
      fVar6 = fVar4 * local_8 - fVar6 * local_10;
      fVar4 = fVar5 * local_10 - fVar4 * local_c;
      fVar5 = fVar7 * *param_1 + fVar6 * param_1[1] + fVar4 * param_1[2];
      *param_5 = fVar5;
      if ((0.0 <= fVar5) && (*param_4 + fVar5 <= (float)param_2)) {
        fVar5 = 1.0 / (float)param_2;
        *param_3 = fVar5 * (fVar4 * fVar3 + fVar6 * fVar2 + fVar1 * fVar7);
        *param_4 = *param_4 * fVar5;
        *param_5 = fVar5 * *param_5;
        return 1;
      }
      return 0;
    }
  }
  return 0;
}

