
float * FUN_008795d0(float *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = FUN_008fed10();
  uVar1 = *(undefined4 *)(*(int *)(in_ECX + 0x38) + iVar2 * 0xc);
  iVar2 = FUN_0089289d();
  iVar3 = FUN_0089289d();
  iVar4 = FUN_0089289d();
  *param_1 = ABS(((float)iVar4 / 32767.0) * 2.0 - 1.0) * 2.0 - 1.0;
  param_1[1] = ABS(((float)iVar3 / 32767.0 + (float)iVar3 / 32767.0) - 1.0) * 2.0 - 1.0;
  param_1[2] = ABS(((float)iVar2 / 32767.0 + (float)iVar2 / 32767.0) - 1.0) * 2.0 - 1.0;
  FUN_00781020(uVar1);
  return param_1;
}

