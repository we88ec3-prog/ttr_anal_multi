
float * FUN_00862c00(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  float *in_ECX;
  float *unaff_EDI;
  
  *param_1 = 0.0;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  fVar2 = (in_ECX[1] - unaff_EDI[1]) * (in_EAX[2] - unaff_EDI[2]) -
          (in_ECX[2] - unaff_EDI[2]) * (in_EAX[1] - unaff_EDI[1]);
  fVar1 = (*in_EAX - *unaff_EDI) * (in_ECX[2] - unaff_EDI[2]) -
          (*in_ECX - *unaff_EDI) * (in_EAX[2] - unaff_EDI[2]);
  fVar3 = (in_EAX[1] - unaff_EDI[1]) * (*in_ECX - *unaff_EDI) -
          (in_ECX[1] - unaff_EDI[1]) * (*in_EAX - *unaff_EDI);
  FUN_00791180(0x3eb0c6f7a0b5ed8d);
  *param_1 = fVar2;
  param_1[1] = fVar1;
  param_1[2] = fVar3;
  param_1[3] = -(*unaff_EDI * fVar2 + unaff_EDI[1] * fVar1 + unaff_EDI[2] * fVar3);
  return param_1;
}

