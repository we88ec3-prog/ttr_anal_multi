
float10 FUN_007cd340(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float unaff_ESI;
  float10 fVar3;
  float *pfStack_24;
  float local_10;
  float local_c;
  
  if (ABS(param_2 - param_1) < 0.001) {
    return (float10)0;
  }
  pfStack_24 = (float *)0x7cd390;
  fVar3 = (float10)FUN_008fef70();
  fVar1 = (float)fVar3;
  pfStack_24 = (float *)0x7cd3a5;
  local_10 = fVar1;
  fVar3 = (float10)FUN_008ff0a0();
  local_c = (float)fVar3;
  pfStack_24 = &local_10;
  D3DXVec2Normalize();
  D3DXVec2Normalize(&pfStack_24);
  pfStack_24 = (float *)((float)&local_10 * fVar1 + (float)&pfStack_24 * unaff_ESI);
  fVar3 = (float10)FUN_008ff1d0();
  fVar2 = (float)fVar3;
  if ((float)&pfStack_24 * fVar1 - (float)&local_10 * unaff_ESI <= 0.0) {
    fVar2 = -fVar2;
  }
  return (float10)fVar2;
}

