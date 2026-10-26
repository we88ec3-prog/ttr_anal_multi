
undefined4 FUN_004d0650(float param_1)

{
  float fVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xf0) != 0) {
    fVar1 = param_1 + *(float *)(in_ECX + 0x118);
    *(float *)(in_ECX + 0x118) = fVar1;
    if (3.1415927 < fVar1) {
      *(undefined4 *)(in_ECX + 0x118) = 0;
    }
    FUN_007bd8d0(param_1);
  }
  return 0;
}

