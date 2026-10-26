
undefined4 FUN_004cc540(float param_1)

{
  float fVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xf0) != 0) && (*(int *)(*(int *)(in_ECX + 0xf0) + 0x24) != 0)) {
    FUN_007bd8d0(param_1);
  }
  fVar1 = param_1 + *(float *)(in_ECX + 0x134);
  *(float *)(in_ECX + 0x134) = fVar1;
  if (*(float *)(in_ECX + 0x130) < fVar1) {
    *(float *)(in_ECX + 0x134) = *(float *)(in_ECX + 0x130);
  }
  if ((*(int *)(in_ECX + 0xfc) != 0) && (*(int *)(*(int *)(in_ECX + 0xfc) + 0x24) != 0)) {
    FUN_007bd8d0(param_1);
    return 0;
  }
  return 0;
}

