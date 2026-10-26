
float10 FUN_00797600(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar2 = (float10)2.0;
  fVar4 = (float10)(double)CONCAT44(param_2,param_1) * fVar2;
  fVar3 = (float10)1;
  if (fVar4 < fVar3) {
    fVar3 = (float10)FUN_007975c0((double)fVar4);
    return (float10)(float)(fVar3 * (float10)0.5);
  }
  uVar1 = 2;
  fVar4 = fVar4 - fVar2;
  while( true ) {
    if ((uVar1 & 1) != 0) {
      fVar3 = fVar3 * fVar4;
    }
    uVar1 = uVar1 >> 1;
    if (uVar1 == 0) break;
    fVar4 = fVar4 * fVar4;
  }
  return (float10)(float)((fVar3 - fVar2) * (float10)-0.5);
}

