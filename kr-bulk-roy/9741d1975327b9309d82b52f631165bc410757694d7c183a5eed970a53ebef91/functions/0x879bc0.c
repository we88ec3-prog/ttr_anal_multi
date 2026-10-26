
float * FUN_00879bc0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  
  iVar4 = FUN_008fed10();
  fVar1 = *(float *)(*(int *)(in_ECX + 0x38) + iVar4 * 0xc);
  iVar4 = FUN_008fed10();
  fVar2 = *(float *)(*(int *)(in_ECX + 0x74) + iVar4 * 0xc);
  iVar4 = FUN_0089289d();
  iVar5 = FUN_0089289d();
  *param_1 = ABS(((float)iVar5 / 32767.0) * 2.0 - 1.0) * 2.0 - 1.0;
  param_1[1] = ABS(((float)iVar4 / 32767.0 + (float)iVar4 / 32767.0) - 1.0) * 2.0 - 1.0;
  param_1[2] = 0.0;
  iVar4 = FUN_0089289d();
  fVar3 = (fVar2 - 0.0) * ABS(((float)iVar4 / 32767.0 + (float)iVar4 / 32767.0) - 1.0) + 0.0;
  FUN_00781020(((fVar2 - fVar3) / fVar2) * fVar1);
  param_1[2] = fVar3 - fVar2 * 0.5;
  return param_1;
}

