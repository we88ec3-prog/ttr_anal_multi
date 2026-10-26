
float10 FUN_00801230(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float *unaff_ESI;
  
  iVar4 = FUN_0089289d();
  fVar1 = unaff_ESI[3];
  fVar2 = unaff_ESI[1];
  fVar3 = unaff_ESI[3];
  iVar5 = FUN_0089289d();
  return (float10)(param_1 * ((((float)iVar4 / 32767.0) * fVar1 + fVar2) - fVar3 * 0.5) +
                  (1.0 - param_1) *
                  ((((float)iVar5 / 32767.0) * unaff_ESI[2] + *unaff_ESI) - unaff_ESI[2] * 0.5));
}

