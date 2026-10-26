
void FUN_004cfe90(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int unaff_ESI;
  float10 fVar3;
  
  *(undefined4 *)(unaff_ESI + 0x108) = param_1;
  *(undefined4 *)(unaff_ESI + 0x10c) = param_2;
  fVar3 = (float10)FUN_008ff870();
  fVar1 = (float)fVar3;
  *(float *)(unaff_ESI + 0x110) = fVar1;
  *(float *)(unaff_ESI + 0x114) = fVar1;
  if (fVar1 < 5.0) {
    *(undefined4 *)(unaff_ESI + 0x114) = 0x40a00000;
  }
  if (20.0 < *(float *)(unaff_ESI + 0x114)) {
    *(undefined4 *)(unaff_ESI + 0x114) = 0x41a00000;
  }
  fVar1 = *(float *)(unaff_ESI + 0x114);
  iVar2 = FUN_0089289d();
  *(float *)(unaff_ESI + 0x114) = fVar1 * ((float)iVar2 / 32767.0) * 0.3 + fVar1;
  return;
}

