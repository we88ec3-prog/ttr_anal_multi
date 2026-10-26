
float * FUN_0077e910(float *param_1,int param_2,float *param_3)

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
  float fVar10;
  float fVar11;
  float fVar12;
  float *pfVar13;
  
  fVar1 = *(float *)(param_2 + 0x1c);
  fVar2 = param_3[7];
  fVar3 = *(float *)(param_2 + 0x20);
  fVar4 = param_3[8];
  fVar5 = *(float *)(param_2 + 0x24);
  fVar6 = param_3[9];
  pfVar13 = (float *)FUN_0077e800();
  fVar7 = *pfVar13;
  fVar8 = *param_3;
  fVar9 = pfVar13[1];
  fVar10 = param_3[1];
  fVar11 = pfVar13[2];
  fVar12 = param_3[2];
  pfVar13 = (float *)FUN_0077e880(param_2 + 0xc);
  *param_1 = fVar7 + fVar8;
  param_1[1] = fVar9 + fVar10;
  param_1[3] = *pfVar13;
  fVar7 = pfVar13[2];
  param_1[2] = fVar11 + fVar12;
  fVar8 = pfVar13[3];
  param_1[4] = pfVar13[1];
  param_1[5] = fVar7;
  param_1[6] = fVar8;
  param_1[7] = fVar1 * fVar2;
  param_1[8] = fVar3 * fVar4;
  param_1[9] = fVar5 * fVar6;
  param_1[10] = 1.4013e-45;
  return param_1;
}

