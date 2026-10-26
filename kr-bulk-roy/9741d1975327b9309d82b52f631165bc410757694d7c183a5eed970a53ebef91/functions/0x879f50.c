
float * FUN_00879f50(float *param_1)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int in_ECX;
  
  iVar4 = FUN_008fed10();
  fVar1 = *(float *)(*(int *)(in_ECX + 0x38) + iVar4 * 0xc);
  iVar4 = FUN_008fed10();
  uVar2 = *(undefined4 *)(*(int *)(in_ECX + 0x74) + iVar4 * 0xc);
  iVar4 = FUN_0089289d();
  iVar5 = FUN_0089289d();
  *param_1 = ABS(((float)iVar5 / 32767.0) * 2.0 - 1.0) * 2.0 - 1.0;
  param_1[1] = ABS(((float)iVar4 / 32767.0 + (float)iVar4 / 32767.0) - 1.0) * 2.0 - 1.0;
  param_1[2] = 0.0;
  FUN_00781020(uVar2);
  *param_1 = *param_1 + fVar1;
  FUN_0089289d();
  FUN_008ff0a0();
  FUN_008fef70();
  pfVar6 = (float *)FUN_0077e800();
  fVar1 = pfVar6[1];
  fVar3 = pfVar6[2];
  *param_1 = *pfVar6;
  param_1[1] = fVar1;
  param_1[2] = fVar3;
  return param_1;
}

