
undefined4 FUN_007ff0d0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0x7c) + 4) != 0) {
    return 0;
  }
  fVar1 = (*param_1 + *param_2) * 0.5 - *(float *)(in_ECX + 0x34);
  fVar2 = (param_1[1] + param_2[1]) * 0.5 - *(float *)(in_ECX + 0x38);
  fVar3 = (param_1[2] + param_2[2]) * 0.5 - *(float *)(in_ECX + 0x3c);
  if (*(float *)(in_ECX + 0x40) * *(float *)(in_ECX + 0x40) <
      fVar3 * fVar3 + fVar1 * fVar1 + fVar2 * fVar2) {
    return 0;
  }
  uVar4 = FUN_007cacc0(*(undefined4 *)(in_ECX + 0x28),0,param_1,param_2);
  return uVar4;
}

