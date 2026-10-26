
undefined4 FUN_008033b0(undefined4 param_1,float *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0089289d();
  *param_2 = ((float)iVar1 / 32767.0) * *(float *)(in_ECX + 4) - *(float *)(in_ECX + 4) * 0.5;
  iVar1 = FUN_0089289d();
  param_2[1] = ((float)iVar1 / 32767.0) * *(float *)(in_ECX + 4) - *(float *)(in_ECX + 4) * 0.5;
  param_2[2] = 0.0;
  return 1;
}

