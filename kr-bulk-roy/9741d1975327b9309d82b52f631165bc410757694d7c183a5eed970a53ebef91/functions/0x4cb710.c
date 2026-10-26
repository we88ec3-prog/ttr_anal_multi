
void FUN_004cb710(float param_1)

{
  float fVar1;
  int in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004c9ab0();
  if ((float10)0.9900000095367432 < fVar2) {
    param_1 = *(float *)(in_ECX + 0x38) + param_1;
    *(float *)(in_ECX + 0x38) = param_1;
    if (1.0 < param_1) {
      *(undefined4 *)(in_ECX + 0x38) = 0x3f800000;
    }
    if (0.5 < *(float *)(in_ECX + 0x38)) {
      fVar1 = *(float *)(in_ECX + 0x38) - 0.5;
      FUN_004c9a60(0x3f800000,0x3f800000,0x3f800000,1.0 - (fVar1 + fVar1));
    }
  }
  return;
}

