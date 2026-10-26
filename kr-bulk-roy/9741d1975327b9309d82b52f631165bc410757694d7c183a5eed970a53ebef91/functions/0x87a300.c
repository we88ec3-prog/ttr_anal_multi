
void FUN_0087a300(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int in_ECX;
  
  iVar7 = FUN_008fed10();
  fVar1 = *(float *)(*(int *)(in_ECX + 0x38) + iVar7 * 0xc);
  iVar7 = *(int *)(in_ECX + 0x38) + iVar7 * 0xc;
  fVar2 = *(float *)(iVar7 + 4);
  fVar3 = *(float *)(iVar7 + 8);
  fVar4 = -fVar3;
  iVar7 = FUN_0089289d();
  fVar5 = -fVar2;
  iVar8 = FUN_0089289d();
  fVar6 = -fVar1;
  iVar9 = FUN_0089289d();
  *param_1 = (fVar1 - fVar6) * ABS(((float)iVar9 / 32767.0 + (float)iVar9 / 32767.0) - 1.0) + fVar6;
  param_1[1] = (fVar2 - fVar5) * ABS(((float)iVar8 / 32767.0 + (float)iVar8 / 32767.0) - 1.0) +
               fVar5;
  param_1[2] = (fVar3 - fVar4) * ABS(((float)iVar7 / 32767.0 + (float)iVar7 / 32767.0) - 1.0) +
               fVar4;
  return;
}

