
float10 FUN_007975c0(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint in_ECX;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)(double)CONCAT44(param_2,param_1);
  uVar1 = in_ECX;
  if ((int)in_ECX < 0) {
    uVar1 = -in_ECX;
  }
  fVar3 = (float10)1;
  while( true ) {
    if ((uVar1 & 1) != 0) {
      fVar3 = fVar3 * fVar2;
    }
    uVar1 = uVar1 >> 1;
    if (uVar1 == 0) break;
    fVar2 = fVar2 * fVar2;
  }
  if ((int)in_ECX < 0) {
    return (float10)(float)((float10)1 / fVar3);
  }
  return (float10)(float)fVar3;
}

