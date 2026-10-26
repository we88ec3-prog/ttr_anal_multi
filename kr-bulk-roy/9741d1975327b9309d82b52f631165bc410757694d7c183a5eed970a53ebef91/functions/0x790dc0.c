
void FUN_00790dc0(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int unaff_ESI;
  float10 fVar4;
  
  if (param_1 != 0.0) {
    fVar4 = (float10)FUN_008ff0a0();
    fVar1 = (float)fVar4;
    fVar4 = (float10)FUN_008fef70();
    fVar2 = (float)fVar4;
    fVar3 = *(float *)(unaff_ESI + 8);
    *(float *)(unaff_ESI + 8) =
         *(float *)(unaff_ESI + 8) * fVar2 + *(float *)(unaff_ESI + 4) * fVar1;
    *(float *)(unaff_ESI + 4) = *(float *)(unaff_ESI + 4) * fVar2 - fVar3 * fVar1;
    fVar3 = *(float *)(unaff_ESI + 0x14);
    *(float *)(unaff_ESI + 0x14) =
         *(float *)(unaff_ESI + 0x10) * fVar1 + *(float *)(unaff_ESI + 0x14) * fVar2;
    *(float *)(unaff_ESI + 0x10) = *(float *)(unaff_ESI + 0x10) * fVar2 - fVar3 * fVar1;
    fVar3 = *(float *)(unaff_ESI + 0x20);
    *(float *)(unaff_ESI + 0x20) =
         *(float *)(unaff_ESI + 0x1c) * fVar1 + *(float *)(unaff_ESI + 0x20) * fVar2;
    *(float *)(unaff_ESI + 0x1c) = *(float *)(unaff_ESI + 0x1c) * fVar2 - fVar3 * fVar1;
    fVar3 = *(float *)(unaff_ESI + 0x2c);
    *(float *)(unaff_ESI + 0x2c) =
         *(float *)(unaff_ESI + 0x2c) * fVar2 + *(float *)(unaff_ESI + 0x28) * fVar1;
    *(float *)(unaff_ESI + 0x28) = *(float *)(unaff_ESI + 0x28) * fVar2 - fVar3 * fVar1;
    return;
  }
  return;
}

