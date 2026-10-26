
float * FUN_00879880(float *param_1)

{
  undefined4 uVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  
  iVar4 = FUN_008fed10();
  uVar1 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + iVar4 * 0xc);
  iVar4 = FUN_008fed10();
  fVar2 = *(float *)(*(int *)(in_ECX + 0x74) + iVar4 * 0xc);
  iVar4 = FUN_0089289d();
  iVar5 = FUN_0089289d();
  *param_1 = ABS(((float)iVar5 / 32767.0) * 2.0 - 1.0) * 2.0 - 1.0;
  param_1[1] = ABS(((float)iVar4 / 32767.0 + (float)iVar4 / 32767.0) - 1.0) * 2.0 - 1.0;
  param_1[2] = 0.0;
  FUN_00781020(uVar1);
  fVar2 = fVar2 * 0.5;
  fVar3 = -fVar2;
  iVar4 = FUN_0089289d();
  param_1[2] = ABS(((float)iVar4 / 32767.0 + (float)iVar4 / 32767.0) - 1.0) * (fVar2 - fVar3) +
               fVar3;
  return param_1;
}

