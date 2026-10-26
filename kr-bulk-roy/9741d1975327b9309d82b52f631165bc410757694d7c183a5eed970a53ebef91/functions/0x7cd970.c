
void FUN_007cd970(void)

{
  float *in_EAX;
  float10 fVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fStack_28;
  float fStack_24;
  float local_20;
  float local_1c;
  float fStack_18;
  float fStack_14;
  
  local_20 = *in_EAX;
  local_1c = in_EAX[1];
  pfVar2 = &local_20;
  pfVar3 = pfVar2;
  D3DXVec2Normalize(pfVar2,pfVar2);
  fVar1 = (float10)FUN_008ff1d0(pfVar2,pfVar3,fStack_28 * 0.0 - fStack_24 * 1.0);
  fVar4 = (float)fVar1;
  if (fStack_28 * -1.0 - fStack_24 * 0.0 <= 0.0) {
    fVar4 = -fVar4;
  }
  fVar1 = (float10)FUN_008ff0a0(pfVar2,pfVar3,(double)(-fVar4 * 0.5));
  local_20 = (float)((float10)0.0 * fVar1);
  fStack_18 = (float)fVar1;
  local_1c = local_20;
  fVar1 = (float10)FUN_008fef70();
  fStack_14 = (float)fVar1;
  FUN_0077efc0();
  return;
}

