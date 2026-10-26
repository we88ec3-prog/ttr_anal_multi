
void FUN_00556a20(void)

{
  float fVar1;
  float fVar2;
  int unaff_ESI;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar3 = (float10)FUN_008ff870();
  if ((float)fVar3 <= 2.829) {
    *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_ESI + 0x18);
    *(undefined4 *)(unaff_ESI + 0xc) = *(undefined4 *)(unaff_ESI + 0x1c);
  }
  else {
    fVar4 = (float10)FUN_008fedca();
    fVar5 = (float10)FUN_007cd340(*(undefined4 *)(unaff_ESI + 0x24),(float)fVar4 + 1.5707964);
    fVar1 = (float)fVar5;
    fVar2 = (float)fVar3 / 6.0;
    if (fVar2 < 2.0) {
      fVar2 = 2.0;
    }
    fVar3 = (float10)FUN_008ff0a0();
    fVar5 = (float10)FUN_008fef70();
    *(float *)(unaff_ESI + 8) = fVar2 * (float)fVar3 + *(float *)(unaff_ESI + 8);
    *(float *)(unaff_ESI + 0xc) = *(float *)(unaff_ESI + 0xc) + fVar2 * -(float)fVar5;
    fVar3 = (float10)FUN_004ff540(fVar1);
    if (fVar3 <= (float10)0.005) {
      *(float *)(unaff_ESI + 0x24) = (float)fVar4 + 1.5707964;
      return;
    }
    if (0.0 < fVar1) {
      *(float *)(unaff_ESI + 0x24) = *(float *)(unaff_ESI + 0x24) + 0.005;
      return;
    }
    if (fVar1 < 0.0) {
      *(float *)(unaff_ESI + 0x24) = *(float *)(unaff_ESI + 0x24) - 0.005;
      return;
    }
  }
  return;
}

